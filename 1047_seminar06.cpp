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
//	static int getNrGenerator()  {
//		return Monitor::nrGenerator;
//	}
//
//
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
//	
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
//	float getRezolutie() const {
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
//	int getNrInventar() const {
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
//	string* getnumePorturi() const {
//		return numePorturi;
//	}
//	string getNumePort(int i) const {
//		if (i >= 0 && i < nrPorturi)
//		{
//			return numePorturi[i];
//		}
//	}
//
//	string& operator[](int i) {
//		if (i >= 0 && i < nrPorturi)
//		{
//			return numePorturi[i];
//		}
//	}
//
//	friend string getSirPorturi(const Monitor& m);
//	friend ostream& operator<<(ostream& ecran, const Monitor& m);
//	friend istream& operator>>(istream& intr, Monitor& m) {
//		cout << "Introduceti producatorul: ";
//		intr >> m.producator;
//		cout << "Rezolutie: ";
//		intr >> m.rezolutie;
//		cout << "Numarul de porturi: ";
//		intr >> m.nrPorturi;
//		cout << "Numele porturilor: ";
//		if (m.numePorturi != NULL) {
//			delete[]m.numePorturi;
//		}
//		m.numePorturi = new string[m.nrPorturi];
//		for (int i = 0; i < m.nrPorturi; i++) {
//			intr >> m.numePorturi[i];
//		}
//		return intr;
//	}
//
//	Monitor operator+=(const Monitor& m) {
//		int aux = this->nrPorturi;
//		this->nrPorturi += m.nrPorturi;
//		string* vector = new string[this->nrPorturi];
//		for (int i = 0; i < aux; i++) {
//			vector[i] = this->numePorturi[i];
//		}
//		for (int i = aux; i < this->nrPorturi; i++) {
//			vector[i] = m.numePorturi[i - aux];
//		}
//		if (this->numePorturi != NULL) {
//			delete[]this->numePorturi;
//		}
//		this->numePorturi = vector;
//		return *this;
//	}
//
//	bool operator!=(const Monitor& m) {
//		return this->rezolutie != m.rezolutie && this->nrPorturi != m.nrPorturi;
//	}
//};
//int Monitor::nrGenerator = 1000;
//
//ostream& operator<<(ostream& ecran, const Monitor& m) {
//
//	ecran << "Monitorul de la producatorul:" << m.producator << " are o rezolutie de: " << m.getRezolutie() << " si un numar porturi de:" << m.nrPorturi << " cu denumirile: ";
//	if (m.nrPorturi > 0) {
//		for (int i = 0; i < m.nrPorturi; i++) {
//			ecran << m.numePorturi[i] << " ";
//		}
//	}
//	else {
//		ecran << "NA";
//	}
//	ecran << endl;
//	return ecran;
//}
//
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
//	
//	string* numePorturi=new string[3];
//	numePorturi[0] = "VGA";
//	numePorturi[1] = "DVI";
//	numePorturi[2] = "HDMI";
//
//	Monitor monitor2("Acer", 24, 3, numePorturi);
//	cout << monitor1<<monitor2;
//	cin >> monitor1;
//	cout << monitor1;
//
//	monitor1 += monitor2;
//	cout << monitor1 << endl;;
//	
//	if (monitor1 != monitor1) {
//		cout << "DIFERITE";
//	}
//	else
//		cout << "EGALE";
//
//	cout << monitor1.getNumePort(2) << endl;
//	cout << monitor1[2]<< endl;
//	monitor1[2] = "PS2";
//	cout << monitor1[2] << endl;
//}