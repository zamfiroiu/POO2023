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
//		tipCPU = new char[strlen("AMD")+1];
//		strcpy(tipCPU, "AMD");
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
//	friend ostream& operator<<(ostream& console, Laptop laptop) {
//		console << laptop.RAM << " " << laptop.tipCPU << " ";
//		console << laptop.rezolutieEcran << " " << laptop.cameraWeb << endl;
//		return console;
//	};
//
//	void scrieInFisierBinar(fstream& f) {
//		f.write((char*)&this->RAM, sizeof(int));
//		int lungime = strlen(this->tipCPU);
//		f.write((char*)&lungime, sizeof(int));
//		for (int i = 0; i < lungime; i++) {
//			f.write((char*)&this->tipCPU[i], sizeof(char));
//		}
//		f.write((char*)&this->rezolutieEcran, sizeof(float));
//		f.write((char*)&this->cameraWeb, sizeof(bool));
//	}
//
//	void citesteDinFisierBinar(fstream& f) {
//		f.read((char*)&this->RAM, sizeof(int));
//		int lungime;
//		f.read((char*)&lungime, sizeof(int));
//		if (this->tipCPU != NULL) {
//			delete[]this->tipCPU;
//		}
//		this->tipCPU = new char[lungime + 1];
//		for (int i = 0; i < lungime; i++) {
//			f.read((char*)&this->tipCPU[i], sizeof(char));
//		}
//		this->tipCPU[lungime] = '\0';
//		f.read((char*)&this->rezolutieEcran, sizeof(float));
//		f.read((char*)&this->cameraWeb, sizeof(bool));
//	}
//};
//
//
//void main() {
//	//Laptop laptop(20, "INTEL", 30, true);
//	//fstream fisier("laptopuri.txt", ios::out | ios::binary);
//	//fisier.write((char*)&laptop, sizeof(Laptop));
//
//	//fisier.close();
//	fstream fis("laptopuri.txt", ios::in | ios::binary);
//	Laptop laptopCitit;
//	//fis.read((char*)&laptopCitit, sizeof(Laptop));
//
//	//cout << laptopCitit;
//
//
//	//laptop.scrieInFisierBinar(fisier);
//	//fisier.close();
//	laptopCitit.citesteDinFisierBinar(fis);
//	cout << laptopCitit;
//	fis.close();
//
//
//
//
//
//}