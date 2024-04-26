#pragma once
#include "ALU.h"
#include "ControlUnit.h"
#include "IntregatedGraphics.h"

#include <iostream>
using namespace std;


class CPU {
protected:
	ALU* alu;//(COMPOSITION)
	ControlUnit* cu;//(COMPOSITION)
	IntegratedGraphics* integratedGraphics;//(COMPOSITION)
	string architecture;
	bool hasGPU;
public:

	CPU() {
		alu = nullptr;
		cu = nullptr;
		integratedGraphics = nullptr;
		architecture = "x86";
		hasGPU = 0;

	}

	CPU(ALU* a, ControlUnit* b, const string& c, bool d, IntegratedGraphics* e = nullptr) {
		alu = new ALU(*a);
		cu = new ControlUnit(*b);
		architecture = c;
		hasGPU = d;
		if (e != nullptr) {
			integratedGraphics = new IntegratedGraphics(*e);
		}
	}

	~CPU() {
		delete alu;
		delete cu;
		delete integratedGraphics;
	}
	CPU(const CPU& other) {
		if (other.alu) {
			alu = new ALU(*other.alu);
		}
		else {
			alu = nullptr;
		}

		if (other.cu) {
			cu = new ControlUnit(*other.cu);
		}
		else {
			cu = nullptr;
		}

		if (other.integratedGraphics) {
			integratedGraphics = new IntegratedGraphics(*other.integratedGraphics);
		}
		else {
			integratedGraphics = nullptr;
		}

		architecture = other.architecture;
		hasGPU = other.hasGPU;
	}

	ALU* getALU() const {
		return alu;
	}
	ControlUnit* getCU() const {
		return cu;
	}
	IntegratedGraphics* getGraphics()const {
		return integratedGraphics;
	}
	string getArchitecture() const {
		return architecture;
	}
	bool hasIntegratedGPU() const {
		return hasGPU;
	}
	void hasIntegratedGPU(bool ans) {
		hasGPU = ans;
	}

	void setALU(ALU* newALU) {
		alu = newALU;
	}
	void setGraphics(IntegratedGraphics* newGraphics) {
		integratedGraphics = newGraphics;
	}
	void setCU(ControlUnit* newCU) {
		cu = newCU;
	}

	void setArchitecture(const string& newArchitecture) {
		architecture = newArchitecture;
		return;
	}

	void setGPU(bool GPU) {
		hasGPU = GPU;
	}
};
