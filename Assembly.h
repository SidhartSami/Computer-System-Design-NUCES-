#pragma once
#include <iostream>
using namespace std;
#include "Case.h"

class ComputerAssembly {
private:
	PCCase* computerCase;//(COMPOSITION)
	double price;

public:
	double getPrice() const {
		return price;
	}

	void setPrice(double p) {
		price = abs(p);
	}

	ComputerAssembly() {
		computerCase = nullptr;
		price = 0.0;
	}

	ComputerAssembly(PCCase* c, int price) {
		computerCase = c;
		this->price = price;
	}
	ComputerAssembly(CPU* processor, GraphicsCard* graphics, StorageDevice* storageDev, NetworkCard* netCard, PowerSupply* psu, PCCase* pcCase, double price) {
		computerCase = pcCase;
		this->price = price;
	}

	PCCase* getComputerCase() const {
		return computerCase;
	}

	void setComputerCase(PCCase* pcCase) {
		computerCase = pcCase;
	}
};


class LaptopAssembly {
private:
	LaptopCase* laptopCase;
	double price;

public:
	double getPrice() const {
		return price;
	}

	void setPrice(double p) {
		price = abs(p);
	}

	LaptopAssembly() {
		laptopCase = nullptr;
		price = 0.0;
	}

	LaptopAssembly(LaptopCase* c, int price) {
		laptopCase = c;
		this->price = price;
	}
	LaptopAssembly(CPU* processor, GraphicsCard* graphics, StorageDevice* storageDev, NetworkCard* netCard, PowerSupply* psu, LaptopCase* pcCase, double price) {
		laptopCase = pcCase;
		this->price = price;
	}

	LaptopCase* getComputerCase() const {
		return laptopCase;
	}

	void setLaptopCase(LaptopCase* pcCase) {
		laptopCase = pcCase;
	}
};

class MACAssembly {
private:
	MACCase* macCase;
	double price;

public:
	MACAssembly() {
		macCase = nullptr;
		price = 0.0;
	}

	MACAssembly(MACCase* mac, double price) {
		macCase = mac;
		this->price = price;
	}

	double getPrice() const {
		return price;
	}

	void setPrice(double p) {
		price = abs(p);
	}

	MACCase* getMACCase() const {
		return macCase;
	}

	void setMACCase(MACCase* mac) {
		macCase = mac;
	}
};
