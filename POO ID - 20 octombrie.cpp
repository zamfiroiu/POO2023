#include<iostream>

using namespace std;

enum ModEliberare {
	cuReteta, faraReteta, Gratis, Compensat
};

class Farmacie {
public:
	string nume;
	const int anInfiintare;
	int nrAngajati;
	float* salarii;
	ModEliberare modEliberare;
	static float salariuMinim;

	Farmacie():anInfiintare(2023) {
		this->nume = "NoName";
		this->nrAngajati = 0;
		this->salarii = NULL;
		this->modEliberare = Gratis;
	}

	Farmacie(string nume, ModEliberare modEliberare) :anInfiintare(2023) {
		this->nume = nume;
		this->nrAngajati = 0;
		this->salarii = NULL;
		this->modEliberare = modEliberare;
	}

	Farmacie(string nume, int anInfiintareNou, int nrAngajati, float* salarii, ModEliberare modEliberare):anInfiintare(anInfiintareNou) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = salarii[i];
		}
		this->modEliberare = modEliberare;
	}

	void afisare() { //afisare(Farmacie * this)
		cout << "Nume: " << this->nume<<"; ";
		cout << "Nr angajati: " << nrAngajati << "; ";
		cout << "mod eliberare: " << modEliberare << "; ";
		cout << "salariu minim: " << salariuMinim << "; ";
		cout << "salariile angajatilor: ";
		for (int i = 0; i < nrAngajati; i++) {
			cout << salarii[i] << ", ";
		}
		cout << endl;
	}

	~Farmacie() {
		if (this->salarii != NULL) { 
			delete[]this->salarii;
		}
	}

	static void marireSalariuMinim(int procent) {
		salariuMinim += salariuMinim*(procent / 100.0f);
	}

};
float Farmacie::salariuMinim = 1950;

void main() {
	Farmacie f;
	f.nume = "HelpNet";
	f.nrAngajati = 2;

	Farmacie f2;

	f2.afisare();
	float* salarii = new float[2];
	salarii[0] = 1950;
	salarii[1] = 2300;

	Farmacie f3("Catena", 2000, 2, salarii, cuReteta);
	{
		//aici//3
		Farmacie f4("Tei", faraReteta);
		//aici//4
	}
	//aici3
	f3.afisare();
	cout << endl << Farmacie::salariuMinim<<endl;
	f3.marireSalariuMinim(10);
	cout << endl << Farmacie::salariuMinim << endl;
	Farmacie::marireSalariuMinim(10);
	cout << endl << Farmacie::salariuMinim << endl;

	Farmacie* farmacii = new Farmacie[5];
	delete[]salarii;
	delete[]farmacii;
}