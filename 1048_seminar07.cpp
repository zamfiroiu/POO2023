#include<iostream>

using namespace std;

class Oras {
private:
	const int id;
	static string planeta;
	string nume;
	int populatie;
	float suprafata;
	int* varsteLocuitori;
public:


	Oras() : id(1) {
		this->nume = "NoName";
		this->populatie = 0;
		this->suprafata = 100;
		this->varsteLocuitori = NULL;
	}
	Oras(string nume, float suprafata) : id(4)
	{
		this->nume = nume;
		this->populatie = 0;
		this->suprafata = suprafata;
		this->varsteLocuitori = NULL;

	}
	Oras(int id, string nume, int populatie, float suprafata, int* varsteLocuitori) : id(id) {
		this->nume = nume;
		this->populatie = populatie;
		this->suprafata = suprafata;
		this->varsteLocuitori = new int[populatie];
		for (int i = 0; i < populatie; i++)
		{
			this->varsteLocuitori[i] = varsteLocuitori[i];
		}
	}
	Oras(const Oras& oras) : id(oras.id) {
		this->nume = oras.nume;
		this->populatie = oras.populatie;
		this->suprafata = oras.suprafata;
		this->varsteLocuitori = new int[populatie];
		for (int i = 0; i < populatie; i++) {
			this->varsteLocuitori[i] = oras.varsteLocuitori[i];
		}
	}

	const Oras& operator= (const Oras& oras) {
		if (this != &oras) {
			if (this->varsteLocuitori != NULL)
				delete[]this->varsteLocuitori;
			this->nume = oras.nume;
			this->populatie = oras.populatie;
			this->suprafata = oras.suprafata;
			this->varsteLocuitori = new int[populatie];
			for (int i = 0; i < populatie; i++) {
				this->varsteLocuitori[i] = oras.varsteLocuitori[i];
			}
		}
		return *this;


	}

	Oras operator+(const Oras& oras) {
		Oras aux;
		aux.nume = this->nume;
		aux.populatie = this->populatie + oras.populatie;
		aux.suprafata = this->suprafata + oras.suprafata;
		if (aux.varsteLocuitori != NULL)
			delete[]aux.varsteLocuitori;
		aux.varsteLocuitori = new int[this->populatie + oras.populatie];
		for (int i = 0; i < this->populatie; i++)
			aux.varsteLocuitori[i] = this->varsteLocuitori[i];
		for (int j = this->populatie; j < aux.populatie; j++)
			aux.varsteLocuitori[j] = oras.varsteLocuitori[j - this->populatie];
		return aux;
	}

	~Oras() {
		if (this->varsteLocuitori != NULL) {
			delete[]this->varsteLocuitori;
		}
	}

	float getVarstaMedie() {
		int suma = 0;
		if (this->populatie == 0)
			return 0;
		for (int i = 0; i < this->populatie; i++)
			suma = suma + this->varsteLocuitori[i];
		return suma / (float)populatie;
	}

	void addNouLocuitor(int varsta) {

		int* aux = new int[this->populatie + 1];
		for (int i = 0; i < this->populatie; i++)
			aux[i] = this->varsteLocuitori[i];
		aux[this->populatie] = varsta;

		delete[]this->varsteLocuitori;
		this->varsteLocuitori = aux;

		this->populatie++;

	}
	void addNouNascut() {

		addNouLocuitor(0);

	}

	void afisare() {
		int i;
		cout << "Orasul " << nume << " are id-ul " << id << ", se afla pe planeta " << planeta << ", are populatia de " << populatie << "si o suprafata de " << suprafata << ". Locuitorii orasului au varstele: ";
		if (populatie == 0)
			cout << "-";
		else
			for (i = 0; i < populatie; i++)
				cout << varsteLocuitori[i] << " ";
		cout << endl;

	}

	static void setPlaneta(string planeta) {
		Oras::planeta = planeta;
	}

	static string getPlaneta()
	{
		return Oras::planeta;
	}

	void setNume(string nume) {
		if (nume.length() > 3)
			this->nume = nume;
	}

	string getNume()const
	{
		return this->nume;
	}

	int getId()
	{
		return this->id;
	}

	void setPopulatie(int populatie, int* varste) {
		if (populatie > 0) {
			this->populatie = populatie;
			if (this->varsteLocuitori != NULL) {
				delete[]this->varsteLocuitori;
			}
			varsteLocuitori = new int[this->populatie];
			for (int i = 0; i < populatie; i++) {
				this->varsteLocuitori[i] = varste[i];
			}
		}
	}

	int* getVarsteLocuitori() {
		return varsteLocuitori;
	}

	int getVarstaLocuitor(int index) {
		if (index >= 0 && index < this->populatie) {
			return this->varsteLocuitori[index];
		}
	}

	int& operator[](int index) {
		if (index >= 0 && index < this->populatie) {
			return this->varsteLocuitori[index];
		}
		else {
			throw 404;
		}
	}

	friend ostream& operator<<(ostream& out, const Oras& oras);
	friend istream& operator>>(istream& in, Oras& oras)
	{
		cout << "Nume:";
		in >> oras.nume;
		cout << "\n Populatie:";
		in >> oras.populatie;
		cout << " \nSuprafata:";
		in >> oras.suprafata;
		if (oras.varsteLocuitori != NULL)
		{
			delete[]oras.varsteLocuitori;
		}
		oras.varsteLocuitori = new int[oras.populatie];
		for (int i = 0; i < oras.populatie; i++)
		{
			cout << " Varsta locuitorului" << i + 1 << " : ";
			in >> oras.varsteLocuitori[i];

		}
		return in;
	}

	operator int() {
		return this->populatie;
	}

	explicit operator float() {
		if (this->populatie == 0)
		{
			throw exception("Populatia este 0 !");
		}
		float s=0;
		for (int i = 0; i < this->populatie; i++)
			s += this->varsteLocuitori[i];
		return s / this->populatie;
	}

	float operator()()
	{
		if (suprafata == 0)
		{
			throw exception("Mesaj de eroare !");
		}
		return populatie / suprafata;
	}

	float operator()(int imigranti)
	{
		if (suprafata == 0)
		{
			throw 1;
		}
		return (populatie + imigranti) / suprafata;
	}

	Oras operator!() {
		if (suprafata > 0) {
			suprafata = 0;
		}
		else {
			suprafata = 30;
		}
		return *this;
	}
	Oras& operator--() {
		if (this->suprafata > 0) {
			this->suprafata = this->suprafata - 1;
		}
		return *this;
	}
	Oras operator--(int n) {
		Oras aux = *this;
		if (this->suprafata > 0) {
			this->suprafata = this->suprafata - 1;
		}
		return aux;
	}
};
string Oras::planeta = "Pamant";
ostream& operator<<(ostream& out, const Oras& oras)
{
	out << "Orasul " << oras.getNume() << " are id-ul " << oras.id << ", se afla pe planeta " << oras.planeta << ", are populatia de " << oras.populatie << "si o suprafata de " << oras.suprafata << ". Locuitorii orasului au varstele: ";
	if (oras.populatie == 0)
		out << "-";
	else
		for (int i = 0; i < oras.populatie; i++)
			out << oras.varsteLocuitori[i] << " ";
	out << endl;
	return out;
}


class Tara {
private:
	int nrOrase;
	Oras* orase;
public:
	Tara() {
		nrOrase = 3;
		orase = new Oras[3];
	}
	Oras& operator[](int index) {
		if (index >= 0 && index < this->nrOrase) {
			return this->orase[index];
		}
		else {
			throw 404;
		}
	}
};




void main()
{
	try
	{
		Oras oras2;
		cin >> oras2;
		cout << oras2;

		float medie = (float)oras2;
		cout << medie << endl;
		int populatie = oras2;
		cout << populatie << endl;
		cout << oras2[0] << endl;
		cout << oras2() << endl;
		cout << oras2(5) << endl;
		!oras2;
		cout << oras2;
		Oras oras3;
		cin >> oras3;
		oras3 = !oras2;
		cout << oras3;
		oras3 = --oras2;
		oras3 = oras2--;
		cout << oras2;


		Tara t;
		t[0] = oras2;
		t[1] = oras3;

		cout << t[0][1];
	}
	catch (const std::exception& e)
	{
		cout << endl << e.what();
	}
	catch (int numar)
	{
		cout << endl << numar;
	}
	catch (...)
	{
		cout << "Exceptie necunoscuta" << endl;
	}
	/*
	cout << oras2() << endl;
	cout << oras2(5) << endl;
	*/


}