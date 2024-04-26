#pragma once
#include <iostream>
using namespace std;
#include "powerSupply.h"
#include "Port.h"
#include "MotherBoard.h"
#include "Battery.h"
#include "PhysicalMemory.h"

class Case {
protected:
	string formFactor;
	string color;
	double price;

	PhysicalMemory physicalMemory;
	PowerSupply powerSupply;
	Port* port;//(COMPOSITION)
public:
	Case()
		: formFactor(""), color(""), price(0.0), port(nullptr), powerSupply(0, "", 0.0) , physicalMemory(0,"") {}

	Case(const string& form, const string& clr, double p, const PhysicalMemory& pm, const PowerSupply& ps, Port* ports)
		: formFactor(form), color(clr), price(abs(p)), physicalMemory(pm), port(ports), powerSupply(ps) {}


	~Case() {
		delete[] port;
	}
	double getPrice() const {
		return price;
	}

	void setPrice(double p) {
		price = abs(p);
	}

	string getFormFactor() const {
		return formFactor;
	}

	void setFormFactor(const string& form) {
		formFactor = form;
	}

	string getColor() const {
		return color;
	}

	void setColor(const string& clr) {
		color = clr;
	}

	PhysicalMemory getPhysicalMemory() const {
		return physicalMemory;
	}
	void setPhysicalMemory(const PhysicalMemory& newMemory) {
		physicalMemory = newMemory;
	}
	PowerSupply getPowerSupply() const {
		return powerSupply;
	}

	void setPowerSupply(const PowerSupply& ps) {
		powerSupply = ps;
	}

	Port* getPort() const {
		return port;
	}

	void setPort(Port* p) {
		port = p;
	}
};

class PCCase : public Case {
private:
	WindowsMotherBoard PCBoard;
public:

	PCCase(const string& form, const string& clr, double p,
		const PowerSupply& ps, Port* ports, const PhysicalMemory& phycial, const WindowsMotherBoard& pcBoard)
		: Case(form, clr, p, phycial, ps, ports), PCBoard(pcBoard) {}


	WindowsMotherBoard getPCBoard() const {
		return PCBoard;
	}
	void setPCBoard(const WindowsMotherBoard& pcBoard) {
		PCBoard = pcBoard;
	}
	double getPrice() const {
		return price;
	}

	void setPrice(double p) {
		price = abs(p);
	}

	void setPhysicalMemory(const PhysicalMemory& newMemory) {
		physicalMemory = newMemory;
	}
	PowerSupply getPowerSupply() const {
		return powerSupply;
	}

	string getFormFactor() const {
		return formFactor;
	}

	void setFormFactor(const string& form) {
		formFactor = form;
	}

	string getColor() const {
		return color;
	}

	void setColor(const string& clr) {
		color = clr;
	}


	void setPowerSupply(const PowerSupply& ps) {
		powerSupply = ps;
	}

	Port* getPort() const {
		return port;
	}

	void setPort(Port* p) {
		port = p;
	}

};


class MACCase : public Case {
private:
	Battery macBattery;
	Motherboard macBoard;

public:
	MACCase(const string& form, const string& clr, double p,
		const PowerSupply& ps, Port* ports, const PhysicalMemory& physical, const Motherboard& board,
		const Battery& battery)
		: Case(form, clr, p, physical, ps, ports), macBattery(battery), macBoard(board) {}

	Battery getMACBattery() const {
		return macBattery;
	}

	void setMACBattery(const Battery& battery) {
		macBattery = battery;
	}
	Motherboard getMACBoard() const {
		return macBoard;
	}

	void setMACBoard(const Motherboard& board) {
		macBoard = board;
	}
};

class LaptopCase : public Case {
private:
	Battery laptopBattery;
	WindowsMotherBoard laptopBoard;

public:
	LaptopCase(const string& form, const string& clr, double p,
		const PowerSupply& ps, Port* ports, const PhysicalMemory& physical, const WindowsMotherBoard& board,
		const Battery& battery)
		: Case(form, clr, p, physical, ps, ports), laptopBattery(battery), laptopBoard(board) {}

	Battery getLaptopBattery() const {
		return laptopBattery;
	}

	void setLaptopBattery(const Battery& battery) {
		laptopBattery = battery;
	}

	WindowsMotherBoard getLaptopBoard() const {
		return laptopBoard;
	}

	void setLaptopBoard(const WindowsMotherBoard& board) {
		laptopBoard = board;
	}
};
