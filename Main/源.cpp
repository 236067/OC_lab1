#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include"C:\Users\13323\Desktop\Main\Creator\12312\employee.h"
#pragma warning(disable:4996)
using namespace std;

bool RunProcess(wchar_t* cmd)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (!CreateProcess(NULL, cmd, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
		std::cout << "Failed to create \n";
		return 1;
	}
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return 0;
}

int main() {
	employee e;
	char cmd1[100] = "Creator.exe ";
	char binary[60];
	char num[20];
	cout << "Enter name of binary file: \n";
	cin >> binary;
	strcat(cmd1, binary);
	strcat(cmd1, " ");
	cout << "Enter number of entries: \n";
	cin >> num;
	strcat(cmd1, num);
	wchar_t wcmd1[120];
	mbstowcs(wcmd1, cmd1, strlen(cmd1) + 1);
	RunProcess(wcmd1);
	ifstream inFile1(binary, ios::in | ios::binary);
	cout << "Binary file: \n";
	while (inFile1.read((char*)&e, sizeof(e))) {
		cout << e.num << " " << e.name << " " << e.hours << endl;
	}
	inFile1.close();
	char cmd2[160] = "Reporter.exe ";
	char report[60];
	char pay[20];
	cout << "Enter name of report file: \n";
	cin >> report;
	strcat(report, ".txt");
	strcat(cmd2, binary);
	strcat(cmd2, " ");
	strcat(cmd2, report);
	strcat(cmd2, " ");
	cout << "Enter pay of per hour work: \n";
	cin >> pay;
	strcat(cmd2, pay);
	wchar_t wcmd2[180];
	mbstowcs(wcmd2, cmd2, strlen(cmd2) + 1);
	RunProcess(wcmd2);
	ifstream inFile2(report);
	cout << "Report file: \n";
	string s;
	while (getline(inFile2, s))
	{
		cout << s << endl;
	}

	inFile2.close();

	return 0;
}


