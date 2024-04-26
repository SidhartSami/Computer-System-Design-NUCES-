#pragma once
#include <iostream>
using namespace std;


class IntegratedGraphics {
protected:
	int memorySize;
public:
	IntegratedGraphics() : memorySize(128) {}

	IntegratedGraphics(int size) {
		setMemorySize(size);
	}
	IntegratedGraphics(const IntegratedGraphics& other) {
		memorySize = other.memorySize;
	}

	int getMemorySize() const {
		return memorySize;
	}

	void setMemorySize(int size) {
		if (size < 4 || (size & (size - 1)) != 0) {
			cout << "Error! Invalid memory size for Integrated Graphics." << endl;
			return;
		}
		memorySize = size;
	}
};
