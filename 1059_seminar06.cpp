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

	ZOO(const ZOO& zoo) : anInfiintare(zoo.anInfiintare) {
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

	friend ostream& operator<<(ostream& consola, const ZOO& z) {
		cout << "Nume: " << z.nume << "\nPret bilet: " << z.pretBilet << "\nTVA: " << z.TVA << "\nAn infiintare: " << z.anInfiintare << "\nNumar animale: " <<z.nrAnimale << "\nVarste: ";
		for (int i = 0; i < z.nrAnimale - 1; i++) {
			cout << z.varste[i] << ", ";
		}

		cout << z.varste[z.nrAnimale - 1] << endl;
		return consola;
	}

	friend istream& operator>>(istream& in, ZOO& z) {
		cout << "Nume:"; in >> z.nume;
		cout << "Pret bilet:"; in >> z.pretBilet;
		cout << "Nr animale:"; in >> z.nrAnimale;
		if (z.varste) {
			delete[]z.varste;
		}
		z.varste = new int[z.nrAnimale];
		cout << "Varste animale: ";
		for (int i = 0; i < z.nrAnimale; i++) {
			in >> z.varste[i];
		}
		return in;
	}

	ZOO operator++() {
		this->pretBilet += 10;
		return *this;
	}

	ZOO operator++(int) {
		ZOO temp = *this;
		this->pretBilet += 10;
		return temp;
	}
	
	friend bool operator<(ZOO z1, ZOO z2);
};
float ZOO::TVA = 0.19;

bool operator<(ZOO z1,ZOO z2) {
	return z1.nrAnimale < z2.nrAnimale;
}

void functiePentruZoo(ZOO param) {

}

ZOO functieCUReturnZOO() {
	ZOO zoo;
	return zoo;
}

void main() {
	/* ZOO z1;
	ZOO z2;
	int* varste = new int[5];
	for (int i = 0; i < 5; i++)
		varste[i] = (i * 2) + 1;
	ZOO z3("Iasi", 20, 5, 1990, varste);
	cout<<z3;

	z1.setTVA(0.20);
	ZOO::setTVA(0.21);
	cout<<z1;

	ZOO z4 = z3;
	ZOO z5;
	z5 = z3;//z5.operator=(z3);

	cout<<z5;

	z1 = z5 = z3;

	cout << z1.getNume() << endl;
	z1.setNume("Bucuresti");
	cout << z1.getNume();

	z5 = z5;

	cout << z3;
	int a = 8;
	cout << a;

	cout << z3<<endl;
	cin >> z3;  */
	ZOO z3;
	cin >> z3;
	cout << z3;
	ZOO z4;
	ZOO z5;

	z4=z3++;
	cout << z4;
	cout << z3;
	z5=++z3;
	cout << z5;

	int a1 = 89;
	int a2 = 765;
	if (z3 < z4) {
		cout << "z3 este mai mica";
	}
	else {
		cout << "z3 este mai mare sau cele doua sunt egale";
	}
}