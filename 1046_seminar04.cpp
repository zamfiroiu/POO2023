//#include<iostream>
//
//using namespace std;
//
//class Padure {
//public:
//	const int id;
//	string nume;
//	int nrCopaci;
//	int* varsteCopaci;
//	static int gradDefrisare;
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
//	
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
//}
