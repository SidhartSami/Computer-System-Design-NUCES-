#pragma once
#include <iostream>
using namespace std;
#include "IntregatedGraphics.h"

class GraphicsCard : public IntegratedGraphics {
protected:
	string brand;
	double price;
public:
	GraphicsCard() {
		brand = "\0";
		memorySize = 0;
		price = 0.0;
	}
	GraphicsCard(const string& b, int size, double p)
	{
		if ((size < 2 && ((size & (size - 1)) == 0))) {
			cout << "Error! Wrong Value for Memory(GraphicsCard)" << endl;
			return;
		}
		brand = b;
		memorySize = size;
		price = p;
	}

	GraphicsCard(const GraphicsCard& other) {
		brand = other.brand;
		memorySize = other.memorySize;
		price = other.price;
	}

	double getPrice() const {
		return price;
	}
	void setPrice(double p) {
		price = abs(p);
	}
	string getBrand() const {
		return brand;
	}
	void setBrand(const string& b) {
		brand = b;
	}

	int getMemorySize() const {
		return memorySize;
	}
	void setMemorySize(int size) {
		if ((size < 2 && ((size & (size - 1)) == 0))) {
			cout << "Error! Wrong Value for Memory(GraphicsCard)" << endl;
			return;
		}
		if (size > 32) {
			cout << "Error! Too Big Specs(GraphicsCard)" << endl;
		}
		memorySize = abs(size);
	}
};
