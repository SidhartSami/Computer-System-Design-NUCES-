#pragma once
#include <iostream>
using namespace std;


class ControlUnit {
protected:
	float clock;
public:

	ControlUnit() {
		clock = 0.0;
	}
	ControlUnit(float c) {
		if (c < 0) {
			cout << "Error! Negative Values Not Possible for clock (CU)" << endl;
			clock = -1;
			return;
		}
		clock = c;
	}
	ControlUnit(const ControlUnit& other) {
		clock = other.clock;
	}

	float getClock() const {
		return clock;
	}
	void setClock(float c) {
		if (c < 0) {
			cout << "Error! Negative Values Not Possible for clock (CU)" << endl;
			clock = -1;
			return;
		}
		clock = c;
	}

};
