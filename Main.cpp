#include<iostream>
using namespace std;
#include<string>
#include<stdlib.h>
#include<fstream>
#include"SerialPort.h"

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];

// change the name of the port with the port name of your computer
// must remember that the backslashes are essential so do not remove them
const char *port = "\\\\.\\COM24";

int main()
{
	SerialPort arduino(port);
	if (arduino.isConnected()) {
		cout << "Connection made" << endl << endl;
		Sleep(1000);
	}
	else {
		cout << "Error in port name" << endl << endl;
		Sleep(1000);
	}
	while (arduino.isConnected())
	{
		fstream file1("Tempdata.txt", ios::out);
		arduino.readSerialPort(output, MAX_DATA_LENGTH);
		file1 << output << endl;
		cout << output<< endl << endl;
		file1.close();
		Sleep(1000);
	}
	return 0;
}