//#include<iostream>
//#include<fstream>
//
//using namespace std;
//
//class Laptop {
//	int RAM;
//	char* tipCPU;
//	float rezolutieEcran;
//	bool cameraWeb;
//public:
//	int getRAM() {
//		return RAM;
//	}
//	char* getTipCPU() {
//		return tipCPU;
//	}
//	float getRezolutieEcran() {
//		return rezolutieEcran;
//	}
//	bool hasCameraWeb() {
//		return cameraWeb;
//	}
//	void setRAM(int RAM) {
//		if (RAM > 0) {
//			this->RAM = RAM;
//		}
//	}
//	
//	void setTipCPU(const char* tipCPU) {
//		if (strlen(tipCPU) > 0) {
//			if (this->tipCPU != NULL) {
//				delete[]this->tipCPU;
//			}
//			this->tipCPU = new char[strlen(tipCPU)+1];
//			strcpy(this->tipCPU, tipCPU);
//		}
//	}
//	
//	void setRezolutieEcran(float rezolutieEcran) {
//		if (rezolutieEcran > 10) {
//			this->rezolutieEcran = rezolutieEcran;
//		}
//	}
//	
//	void setCameraWeb(bool cameraWeb) {
//		this->cameraWeb = cameraWeb;
//	}
//
//	Laptop() {
//		RAM = 16;
//		tipCPU = new char[4];
//		strcpy(this->tipCPU,"AMD");
//		rezolutieEcran = 13.3;
//		this->cameraWeb = true;
//	}
//	
//	Laptop(int RAM, const char* tipCPU, float rezolutie, bool camera) {
//		this->RAM = RAM;
//		this->tipCPU = new char[strlen(tipCPU) + 1];
//		strcpy(this->tipCPU, tipCPU);
//		this->rezolutieEcran = rezolutie;
//		this->cameraWeb = camera;
//	}
//
//	Laptop(const Laptop& l) {
//		this->RAM = l.RAM;
//		this->tipCPU = new char[strlen(l.tipCPU) + 1];
//		strcpy(this->tipCPU, l.tipCPU);
//		this->rezolutieEcran = l.rezolutieEcran;
//		this->cameraWeb = l.cameraWeb;
//	}
//
//	Laptop& operator=(const Laptop& l) {
//		this->RAM = l.RAM;
//		if (this->tipCPU != NULL) {
//			delete[]this->tipCPU;
//		}
//		this->tipCPU = new char[strlen(l.tipCPU) + 1];
//		strcpy(this->tipCPU, l.tipCPU);
//		this->rezolutieEcran = l.rezolutieEcran;
//		this->cameraWeb = l.cameraWeb;
//		return *this;
//	}
//
//	virtual ~Laptop() {
//		if (this->tipCPU != NULL) {
//			delete[]this->tipCPU;
//		}
//	}
//
//	friend ostream& operator<<(ostream& console, Laptop laptop) {
//		console << laptop.RAM << " - " << laptop.tipCPU << " - ";
//		console << laptop.rezolutieEcran << " - " << laptop.cameraWeb << endl;
//		return console;
//	};
//
//	friend ofstream& operator<<(ofstream& file, const Laptop &laptop) {
//		file  << laptop.RAM << ", " << laptop.tipCPU << ", ";
//		file << laptop.rezolutieEcran <<", "<< laptop.cameraWeb<< endl;			
//		return file;
//	};
//
//
//	friend ifstream& operator>>(ifstream& file, Laptop& laptop) {
//		//cout << "RAM:";
//		file >> laptop.RAM;
//		//cout << "Tip CPU:";
//
//		char buffer[20];
//		file >> buffer;
//
//		if (laptop.tipCPU) {
//			delete[]laptop.tipCPU;
//		}
//
//		laptop.tipCPU = new char[strlen(buffer) + 1];
//		strcpy(laptop.tipCPU, buffer);
//		//cout << "Rezolutie:";
//		file >> laptop.rezolutieEcran;
//		//cout << "Camera web:";
//		file >> laptop.cameraWeb;
//		return file;
//	};
//
//};
//
//
//
//void main() {
//
//	Laptop laptop(8, "AMD", 13, true);
//	Laptop l2(16, "Intel", 15, false);
//	cout << laptop;
//
//	ofstream f("fisier.csv", ios::out);
//	f << "RAM,Procesor,Rezolutie, Are camera"<<endl;
//	f << laptop;
//	f << l2;
//	f.close();
//
//	Laptop l1;
//
//	ifstream g("fisier.txt", ios::in);
//	g >> l1;
//	cout << l1;
//
//
//
//	//
//	//ofstream file ("fisier16.txt", ios::app);
//	//ofstream file2 ("fisier.txt", ios::app);
//
//	//file << laptop;
//
//
//	//file.close();
//	//file2.close();
//
//	/*Laptop laptopCitit;
//	ifstream fisIn("fisier.txt", ios::in);
//	fisIn >> laptopCitit;
//	cout << laptopCitit;*/
//
//
//}