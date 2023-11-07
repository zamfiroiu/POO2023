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
			aux.varsteLocuitori[j] = oras.varsteLocuitori[j-this->populatie];
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
			cout << " Varsta locuitorului" << i+1<< " : ";
			in >> oras.varsteLocuitori[i];

		}
		return in;
	}
	
};
string Oras::planeta = "Pamant";
 ostream& operator<<(ostream& out,const Oras& oras)
{
	 out << "Orasul " << oras.getNume() << " are id-ul " << oras.id << ", se afla pe planeta " << oras.planeta << ", are populatia de " << oras.populatie << "si o suprafata de " << oras.suprafata << ". Locuitorii orasului au varstele: ";
	 if (oras.populatie == 0)
		 out << "-";
	 else
		 for (int i = 0; i < oras.populatie; i++)
			 out <<oras.varsteLocuitori[i] << " ";
	 out << endl;
	 return out;
}
 


void main() 
{
	Oras oras1;
	oras1.afisare();
	int* varstaLocuitori = new int[2];
	varstaLocuitori[0] = 31;
	varstaLocuitori[1] = 32;
	Oras* pOras2 = new Oras(2, "Galati", 2, 3.2, varstaLocuitori);
	Oras oras2(3, "Galati", 2, 3.2, varstaLocuitori);

	Oras::setPlaneta("planeta pamant");
	oras1.setPlaneta("Earth");

	oras2.afisare();
	pOras2->afisare();
	Oras oras3("Bucuresti", 17.2);
	oras3.afisare();
	cout << "\nMedia de varsta este: " << oras2.getVarstaMedie();

	oras2.addNouLocuitor(19);
	cout << "\nvarstamedie: " << oras2.getVarstaMedie() << "\n";
	oras2.afisare();

	oras2.addNouNascut();
	cout << "\nvarstamedie: " << oras2.getVarstaMedie() << "\n";
	oras2.afisare();

	delete pOras2;

	Oras oras4(oras2);
	oras4.afisare();
	cout << endl;
	Oras oras5 = oras2;
	oras5.afisare();

	cout << endl;

	oras4.addNouLocuitor(88);
	oras5 = oras4;
	oras5.afisare();

	oras4 = oras4;

	oras4.afisare();

	oras4.setNume("Bucuresti");
	cout << endl << oras4.getNume();

	int* vector = new int[7] {32, 7, 34, 15, 75, 54, 22};

	oras4.setPopulatie(7, vector);
	oras4.afisare();

	delete[]vector;
	cout << endl << *(oras4.getVarsteLocuitori() + 1);
	cout << endl << oras4.getVarsteLocuitori()[1] << endl;
	cout << endl << oras4.getVarstaLocuitor(1) << endl;
	cout << endl << oras4[1] << endl;
	oras4[1] = 8;
	cout << endl << oras4[1] << endl;

	
	cout << oras2 << endl;

	cin >> oras2;
	cout << oras2;

	Oras oras10;
	oras10 = oras4 + oras2;
	cout << oras10;

}