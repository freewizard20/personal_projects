#include <iostream>

using namespace std;

int main() {

	for (int z = 0; z < 3; z++) {

		int tot = 0;
		for (int i = 0; i < 4; i++) {
			int tmp;
			cin >> tmp;
			tot += tmp;
		}
		
		switch (tot) {
		case 0:
			cout << "D" << endl;
			break;
		case 1:
			cout << "C" << endl;
			break;
		case 2:
			cout << "B" << endl;
			break;
		case 3:
			cout << "A" << endl;
			break;
		case 4:
			cout << "E" << endl;
			break;
		}
	}

}
