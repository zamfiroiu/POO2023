//#include<iostream>
//
//using namespace std;
//
//class Padure {
//private:
//	const int id;
//	string nume;
//	int nrCopaci;
//	int* varsteCopaci;
//	static int gradDefrisare;
//public:
//	static int getGradDefrisare() {
//		return Padure::gradDefrisare;
//	}
//
//	static void setGradDefrisare(int grad) {
//		if (grad > 0) {
//			Padure::gradDefrisare = grad;
//		}
//	}
//
//	Padure():id(100) {
//		this->nume = "Padure";
//		this->nrCopaci = 0;
//		this->varsteCopaci= NULL;
//	}
//
//	Padure(int idNou, string nume) :id(idNou) {
//		this->nume = nume;
//		this->nrCopaci = 0;
//		this->varsteCopaci = NULL;
//	}
//
//	Padure(int id, string nume, int nrCopaci, int* varsteCopaci):id(id),nume(nume),nrCopaci(nrCopaci) {
//		if (nrCopaci != 0) {
//			this->varsteCopaci = new int[nrCopaci];
//			for (int i = 0; i < nrCopaci; i++)
//			{
//				this->varsteCopaci[i] = varsteCopaci[i];
//			}
//		}
//		else this->varsteCopaci = NULL;
//	}
//	Padure(const Padure &p) :id(p.id){
//		nume = p.nume;
//		nrCopaci = p.nrCopaci;
//		if (nrCopaci != 0) {
//			this->varsteCopaci = new int[nrCopaci];
//			for (int i = 0; i < nrCopaci; i++)
//			{
//				this->varsteCopaci[i] = p.varsteCopaci[i];
//			}
//		}
//		else this->varsteCopaci = NULL;
//		
//	}
//	
//	Padure operator=(const Padure& p) {
//		// Verificare pentru autoatribuire
//		if (this != &p) {
//			if (this->varsteCopaci != NULL) {
//				delete[]this->varsteCopaci;
//			}
//			nume = p.nume;
//			nrCopaci = p.nrCopaci;
//			if (nrCopaci != 0) {
//				this->varsteCopaci = new int[nrCopaci];
//				for (int i = 0; i < nrCopaci; i++)
//				{
//					this->varsteCopaci[i] = p.varsteCopaci[i];
//				}
//			}
//			else this->varsteCopaci = NULL;
//		}
//		return *this;
//	}
//
//	~Padure() {
//		if (this->varsteCopaci != NULL) {
//			delete[]this->varsteCopaci;
//		}
//	}
//	
//	void setNume(string nume ) {
//		if (nume.length() > 3)
//		{
//			this->nume = nume;
//		}
//	}
//	string getNume() const {
//		return this->nume;
//	}
//	const int getId() const{
//		return this->id;
//	}
//
//	void setCopaci(int nrCopaci, int* varste) {
//		if (nrCopaci > 0) {
//			this->nrCopaci = nrCopaci;
//			if (this->varsteCopaci != NULL) {
//				delete[]this->varsteCopaci;
//			}
//			this->varsteCopaci = new int[nrCopaci];
//			for (int i = 0; i < nrCopaci; i++) {
//				this->varsteCopaci[i] = varste[i];
//			}
//		}
//	}
//
//	int* getVarsteCopaci() {
//		return this->varsteCopaci;
//	}
//
//	int getVarstaCopac(int index) {
//		return this->varsteCopaci[index];
//	}
//	friend ostream& operator<<(ostream& monitor,const Padure &padure);
//
//	friend istream& operator>>(istream& mouse,Padure &padure){
//		cout << "Nume:";
//		mouse >> padure.nume;
//		cout << "Nr copaci:";
//		mouse >> padure.nrCopaci;
//		if (padure.varsteCopaci != NULL)
//		{
//			delete[]padure.varsteCopaci;
//		}
//		if(padure.nrCopaci>0)
//		{	
//			padure.varsteCopaci = new int[padure.nrCopaci];
//			for (int i = 0; i < padure.nrCopaci; i++) {
//				cout << "Varsta copacului " << i+1 << ":";
//				mouse >> padure.varsteCopaci[i];
//			}
//		}
//		else {
//			cout << "Nu avem copaci";
//			padure.varsteCopaci = NULL;
//		}
//		return mouse;
//	}
//
//	Padure operator+(const Padure& p)
//	{
//		Padure aux = *this;
//		aux.nrCopaci = this->nrCopaci + p.nrCopaci;
//		if (aux.varsteCopaci != NULL) {
//			delete[]aux.varsteCopaci;
//		}
//		if (aux.nrCopaci > 0) {
//			aux.varsteCopaci = new int[aux.nrCopaci];
//			for (int i = 0; i < this->nrCopaci; i++)
//				aux.varsteCopaci[i] = varsteCopaci[i];
//			for (int i = this->nrCopaci; i < aux.nrCopaci; i++)
//				aux.varsteCopaci[i] = p.varsteCopaci[i - nrCopaci];
//		}
//		else {
//			aux.varsteCopaci = NULL;
//		}
//		return aux;
//	}
//};
//int Padure::gradDefrisare = 2;
//
//ostream& operator<<(ostream& monitor,const Padure& padure)
//{
//	monitor << padure.getId() << "." << "nume: " << padure.getNume() << "." << padure.gradDefrisare << "nr copaci" << padure.nrCopaci << "varste: ";
//	if (padure.varsteCopaci != NULL) {
//		for (int i = 0; i < padure.nrCopaci; i++) {
//			monitor << padure.varsteCopaci[i] << ",";
//		}
//	}
//	else {
//		monitor<< "-";
//	}
//	monitor<< endl;
//	return monitor;
//}
//
//void main() {
//	int* varste;
//	varste = new int[2];
//	varste[0] = 5;
//	varste[1] = 10;
//	Padure padure1;
//	
//	Padure padure2(101,"Padure2",2,varste);
//	cout << padure2;
//
//	Padure padure3(7, "Bucuresti");
//	cout << padure3;
//	Padure padure4(padure1);
//	Padure padure5 = padure1;
//	
//	Padure padure6;
//	padure6 = padure1;
//
//	cout << padure2;
//	padure2 = padure2;
//	cout << padure2;
//	padure6.setNume("Noul nume");
//	cout << padure6.getNume() << endl;
//
//	int* vector = new int[4] {5, 6, 2, 7};
//	padure6.setCopaci(4, vector);
//	cout << padure6;
//
//	cout << padure6.getVarsteCopaci()[1];
//	cout << padure6.getVarstaCopac(1);
//	Padure padure7;
//	cin >> padure7;
//	cout << padure7;
//
//	padure1 = padure7 + padure6;
//	cout << padure1;
//	delete[]vector;
//}