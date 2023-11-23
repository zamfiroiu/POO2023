#include<iostream>
#include<fstream>

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
	friend ofstream& operator<<(ofstream& out, const Oras& oras);
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
		float s = 0;
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
	friend ifstream& operator>>(ifstream& in, Oras& oras);
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

ofstream& operator<<(ofstream& out, const Oras& oras)
{
	out << oras.getNume()  << endl << oras.populatie << endl << oras.suprafata << endl;
	
	for (int i = 0; i < oras.populatie; i++)
		out << oras.varsteLocuitori[i] << " ";
	out << endl;
	return out;
}

ifstream& operator>>(ifstream& in, Oras& oras) {
	in >> oras.nume;
	in >> oras.populatie;
	in >> oras.suprafata;
	if (oras.varsteLocuitori != NULL)
		delete[]oras.varsteLocuitori;
	oras.varsteLocuitori = new int[oras.populatie];
	for (int i = 0; i < oras.populatie; i++)
		in >> oras.varsteLocuitori[i];
	return in;
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
	//ofstream f("orase.txt",ios::out);
	//Oras oras1;
	//cin >> oras1;
	//f << oras1;
//	f.close();
	//ifstream g("orase.txt", ios::in);
	//Oras o1;
	//g >> o1;
	//cout << o1;
	//g.close();


	float suprafata = 456.78;
	char sir[30] = "descriere oras";



	//metoda gresita de scriere in fisiere binare;
	///////////////fis << suprafata << " " << sir << endl;

	//metoda corecta de scriere in fisiser binar
	
	/*fstream fis("fisierO.bin", ios::binary | ios::out);
	fis.write((char*)&suprafata, sizeof(float));
	int lungime = strlen(sir) + 1;
	fis.write((char*)&lungime, sizeof(int));
	fis.write((char*)sir, lungime);
	fis.close();*/


	//fstream fis2("fisierO.bin", ios::binary | ios::in);
	//float valReal;
	//int lungimeCitita;
	//char* pSir;
	//fis2.read((char*)&valReal, sizeof(float));
	//fis2.read((char*)&lungimeCitita, sizeof(int));
	//pSir = new char[lungimeCitita];
	//fis2.read((char*)pSir, sizeof(char) * lungimeCitita);

	//cout << valReal << " " << pSir << endl;

	//fis2.close();


	fstream fo("orase.dat", ios::binary | ios::out);
	Oras o1;
	cin >> o1;
	
	//metoda gresita de scriere a obiectelor in fisier binar
	fo.write((char*)&o1, sizeof(Oras));

	fo.close();


	fstream go("orase.dat", ios::binary | ios::in);

	Oras o2;
	go.read((char*)&o2, sizeof(Oras));

	cout << o2;

	go.close();

	//pentru salvarea obiectelor in fisiere binare trebuie sa realizam
	//metode de scriere/citire in care vom trata independent fiecare atribut


}