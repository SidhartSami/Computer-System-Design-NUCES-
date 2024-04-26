#pragma once
#include <iostream>
using namespace std;


class Battery {
protected:
	int capacity;

public:
	Battery() {
		capacity = 0;
	}

	Battery(int cap) {
		if (cap > 0) {
			cout << "Error! Wrong Value for capacity(Battery)" << endl;
			return;
		}
		capacity = cap;
	}
	
	int getCapacity() const {
		return capacity;
	}

	void setCapacity(int cap) {
		if (cap > 0) {
			cout << "Error! Wrong Value for capacity(Battery)" << endl;
			return;
		}
		capacity = cap;
	}
};

