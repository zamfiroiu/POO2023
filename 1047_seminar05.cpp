//#include<iostream>
//
//using namespace std;
//
//class Monitor {
//	private:
//	static int nrGenerator;
//	const int nrInventar;
//	string producator;
//	float rezolutie;
//	int nrPorturi;
//	string* numePorturi;
//public:
//	static int getNrGenerator() {
//		return Monitor::nrGenerator;
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
//	Monitor( const Monitor &p):nrInventar(nrGenerator++) {
//		this->producator = p.producator;
//		this->rezolutie = p.rezolutie;
//		this->nrPorturi = p.nrPorturi;
//		this->numePorturi = new string[p.nrPorturi];
//		for (int i = 0; i < p.nrPorturi; i++) {
//			this->numePorturi[i] = p.numePorturi[i];
//		}
//		
//	}
//
//	Monitor operator=(const Monitor & p){
//		if (this != &p) {
//			this->producator = p.producator;
//			this->rezolutie = p.rezolutie;
//			this->nrPorturi = p.nrPorturi;
//			if (this->numePorturi != NULL) {
//				delete[]this->numePorturi;
//			}
//			this->numePorturi = new string[p.nrPorturi];
//			for (int i = 0; i < p.nrPorturi; i++) {
//				this->numePorturi[i] = p.numePorturi[i];
//			}
//		}
//		return *this;
//	}
//
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
//	float getRezolutie() {
//		return rezolutie;
//	}
//
//	void setRezolutie(float rezolutie) {
//		if (rezolutie > 0) {
//			this->rezolutie = rezolutie;
//		}
//
//	}
//
//	int getNrInventar() {
//		return nrInventar;
//	}
//
//	void setPorturi(int nrPorturi, string* numePorturi) {
//		if (nrPorturi > 0) {
//			this->nrPorturi = nrPorturi;
//			if (this->numePorturi != NULL) {
//				delete[]this->numePorturi;
//			}
//			this->numePorturi = new string[nrPorturi];
//			for (int i = 0; i < nrPorturi; i++) {
//				this->numePorturi[i] = numePorturi[i];
//			}
//		}
//	}
//	string* getnumePorturi() {
//		return numePorturi;
//	}
//	string getNumePort(int i) {
//		if (i >= 0 && i < nrPorturi)
//		{
//			return numePorturi[i];
//		}
//	}
//	friend string getSirPorturi(const Monitor& m);
//};
//int Monitor::nrGenerator = 1000;
//
//string getSirPorturi(const Monitor& m) {
//	string aux = "";
//	for (int i = 0; i < m.nrPorturi; i++) {
//		aux += m.numePorturi[i]+",";
//	}
//	return aux;
//}
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
//
//	Monitor m1 = monitor2;
//	Monitor m2(monitor2);
//	monitor2.afisareMonitor();
//
//	m1 = monitor2;
//	m1.afisareMonitor();
//
//	
//	cout<<m1.getRezolutie()<<endl;
//	m1.setRezolutie(20.4);
//	cout << m1.getRezolutie()<<endl;
//
//	cout << m1.getNrInventar();
//
//	string* vector = new string[2]{ "USB","PS2" };
//	m1.setPorturi(2, vector);
//	m1.afisareMonitor();
//	cout << *m1.getnumePorturi() << endl;
//	//cout << *(m1.getnumePorturi()+1);
//	cout << m1.getnumePorturi()[1] << endl;
//	cout << m1.getNumePort(1);
//	delete[]vector;
//
//	cout << getSirPorturi(m1);
//}