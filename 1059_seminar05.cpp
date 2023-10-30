#include<iostream>

using namespace std;

class ZOO {
private:
	string nume;
	float pretBilet;
	static float TVA;
	const int anInfiintare;
	int nrAnimale;
	int* varste;

public:

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.length() > 3) {
			this->nume = nume;
		}
	}

	ZOO() :anInfiintare(2000) {
		this->nume = "Baneasa";
		this->pretBilet = 15;
		this->nrAnimale = 3;
		this->varste = new int[this->nrAnimale];
		for (int i = 0; i < this->nrAnimale; i++) {
			this->varste[i] = 10 + i;
		}
	}
	ZOO(string nume, float pretBilet, int nrAnimale, const int an, int* varste) : anInfiintare(an) {
		this->nume = nume;
		this->pretBilet = pretBilet;
		this->nrAnimale = nrAnimale;
		this->varste = new int[this->nrAnimale];
		for (int i = 0; i < this->nrAnimale; i++)
		{
			this->varste[i] = varste[i];
		}
	}

	ZOO(const ZOO &zoo): anInfiintare(zoo.anInfiintare) {
		this->nume = zoo.nume;
		this->pretBilet = zoo.pretBilet;
		this->nrAnimale = zoo.nrAnimale;
		this->varste = new int[this->nrAnimale];
		for (int i = 0; i < this->nrAnimale; i++)
		{
			this->varste[i] = zoo.varste[i];
		}
	}

	ZOO& operator=(const ZOO& zoo) {
		if (this != &zoo) {
			this->nume = zoo.nume;
			this->pretBilet = zoo.pretBilet;
			this->nrAnimale = zoo.nrAnimale;
			if (this->varste != NULL) {
				delete[]this->varste;
			}

			this->varste = new int[this->nrAnimale];
			for (int i = 0; i < this->nrAnimale; i++)
			{
				this->varste[i] = zoo.varste[i];
			}
		}
		return *this;
	}


	~ZOO() {
		if (this->varste != NULL) {
			delete[]this->varste;
			this->varste = NULL;
		}
	}
	void afisare()
	{
		cout << "Nume: " << this->nume << "\nPret bilet: " << this->pretBilet << "\nTVA: " << this->TVA << "\nAn infiintare: " << this->anInfiintare << "\nNumar animale: " << this->nrAnimale << "\nVarste: ";
		for (int i = 0; i < this->nrAnimale - 1; i++) {
			cout << this->varste[i] << ", ";
		}

		cout << this->varste[this->nrAnimale - 1] << endl;
	}

	static void setTVA(float TVAnou) {
		TVA = TVAnou;
	}

};
float ZOO::TVA = 0.19;


void functiePentruZoo(ZOO param) {

}

ZOO functieCUReturnZOO() {
	ZOO zoo;
	return zoo;
}

void main() {
	ZOO z1;
	ZOO z2;
	int* varste = new int[5];
	for (int i = 0; i < 5; i++)
		varste[i] = (i * 2) + 1;
	ZOO z3("Iasi", 20, 5, 1990, varste);
	z3.afisare();

	z1.setTVA(0.20);
	ZOO::setTVA(0.21);
	z1.afisare();

	ZOO z4 = z3;
	ZOO z5;
	z5 = z3;//z5.operator=(z3);

	z5.afisare();

	z1 = z5 = z3;

	cout << z1.getNume()<<endl;
	z1.setNume("Bucuresti");
	cout << z1.getNume();

	z5 = z5;
}