#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int N;
	int mat[100][100];
	int i,j;
	int k,l,m;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> N;
        for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				cin >> mat[i][j];
			}
		}

		for (i = 0; i < N; i++) {
		    for (j = 0; i < N; j++) {
		        for (k = i; k < N; k++) {
				    int tmp = 0;
					for (l = j; l < N; l++) {
						//got two points
						for (m=j;m<l;m++){
						    tmp = tmp + mat[k][m];
						}
						Answer = (Answer>tmp)? Answer:tmp;
					}
					
				}
			}
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}
	return 0;
}
