#pragma once
#include <iostream>
using namespace std;

class ALU {
protected:
	int NoOfAdders;
	int NoOfSubractor;
	int NoOfRegisters;
	int SizeOfRegisters;
public:

	ALU() {
		NoOfAdders = 1;
		NoOfSubractor = 1;
		NoOfRegisters = 8;
		SizeOfRegisters = 32;
	}

	ALU(int adder, int subractor, int noofReg, int sizeOfReg) {
		if (sizeOfReg != 32 && sizeOfReg != 64 && (noofReg > 0 && ((noofReg & (noofReg - 1)) == 0))) {
			cout << "Error! Wrong Values for Register (ALU)!" << endl;
			return;
		}
		else if (adder < 0 || subractor < 0) {
			cout << "Error! Negative Values Not Possible for Adder/Subractor(ALU)" << endl;
			return;
		}
		NoOfAdders = abs(adder);
		NoOfSubractor = abs(subractor);
		NoOfRegisters = abs(noofReg);
		SizeOfRegisters = abs(sizeOfReg);
	}
	ALU(const ALU& other) {
		NoOfAdders = other.NoOfAdders;
		NoOfSubractor = other.NoOfSubractor;
		NoOfRegisters = other.NoOfRegisters;
		SizeOfRegisters = other.SizeOfRegisters;
	}
	int getAdder() const {
		return NoOfAdders;
	}
	int getSubractor() const {
		return NoOfSubractor;
	}
	int getRegisters() const {
		return NoOfRegisters;
	}
	int getSizeofRegisters() const {
		return SizeOfRegisters;
	}
	void setAdder(int adder) {
		if (adder < 0) {
			cout << "Error! Negative Values Not Possible for Adder(ALU)" << endl;
			NoOfAdders = -1;
			return;
		}
		NoOfAdders = abs(adder);
	}
	void setSubractor(int subracter) {
		if (subracter < 0) {
			cout << "Error! Negative Values Not Possible for Subractor(ALU)" << endl;
			NoOfSubractor = -1;
			return;
		}
		NoOfSubractor = abs(subracter);
	}
	void setRegisters(int noOfReg) {
		if ((noOfReg > 0 && ((noOfReg & (noOfReg - 1)) == 0))) {
			cout << "Error! Those Values Not Possible for Register(ALU)" << endl;
			noOfReg = -1;
			return;
		}
		NoOfRegisters = abs(noOfReg);
	}
	void getSizeofRegisters(int sizeOfReg) {
		if (sizeOfReg != 32 && sizeOfReg != 64) {
			cout << "Error! Those Values Not Possible for Size of Register(ALU)" << endl;
			SizeOfRegisters = -1;
			return;

		}
		SizeOfRegisters = abs(sizeOfReg);
	}

};
