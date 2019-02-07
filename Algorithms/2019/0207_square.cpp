#include <iostream>

using namespace std;

int sam, sam2, sa1, sa2;
int in, on, out;

int main() {

	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {

		in = 0;
		on = 0;
		out = 0;
		cin >> sam >> sam2 >> sa1 >> sa2;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int currx;
			int curry;
			cin >> currx >> curry;

			// check on line
			if (currx == sam && sa1 <= curry && curry <= sa2) {
				on++;
			}
			else if (currx == sam2 && sa1 <= curry && curry <= sa2) {
				on++;
			}
			else if (curry == sa1 && sam <= currx && currx <= sam2) {
				on++;
			}
			else if (curry == sa2 && sam <= currx && currx <= sam2) {
				on++;
			}
			else if(sam < currx && currx < sam2 && sa1 < curry && curry < sa2){
				in++;
			}
			else {
				out++;
			}
		}
		
		cout << "#" << (z + 1) << " " << in << " " << on << " " << out << endl;


	}

}
