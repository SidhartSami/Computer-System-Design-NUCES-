#pragma once
#include <iostream>
using namespace std;
#include "Assembly.h"

class Computer {
private:
	ComputerAssembly* CA;//(COMPOSITION)
public:
	Computer(ComputerAssembly* assembly = nullptr)
		: CA(assembly) {}

	Computer(const Computer& other) {
		if (other.CA) {
			CA = new ComputerAssembly(*(other.CA));
		}
		else {
			CA = nullptr;
		}
	}

	~Computer() {
		delete CA;
	}

	ComputerAssembly* getAssembly() const {
		return CA;
	}

	void setAssembly(ComputerAssembly* assembly) {
		CA = assembly;
	}
};
