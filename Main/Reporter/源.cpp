#include<iostream>
#include <fstream>
#pragma warning(disable:4996)
#include"C:\Users\13323\Desktop\Main\Creator\12312\employee.h"
using namespace std;
int main(int argc, char** argv) {
	if (argc != 4) {
		cout << "wrong number of arg!" << endl;
		return 1;
	}
	employee e;
	char inFileName[60];
	char outFileName[60];
	strncpy(inFileName, argv[1], 59);
	strncpy(outFileName, argv[2], 59);
	double pay = atof(argv[3]);
	ifstream inFile(inFileName, ios::in | ios::binary);
	if (!inFile) {
		cout << "error to open the binary file!" << endl;
		return 0;
	}
	ofstream outFile(outFileName);
	outFile << inFileName << endl;
	while (inFile.read((char*)&e, sizeof(e))) {
		outFile << e.num << " " << e.name << " " << e.hours << " " << e.hours * pay << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}