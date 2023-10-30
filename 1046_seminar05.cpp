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
//	void afisare() {
//		cout << id << "." << "nume: " << nume << "." << gradDefrisare << "nr copaci" << nrCopaci << "varste: ";
//		if (varsteCopaci != NULL) {
//			for (int i = 0; i < nrCopaci; i++) {
//				cout << varsteCopaci[i] << ",";
//			}
//		}
//		else {
//			cout << "-";
//		}
//		cout << endl;
//	}
//	void setNume(string nume ) {
//		if (nume.length() > 3)
//		{
//			this->nume = nume;
//		}
//	}
//	string getNume() {
//		return this->nume;
//	}
//	const int getId() {
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
//};
//int Padure::gradDefrisare = 2;
//
//void main() {
//	int* varste;
//	varste = new int[2];
//	varste[0] = 5;
//	varste[1] = 10;
//	Padure padure1;
//	padure1.afisare();
//	Padure padure2(101,"Padure2",2,varste);
//	padure2.afisare();
//
//	Padure padure3(7, "Bucuresti");
//	padure3.afisare();
//
//	Padure padure4(padure1);
//	Padure padure5 = padure1;
//	
//	Padure padure6;
//	padure6 = padure1;
//
//	padure2.afisare();
//	padure2 = padure2;
//	padure2.afisare();
//	padure6.setNume("Noul nume");
//	cout << padure6.getNume() << endl;
//
//	int* vector = new int[4] {5, 6, 2, 7};
//	padure6.setCopaci(4, vector);
//	padure6.afisare();
//
//	cout << padure6.getVarsteCopaci()[1];
//	cout << padure6.getVarstaCopac(1);
//
//	delete[]vector;
//
//
//}