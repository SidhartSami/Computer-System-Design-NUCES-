#pragma once
#include <iostream>
using namespace std;
#include"StorageDevice.h"
#include "NetworkCard.h"
#include "CPU.h"
#include "MainMemory.h"
#include "Port.h"
#include "GraphicsCard.h"
class Motherboard {
protected:
	NetworkCard* networkInterface;  // (COMPOSITION)
	MainMemory mainMemory;
	CPU cpu;
	StorageDevice storageDevice;
	Port* internalPorts;  //(COMPOSITION)

public:
	Motherboard() : networkInterface(nullptr), mainMemory(), cpu(), storageDevice(), internalPorts(nullptr) {}

	Motherboard(NetworkCard* netCard, const StorageDevice& storageDev,
		const MainMemory& memory, const CPU& processor, Port* ports = nullptr)
		: networkInterface(netCard), mainMemory(memory), cpu(processor), storageDevice(storageDev), internalPorts(ports) {}

	~Motherboard() {
		if (networkInterface != nullptr) {
			delete networkInterface;
			networkInterface = nullptr;
		}
		if (internalPorts != nullptr) {
			delete internalPorts;
			internalPorts = nullptr;
		}
	}
	MainMemory getMainMemory() const {
		return mainMemory;
	}
	CPU getCPU() const {
		return cpu;
	}
	Port* getPort() const {
		return internalPorts;
	}
	void setPort(Port* port) {
		internalPorts = port;
	}
	StorageDevice getStorageDevice() const {
		return storageDevice;
	}
	NetworkCard* getNetworkInterface() const {
		return networkInterface;
	}

	void setNetworkInterface(NetworkCard* netCard) {
		networkInterface = netCard;
	}

	void setMainMemory(const MainMemory& memory) {
		mainMemory = memory;
	}

	void setCPU(const CPU& processor) {
		cpu = processor;
	}

	void setStorageDevice(const StorageDevice& storageDev) {
		storageDevice = storageDev;
	}
};


class WindowsMotherBoard : public Motherboard {
	GraphicsCard dedicatedGraphicCard;
public:
	WindowsMotherBoard() : dedicatedGraphicCard() {}

	~WindowsMotherBoard() {
		if (networkInterface != nullptr) {
			delete networkInterface;
			networkInterface = nullptr;
		}
		if (internalPorts != nullptr) {
			delete internalPorts;
			internalPorts = nullptr;
		}
	}
	WindowsMotherBoard(NetworkCard* netCard, const StorageDevice& storageDev,
		const MainMemory& memory = MainMemory(), const CPU& processor = CPU(),
		Port* ports = nullptr, const GraphicsCard& graphics = GraphicsCard())
		: Motherboard(netCard, storageDev, memory, processor, ports), dedicatedGraphicCard(graphics) {}

	WindowsMotherBoard(const WindowsMotherBoard& other)
		: Motherboard(other),
		dedicatedGraphicCard(other.dedicatedGraphicCard) {}
	
	const GraphicsCard& getDedicatedGraphicCard() const {
		return dedicatedGraphicCard;
	}
	void setDedicatedGraphicCard(const GraphicsCard& graphicsCard) {
		dedicatedGraphicCard = graphicsCard;
	}
	NetworkCard* getNetworkInterface() const {
		return networkInterface;
	}

	void setNetworkInterface(NetworkCard* netCard) {
		networkInterface = netCard;
	}
	MainMemory getMainMemory() const {
		return mainMemory;
	}
	void setMainMemory(const MainMemory& memory) {
		mainMemory = memory;
	}

	CPU getCPU() const {
		return cpu;
	}

	void setCPU(const CPU& processor) {
		cpu = processor;
	}

	StorageDevice getStorageDevice() const {
		return storageDevice;
	}

	void setStorageDevice(const StorageDevice& storageDev) {
		storageDevice = storageDev;
	}

	Port* getInternalPorts() const {
		return internalPorts;
	}

	void setInternalPorts(Port* ports) {
		internalPorts = ports;
	}

};
