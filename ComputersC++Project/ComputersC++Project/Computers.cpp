#include <iostream>
using namespace std;

//QEYD: Kechdiymiz her shey istifade olunsun
//
//class : Computer
//	fields :
//id(static)
//object_Id
//model(char*)
//vendor(char*)
//videocard(char*)
//monitor(char*)
//cpu_hz
//core
//ram
//disk_size
//isSSD(bool)
//cin, cout overload
//constructors
//destructor
//
//
//class : ComputerStore
//	store_name(char*)
//	store_address(char*)
//	Computer** computers; (array)
//	addComputer();
//deleteComputer(int id);
//cin, cout overload
//constructors
//destructor


class Computer {
	static int Id;
	int ObjectId;
	char* model = nullptr;
	char* vendor = nullptr;
	char* videocard = nullptr;
	char* monitor = nullptr;
	int cpuHz = 0;
	int core = 0;
	int ram = 0;
	int discSize = 0;
	bool isSSD;

public:
#pragma region Constructors


	Computer() : model(nullptr), vendor(nullptr), videocard(nullptr), monitor(nullptr), cpuHz(0), core(0), ram(0), discSize(0), isSSD(0) { ObjectId = Id++; }

	Computer(const char* model) :Computer() {
		SetModel(model);
	}

	Computer(const char* model, const char* vendor) :Computer(model) {
		SetVendor(vendor);
	}

	Computer(const char* model, const char* vendor, const char* videocard) :Computer(model, vendor) {
		SetVideoCard(videocard);
	}

	Computer(const char* model, const char* vendor, const char* videocard, const char* monitor) :Computer(model, vendor, videocard) {
		SetMonitor(monitor);
	}

	Computer(const char* model, const char* vendor, const char* videocard, const char* monitor, int cpuHz) :Computer(model, vendor, videocard, monitor) {
		SetCpuHz(cpuHz);
	}

	Computer(const char* model, const char* vendor, const char* videocard, const char* monitor, int cpuHz, int core) :Computer(model, vendor, videocard, monitor, cpuHz) {
		SetCore(core);
	}

	Computer(const char* model, const char* vendor, const char* videocard, const char* monitor, int cpuHz, int core, int ram) :Computer(model, vendor, videocard, monitor, cpuHz, core) {
		SetRam(ram);
	}

	Computer(const char* model, const char* vendor, const char* videocard, const char* monitor, int cpuHz, int core, int ram, int discSize) :Computer(model, vendor, videocard, monitor, cpuHz, core, ram) {
		SetDiscSize(discSize);
	}

	Computer(const char* model, const char* vendor, const char* videocard, const char* monitor, int cpuHz, int core, int ram, int discSize, bool isSSD) :Computer(model, vendor, videocard, monitor, cpuHz, core, ram, discSize) {
		SetIsSSD(isSSD);
	}
#pragma endregion


	Computer(const Computer& other) {
		SetObjectId(other.ObjectId);
		SetModel(other.model);
		SetVendor(other.vendor);
		SetVideoCard(other.videocard);
		SetMonitor(other.monitor);
		SetCpuHz(other.cpuHz);
		SetCore(other.core);
		SetRam(other.ram);
		SetDiscSize(other.discSize);
		SetIsSSD(other.isSSD);
	}

#pragma region Setters
	void SetObjectId(int ObjectId) {
		this->ObjectId = ObjectId > 0 ? ObjectId : 1;
	}

	void SetModel(const char* model) {
		delete[] this->model;
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}

	void SetVendor(const char* vendor) {
		delete[] this->vendor;
		this->vendor = new char[strlen(vendor) + 1];
		strcpy_s(this->vendor, strlen(vendor) + 1, vendor);
	}

	void SetVideoCard(const char* videocard) {
		delete[] this->videocard;
		this->videocard = new char[strlen(videocard) + 1];
		strcpy_s(this->videocard, strlen(videocard) + 1, videocard);
	}

	void SetMonitor(const char* monitor) {
		delete[] this->monitor;
		this->monitor = new char[strlen(monitor) + 1];
		strcpy_s(this->monitor, strlen(monitor) + 1, monitor);
	}

	void SetCpuHz(int cpuHz) {
		this->cpuHz = cpuHz > 0 ? cpuHz : 6;
	}

	void SetCore(int core) {
		this->core = core > 0 ? core : 7;
	}

	void SetRam(int ram) {
		this->ram = ram > 0 ? ram : 8;
	}

	void SetDiscSize(int discSize) {
		this->discSize = discSize > 0 ? discSize : 120;
	}

	void SetIsSSD(bool isSSD) {
		this->isSSD = isSSD == true ? true : false;
	}

#pragma endregion


#pragma region Getters
	int GetObjectId() { return ObjectId; }
	const char* GetModel() { return model; }
	const char* GetVendor() { return vendor; }
	const char* GetVideoCard() { return videocard; }
	const char* GetMonitor() { return monitor; }
	int GetCpuHz() { return cpuHz; }
	int GetCore() { return core; }
	int GetRam() { return ram; }
	int GetDiscSize() { return discSize; }
	bool GetIsSSD() { return isSSD; }
#pragma endregion


	Computer& operator=(const Computer& other) {
		SetObjectId(other.ObjectId);
		SetModel(other.model);
		SetVendor(other.vendor);
		SetVideoCard(other.videocard);
		SetMonitor(other.monitor);
		SetCpuHz(other.cpuHz);
		SetCore(other.core);
		SetDiscSize(other.discSize);
		SetRam(other.ram);
		SetIsSSD(other.isSSD);
		return *this;
	}


	friend ostream& operator<<(ostream& out, const Computer& comp) {
		out << "======= Computer =======\n"
			<< "Id: " << comp.ObjectId
			<< "\nModel: " << comp.model
			<< "\nVendor: " << comp.vendor
			<< "\nVideo Card: " << comp.videocard
			<< "\nMonitor: " << comp.monitor
			<< "\nCpu Hz: " << comp.cpuHz
			<< "\nCore: " << comp.core
			<< "\nRam: " << comp.ram
			<< "\nDisc Size: " << comp.discSize
			<< "\nSSD: " << comp.isSSD << endl;
		return out;
	}


	friend istream& operator>>(istream& in, Computer& comp) {
		cout << "Model: ";
		char* bf = new char[20];
		in.getline(bf, 20);
		comp.SetModel(bf);
		delete[] bf;


		bf = new char[20];
		cout << "Vendor: ";
		in.getline(bf, 20);
		comp.SetVendor(bf);
		delete[] bf;

		bf = new char[20];
		cout << "Video Card: ";
		in.getline(bf, 20);
		comp.SetVideoCard(bf);
		delete[] bf;

		bf = new char[20];
		cout << "Monitor: ";
		in.getline(bf, 20);
		comp.SetMonitor(bf);
		delete[] bf;

        int id;
		cout << "Id: ";
		cin >> id;
		comp.SetObjectId(id);

		int chz;
		cout << "Cpu Hz: ";
		cin >> chz;
		comp.SetCpuHz(chz);

		int core;
		cout << "Core: ";
		cin >> core;
		comp.SetCore(core);

		int ram;
		cout << "Ram: ";
		cin >> ram;
		comp.SetRam(ram);

		int ds;
		cout << "Disc size: ";
		cin >> ds;
		comp.SetDiscSize(ds);

		bool ssd;
		cout << "SSD: ";
		cin >> ssd;
		comp.SetIsSSD(ssd);

		return in;
	}



	~Computer() {
		delete[] model;
		delete[] vendor;
		delete[] videocard;
		delete[] monitor;
	}

};

int Computer::Id = 1;



class ComputerStore {
	char* storeName = nullptr;
	char* storeAddress = nullptr;
public:
	ComputerStore() :storeName(nullptr), storeAddress(nullptr) {}

	ComputerStore(const char* storeName) :ComputerStore() {
		SetStoreName(storeName);
	}

	ComputerStore(const char* storeName, const char* storeAddress) :ComputerStore(storeName) {
		SetStoreAddress(storeAddress);
	}
	int size = 2;
	Computer* computers = new Computer[size];



	void AddComputer() {
		Computer* temp = new Computer[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = computers[i];
		}
		Computer newComp;
		cin >> newComp;
		temp[size] = newComp;

		delete[] computers;
		size++;
		computers = temp;
		temp = nullptr;
	}

	void DeleteComputer(int id) {
		Computer* temp = new Computer[size - 1];
		for (int i = 0; i < (id - 1); i++) {
			temp[i] = computers[i];
		}
		for (int i = id; i < size; i++) {
			temp[i - 1] = computers[i];
		}

		delete[] computers;
		size--;
		computers = temp;
		temp = nullptr;
	}

	friend istream& operator>>(istream& in, ComputerStore& compstore) {
		cout << "Store Name: ";
		char* bf = new char[20];
		in.getline(bf, 20);
		compstore.SetStoreName(bf);
		delete[] bf;

		bf = new char[20];
		cout << "Store Address: ";
		in.getline(bf, 20);
		compstore.SetStoreAddress(bf);
		delete[] bf;
	}

	friend ostream& operator<<(ostream& out, const ComputerStore& compstore) {
		out << "======= Computer Store =======\n"
			<< "Store Name: " << compstore.storeName
			<< "\nStore Address: " << compstore.storeAddress << endl;
		return out;
	}

#pragma region Setters
	void SetStoreName(const char* storeName) {
		delete[] this->storeName;
		this->storeName = new char[strlen(storeName) + 1];
		strcpy_s(this->storeName, strlen(storeName) + 1, storeName);
	}

	void SetStoreAddress(const char* storeAddress) {
		delete[] this->storeAddress;
		this->storeAddress = new char[strlen(storeAddress) + 1];
		strcpy_s(this->storeAddress, strlen(storeAddress) + 1, storeAddress);
	}
#pragma endregion

#pragma region Getters
	const char* GetStoreName() { return storeName; }
	const char* GetStoreAddress() { return storeAddress; }
#pragma endregion


	ComputerStore(const ComputerStore& other) {
		SetStoreName(other.storeName);
		SetStoreAddress(other.storeAddress);
	}

	~ComputerStore() {
		delete[] storeName;
		delete[] storeAddress;
	}

};




void main() {
	Computer comp1 = Computer("HP Pavilion Laptop", "HP", "15FF", "Rampage SLICE", 6, 7, 16, 120, 1);
	Computer comp2 = Computer("MacBook Air", "Apple", "M1", "Mac Monitor", 7, 8, 8, 120, 1);

	int size = 2;
	ComputerStore compstore = ComputerStore("28 Komputer evi", "28 may metrosunun yaxinligi");
	compstore.computers = new Computer[size]{ comp1,comp2 };
	compstore.AddComputer();
	compstore.DeleteComputer(2);
}