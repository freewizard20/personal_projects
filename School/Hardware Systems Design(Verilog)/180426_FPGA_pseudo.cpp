#include "fpga_api.h"
#include <cstring>
#define DATA_SIZE SIZE*(SIZE+1) // fpga bram data size

#define min(x,y) (((x)<(y))?(x):(y))

FPGA::FPGA(off_t data_addr, off_t api_addr)
{
    api_ = new unsigned int[SIZE];    // use api_ as tempolar output 
    data_ = new float[DATA_SIZE];	
}

FPGA::~FPGA()
{
    delete[] api_;
    delete[] data_;
}

float* FPGA::matrix(void)
{
	return data_ + SIZE;
}

float* FPGA::vector(void)
{
	return data_;
}

const float* FPGA::run()
{
    float* vec = this->vector();
    float* mat = this->matrix();
    float* out  = reinterpret_cast<float*>(api_);  

    for(int i = 0 ; i < SIZE; ++i)
    {
        out[i] = 0;

        for(int j = 0 ; j < SIZE; ++j)
           out[i] += vec[j] * mat[SIZE*i + j];
    }

	for(int i = 0 ; i < SIZE; ++i)
	{
		data_[i] = out[i];
	}

    return data_;    
}

void FPGA::largeMV(const float* large_mat, const float* input,
		float* output, int M, int N)
{
	float* vec = this->vector();
    float* mat = this->matrix();

    const float* out;
    for (int i = 0; i < N; i++){
        output[i] = 0.0f;
    }

    for (int x = 0; x < N; x += SIZE) {
        for (int y = 0; y < M; y += SIZE) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    mat[i*SIZE + j] = (x+i < N && y+j < M) ? large_mat[(x+i)*M + (y+j)] : 0.0f;
                }
            }
            
            for (int j = 0; j < SIZE; j++)
                vec[j] = (y+j < M) ? input[y+j] : 0.0f;
            
            out = this->run();
            for (int i = 0; i < SIZE; i++) {
                if (x+i < N)
                    output[x+i] += out[i];
            }

        }
    }
    
}
