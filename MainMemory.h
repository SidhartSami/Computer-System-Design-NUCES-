#pragma once
#include <iostream>
using namespace std;

class MainMemory {
protected:
	int capacity;
	string technologyType;
public:
	MainMemory() {
		capacity = 8;// in Gbs
		technologyType = "\0";
	}
	MainMemory(int cap, string type) {
		if ((cap > 8 && ((cap & (cap - 1)) == 0))) {
			cout << "Error! Wrong Value for MainMemory" << endl;
			return;
		}
		capacity = cap;
		technologyType = type;
	}
	MainMemory(const MainMemory& other) {
		capacity = other.capacity;
		technologyType = other.technologyType;
	}

	int getCapacity() const {
		return capacity;
	}
	string getTechnologyType() const {
		return technologyType;
	}
	void setCapacity(int cap) {
		if ((cap > 8 && ((cap & (cap - 1)) == 0))) {
			cout << "Error! Wrong Value for MainMemory" << endl;
			return;
		}

		capacity = abs(cap);
	}
	void setTechnologyType(const string& type) {
		technologyType = type;
	}
};
