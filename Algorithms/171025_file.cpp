#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream myfile;
	myfile.open("example.txt");
	myfile << "Writing kill people";
	myfile.close();
	return 0;
}
