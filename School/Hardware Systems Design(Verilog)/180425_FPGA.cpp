#include "fpga_api.h"
#include <cstring>

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define DATA_SIZE SIZE*(SIZE+1)*sizeof(float) // fpga bram data size

#define min(x,y) (((x)<(y))?(x):(y))

FPGA::FPGA(off_t data_addr, off_t api_addr)
{
    fd_ = open("/dev/mem", O_RDWR);
    data_ = static_cast<float*>(mmap(NULL, DATA_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd_, data_addr));
    api_ = static_cast<unsigned int*>(mmap(NULL, sizeof(unsigned int), PROT_READ|PROT_WRITE, MAP_SHARED,fd_, api_addr));
}

FPGA::~FPGA()
{
    munmap(data_, DATA_SIZE );
    munmap(api_, sizeof(unsigned int));
    close(fd_);
}

float* FPGA::matrix(void)
{
	return data_ + SIZE;
}

float* FPGA::vector(void)
{
	return data_;
}

const float* __attribute__((optimize("O0"))) FPGA::run()
{
    *api_ = 0x5555;
    while(*api_ == 0x5555);

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
