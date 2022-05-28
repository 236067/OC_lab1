#include<iostream>
#include <fstream>
#pragma warning(disable:4996)
#include"C:\Users\13323\Desktop\Main\Creator\12312\employee.h"
using namespace std;
int main(int argc, char** argv) {
	if (argc != 3) {
		cout << "wrong number of arg!" << endl;
		return 1;
	}
	employee e;
	char fileName[60];
	strncpy(fileName, argv[1], 59);
	int number;
	number = atoi(argv[2]);
	ofstream outFile(fileName, ios::out | ios::binary);
	while (number > 0) {
		cin >> e.num >> e.name >> e.hours;
		outFile.write((char*)&e, sizeof(e));
		number--;
	}
	outFile.close();
	return 0;
}