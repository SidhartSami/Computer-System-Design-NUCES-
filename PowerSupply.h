#pragma once

#include <iostream>
using namespace std;


class PowerSupply {
	int wattage;
	string efficiencyRating;
	double price;
public:
	PowerSupply() {
		wattage = 80;
		efficiencyRating = "Silver 80";
		price = 10;
	}
	PowerSupply(int watt, const string& rating, double cost)
		: wattage(watt), efficiencyRating(rating), price(abs(cost)) {
		if (cost <= 0) {
			cout << "ERROR! Postive Values Required!:" << endl;
		}
	}

	int getWattage() const {
		return wattage;
	}

	void setWattage(int watt) {
		if (watt <= 0) {
			cout << "ERROR! Postive Values Required!:" << endl;
		}
		wattage = abs(watt);
	}

	string getEfficiencyRating() const {
		return efficiencyRating;
	}

	void setEfficiencyRating(const std::string& rating) {
		efficiencyRating = rating;
	}

	double getPrice() const {
		return price;
	}

	void setPrice(double cost) {
		if (cost <= 0) {
			cout << "ERROR! Postive Values Required!:" << endl;
		}

		price = abs(cost);
	}
};

