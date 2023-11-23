#include<iostream>
#include<fstream>

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

	int* getVarste() {
		return this->varste;
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
		consola << "Nume: " << z.nume << "\nPret bilet: " << z.pretBilet << "\nTVA: " << z.TVA << "\nAn infiintare: " << z.anInfiintare << "\nNumar animale: " << z.nrAnimale << "\nVarste: ";
		for (int i = 0; i < z.nrAnimale - 1; i++) {
			consola << z.varste[i] << ", ";
		}

		consola << z.varste[z.nrAnimale - 1] << endl;
		return consola;
	}

	friend ofstream& operator<<(ofstream& consola, const ZOO& z) {
		consola << z.nume << "\n" << z.pretBilet << "\n" << z.TVA << "\n" << z.anInfiintare << "\n" << z.nrAnimale << "\n";
		for (int i = 0; i < z.nrAnimale - 1; i++) {
			consola << z.varste[i] << " ";
		}
		consola << z.varste[z.nrAnimale - 1] << endl;
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

	friend ifstream& operator>>(ifstream& in, ZOO& z) {
		in >> z.nume;
		in >> z.pretBilet;
		float val = 0;
		in >> val;//citire tva
		in >> val;//citire an

		in >> z.nrAnimale;
		if (z.varste) {
			delete[]z.varste;
		}
		z.varste = new int[z.nrAnimale];
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

	int& operator[](int idx) {
		if (idx >= 0 && idx < nrAnimale)
			return this->varste[idx];
		throw 404;
	}

	int operator()() {
		int s = 0;
		for (int i = 0; i < this->nrAnimale; i++) {
			s = s + this->varste[i];
		}
		return s;
	}

	int operator()(int idxStart, int idxStop) {
		int s = 0;
		for (int i = idxStart; i < idxStop; i++) {
			s = s + this->varste[i];
		}
		return s;
	}

	int operator()(int idxStop) {
		ZOO aux = (*this);
		return aux(0, idxStop);
	}

	explicit operator int() {
		return this->nrAnimale;
	}
	operator float() {
		return this->pretBilet;
	}

	operator double() {
		double suma = (*this)();
		return suma / this->nrAnimale;
	}


	friend bool operator<(ZOO z1, ZOO z2);
};
float ZOO::TVA = 0.19;


class Oras {
private:
	string nume;
	int nrGradiniZOO;
	ZOO* gradiniZOO;
public:
	Oras() {
		this->nume = "Bucuresti";
		this-> nrGradiniZOO = 2;
		this->gradiniZOO = new ZOO[2];
	}

	ZOO& operator[](int index) {
		if (index >= 0 && index < this->nrGradiniZOO) {
			return this->gradiniZOO[index];
		}
	}
};


bool operator<(ZOO z1, ZOO z2) {
	return z1.nrAnimale < z2.nrAnimale;
}

void functiePentruZoo(ZOO param) {

}

ZOO functieCUReturnZOO() {
	ZOO zoo;
	return zoo;
}

void eroareChar()
{
	throw '@';
}
void eroareCharP()
{
	throw "Eroare 404";
}

void main() {
	//Oras oras1;
	//ZOO z1;
	//cin >> z1;
	//cout << oras1[0];
	//oras1[0] = z1;
	//cout << oras1[0];
	//cout <<"Varsta animalului:" << oras1[0][1]<<endl;
	//cout << oras1[0].getNume();


	//ZOO z1;
	//cin >> z1;

	//ofstream file("fisier.txt", ios::out);
	//file << z1;

	//ifstream citire("fisier.txt", ios::in);
	//ZOO z2;
	//citire >> z2;
	//cout << z2;
	//ZOO z3;
	//citire >> z3;
	//cout << endl << z3;


	//fisiere binare
	char* text = new char[6];
	strcpy_s(text, 6, "text:");
	int variabila = 67;
	float valReala = 44.98;
	fstream fisierBinar("fisierBinar.g59", ios::binary | ios::out);

	//in fisiere binare nu scriem cu operatorul<<
	// //EXCEPTIE: doar daca operatorul<< este supraincarcat in aceasta privinta
	//fisierBinar << "text:" << variabila;
	//ZOO z4;
	//fisierBinar << z4;
	{
		ZOO z5;
		cin >> z5;

		//metoda corecta
		int lungime = strlen(text);
		fisierBinar.write((char*)&lungime, sizeof(int));
		fisierBinar.write((char*)text, (sizeof(char) * (strlen(text) + 1)));
		fisierBinar.write((char*)&variabila, sizeof(int));
		fisierBinar.write((char*)&valReala, sizeof(float));


		//metoda gresita
		fisierBinar.write((char*)&z5, sizeof(ZOO));
	}
	//metoda corecta

	//trebuie creata o metoda care va scrie in fisierul binar atribut cu atribut...

	fisierBinar.close();


	//alta aplicatie
	char textCitit[50];
	int intregCitit;
	float realCitit;

	fstream fisierBCitire("fisierBinar.g59", ios::binary | ios::in);
	fisierBCitire.read((char*)&intregCitit, sizeof(int));

	fisierBCitire.read((char*)textCitit, sizeof(char)*(intregCitit+1));
	fisierBCitire.read((char*)&intregCitit, sizeof(int));
	fisierBCitire.read((char*)&realCitit, sizeof(float));
	
	ZOO z6;
	//gresit
	fisierBCitire.read((char*)&z6, sizeof(ZOO));
	
	
	//corect
	//trebuie creata o metoda care citeste din fisierul binar atribut atribut.

	cout << textCitit << " " << intregCitit << " " << realCitit << endl;

cout << z6;

}