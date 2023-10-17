//#include<iostream>
//
//using namespace std;
//
//class Apartament {
//public:
//	int nrCamere;
//	float suprafata;
//	string zona;
//	char* strada;
//	bool areBalcon;
//
//	Apartament() {
//		this->nrCamere = 3;
//		this->suprafata = 70;
//		this->areBalcon = true;
//		this->zona = "Piata Romana";
//		this->strada = new char[strlen("Dorobanti") + 1];
//		strcpy_s(this->strada, strlen("Dorobanti") + 1, "Dorobanti");
//	}
//	void afisare() {
//		cout << "Apartamentul de pe strada: " << this->zona << " din zona " << zona << " are " << this->nrCamere << " camere, o suprafata de " << suprafata << " metri patrati si " << (this->areBalcon ? "are balcon" : "nu are balcon")<<".\n";
//	}
//
//	void modificaNumarCamere(int nrCamere) {
//		this->nrCamere = nrCamere;
//	}
//
//	~Apartament() {
//		if (this->strada != NULL) {
//			delete[]this->strada;
//		}
//	}
//};
//
//void main() {
//	Apartament apartament;
//	apartament.afisare();
//	{
//		Apartament ap2;
//		ap2.afisare();
//	}
//	apartament.modificaNumarCamere(5);
//	apartament.afisare();
//
//	Apartament* apartamente = new Apartament[40];
//	delete[]apartamente;
//
//
//
//}