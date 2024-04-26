#pragma once
#include <iostream>
using namespace std;

class NetworkCard {
protected:
	string type;
	int speed;
	double price;
public:
	NetworkCard() {
		type = "\0";
		speed = 0;
		price = 0.0;
	}

	NetworkCard(const string& t, int s, double p) {
		if (s <= 0) {
			cout << "Error! Wrong Value for speed(Network Card)" << endl;
			return;
		}
		type = t;
		speed = s;
		price = abs(p);
	}
	NetworkCard(const NetworkCard& other) {
		type = other.type;
		speed = other.speed;
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

	int getSpeed() const {
		return speed;
	}

	void setSpeed(int s) {
		if (s <= 0 && ((s & (s - 1)) == 0)) {
			cout << "Error! Wrong Value for speed(Network Card)" << endl;
			return;
		}
		speed = s;
	}
};
