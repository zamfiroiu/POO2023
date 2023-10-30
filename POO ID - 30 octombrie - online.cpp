#include<iostream>
#include<vector>
using namespace std;

enum ModEliberare {
	cuReteta, faraReteta, Gratis, Compensat
};

class Farmacie {
private:
	string nume;
	const int anInfiintare;
	int nrAngajati;
	float* salarii;
	ModEliberare modEliberare;
	static float salariuMinim;
public:

	class Farmacist {
	public:
		string nume;
		Farmacist() {
			this->nume = "NoName";
		}
	};

	Farmacie() :anInfiintare(2023) {
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

	Farmacie(const Farmacie& f) :anInfiintare(f.anInfiintare) {
		this->nume = f.nume;
		this->nrAngajati = f.nrAngajati;
		this->salarii = new float[f.nrAngajati];
		for (int i = 0; i < f.nrAngajati; i++) {
			this->salarii[i] = f.salarii[i];
		}
		this->modEliberare = f.modEliberare;
	}

	Farmacie operator=(const Farmacie& f)
	{
		if (this != &f)
		{
			this->nume = f.nume;
			this->nrAngajati = f.nrAngajati;
			if (this->salarii != NULL)
			{
				delete[]this->salarii;
			}
			this->salarii = new float[f.nrAngajati];
			for (int i = 0; i < f.nrAngajati; i++)
			{
				this->salarii[i] = f.salarii[i];
			}
			this->modEliberare = f.modEliberare;
		}
		return *this;
	}

	Farmacie(string nume, int anInfiintareNou, int nrAngajati, float* salarii, ModEliberare modEliberare) :anInfiintare(anInfiintareNou) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = salarii[i];
		}
		this->modEliberare = modEliberare;
	}

	string getNume() {
		return this->nume;
	}
	int getAnInfiintare() {
		return this->anInfiintare;
	}

	void setNume(string nume) {
		if (nume.length() > 2) {
			this->nume = nume;
		}
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}

	void setNrAngajati(int nr, float* salarii) {
		if (nr > 0) {
			this->nrAngajati = nr;
			//nu asa: this->salarii = salarii;//shallow copy
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[nr];
			for (int i = 0; i < nr; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii() {
		return this->salarii;
	}

	float getSalariu(int pozitie) {
		return this->salarii[pozitie];
	}


	void afisare() { //afisare(Farmacie * this)
		cout << "Nume: " << this->nume << "; ";
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
		salariuMinim += salariuMinim * (procent / 100.0f);
	}

	static float getSalariuMinim() {
		return salariuMinim;
	}

	static void setSalariuMinim(float salariuMinim) {
		if (salariuMinim > 10) {
			Farmacie::salariuMinim = salariuMinim;
		}
	}
	friend class DistribuitorMedicamente;
	friend void functiePrietena(Farmacie& f) {
		f.nume = "Dona";
	}

	Farmacie operator+(float adaosSalarial) const {
		Farmacie aux = *this;
		for (int i = 0; i < aux.nrAngajati; i++) {
			aux.salarii[i] += adaosSalarial;
		}
		return aux;
	}

	friend Farmacie operator+(int adaosSalarial, Farmacie f) {
		Farmacie aux = f;
		for (int i = 0; i < aux.nrAngajati; i++) {
			aux.salarii[i] += adaosSalarial;
		}
		return aux;
	}

	Farmacie operator+(const Farmacie& f) const {
		Farmacie aux = *this;
		aux.nrAngajati = this->nrAngajati + f.nrAngajati;
		if (aux.salarii != NULL) {
			delete[]aux.salarii;
		}
		aux.salarii = new float[aux.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux.salarii[i] = this->salarii[i];
		}
		for (int i = this->nrAngajati; i < aux.nrAngajati; i++) {
			aux.salarii[i] = f.salarii[i - this->nrAngajati];
		}

		//for (int i = 0; i < f.nrAngajati; i++) {
		//	aux.salarii[i+this->nrAngajati] = f.salarii[i];
		//}
		return aux;
	}
	Farmacie operator+=(const Farmacie& f) {
		this->nrAngajati += f.nrAngajati;
		float* temp = new float[this->nrAngajati];
		for (int i = 0; i < this->nrAngajati - f.nrAngajati; i++) {
			temp[i] = this->salarii[i];
		}
		for (int i = this->nrAngajati - f.nrAngajati; i < this->nrAngajati; i++) {
			temp[i] = f.salarii[i - (this->nrAngajati - f.nrAngajati)];
		}
		if (this->salarii != NULL) {
			delete[]this->salarii;
		}
		this->salarii = temp;
		return *this;
	}

	bool operator<(const Farmacie& f)const {
		return this->nrAngajati<f.nrAngajati;
	}
	bool operator>(const Farmacie& f)const {
		return this->nrAngajati > f.nrAngajati;
	}
	bool operator==(const Farmacie& f)const {
		return this->nrAngajati == f.nrAngajati;
	}	
	bool operator!=(const Farmacie& f)const {
		return this->nrAngajati != f.nrAngajati;
	}

	friend ostream& operator<<(ostream& monitor, const Farmacie f) {
		monitor << "Nume: " << f.nume << "; ";
		monitor << "Nr angajati: " << f.nrAngajati << "; ";
		monitor << "mod eliberare: " << f.modEliberare << "; ";
		monitor << "salariu minim: " << f.salariuMinim << "; ";
		monitor << "salariile angajatilor: ";
		for (int i = 0; i < f.nrAngajati; i++) {
			monitor << f.salarii[i] << ", ";
		}
		monitor << endl;
		return monitor;
	}

};
float Farmacie::salariuMinim = 1950;

void functie(Farmacie f) {
	//f.getNume = "DrMax";
}


Farmacie functie2() {
	Farmacie f;
	return f;
}

class DistribuitorMedicamente {
private:
	string nume;
	Farmacie farmacie;
public:
	string getNume() {
		return nume;
	}
	void setNume(string nume) {
		if (nume.length() > 0) {
			this->nume = nume;
		}
	}
	Farmacie getFarmacie() {
		return this->farmacie;
	}
	void setFarmacie(Farmacie f) {
		this->farmacie = f;
	}
	void modificaModEliberare() {
		this->farmacie.modEliberare = cuReteta;
	}
	
	
};


void main() {

	float* salarii = new float[2];
	salarii[0] = 1950;
	salarii[1] = 2300;

	Farmacie f3("Catena", 2000, 2, salarii, cuReteta);

	Farmacie f2 = f3;
	Farmacie f1;
	//f2.afisare();
	cout << f2<<endl;
	f1 = f3 + f2;
	//f1.afisare();
	cout << f1<<endl;

	f1 += f3;//f1=f1+f3
	//f1.afisare();
	cout << f1<<endl;
	

}