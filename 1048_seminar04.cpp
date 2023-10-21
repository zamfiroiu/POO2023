#include<iostream>

using namespace std;

class Oras {
public:
	const int id;
	static string planeta;
	string nume;
	int populatie;
	float suprafata;
	int* varsteLocuitori;

	Oras() : id(1) {
		this->nume = "NoName";
		this->populatie = 0;
		this->suprafata = 100;
		this->varsteLocuitori = NULL;
	}
	Oras(string nume, float suprafata): id(4)
	{
		this->nume = nume;
		this->populatie = 0;
		this->suprafata = suprafata;
		this->varsteLocuitori = NULL;
		
	}
	Oras(int id,string nume,int populatie,float suprafata,int* varsteLocuitori) : id(id) {
		this->nume = nume;
		this->populatie = populatie;
		this->suprafata = suprafata;
		this->varsteLocuitori = new int[populatie];
		for (int i = 0; i < populatie; i++)
		{
			this->varsteLocuitori[i] = varsteLocuitori[i];
		}
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
		return suma /(float) populatie;
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
		cout << "Orasul " << nume << " are id-ul " << id << ", se afla pe planeta " << planeta << ", are populatia de " << populatie << "si o suprafata de " << suprafata<<". Locuitorii orasului au varstele: ";
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
};
string Oras::planeta = "Pamant";

void main() {
	Oras oras1;
	oras1.afisare();
	int* varstaLocuitori = new int[2];
	varstaLocuitori[0] = 31;
	varstaLocuitori[1] = 32;
	Oras* pOras2 = new Oras(2,"Galati",2,3.2,varstaLocuitori);
	Oras oras2(3, "Galati", 2, 3.2, varstaLocuitori);

	Oras::setPlaneta("planeta pamant");
	oras1.setPlaneta("Earth");

	oras2.afisare();
	pOras2->afisare();
	Oras oras3("Bucuresti",17.2);
	oras3.afisare();
	cout<<"\nMedia de varsta este: "<<oras2.getVarstaMedie();

	oras2.addNouLocuitor(19);
	cout<<"\nvarstamedie: " << oras2.getVarstaMedie()<<"\n";
	oras2.afisare();

	oras2.addNouNascut();
	cout << "\nvarstamedie: " << oras2.getVarstaMedie() << "\n";
	oras2.afisare();

	delete pOras2;
}