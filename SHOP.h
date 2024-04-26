#pragma once
#include <iostream>
using namespace std;
#include "Assembly.h"
#include "Computer.h"
#include "Laptop.h"
#include <iomanip>
#include "Battery.h"
#include "MAC.h"
class Shop {
    private:
        Computer computer;
        Laptop laptop;
        MAC Assembly;
		int Total;
public:
        Shop() {
			Total = 0;
	        srand(time(0));
        }
		Shop(Computer& comp,Laptop& lap) {
			Total = 0;
			computer = comp;
			laptop = lap;
			srand(time(0));
		}
		int getTotal() const {
			return Total;
		}
		Computer getCompuuter() {
			return computer;
		}
		Laptop getLaptop() {
			return laptop;
		}

		void setTotal(int total) {
			Total = total;
		}
		void setCompuuter(Computer& comp) {
			computer = comp;
		}
		void setLaptop(Laptop& lap) {
			laptop = lap;
		}


		Computer BuildYourPC() {
			bool B1;
			string S1, S2;
			double I1, I2, I3, TotalPrice = 0;
			cout << "WELCOME TO FAST PC SHOP" << endl;
		
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Lets Start With CPU Details." << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			cout << "Enter CPU architecture:";
			cin >> S1;

			bool hasGPU = false;
			cout << "Do you want a GPU in your PC:" << endl;
			cin >> hasGPU;

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "ALU attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			do {
				cout << "How many adder & subractor should your ALU have: " << endl;
				cin >> I1;
				if (I1 <= 0) {
					cout << "Invalid input! Please enter a positive integer." << endl;
				}
			} while (I1 <= 0);

			do {
				cout << "How many Registers should your ALU have (8/16/32): " << endl;
				cin >> I2;
				if (I2 <= 0) {
					cout << "Invalid input! Please enter a positive integer." << endl;
				}
				if (I2 != 8 && I2 != 16 && I2 != 32 && I2 != 64) {
					cout << "Invalid input! Please enter a power of 2." << endl;
				}
			} while (I2 <= 0 && (I2 != 8 && I2 != 16 && I2 != 32 && I2 != 64));

			do {
				cout << "What size should be of your Registers in your ALU (32 / 64): " << endl;
				cin >> I3;
				if (I3 != 32 && I3 != 64) {
					cout << "Invalid input! Please enter a 32/64" << endl;
				}
			} while (I3 != 32 && I3 != 64);

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "ALU Attributes Finished" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			ALU a(I1, I1, I2, I3);

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Control Unit attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			do {
				cout << "Enter the integer for clock: " << endl;
				cin >> I1;
				if (I1 <= 0) {
					cout << "Invalid input! Please enter a positive integer." << endl;
				}
			} while (I1 <= 0);

			ControlUnit c(I1);

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Control Unit Attributes Finished" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;


			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Integrated Graphic Card Attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			cout << "Do You Want Intregated Graphics:" << endl;
			cin >> B1;
			IntegratedGraphics IG(128);  // Default size
			if (B1 == 1) {
				do {
					cout << "Enter the Size of Memory for Integrated Graphics(128/256/512):" << endl;
					cin >> I1;
					if (I1 != 128 && I1 != 256 && I1 != 512) {
						cout << "Error! Your Value Should be from 128/256/512" << endl;
					}
				} while (I1 != 128 && I1 != 256 && I1 != 512);
				IG = IntegratedGraphics(I1);
			}
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "CPU Attributes Finished" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			CPU processor(&a, &c, S1, hasGPU, &IG);

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Network Card Attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			string networkCardType;
			int networkCardSpeed;
			double networkCardPrice;
			cout << "Do you Want Network Card In you PC:";
			cin >> B1;
			NetworkCard networkCard;
			if (B1 == 1) {
				do {
					cout << "Enter the type of Network Card(WI-FI/Ethernet/Both): " << endl;
					cin >> networkCardType;
					if (networkCardType != "WI-FI" && networkCardType != "Ethernet" && networkCardType != "Both") {
						cout << "Wrong Input for Network Type:";
					}
				} while (networkCardType != "WI-FI" && networkCardType != "Ethernet" && networkCardType != "Both");
				do {
					cout << "Enter the speed of Network Card (in Mbps): ";
					cin >> networkCardSpeed;
					if (networkCardSpeed < 0) {
						cout << "Error! Your networkCardSpeed Should be Positive" << endl;
					}
				} while (networkCardSpeed < 0);
				networkCardPrice = rand() % 1000 + 90;
				TotalPrice += networkCardPrice;
				cout << "Price:" << networkCardPrice << endl;
				networkCard = NetworkCard(networkCardType, networkCardSpeed, networkCardPrice);
			}
			else {
				cout << "Moving Forward:" << endl;
			}

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "NetworkCard Attributes Finished" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Graphics Card Attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			GraphicsCard graphicsCard;  // Declared outside the if block

			if (hasGPU == 1) {

				string graphicsCardBrand;
				int graphicsCardMemorySize;
				double graphicsCardPrice;

				cout << "Enter the brand of Graphics Card: ";
				cin >> graphicsCardBrand;
				do {
					cout << "Enter the memory size of Graphics Card (2/4/8): ";
					cin >> graphicsCardMemorySize;

					if ((graphicsCardMemorySize < 2 && ((graphicsCardMemorySize & (graphicsCardMemorySize - 1)) == 0))) {
						cout << "Error!Wrong Value for Memory(GraphicsCard)" << endl;
					}
					if (graphicsCardMemorySize > 32) {
						cout << "Error! Too Big Specs(GraphicsCard)" << endl;
					}

				} while ((graphicsCardMemorySize < 2 && ((graphicsCardMemorySize & (graphicsCardMemorySize - 1)) == 0)) && graphicsCardMemorySize > 32);

				graphicsCardPrice = rand() % 1000 + 100;
				TotalPrice += graphicsCardPrice;
				cout << "Price: " << graphicsCardPrice << endl;
				graphicsCard = GraphicsCard(graphicsCardBrand, graphicsCardMemorySize, graphicsCardPrice);
			}
			else {
				cout << "Lets Move On" << endl;
			}

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Graphics Card Attributes Finished" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;


			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Storage Device Attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			string storageDeviceType;
			int storageDeviceCapacity;
			double storageDevicePrice;

			cout << "Enter the type of Storage Device: ";
			cin >> storageDeviceType;
			do {
				cout << "Enter the capacity of Storage Device (16/32/64): ";
				cin >> storageDeviceCapacity;

				if ((storageDeviceCapacity < 16 && ((storageDeviceCapacity & (storageDeviceCapacity - 1)) == 0))) {
					cout << "Error! Wrong Value for Memory(GraphicsCard)" << endl;
				}
			} while ((storageDeviceCapacity < 2 && ((storageDeviceCapacity & (storageDeviceCapacity - 1)) == 0)));


			storageDevicePrice = rand() % 1000 + 100;
			TotalPrice += storageDevicePrice;
			cout << "Price: " << storageDevicePrice << endl;

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Storage Device Attributes Finished" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			StorageDevice storageDevice(storageDeviceType, storageDeviceCapacity, storageDevicePrice);

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Motherboard Attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			do {
				cout << "Enter the No of Ports You Want With MotherBoard" << endl;
				cin >> I1;
				if (I1 < 0) {
					cout << "Your Input Should be Positive" << endl;
				}
			} while (I1 < 0);

			string* Arr = new string[I1];
			int* rate = new int[I1];

			for (int i = 0; i < I1; i++) {
				cout << "Enter Port " << i + 1 << " Name :";
				cin >> S1;
				cout << "Enter " << i + 1 << " Port Baud rate ";
				cin >> I3;
				*(Arr + i) = S1;
				*(rate + i) = I3;
			}

			Port port(Arr, I1, rate);
			delete[]Arr;
			delete[]rate;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Main Memory (RAM) Attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			string mainMemoryType;
			int mainMemoryCap;
			cout << "Enter the Type of Main Memory:";
			cin >> mainMemoryType;
			do {
				cout << "Enter the Capacity of the Main Memory:";
				cin >> mainMemoryCap;
				if (mainMemoryCap < 0)
					cout << "Your Value Should Be Positive:";
			} while (mainMemoryCap < 0);
			MainMemory mainMemory(mainMemoryCap, mainMemoryType);

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << " CASE Details." << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			cout << "Enter the Type of Case You Want:" << endl;
			cin >> S1;
			do {
				cout << "Enter the Color of Case You Want:" << endl;
				cin >> S2;
				if ((S2 != "White" && S2 != "Black")) {
					cout << "Sorry! We only have White & Black available." << endl;
				}
			} while (S2 != "White" && S2 != "Black");

			int p = rand() % 1000 + 100;

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << " Power Supply Details." << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			int powerWattage;
			string powerEfficiencyRating;
			double powerPrice;

			cout << "Enter Power Supply Wattage: ";
			cin >> powerWattage;

			cout << "Enter Power Supply Efficiency Rating (Gold/Silver/Bronze): ";
			cin >> powerEfficiencyRating;

			while (powerEfficiencyRating != "Gold" && powerEfficiencyRating != "Silver" && powerEfficiencyRating != "Bronze") {
				cout << "Invalid input! Efficiency Rating should be Gold, Silver, or Bronze." << endl;
				cout << "Enter Power Supply Efficiency Rating (Gold/Silver/Bronze): ";
				cin >> powerEfficiencyRating;
			}
			powerPrice = rand() % 1000 + 100;
			TotalPrice += powerPrice;
			cout << "Price: " << powerPrice << endl;

			PowerSupply powerSupply(powerWattage, powerEfficiencyRating, powerPrice);

			string memoryType;
			int memoryCapacity;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Power Supply Details Finished." << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Physical Memory (RAM) Attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			cout << "Enter the type of RAM (DDR3/DDR4): ";
			cin >> memoryType;

			cout << "Enter the capacity of RAM (in GB): ";
			cin >> memoryCapacity;

			while (memoryCapacity <= 0) {
				cout << "Invalid input! RAM capacity should be a positive integer." << endl;
				cout << "Enter the capacity of RAM (in GB): ";
				cin >> memoryCapacity;
			}

			PhysicalMemory physicalMemory(memoryCapacity, memoryType);
			WindowsMotherBoard Board(&networkCard, storageDevice, mainMemory, processor, &port, graphicsCard);

			PCCase CASE(S1, S2, p, powerSupply, &port, physicalMemory, Board);
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << " Case Attributes Finished." << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			cout << "Computer assembly completed successfully!" << endl;
			ComputerAssembly computerAssembly(&CASE, TotalPrice);
			
			
			Computer newComputer = Computer(&computerAssembly);
			computer = newComputer;
			printComputerDetails(&newComputer);
			
			return newComputer;
		}

		void printComputerDetails(Computer* computer) {

			ComputerAssembly* assembly = computer->getAssembly();
			if (!assembly) {
				cout << "Computer Assembly Details: N/A" << endl;
				return;
			}

			PCCase* pcCase = assembly->getComputerCase();
			if (!pcCase) {
				cout << "PC Case Details: N/A" << endl;
				return;
			}
			else {
				WindowsMotherBoard computerBoard = pcCase->getPCBoard();
				{
					cout << "Motherboard Details:" << endl;
					cout << "  Port Details:" << endl;
					Port* ports = computerBoard.getInternalPorts();
					if (!ports) {
						cout << "    Ports: N/A" << endl;
					}
					else {
						for (int i = 0; i < ports->getPortCount(); ++i) {
							cout << "    Port " << i + 1 << ": " << ports->getPortName(i) << ", Baud Rate: " << ports->getBaudRate(i) << endl;
						}
					}
				}
			}

			PowerSupply powerSupply = pcCase->getPowerSupply();
			cout << "Power Supply Details:" << endl;
			cout << "  Wattage: " << powerSupply.getWattage() << " W" << endl;
			cout << "  Efficiency Rating: " << powerSupply.getEfficiencyRating() << endl;
			cout << "  Price: $" << powerSupply.getPrice() << endl;



			PhysicalMemory physicalMemory = pcCase->getPhysicalMemory();
			cout << "Physical Memory (RAM) Details:" << endl;
			cout << "  Type: " << physicalMemory.getType() << endl;
			cout << "  Capacity: " << physicalMemory.getCapacity() << " GB" << endl;


			MainMemory mainMemory = pcCase->getPCBoard().getMainMemory();
			cout << "Main Memory Details:" << endl;
			cout << "  Type: " << mainMemory.getTechnologyType() << endl;
			cout << "  Capacity: " << mainMemory.getCapacity() << " GB" << endl;

			StorageDevice storageDevice = pcCase->getPCBoard().getStorageDevice();
			cout << "Storage Device Details:" << endl;
			cout << "  Type: " << storageDevice.getType() << endl;
			cout << "  Capacity: " << storageDevice.getCapacity() << " GB" << endl;
			cout << "  Price: $" << storageDevice.getPrice() << endl;

			NetworkCard* networkCard = pcCase->getPCBoard().getNetworkInterface();
			cout << "Network Interface Card Details:" << endl;
			cout << "  Type: " << networkCard->getType() << endl;
			cout << "  Speed: " << networkCard->getSpeed() << " Mbps" << endl;
			cout << "  Price: $" << networkCard->getPrice() << endl;

			GraphicsCard graphicsCard = pcCase->getPCBoard().getDedicatedGraphicCard();
			cout << "Graphics Card Details:" << endl;
			cout << "  Brand: " << graphicsCard.getBrand() << endl;
			cout << "  Memory Size: " << graphicsCard.getMemorySize() << " GB" << endl;
			cout << "  Price: $" << graphicsCard.getPrice() << endl;

			CPU computerCPU = pcCase->getPCBoard().getCPU();
			cout << "  CPU Details:" << endl;
			cout << "    Architecture: " << computerCPU.getArchitecture() << endl;
			cout << "    Has GPU: " << (computerCPU.hasIntegratedGPU() ? "Yes" : "No") << endl;

			ALU* cpuALU = computerCPU.getALU();
			if (cpuALU) {
				cout << "    ALU Attributes:" << endl;
				cout << "      Adder & Subtractor Count: " << cpuALU->getAdder() << endl;
				cout << "      Register Count: " << cpuALU->getRegisters() << endl;
				cout << "      Register Size: " << cpuALU->getSizeofRegisters() << " bits" << endl;
			}

			ControlUnit* cpuControlUnit = computerCPU.getCU();
			if (cpuControlUnit) {
				cout << "    Control Unit Attributes:" << endl;
				cout << "      Clock Integer: " << cpuControlUnit->getClock() << endl;
			}
			IntegratedGraphics* iGraphic = computerCPU.getGraphics();
			cout << "Intregrated Graphics Details: " << endl;
			cout << "Memory Size: " << iGraphic->getMemorySize() << endl;

			cout << "Total Price: $" << assembly->getPrice() << endl;

		}


		Laptop BuildYourLaptop() {
			bool B1;
			string S1, S2;
			double I1, I2, I3, TotalPrice = 0;
			cout << "WELCOME TO FAST Laptop SHOP" << endl;
			cout << "Do You Want to Start Now? (0 for NO & 1 for Yes)" << endl;
			cin >> B1;
			if (B1 == 0) {
				cout << "OKAY THANK YOU FOR VISITING." << endl;
				return Laptop();
			}

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Lets Start With CPU Details." << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			cout << "Enter CPU architecture:";
			cin >> S1;

			bool hasGPU = false;
			cout << "Do you want a GPU in your PC:" << endl;
			cin >> hasGPU;

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "ALU attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			do {
				cout << "How many adder & subractor should your ALU have: " << endl;
				cin >> I1;
				if (I1 <= 0) {
					cout << "Invalid input! Please enter a positive integer." << endl;
				}
			} while (I1 <= 0);

			do {
				cout << "How many Registers should your ALU have (8/16/32): " << endl;
				cin >> I2;
				if (I2 <= 0) {
					cout << "Invalid input! Please enter a positive integer." << endl;
				}
				if (I2 != 8 && I2 != 16 && I2 != 32 && I2 != 64) {
					cout << "Invalid input! Please enter a power of 2." << endl;
				}
			} while (I2 <= 0 && (I2 != 8 && I2 != 16 && I2 != 32 && I2 != 64));

			do {
				cout << "What size should be of your Registers in your ALU (32 / 64): " << endl;
				cin >> I3;
				if (I3 != 32 && I3 != 64) {
					cout << "Invalid input! Please enter a 32/64" << endl;
				}
			} while (I3 != 32 && I3 != 64);

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "ALU Attributes Finished" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			ALU a(I1, I1, I2, I3);

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Control Unit attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			do {
				cout << "Enter the integer for clock: " << endl;
				cin >> I1;
				if (I1 <= 0) {
					cout << "Invalid input! Please enter a positive integer." << endl;
				}
			} while (I1 <= 0);

			ControlUnit c(I1);

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Control Unit Attributes Finished" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;


			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Integrated Graphic Card Attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			cout << "Do You Want Intregated Graphics:" << endl;
			cin >> B1;
			IntegratedGraphics IG(128);  
			if (B1 == 1) {
				do {
					cout << "Enter the Size of Memory for Integrated Graphics(128/256/512):" << endl;
					cin >> I1;
					if (I1 != 128 && I1 != 256 && I1 != 512) {
						cout << "Error! Your Value Should be from 128/256/512" << endl;
					}
				} while (I1 != 128 && I1 != 256 && I1 != 512);
				IG = IntegratedGraphics(I1);
			}
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "CPU Attributes Finished" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			CPU processor(&a, &c, S1, hasGPU, &IG);

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Network Card Attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			string networkCardType;
			int networkCardSpeed;
			double networkCardPrice;
			cout << "Do you Want Network Card In you PC:";
			cin >> B1;
			NetworkCard networkCard;
			if (B1 == 1) {
				do {
					cout << "Enter the type of Network Card(WI-FI/Ethernet/Both): " << endl;
					cin >> networkCardType;
					if (networkCardType != "WI-FI" && networkCardType != "Ethernet" && networkCardType != "Both") {
						cout << "Wrong Input for Network Type:";
					}
				} while (networkCardType != "WI-FI" && networkCardType != "Ethernet" && networkCardType != "Both");
				do {
					cout << "Enter the speed of Network Card (in Mbps): ";
					cin >> networkCardSpeed;
					if (networkCardSpeed < 0) {
						cout << "Error! Your networkCardSpeed Should be Positive" << endl;
					}
				} while (networkCardSpeed < 0);
				networkCardPrice = rand() % 1000 + 90;
				TotalPrice += networkCardPrice;
				cout << "Price:" << networkCardPrice << endl;
				networkCard = NetworkCard(networkCardType, networkCardSpeed, networkCardPrice);
			}
			else {
				cout << "Moving Forward:" << endl;
			}

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "NetworkCard Attributes Finished" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Graphics Card Attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			GraphicsCard graphicsCard;  // Declared outside the if block

			if (hasGPU == 1) {

				string graphicsCardBrand;
				int graphicsCardMemorySize;
				double graphicsCardPrice;

				cout << "Enter the brand of Graphics Card: ";
				cin >> graphicsCardBrand;
				do {
					cout << "Enter the memory size of Graphics Card (2/4/8): ";
					cin >> graphicsCardMemorySize;

					if ((graphicsCardMemorySize < 2 && ((graphicsCardMemorySize & (graphicsCardMemorySize - 1)) == 0))) {
						cout << "Error!Wrong Value for Memory(GraphicsCard)" << endl;
					}
					if (graphicsCardMemorySize > 32) {
						cout << "Error! Too Big Specs(GraphicsCard)" << endl;
					}

				} while ((graphicsCardMemorySize < 2 && ((graphicsCardMemorySize & (graphicsCardMemorySize - 1)) == 0)) && graphicsCardMemorySize > 32);

				graphicsCardPrice = rand() % 1000 + 100;
				TotalPrice += graphicsCardPrice;
				cout << "Price: " << graphicsCardPrice << endl;
				graphicsCard = GraphicsCard(graphicsCardBrand, graphicsCardMemorySize, graphicsCardPrice);
			}
			else {
				cout << "Lets Move On" << endl;
			}

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Graphics Card Attributes Finished" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;


			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Storage Device Attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			string storageDeviceType;
			int storageDeviceCapacity;
			double storageDevicePrice;

			cout << "Enter the type of Storage Device: ";
			cin >> storageDeviceType;
			do {
				cout << "Enter the capacity of Storage Device (16/32/64): ";
				cin >> storageDeviceCapacity;

				if ((storageDeviceCapacity < 16 && ((storageDeviceCapacity & (storageDeviceCapacity - 1)) == 0))) {
					cout << "Error! Wrong Value for Memory(GraphicsCard)" << endl;
				}
			} while ((storageDeviceCapacity < 2 && ((storageDeviceCapacity & (storageDeviceCapacity - 1)) == 0)));


			storageDevicePrice = rand() % 1000 + 100;
			TotalPrice += storageDevicePrice;
			cout << "Price: " << storageDevicePrice << endl;

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Storage Device Attributes Finished" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			StorageDevice storageDevice(storageDeviceType, storageDeviceCapacity, storageDevicePrice);

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Motherboard Attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			do {
				cout << "Enter the No of Ports You Want With MotherBoard" << endl;
				cin >> I1;
				if (I1 < 0) {
					cout << "Your Input Should be Positive" << endl;
				}
			} while (I1 < 0);

			string* Arr = new string[I1];
			int* rate = new int[I1];

			for (int i = 0; i < I1; i++) {
				cout << "Enter Port " << i + 1 << " Name :";
				cin >> S1;
				cout << "Enter " << i + 1 << " Port Baud rate ";
				cin >> I3;
				*(Arr + i) = S1;
				*(rate + i) = I3;
			}

			Port port(Arr, I1, rate);

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Main Memory (RAM) Attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			string mainMemoryType;
			int mainMemoryCap;
			cout << "Enter the Type of Main Memory:";
			cin >> mainMemoryType;
			do {
				cout << "Enter the Capacity of the Main Memory:";
				cin >> mainMemoryCap;
				if (mainMemoryCap < 0)
					cout << "Your Value Should Be Positive:";
			} while (mainMemoryCap < 0);
			MainMemory mainMemory(mainMemoryCap, mainMemoryType);

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << " CASE Details." << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			cout << "Enter the Type of Case You Want:" << endl;
			cin >> S1;
			do {
				cout << "Enter the Color of Case You Want:" << endl;
				cin >> S2;
				if ((S2 != "White" && S2 != "Black")) {
					cout << "Sorry! We only have White & Black available." << endl;
				}
			} while (S2 != "White" && S2 != "Black");

			int p = rand() % 1000 + 100;

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << " Power Supply Details." << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			int powerWattage;
			string powerEfficiencyRating;
			double powerPrice;

			cout << "Enter Power Supply Wattage: ";
			cin >> powerWattage;

			cout << "Enter Power Supply Efficiency Rating (Gold/Silver/Bronze): ";
			cin >> powerEfficiencyRating;

			while (powerEfficiencyRating != "Gold" && powerEfficiencyRating != "Silver" && powerEfficiencyRating != "Bronze") {
				cout << "Invalid input! Efficiency Rating should be Gold, Silver, or Bronze." << endl;
				cout << "Enter Power Supply Efficiency Rating (Gold/Silver/Bronze): ";
				cin >> powerEfficiencyRating;
			}
			powerPrice = rand() % 1000 + 100;
			TotalPrice += powerPrice;
			cout << "Price: " << powerPrice << endl;

			PowerSupply powerSupply(powerWattage, powerEfficiencyRating, powerPrice);

			string memoryType;
			int memoryCapacity;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Power Supply Details Finished." << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Physical Memory (RAM) Attributes" << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			cout << "Enter the type of RAM (DDR3/DDR4): ";
			cin >> memoryType;

			cout << "Enter the capacity of RAM (in GB): ";
			cin >> memoryCapacity;

			while (memoryCapacity <= 0) {
				cout << "Invalid input! RAM capacity should be a positive integer." << endl;
				cout << "Enter the capacity of RAM (in GB): ";
				cin >> memoryCapacity;
			}

			
			
			PhysicalMemory physicalMemory(memoryCapacity, memoryType);
			WindowsMotherBoard Board(&networkCard, storageDevice, mainMemory, processor, &port, graphicsCard);
			int cap;

			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << " Battery Attributes." << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << "Enter the Capacity of Battery(Mah):";
			cin >> cap;
			Battery battery(cap);
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << " Battery Attributes Finished." << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;


			LaptopCase CASE(S1, S2, p, powerSupply, &port, physicalMemory, Board,battery);
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
			cout << " Case Attributes Finished." << endl;
			cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

			cout << "Computer assembly completed successfully!" << endl;
			LaptopAssembly laptopAssembly(&CASE, TotalPrice);


			Laptop newLaptop = Laptop(&laptopAssembly);
			laptop = newLaptop;
			return newLaptop;
		}

		void printComputerDetails(Laptop* laptop) {
			LaptopAssembly* assembly = laptop->getAssembly();
			if (!assembly) {
				cout << "Computer Assembly Details: N/A" << endl;
				return;
			}

			LaptopCase* LaptopCase = assembly->getComputerCase();
			if (!LaptopCase) {
				cout << "PC Case Details: N/A" << endl;
				return;
			}
			else {
				WindowsMotherBoard LaptopBoard = LaptopCase->getLaptopBoard();
				{
					cout << "Motherboard Details:" << endl;
					cout << "  Port Details:" << endl;
					Port* ports = LaptopBoard.getInternalPorts();
					if (!ports) {
						cout << "    Ports: N/A" << endl;
					}
					else {
						for (int i = 0; i < ports->getPortCount(); ++i) {
							cout << "    Port " << i + 1 << ": " << ports->getPortName(i) << ", Baud Rate: " << ports->getBaudRate(i) << endl;
						}
					}
				}
			}

			PowerSupply powerSupply = LaptopCase->getPowerSupply();
			cout << "Power Supply Details:" << endl;
			cout << "  Wattage: " << powerSupply.getWattage() << " W" << endl;
			cout << "  Efficiency Rating: " << powerSupply.getEfficiencyRating() << endl;
			cout << "  Price: $" << powerSupply.getPrice() << endl;



			PhysicalMemory physicalMemory = LaptopCase->getPhysicalMemory();
			cout << "Physical Memory (RAM) Details:" << endl;
			cout << "  Type: " << physicalMemory.getType() << endl;
			cout << "  Capacity: " << physicalMemory.getCapacity() << " GB" << endl;


			MainMemory mainMemory = LaptopCase->getLaptopBoard().getMainMemory();
			cout << "Main Memory Details:" << endl;
			cout << "  Type: " << mainMemory.getTechnologyType() << endl;
			cout << "  Capacity: " << mainMemory.getCapacity() << " GB" << endl;

			StorageDevice storageDevice = LaptopCase->getLaptopBoard().getStorageDevice();
			cout << "Storage Device Details:" << endl;
			cout << "  Type: " << storageDevice.getType() << endl;
			cout << "  Capacity: " << storageDevice.getCapacity() << " GB" << endl;
			cout << "  Price: $" << storageDevice.getPrice() << endl;

			NetworkCard* networkCard = LaptopCase->getLaptopBoard().getNetworkInterface();
			cout << "Network Interface Card Details:" << endl;
			cout << "  Type: " << networkCard->getType() << endl;
			cout << "  Speed: " << networkCard->getSpeed() << " Mbps" << endl;
			cout << "  Price: $" << networkCard->getPrice() << endl;

			GraphicsCard graphicsCard = LaptopCase->getLaptopBoard().getDedicatedGraphicCard();
			cout << "Graphics Card Details:" << endl;
			cout << "  Brand: " << graphicsCard.getBrand() << endl;
			cout << "  Memory Size: " << graphicsCard.getMemorySize() << " GB" << endl;
			cout << "  Price: $" << graphicsCard.getPrice() << endl;

			CPU computerCPU = LaptopCase->getLaptopBoard().getCPU();
			cout << "  CPU Details:" << endl;
			cout << "    Architecture: " << computerCPU.getArchitecture() << endl;
			cout << "    Has GPU: " << (computerCPU.hasIntegratedGPU() ? "Yes" : "No") << endl;

			ALU* cpuALU = computerCPU.getALU();
			if (cpuALU) {
				cout << "    ALU Attributes:" << endl;
				cout << "      Adder & Subtractor Count: " << cpuALU->getAdder() << endl;
				cout << "      Register Count: " << cpuALU->getRegisters() << endl;
				cout << "      Register Size: " << cpuALU->getSizeofRegisters() << " bits" << endl;
			}

			ControlUnit* cpuControlUnit = computerCPU.getCU();
			if (cpuControlUnit) {
				cout << "    Control Unit Attributes:" << endl;
				cout << "      Clock Integer: " << cpuControlUnit->getClock() << endl;
			}
			IntegratedGraphics* iGraphic = computerCPU.getGraphics();
			cout << "Intregrated Graphics Details: " << endl;
			cout << "Memory Size: " << iGraphic->getMemorySize() << endl;

			
			Battery battery = LaptopCase->getLaptopBattery();
				cout << "Battery Details:" << endl;
				cout << "  Capacity: " << battery.getCapacity() << " mAh" << endl;
			
			cout << "Total Price: $" << assembly->getPrice() << endl;

		}
      
};