//#include<iostream>
//using namespace std;
//
//class Laptop {
//public:
//	static int nrLaptopuri;
//	static int nrTotalLaptopuri;
//	static int nrLaptopuriInMemorie;
//	static int TVA;
//	const int id;
//	int RAM;
//	string tipCPU;
//	float rezolutieEcran;
//	bool cameraWeb;
//	int nrTaste;
//	int* nrApasariTasta;
//
//public:
//	int getID() {
//		return this->id;
//	}
//	int getRAM() {
//		return this->RAM;
//	}
//	string getTipCPU() {
//		return tipCPU;
//	}
//	float getRezolutieEcran() {
//		return rezolutieEcran;
//	}
//	bool hasCameraWeb() {
//		return cameraWeb;
//	}
//
//	void setRAM(int RAM) {
//		if (RAM > 0) {
//			this->RAM = RAM;
//		}
//	}
//
//	void setTipCPU(string tipCPU) {
//		if (tipCPU.length() > 0) {
//			this->tipCPU = tipCPU;
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
//	~Laptop() {
//
//		this->nrLaptopuriInMemorie--;
//
//		if (this->nrApasariTasta != NULL) {
//			delete[] this->nrApasariTasta;
//		}
//	}
//
//	int getNrTaste() {
//		return nrTaste;
//	}
//
//	void setNrTaste(int nr) {
//		nrTaste = nr;
//	}
//
//	int* getNrApasariTasta() {
//		return nrApasariTasta;
//	}
//
//	void seNrApasariTasta(int* vector, int dim) {
//		if (dim > 0 && vector != NULL) {
//			if (this->nrApasariTasta != NULL) {
//				delete[]nrApasariTasta;
//			}
//			nrApasariTasta = new int[dim];
//			for (int i = 0; i < dim; i++) {
//				nrApasariTasta[i] = vector[i];
//			}
//			nrTaste = dim;
//		}
//	}
//
//	Laptop():id(nrLaptopuri) {
//		this->RAM = 16;
//		this->tipCPU = "AMD";
//		this->rezolutieEcran = 13.3;
//		this->cameraWeb = true;
//		this->nrLaptopuri++;
//		this->nrLaptopuriInMemorie++;
//		this->nrTotalLaptopuri++;
//		this->nrTaste = 0;
//		this->nrApasariTasta = NULL;
//	}
//
//	Laptop(int RAM, string tipCPU, float rezolutie, bool camera):id(nrLaptopuri) {
//		this->RAM = RAM;
//		this->tipCPU = tipCPU;
//		this->rezolutieEcran = rezolutie;
//		this->cameraWeb = camera;
//		this->nrLaptopuri++;
//		this->nrLaptopuriInMemorie++;
//		this->nrTotalLaptopuri++;
//		this->nrTaste = 0;
//		this->nrApasariTasta = NULL;
//	}
//
//	//Laptop(int RAM, float rezolutie, bool camera):id(0) {
//	//	this->RAM = RAM;
//	//	this->tipCPU = "Intel";
//	//	this->rezolutieEcran = rezolutie;
//	//	this->cameraWeb = camera;
//	//}
//
//	//Laptop(int newRAM, float rezolutie, bool camera):RAM(newRAM),tipCPU("Intel"),
//	//												rezolutieEcran(rezolutie),
//	//												cameraWeb(camera) 
//	//{
//	//}
//
//	//Laptop(int RAM=12, string tipCPU="AMD", float rezolutie=15, bool camera=true) {
//	//	this->RAM = RAM;
//	//	this->tipCPU = tipCPU;
//	//	this->rezolutieEcran = rezolutie;
//	//	this->cameraWeb = camera;
//	//}
//
//
//
//	inline void modificaRAM(int RAM) {
//		this->RAM = RAM;
//	}
//
//	static int cateLaptopuri() {
//		return nrLaptopuri;
//	}
//
//
//
//	void modificaTipCPU(string newTipCPU);
//
//
//
//};
//
//int Laptop::nrLaptopuri = 100;
//int Laptop::nrTotalLaptopuri = 0;
//int Laptop::nrLaptopuriInMemorie = 0;
//int Laptop::TVA = 0;
//
//void Laptop::modificaTipCPU(string newTipCPU) {
//	this->tipCPU = tipCPU;
//}
//
//
//
//void main() {
//	Laptop laptop1;
//
//	cout << laptop1.RAM<<endl;
//	Laptop laptop2(24, "INTEL", 17, true);
//	cout << laptop2.RAM;
//
//
//	Laptop laptop3;
//
//	{
//		Laptop l;
//		l.modificaRAM(40);
//	//1
//	}
//	//2	
//
//	////Laptop l1(20, 13, true);
//	////Laptop l2(10, 15, false);
//
//	//cout << Laptop::cateLaptopuri();
//
//	//Laptop l;
//	//l.seNrApasariTasta(new int[4]{ 10,2,5,7 }, 4);
//	//cout<<l.getNrApasariTasta()[3];
//
//
//}
