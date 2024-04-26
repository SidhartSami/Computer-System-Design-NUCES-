#pragma once
#pragma once
#include <iostream>
using namespace std;
#include "Assembly.h"

class Laptop{
private:
	LaptopAssembly* LA;//(COMPOSITION)
public:
	Laptop(LaptopAssembly* assembly = nullptr)
		: LA(assembly) {}

	Laptop(const Laptop& other) {
		if (other.LA) {
			LA = new LaptopAssembly(*(other.LA));
		}
		else {
			LA = nullptr;
		}
	}

	~Laptop() {
		delete LA;
	}

	LaptopAssembly* getAssembly() const {
		return LA;
	}

	void setAssembly(LaptopAssembly* assembly) {
		LA = assembly;
	}
};
