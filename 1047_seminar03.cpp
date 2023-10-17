//#include<iostream>
//
//using namespace std;
//
//class EchipaFotbal {
//public:
//	int nrJucatori;
//	string* numeJucatori;
//	int pozitieClasament;
//	float buget;
//
//	/*EchipaFotbal() {
//		this->nrJucatori = 3;
//		numeJucatori = new string[3];
//		numeJucatori[0] = "Popescu";
//		numeJucatori[1] = "Georgescu";
//		numeJucatori[2] = "Ionescu";
//		pozitieClasament = 2;
//		buget = 23000;
//	}*/
//
//	~EchipaFotbal() {
//		if (this->numeJucatori != NULL) {
//			delete[]this->numeJucatori;
//		}
//	}
//
//	void afisare() {
//		cout << "Echipa de fotbal de pe locul " << pozitieClasament << " are un buget de " << buget << " pentru " << nrJucatori << " jucatori, cu numele: ";
//		for (int i = 0; i < nrJucatori; i++) {
//			cout << numeJucatori[i] << ", ";
//		}
//		cout << endl;
//	}
//
//	void modificaPozitie(int pozitieClasament) {
//		this->pozitieClasament = pozitieClasament;
//	}
//
//	
//};
//
//EchipaFotbal initializareEchipa() {
//	EchipaFotbal ef;
//	ef.nrJucatori = 3;
//	ef.numeJucatori = new string[3];
//	ef.numeJucatori[0] = "Popescu";
//	ef.numeJucatori[1] = "Georgescu";
//	ef.numeJucatori[2] = "Ionescu";
//	ef.pozitieClasament = 2;
//	ef.buget = 23000;
//	return ef;
//}
//
//void main() {
//	EchipaFotbal echipa;
//	echipa.afisare();
//	//echipa = initializareEchipa();
//	//echipa.afisare();
//	
//	EchipaFotbal echipa2;
//	echipa2.afisare();
//	
//	echipa.modificaPozitie(5);
//	echipa.afisare();
//
//	EchipaFotbal* echipe = new EchipaFotbal[53];
//
//	delete[]echipe;
//
//}