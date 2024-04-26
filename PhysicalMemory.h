#pragma once
#include <iostream>
using namespace std;

class PhysicalMemory {
protected:
	int capacity;
	string MemoryType;

public:
	PhysicalMemory() {
		capacity = 4; // in GBs
		MemoryType = "\0";
	}

	PhysicalMemory(int X, string Y) {
		if (X <= 4 && ((X & (X - 1)) == 0)) {
			cout << "Error! Wrong Value for PhysicalMemory" << endl;
			return;
		}
		capacity = X;
		MemoryType = Y;
	}

	int getCapacity() const {
		return capacity;
	}

	void setCapacity(int X) {
		if (X <= 4 && ((X & (X - 1)) == 0)) {
			cout << "Error! Wrong Value for PhysicalMemory" << endl;
			return;
		}
		capacity = X;
	}

	string getType() const {
		return MemoryType;
	}

	void setType(const string& type, const string& systemArchitecture) {
		if (systemArchitecture == "Intel" || systemArchitecture == "AMD") {
			if (type == "DDR4" || type == "DDR5") {
				MemoryType = type;
			}
			else {
				cout << "Error: Intel and AMD systems must use DDR4/5 memory." << endl;
			}
		}
		else if (systemArchitecture == "AppleSilicon") {
			if (type == "LPDDR4" || type == "LPDDR5") {
				MemoryType = type;
			}
			else {
				cout << "Error: AppleSilicon-based systems must use LPDDR4/5 memory." << endl;
			}
		}
		else {
			cout << "Error: Unsupported system architecture." << endl;
		}
	}
};
// PhysicalMemory,MotherBoard and CPU all exist without computer (agrregation)
