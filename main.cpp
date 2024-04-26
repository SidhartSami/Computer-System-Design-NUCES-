#include <iostream>
using namespace std;
#include <cstdlib> 
#include <ctime>
#include <iomanip>

#include "CPU.h"
#include "ControlUnit.h"
#include "MotherBoard.h"
#include "Case.h"
#include "Assembly.h"
#include "Computer.h"
#include "SHOP.h"

int main() {
    srand(time(0));

    cout << "Welcome to Fast PC Shop!" << endl;
    cout << "How can we assist you today?" << endl;
    cout << "1. Build a PC" << endl;
    cout << "2. Build a Laptop" << endl;
    cout << "3. Buy a pre-built PC" << endl;
    cout << "4. Buy a pre-built Laptop" << endl;
    cout << "Please enter your choice (1-4): ";

    int choice;
    cin >> choice;

    Shop Fast;
    ALU alu(1, 1, 4, 64);
    ControlUnit cu(2);
    IntegratedGraphics graphic(128);
    string S1 = "Intel";
    CPU cpu(&alu, &cu, S1, 1, &graphic);

    PhysicalMemory physicalMemory(16, "SSD");
    PowerSupply powerSupply(120, "Gold", 100);
    GraphicsCard Card("NVDIA", 8, 120);
    MainMemory Memory(8, "SSD");
    NetworkCard Net("Ethernet", 10, 120);
    StorageDevice Device("HHD", 32, 120);

    string* ports = new string[1];
    ports[0] = "USB";
    int* rate = new int[1];
    rate[0] = 10;
    Port port(ports, 1, rate);
    WindowsMotherBoard Board(&Net, Device, Memory, cpu, &port, Card);

    string S3 = "Metal";
    string S2 = "Black";
    double p = 0;
    PCCase CASE(S3, S2, p, powerSupply, &port, physicalMemory, Board);
    ComputerAssembly assembly(&CASE, 1000);


    Computer computer(&assembly);

    
    Battery laptopBattery(5000);
    LaptopCase LapCASE(S3, S2, p, powerSupply, &port, physicalMemory, Board, laptopBattery);

    LaptopAssembly laptopAssembly(&LapCASE, 1200);
    Laptop laptop(&laptopAssembly);

    switch (choice) {
    case 1: {
        cout << "\nBuilding a PC..." << endl;
        Fast.BuildYourPC();
        break;
    }
    case 2: {
        cout << "\nBuilding a Laptop..." << endl;
        Fast.BuildYourLaptop();
        break;
    }
    case 3: {
        cout << "\nBuying a pre-built PC..." << endl;
        Fast.printComputerDetails(&computer);
        break;
    }
    case 4: {
        cout << "\nBuying a pre-built Laptop..." << endl;
        Fast.printComputerDetails(&laptop);
        break;
    }
    default:
        cout << "\nInvalid choice. Exiting..." << endl;
        return 0;
    }

    return 0;
}