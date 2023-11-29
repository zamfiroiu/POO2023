#include<iostream>
#include<fstream>
using namespace std;
 
class Padure {
private:

	const int id;
	string nume;
	int nrCopaci;
	int* varsteCopaci;
	static int gradDefrisare;
public:
	static int getGradDefrisare() {
		return Padure::gradDefrisare;
	}

	static void setGradDefrisare(int grad) {
		if (grad > 0) {
			Padure::gradDefrisare = grad;
		}
	}

	Padure():id(100) {
		this->nume = "Padure";
		this->nrCopaci = 0;
		this->varsteCopaci= NULL;
	}

	Padure(int idNou, string nume) :id(idNou) {
		this->nume = nume;
		this->nrCopaci = 0;
		this->varsteCopaci = NULL;
	}

	Padure(int id, string nume, int nrCopaci, int* varsteCopaci):id(id),nume(nume),nrCopaci(nrCopaci) {
		if (nrCopaci != 0) {
			this->varsteCopaci = new int[nrCopaci];
			for (int i = 0; i < nrCopaci; i++)
			{
				this->varsteCopaci[i] = varsteCopaci[i];
			}
		}
		else this->varsteCopaci = NULL;
	}
	Padure(const Padure &p) :id(p.id){
		nume = p.nume;
		nrCopaci = p.nrCopaci;
		if (nrCopaci != 0) {
			this->varsteCopaci = new int[nrCopaci];
			for (int i = 0; i < nrCopaci; i++)
			{
				this->varsteCopaci[i] = p.varsteCopaci[i];
			}
		}
		else this->varsteCopaci = NULL;
		
	}
	
	explicit operator float() {
		float aux = 0;
		if(nrCopaci>0)
		{
			for (int i = 0; i < nrCopaci; i++)
				aux = aux + varsteCopaci[i];
			aux = aux / nrCopaci;
		}
		return aux;
	}
	Padure operator=(const Padure& p) {
		// Verificare pentru autoatribuire
		if (this != &p) {
			if (this->varsteCopaci != NULL) {
				delete[]this->varsteCopaci;
			}
			nume = p.nume;
			nrCopaci = p.nrCopaci;
			if (nrCopaci != 0) {
				this->varsteCopaci = new int[nrCopaci];
				for (int i = 0; i < nrCopaci; i++)
				{
					this->varsteCopaci[i] = p.varsteCopaci[i];
				}
			}
			else this->varsteCopaci = NULL;
		}
		return *this;
	}

	~Padure() {
		if (this->varsteCopaci != NULL) {
			delete[]this->varsteCopaci;
		}
	}
	
	void setNume(string nume ) {
		if (nume.length() > 3)
		{
			this->nume = nume;
		}
	}
	string getNume() const {
		return this->nume;
	}
	const int getId() const{
		return this->id;
	}

	void setCopaci(int nrCopaci, int* varste) {
		if (nrCopaci > 0) {
			this->nrCopaci = nrCopaci;
			if (this->varsteCopaci != NULL) {
				delete[]this->varsteCopaci;
			}
			this->varsteCopaci = new int[nrCopaci];
			for (int i = 0; i < nrCopaci; i++) {
				this->varsteCopaci[i] = varste[i];
			}
		}
	}

	int* getVarsteCopaci() {
		return this->varsteCopaci;
	}

	int getVarstaCopac(int index) {
		return this->varsteCopaci[index];
	}
	int getNrCopaci() {
		return this->nrCopaci;
	}
	friend ostream& operator<<(ostream& monitor,const Padure &padure);

	friend istream& operator>>(istream& mouse,Padure &padure){
		cout << "Nume:";
		mouse >> padure.nume;
		cout << "Nr copaci:";
		mouse >> padure.nrCopaci;
		if (padure.varsteCopaci != NULL)
		{
			delete[]padure.varsteCopaci;
		}
		if(padure.nrCopaci>0)
		{	
			padure.varsteCopaci = new int[padure.nrCopaci];
			for (int i = 0; i < padure.nrCopaci; i++) {
				cout << "Varsta copacului " << i+1 << ":";
				mouse >> padure.varsteCopaci[i];
			}
		}
		else {
			cout << "Nu avem copaci";
			padure.varsteCopaci = NULL;
		}
		return mouse;
	}

	operator string(){
		return this->nume;
	}

	Padure operator+(const Padure& p)
	{
		Padure aux = *this;
		aux.nrCopaci = this->nrCopaci + p.nrCopaci;
		if (aux.varsteCopaci != NULL) {
			delete[]aux.varsteCopaci;
		}
		if (aux.nrCopaci > 0) {
			aux.varsteCopaci = new int[aux.nrCopaci];
			for (int i = 0; i < this->nrCopaci; i++)
				aux.varsteCopaci[i] = varsteCopaci[i];
			for (int i = this->nrCopaci; i < aux.nrCopaci; i++)
				aux.varsteCopaci[i] = p.varsteCopaci[i - nrCopaci];
		}
		else {
			aux.varsteCopaci = NULL;
		}
		return aux;
	}

	Padure operator++()
	{
		for (int i = 0; i < this->nrCopaci; i++)
		{
			this->varsteCopaci[i]++;
		}
		return *this;
	}

	Padure operator++(int)
	{
		Padure aux = *this;
		for (int i = 0; i < this->nrCopaci; i++)
		{
			this->varsteCopaci[i]++;
		}
		return aux;
	}

	int& operator[](int index) {
		if (index >= 0 && index < this->nrCopaci) {
			return this->varsteCopaci[index];
		}
		else throw 404;
	}
	Padure operator+=(int varsta) {
		int* varsteCopaci = new int[nrCopaci + 1];
		for (int i = 0; i < nrCopaci; i++) {
			varsteCopaci[i] = this->varsteCopaci[i];
		}
		varsteCopaci[nrCopaci] = varsta;
		nrCopaci++;
		if (this->varsteCopaci != NULL) {
			delete[]this->varsteCopaci;
		}
		this->varsteCopaci = varsteCopaci;
		return *this;
	}
	friend ofstream& operator<<(ofstream& fisier, const Padure& padure) {
		fisier << padure.getNume() << endl << padure.gradDefrisare<<endl<< padure.nrCopaci <<endl;
		if (padure.varsteCopaci != NULL) {
			for (int i = 0; i < padure.nrCopaci; i++) {
				fisier << padure.varsteCopaci[i] << " ";
			}
		}
		fisier << endl;
		return fisier;
}
	friend ifstream& operator>>(ifstream& mouse, Padure& padure) {
		int a;
		mouse >> padure.nume;
		mouse >> a;
		mouse >> padure.nrCopaci;
		if (padure.varsteCopaci != NULL)
		{
			delete[]padure.varsteCopaci;
		}
		if (padure.nrCopaci > 0)
		{
			padure.varsteCopaci = new int[padure.nrCopaci];
			for (int i = 0; i < padure.nrCopaci; i++) {
				
				mouse >> padure.varsteCopaci[i];
			}
		}
		else {
			
			padure.varsteCopaci = NULL;
		}
		return mouse;
	}
};
int Padure::gradDefrisare = 2;

ostream& operator<<(ostream& monitor,const Padure& padure)
{
	monitor << padure.getId() << "." << "nume: " << padure.getNume() << "." << padure.gradDefrisare << "nr copaci" << padure.nrCopaci << "varste: ";
	if (padure.varsteCopaci != NULL) {
		for (int i = 0; i < padure.nrCopaci; i++) {
			monitor << padure.varsteCopaci[i] << ",";
		}
	}
	else {
		monitor<< "-";
	}
	monitor<< endl;
	return monitor;
}

class TaraCuPaduri {
private:
	int nrPaduri;
	Padure* paduri;

public:
	TaraCuPaduri() {
		this->nrPaduri = 3;
		this->paduri = new Padure[3];
	}

	Padure& operator[](int index) {
		if (index >= 0 && index < this->nrPaduri) {
			return this->paduri[index];
		}
	}
	~TaraCuPaduri() {
		if (this->paduri) {
			delete[]this->paduri;
		}
	}

};

class PadureTropicala : public Padure {
private:
	float umiditate;
	int nrLuni;
	float* precipitatiiPeLuna;
public:

	void setUmiditate(float val) {
		if (val >= 0) {
			this->umiditate = val;
		}
	}
	PadureTropicala() :Padure(2, "Padure tropicala") {
		this->umiditate = 0;
		this->nrLuni = 12;
		this->precipitatiiPeLuna = new float[this->nrLuni];
		for (int i = 0; i < this->nrLuni; i++)
		{
			this->precipitatiiPeLuna[i] = 0;
		}
	}

	PadureTropicala(string nume, float umiditate) :Padure(3, nume) {
		this->umiditate = umiditate;
		this->nrLuni = 12;
		this->precipitatiiPeLuna = new float[this->nrLuni];
		for (int i = 0; i < this->nrLuni; i++)
		{
			this->precipitatiiPeLuna[i] = 0;
		}
	}

	~PadureTropicala() {
		if (this->precipitatiiPeLuna != NULL) {
			delete[]this->precipitatiiPeLuna;
		}
	}

	PadureTropicala(const PadureTropicala& p) :Padure(p) {
		this->umiditate = p.umiditate;
		this->nrLuni = p.nrLuni;
		this->precipitatiiPeLuna = new float[this->nrLuni];
		for (int i = 0; i < this->nrLuni; i++)
		{
			this->precipitatiiPeLuna[i] = p.precipitatiiPeLuna[i];
		}
	}

	PadureTropicala operator=(const PadureTropicala& p) {
		if (this != &p) {
			Padure::operator=(p);
			this->umiditate = p.umiditate;
			this->nrLuni = p.nrLuni;
			if (this->precipitatiiPeLuna != NULL) {
				delete[]this->precipitatiiPeLuna;
			}
			if (this->nrLuni > 0) {
				this->precipitatiiPeLuna = new float[this->nrLuni];
				for (int i = 0; i < this->nrLuni; i++) {
					this->precipitatiiPeLuna[i] = p.precipitatiiPeLuna[i];
				}
			}
			else {
				this->precipitatiiPeLuna = NULL;
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const PadureTropicala& padure) {
		out << "Umiditate:" << padure.umiditate
			<< "Nr luni: " << padure.nrLuni<<":";

			for (int i = 0; i < padure.nrLuni; i++) {
				out << padure.precipitatiiPeLuna[i] << ",";
			}
			out << (Padure)padure;
			return out;
	}
   //copacii cu o vartsa mai mare de 50 de ani se vor prabusi la o umiditate mai mare de 70%
	//cati copaci se vor prabusi intr-o padure tropicala cu umiditatea data
	int calcCopaciPrabusiti() {
		int s = 0;
		if (umiditate > 70) {
			for (int i = 0; i < getNrCopaci(); i++) {
				if (getVarstaCopac(i) > 50) {
					s++;
				}
			}
		}
		return s;
	}
};

void main() {
	PadureTropicala p1;
	PadureTropicala p2("Padure Tropicala 2", 20);

	PadureTropicala p3 = p2;
	p3 = p2;
	cout << p1;

	p1.setUmiditate(90);
	int varste[5] {51, 70, 23, 45, 67};
	p1.setCopaci(5, varste);
	cout << p1;

	cout << "Numar copaci care vor cadea:" << p1.calcCopaciPrabusiti();
}