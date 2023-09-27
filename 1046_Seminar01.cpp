#include<iostream>

struct Masina {
	char categoriePermis;
	char* marca;
	int nrUsi;
	float capacitateMotor;
	bool esteElectrica;
};

void main() {
	Masina masina;
	masina.categoriePermis = 'B';
	//masina.marca = (char*)malloc(strlen("BMW") + 1);
	masina.marca = new char[strlen("BMW") + 1];
	strcpy_s(masina.marca, strlen("BMW") + 1, "BMW");
	masina.nrUsi = 5;
	masina.capacitateMotor = 1.9;
	masina.esteElectrica = false;

	std::cout << masina.marca << " se conduce cu categoria " << masina.categoriePermis << " are " << masina.nrUsi << " usi, o capacitate cilindrica de " << masina.capacitateMotor<<". ";
	//if (masina.esteElectrica) {
	//	std::cout << "Masina este electrica.";
	//}
	//else {
	//	std::cout << "Masina nu este electrica.";
	//}

	std::cout << "Masina" << (masina.esteElectrica ? " " : " nu ")<<"este electrica.";
}