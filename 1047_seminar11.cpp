//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<fstream>
//
//using namespace std;
//
//
////clasa abastracta - nu poate fi instantiata
////folosita doar pentru mostenire
////Design By Contract
////reference type
//
//class Dispozitiv {
//	string nume;
//public:
//	virtual void descrieDispozitiv() = 0;
//
//	Dispozitiv() {
//		this->nume = "Nume dispozitiv";
//	}
//
//	string getNume() {
//		return this->nume;
//	}
//
//	void setNume(string nume) {
//		if (nume.length() > 3) {
//			this->nume = nume;
//		}
//	}
//};
//
//class Tastatura : public Dispozitiv {
//	int nrTaste;
//	char* tipTastatura;
//public:
//	Tastatura() : Dispozitiv() {
//		this->nrTaste = 104;
//		tipTastatura = new char[strlen("qwerty") + 1];
//		strcpy(this->tipTastatura, "qwerty");
//	}
//	Tastatura(int nrTaste, const char* tipTastatura) : Dispozitiv() {
//		this->nrTaste = nrTaste;
//		this->tipTastatura = new char[strlen(tipTastatura) + 1];
//		strcpy(this->tipTastatura , tipTastatura);
//	}
//	Tastatura(const Tastatura &t) : Dispozitiv(t) {
//		this->nrTaste = t.nrTaste;
//		this->tipTastatura = new char[strlen(t.tipTastatura) + 1];
//		strcpy(this->tipTastatura, t.tipTastatura);
//	}
//	Tastatura operator= (const Tastatura& t) {
//		if (this != &t) {
//			Dispozitiv::operator=(t);
//			this->nrTaste = t.nrTaste;
//			if (this->tipTastatura != NULL)
//				delete[] this->tipTastatura;
//			this->tipTastatura = new char[strlen(t.tipTastatura) + 1];
//			strcpy(this->tipTastatura, t.tipTastatura);
//		}
//		return *this;
//	}
//	void descrieDispozitiv() {
//		cout << "Tastatura de tip " << this->tipTastatura <<
//			"are " << this->nrTaste << " taste" << endl;
//	}
//	~Tastatura() {
//		delete[] this->tipTastatura;
//	}
//};
//
//class Monitor: public Dispozitiv {
//	private:
//	static int nrGenerator;
//	const int nrInventar;
//	string producator;
//	float rezolutie;
//	int nrPorturi;
//	string* numePorturi;
//public:
//
//	static int getNrGenerator()  {
//		return Monitor::nrGenerator;
//	}
//
//	void descrieDispozitiv() {
//		cout << "Monitorul produs de " << this->producator << " are " << this->nrPorturi << " porturi." << endl;
//	}
//
//	Monitor():Dispozitiv(), nrInventar(nrGenerator++){
//		this->producator = "Acer";
//		this->rezolutie = 24;
//		this->nrPorturi = 0;
//		this->numePorturi = NULL;
//	}
//
//	Monitor(string producator, float rezolutie) :
//		Dispozitiv(),nrInventar(nrGenerator) {
//		nrGenerator++;
//		this->producator = producator;
//		this->rezolutie = rezolutie;
//		this->nrPorturi = 0;
//		this->numePorturi = NULL;
//	}
//
//	Monitor(string producator, float rezolutie, int nrPorturi,		string* numePorturi):Dispozitiv(), nrInventar(nrGenerator) {
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
//	Monitor( const Monitor &p):Dispozitiv(p), nrInventar(nrGenerator++) {
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
//			Dispozitiv::operator=(p);
//			/////(Dispozitiv)*this = (Dispozitiv)p;
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
//	friend ofstream& operator<<(ofstream& ecran, const Monitor& m) {
//
//		ecran << m.producator << endl;
//		ecran << m.getRezolutie() << endl;  
//		ecran << m.nrPorturi <<endl;
//		if (m.nrPorturi > 0) {
//			for (int i = 0; i < m.nrPorturi; i++) {
//				ecran << m.numePorturi[i] << " ";
//			}
//			
//		}
//		ecran << endl;
//		return ecran;
//	}
//	friend ifstream& operator>>(ifstream& intr, Monitor& m) {
//		intr >> m.producator;
//		intr >> m.rezolutie;
//		intr >> m.nrPorturi;
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
//	
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
//class Sistem {
//	int nrDispozitive;
//	Dispozitiv** dispozitive;
//public:
//	Sistem() {
//		this->nrDispozitive = 4;
//		this->dispozitive = new Dispozitiv * [4];
//		for (int i = 0; i < 4; i++) {
//			this->dispozitive[i] = new Tastatura;
//		}
//	}
//	Dispozitiv* & operator[](int i){
//		if(i>=0&&i<this->nrDispozitive)
//		return this->dispozitive[i];
//	}
//};
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
////void utilizareDispozitiv(Dispozitiv* d) {
////	d->descrieDispozitiv();
////}
////
////void utilizareTastatura(Tastatura* t) {
////	t->descrieDispozitiv();
////}
//
//void main() {
//	//o clasa abstracta nu poate fi instantiata
//	//Dispozitiv d;
//
//	/*Monitor m;
//	
//	Tastatura t1(105, "azerty");
//	t1.descrieDispozitiv();
//
//	Dispozitiv* d;
//	d = new Monitor();
//	d->descrieDispozitiv();*/
//
//	Sistem s1;
//	s1[0] = new Tastatura(110, "qwerty");
//	s1[1] = new Monitor("ACER", 49.6);
//	s1[2] = new Monitor("HP", 90.2);
//	s1[3] = new Tastatura(89, "artuy");
//	for (int i = 0; i < 4; i++) {
//		s1[i]->descrieDispozitiv();
//	}
//}