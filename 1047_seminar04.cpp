//#include<iostream>
//
//using namespace std;
//
//class Monitor {
//public:
//	static int nrGenerator;
//	const int nrInventar;
//	string producator;
//	float rezolutie;
//	int nrPorturi;
//	string* numePorturi;
//
//	static int getNrGenerator() {
//		return nrGenerator;
//	}
//
//	Monitor(): nrInventar(nrGenerator++){
//		this->producator = "Acer";
//		this->rezolutie = 24;
//		this->nrPorturi = 0;
//		this->numePorturi = NULL;
//	}
//
//	Monitor(string producator, float rezolutie) : nrInventar(nrGenerator) {
//		nrGenerator++;
//		this->producator = producator;
//		this->rezolutie = rezolutie;
//		this->nrPorturi = 0;
//		this->numePorturi = NULL;
//	}
//
//	Monitor(string producator, float rezolutie, int nrPorturi,		string* numePorturi): nrInventar(nrGenerator) {
//		nrGenerator++;
//		this->producator = producator;
//		this->rezolutie = rezolutie;
//		this->nrPorturi = nrPorturi;
//		this->numePorturi = new string[nrPorturi];
//		for (int i = 0; i < nrPorturi; i++) {
//			this->numePorturi[i] = numePorturi[i];
//		}			
//	}
//	
//	~Monitor() {
//		if (this->numePorturi != NULL) {
//			delete[]this->numePorturi;
//		}
//	}
//
//	void afisareMonitor() {
//		cout << "Monitorul de la producatorul:" << producator << " are o rezolutie de: " << rezolutie << " si un numar porturi de:" << nrPorturi << " cu denumirile: ";
//		if (nrPorturi > 0) {
//			for (int i = 0; i < nrPorturi; i++) {
//				cout << numePorturi[i] << " ";
//			}
//		}
//		else {
//			cout << "NA";
//		}
//		cout << endl;
//	}
//
//	void adaugarePort(string numePort) {
//		string* aux = new string[this->nrPorturi + 1];
//		for (int i = 0; i < this->nrPorturi; i++) {
//			aux[i] = this->numePorturi[i];
//		}
//		aux[this->nrPorturi] = numePort;
//		this->nrPorturi++;
//		if (this->numePorturi) {
//			delete[]this->numePorturi;
//		}
//		this->numePorturi = aux;
//	}
//	
//};
//int Monitor::nrGenerator = 1000;
//
//void main() {
//	Monitor monitor1;
//	monitor1.afisareMonitor();
//	string* numePorturi=new string[3];
//	numePorturi[0] = "VGA";
//	numePorturi[1] = "DVI";
//	numePorturi[2] = "HDMI";
//
//	Monitor monitor2("Acer", 24, 3, numePorturi);
//	monitor2.afisareMonitor();
//	monitor2.adaugarePort("USB");
//	monitor2.afisareMonitor();
//
//	Monitor monitor3("Samsung", 17);
//	monitor3.afisareMonitor();
//
//	cout<<monitor2.getNrGenerator()<<endl;
//	cout << Monitor::getNrGenerator() << endl;
//}