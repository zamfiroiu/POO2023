#include<iostream>
#include<fstream>

using namespace std;

class Park {
private:
	string nume;
	int suprafata;
public:

	virtual ~Park() {

	}
	virtual void metodaPura() = 0;

	virtual float platesteIntrare() = 0;

	void metodaNonVirtualaPura() {
		cout << "Non virtual pur";
	}

	Park() {
		this->nume = "Park";
		this->suprafata = 345;
	}
};

class ZOO:public Park {
private:
	string nume;
protected:
	float pretBilet;
	static float TVA;
private:
	const int anInfiintare;
	int nrAnimale;
	int* varste;

public:
	void metodaPura(){
	}

	virtual float platesteIntrare() {
		return pretBilet + pretBilet * TVA / 100;
	}

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
		if (this->nrAnimale > 0) {
			this->varste = new int[this->nrAnimale];
			for (int i = 0; i < this->nrAnimale; i++)
			{
				this->varste[i] = varste[i];
			}
		}
		else {
			this->varste = NULL;
		}
	}

	ZOO(const ZOO& zoo) : anInfiintare(zoo.anInfiintare) {
		this->nume = zoo.nume;
		this->pretBilet = zoo.pretBilet;
		this->nrAnimale = zoo.nrAnimale;
		if (this->nrAnimale > 0) {
			this->varste = new int[this->nrAnimale];
			for (int i = 0; i < this->nrAnimale; i++)
			{
				this->varste[i] = zoo.varste[i];
			}
		}
		else this->varste = NULL;
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
		if (z.nrAnimale > 0) {
			consola << z.varste[z.nrAnimale - 1] << endl;
		}
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
		this->nrGradiniZOO = 2;
		this->gradiniZOO = new ZOO[2];
	}

	ZOO& operator[](int index) {
		if (index >= 0 && index < this->nrGradiniZOO) {
			return this->gradiniZOO[index];
		}
	}
};


class SafariPark : public ZOO {
private:
	int nrMasiniDinParc;
	float taxaIntrareMasina;
	int* nrPersoaneMasina;
public:

	float platesteIntrare() {
		float s = 0;
		s += this->nrMasiniDinParc * this->taxaIntrareMasina;
		for (int i = 0; i < this->nrMasiniDinParc; i++) {
			s += this->nrPersoaneMasina[i] * this->pretBilet;
		}

		return s + s * ZOO::TVA / 100;
	}


	//nu utilizati niciodata initialziarea inline a unui vector
	//deoarece aveti memory leak
	SafariPark() : ZOO("Safari", 20, 0, 2023, NULL) {
		this->nrMasiniDinParc = 0;
		this->taxaIntrareMasina = 10;
		this->nrPersoaneMasina = NULL;
	}

	~SafariPark() {
		if (this->nrPersoaneMasina) {
			delete[]this->nrPersoaneMasina;
		}
	}

	SafariPark(const SafariPark& s) :ZOO(s) {
		this->nrMasiniDinParc = s.nrMasiniDinParc;
		this->taxaIntrareMasina = s.taxaIntrareMasina;
		this->nrPersoaneMasina = new int[s.nrMasiniDinParc];
		for (int i = 0; i < s.nrMasiniDinParc; i++) {
			this->nrPersoaneMasina[i] = s.nrPersoaneMasina[i];
		}
	}
	SafariPark(int nrMasiniDinParc, float taxaIntrareMasina, const int* nrPersoaneMasina) :ZOO() {
		this->nrMasiniDinParc = nrMasiniDinParc;
		this->taxaIntrareMasina = taxaIntrareMasina;
		this->nrPersoaneMasina = new int[nrMasiniDinParc];
		for (int i = 0; i < nrMasiniDinParc; i++) {
			this->nrPersoaneMasina[i] = nrPersoaneMasina[i];
		}
	}


	SafariPark(string nume, float pretBilet, int nrAnimale, const int an, int* varste, int nrMasiniDinParc, float taxaIntrareMasina, const int* nrPersoaneMasina) :ZOO(nume, pretBilet, nrAnimale, an, varste) {
		this->nrMasiniDinParc = nrMasiniDinParc;
		this->taxaIntrareMasina = taxaIntrareMasina;
		this->nrPersoaneMasina = new int[nrMasiniDinParc];
		for (int i = 0; i < nrMasiniDinParc; i++) {
			this->nrPersoaneMasina[i] = nrPersoaneMasina[i];
		}
	}
	SafariPark operator=(const SafariPark& s) {
		if (this != &s) {
			//apelarea operatorului = din clasa de baza
			ZOO::operator=(s);
			//(ZOO)*this = (ZOO)s;

			this->nrMasiniDinParc = s.nrMasiniDinParc;
			this->taxaIntrareMasina = s.taxaIntrareMasina;
			if (this->nrPersoaneMasina) {
				delete[]this->nrPersoaneMasina;
			}
			this->nrPersoaneMasina = new int[s.nrMasiniDinParc];
			for (int i = 0; i < s.nrMasiniDinParc; i++) {
				this->nrPersoaneMasina[i] = s.nrPersoaneMasina[i];
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const  SafariPark& s)
	{
		out << (ZOO)s;
		out << " Numarul masainilor este:" << s.nrMasiniDinParc;
		out << "\n taxa masina este:" << s.taxaIntrareMasina;
		for (int i = 0; i < s.nrMasiniDinParc; i++) {
			out << "Numar persoane masina " << i + 1 << ": " << s.nrPersoaneMasina[i];
			out << endl;
		}
		return out;
	}


};




bool operator<(ZOO z1, ZOO z2) {
	return z1.nrAnimale < z2.nrAnimale;
}


void main() {

	//ZOO z;

	//cout << z.platesteIntrare()<<endl;

	//SafariPark sp;
	//z = sp;

	////early binding
	//cout << z.platesteIntrare()<<endl;


	////late binding
	//ZOO* pointerZ;
	//pointerZ = new ZOO();
	//cout << pointerZ->platesteIntrare()<<endl;
	//delete pointerZ;

	//int* nrPers = new int[2] {3, 4};
	//pointerZ = new SafariPark(2,20,nrPers);
	//cout << pointerZ->platesteIntrare()<<endl;
	//delete pointerZ;


	//Park** pointeri;
	//pointeri = new Park * [5];
	//pointeri[0] = new ZOO();
	//pointeri[1] = new SafariPark(2, 10, nrPers);
	//pointeri[2] = new ZOO();
	//pointeri[3] = new ZOO();
	//nrPers[0] = 5;
	//pointeri[4] = new SafariPark(2, 25, nrPers);
	//cout << "Preturi platite:" << endl;
	//for (int i = 0; i < 5; i++) {
	//	cout << pointeri[i]->platesteIntrare()<<endl;
	//}
	//delete[]nrPers;




	//Park* p;
	//p = new ZOO();
	//p->metodaNonVirtualaPura();
	//cout << endl;
	//cout<<p->platesteIntrare()<<std::endl;

	//SafariPark sp;
	//ZOO zoo = sp;

	ZOO* pZOO = new SafariPark();
	delete pZOO;
}

