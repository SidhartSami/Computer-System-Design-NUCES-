#pragma once
#include <iostream>
using namespace std;
#include "Assembly.h"



class MAC {
private:
	MACAssembly* MA;//(COMPOSITION)
public:
	MAC(MACAssembly* assembly = nullptr)
		: MA(assembly) {}

	MAC(const MAC& other) {
		if (other.MA) {
			MA = new MACAssembly(*(other.MA));
		}
		else {
			MA = nullptr;
		}
	}

	~MAC() {
		delete MA;
	}

	MACAssembly* getAssembly() const {
		return MA;
	}

	void setAssembly(MACAssembly* assembly) {
		MA = assembly;
	}
};
