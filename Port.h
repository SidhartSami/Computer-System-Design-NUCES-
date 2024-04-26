#pragma once

#include <iostream>
using namespace std;

class Port {
protected:
	string* type; //(COMPOSITION)
	int* baudRate;//(COMPOSITION)
	int numberOfPorts;//(Association))

public:
	Port() {
		numberOfPorts = 0;
		type = new string[numberOfPorts];
		baudRate = new int[numberOfPorts];
	}
	Port(string* t, int num, int* br) {
		numberOfPorts = num;
		type = new string[num];
		baudRate = new int[num];
		for (int i = 0; i < num; ++i) {
			type[i] = t[i];
			baudRate[i] = br[i];
		}
	}
	~Port() {
		delete[] type;
		type = nullptr;
		delete[] baudRate;
		baudRate = nullptr;
	}

	Port(const Port& other) {
		numberOfPorts = other.numberOfPorts;
		type = new string[numberOfPorts];
		baudRate = new int[numberOfPorts];
		for (int i = 0; i < numberOfPorts; ++i) {
			type[i] = other.type[i];
			baudRate[i] = other.baudRate[i];
		}
	}

	string getType(int index) const {
		if (index >= 0 && index < numberOfPorts) {
			return type[index];
		}
		else {
			cout << "Error! Your Value doesn't exist." << endl;
			return "";
		}
	}

	void setType(const string* t) {
		type = new string[numberOfPorts];
		for (int i = 0; i < numberOfPorts; ++i) {
			type[i] = t[i];
		}
	}

	int getBaudRate(int index) const {
		if (index >= 0 && index < numberOfPorts) {
			return baudRate[index];
		}
		else {
			cout << "Error! Your Value doesn't exist." << endl;
			return -1;
		}
	}

	void setBaudRate(int* br) {
		baudRate = new int[numberOfPorts];
		for (int i = 0; i < numberOfPorts; ++i) {
			baudRate[i] = br[i];
		}
	}
	int getPortCount() {
		return numberOfPorts;	}

	string& getPortName(int index) {
		return type[index];
	}
};
