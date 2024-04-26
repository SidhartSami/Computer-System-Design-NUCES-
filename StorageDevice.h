#pragma once
#include <iostream>
using namespace std;

class StorageDevice {
protected:
	string type;
	int capacity;
	double price;
public:
	StorageDevice() {
		type = "\0";
		capacity = 0;
		price = 0;
	}

	StorageDevice(const string& t, int cap, double p) {
		if (cap < 16 && ((cap & (cap - 1)) == 0)) {
			cout << "Error! Wrong Value for StorageDevice capacity" << endl;
			return;
		}
		type = t;
		capacity = cap;
		price = p;
	}
	StorageDevice(const StorageDevice& other) {
		type = other.type;
		capacity = other.capacity;
		price = other.price;
	}

	double getPrice() const {
		return price;
	}

	void setPrice(double p) {
		price = abs(p);
	}

	string getType() const {
		return type;
	}

	void setType(const string& t) {
		type = t;
	}

	int getCapacity() const {
		return capacity;
	}

	void setCapacity(int cap) {
		if (cap < 16 && ((cap & (cap - 1)) == 0)) {
			cout << "Error! Wrong Value for StorageDevice capacity" << endl;
			return;
		}
		capacity = cap;
	}
};
