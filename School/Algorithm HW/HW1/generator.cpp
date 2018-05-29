#include <fstream>
#include <cstdlib>
#include <random>
#include <iomanip>

using namespace std;

int main(int argc, char ** argv){
	srand(time(NULL));
	int total = atoi(argv[1]);
	ofstream out(argv[2]);
	for(int i = 0 ; i < total/20 ; i++){
		for(int j = 0 ; j < 20 ; j++){
			out << rand()%100000 << " ";
		}
	out << endl;
	}
	out.close();
}
