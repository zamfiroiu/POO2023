#include<iostream>

using namespace std;

class Scara {
private:
	static float gravitatie;
	const int id;
public:
	int nrTrepte;
	float* latimeTrepte;
public:
	float inaltime;
	float greutate;
	bool rulanta;

	class Treapta {
	private:
		int greutateTreapta;
	public:
		string culoare;
	};

	void afiseazaActiune() {  //afiseazaActiune(Scara* this)
		if (this->rulanta == true) {
			cout << "Scara este rulanta";
		}
		else {
			cout << "Trebuie sa urci la pas!";
		}
	}

	static void schimbaGravitatie(float nouaG) {
		gravitatie = nouaG;
	}
	Scara() : nrTrepte(10), inaltime(2),
		greutate(5),rulanta(false),id(0){
		this->latimeTrepte = new float[nrTrepte];
		for (int i = 0; i < nrTrepte; i++) {
			this->latimeTrepte[i] = nrTrepte - i;
		}
	}

	Scara(int nrTrepte):id(0) {
		this->nrTrepte = nrTrepte;
		this->inaltime = 2;
		this->greutate = 5;
		this->rulanta = false;
		this->latimeTrepte = new float[nrTrepte];
		for (int i = 0; i < nrTrepte; i++) {
			this->latimeTrepte[i] = nrTrepte - i;
		}
	}


	Scara(float nouaGreutate):nrTrepte(10),
		inaltime(2),greutate(nouaGreutate),
		rulanta(false),id(0) {
		this->latimeTrepte = new float[nrTrepte];
		for (int i = 0; i < nrTrepte; i++) {
			this->latimeTrepte[i] = nrTrepte - i;
		}
	}

	Scara(int nrTrepte, float inaltime, const int idNou, float* latime):id(idNou) {
		this->nrTrepte = nrTrepte;
		this->inaltime = inaltime;
		this->greutate = 5;
		this->rulanta = false;
		this->latimeTrepte = new float[nrTrepte];
		for (int i = 0; i < nrTrepte; i++) {
			this->latimeTrepte[i] = latime[i];
		}
	}

	 Scara(const Scara &s):id(s.id) {
		this->nrTrepte = s.nrTrepte;
		this->inaltime = s.inaltime;
		this->greutate = s.greutate;
		this->rulanta = s.rulanta;
		this->latimeTrepte = new float[this->nrTrepte];
		for (int i = 0; i < this->nrTrepte; i++) {
			this->latimeTrepte[i] = s.latimeTrepte[i];
		}
	}


	 Scara& operator=(const Scara& s2) {
		 if (this != &s2) {
			 this->nrTrepte = s2.nrTrepte;
			 this->inaltime = s2.inaltime;
			 this->greutate = s2.greutate;
			 this->rulanta = s2.rulanta;
			 if (this->latimeTrepte != NULL) {
				 delete[]this->latimeTrepte;
			 }
			 this->latimeTrepte = new float[this->nrTrepte];
			 for (int i = 0; i < this->nrTrepte; i++) {
				 this->latimeTrepte[i] = s2.latimeTrepte[i];
			 }
		 }
		 return *this;
	 }


	~Scara() {
		if (this->latimeTrepte != NULL) {
			delete[]this->latimeTrepte;
		}
	}

	int getNrTrepte() {
		return this->nrTrepte;
	}

	void setNrTrepte(int nrTrepte) {
		if (nrTrepte = 2) {
			this->nrTrepte = nrTrepte;
		}
	}
};
float Scara::gravitatie = 9.81;

void functie1(const Scara& scara) {

}

Scara& functie2() {
	Scara s;

	return s;
}


class Muncitor {
public:
	string nume;
	Scara scara;

	void folosesteScara() {
		scara.nrTrepte;
	}
};

void main() {
	Scara scara(5.3f);
	float* latimeTrepte = new float[2] {30, 45};
	Scara scara2(2,4,100,latimeTrepte);

	cout<<scara.getNrTrepte();
	scara.setNrTrepte(-7);


	{
		Scara scara3;
	}
	Scara* scari = new Scara[10];

	delete[]scari;

	Scara** pScari = new Scara * [3];
	pScari[0] = new Scara(5);
	pScari[1] = new Scara(8);
	pScari[2] = new Scara(7);


	//scara.nrTrepte = 10;
	scara.inaltime = 2;
	scara.afiseazaActiune();
	scara2.afiseazaActiune();
	scara.schimbaGravitatie(10);
	Scara::schimbaGravitatie(9.9);

	Scara scara4 = scara2;
	scara4.latimeTrepte[0] = 20;
	scara2.latimeTrepte[0] = 80;
	cout <<endl<< scara4.latimeTrepte[0];


	Scara scara5;

	scara5 = scara2;
	scara5.operator=(scara2);

	int i, j;
	i = j = 0;

	scara4 = scara5 = scara2;

	scara2 = scara2;

	Scara::Treapta treapta;
	Muncitor muncitor;
	muncitor.scara.nrTrepte=9;
}