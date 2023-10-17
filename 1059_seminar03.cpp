#include<iostream>

using namespace std;

class Masina {
public:	
	string culoare;
	char* marca;
	int an;
	float pret;

	void afisare() {
		cout << (*this).an<<" ";//dereferentiere+accesare
		cout << this->culoare << " "<<this->marca<<" "<< this->pret << endl;
	}

	~Masina() {
		if (this->marca != NULL) {
			delete[]this->marca;
		}
	}

	Masina() {
		this->culoare = "Alba";
		this->marca = new char[strlen("Audi") + 1];
		strcpy_s(this->marca, strlen("Audi") + 1, "Audi");
		this->an = 2023;
		this->pret = 20000;
	}

	Masina(string culoare, const char* marca, int an, float pret) {
		this->culoare = culoare;
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->an = an;
		this->pret = pret;
	}


};

Masina initializareMasina() {
	Masina masina;
	masina.culoare = "Rosie";
	masina.marca = new char[strlen("Audi") + 1];
	strcpy_s(masina.marca, strlen("Audi") + 1, "Audi");
	masina.an = 2023;
	masina.pret = 20000;

	return masina;
}

void main() {
	Masina masina;
	masina.afisare();
	//masina = initializareMasina();

	//masina.afisare();
	{
		Masina masina2("Albastra", "BMW", 2022, 25000);
		masina2.afisare();
	}

	Masina masina3("Galbena", "Dacia", 2012, 3000);
	masina3.afisare();
	Masina* pMasina = new Masina();
	delete pMasina;
}