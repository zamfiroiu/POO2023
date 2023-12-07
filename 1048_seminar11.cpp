//#include<iostream>
//#include<fstream>
//
//using namespace std;
//
////clasa care are cel putin un pointer din tabela de pointeri la functii virtuale, egal cu NULL, devine clasa abstracta
////clasa abstracta nu poate fi instantiata
////ReferenceType
////Design by contract
//class City {
//public:
//	virtual void printCity() = 0;
//};
//
//class Oras: public City {
//private:
//	const int id;
//	static string planeta;
//	string nume;
//	int populatie;
//	float suprafata;
//	int* varsteLocuitori;
//public:
//	void printCity() {
//		cout << "Orasul " << this->nume << " are " << this->populatie << " locuitori." << endl;
//	}
//
//	Oras() : id(1) {
//		this->nume = "NoName";
//		this->populatie = 0;
//		this->suprafata = 100;
//		this->varsteLocuitori = NULL;
//	}
//	Oras(string nume, float suprafata) : id(4)
//	{
//		this->nume = nume;
//		this->populatie = 0;
//		this->suprafata = suprafata;
//		this->varsteLocuitori = NULL;
//
//	}
//	Oras(int id, string nume, int populatie, float suprafata, int* varsteLocuitori) : id(id) {
//		this->nume = nume;
//		this->suprafata = suprafata;
//		if (populatie > 0) {
//			this->populatie = populatie;
//			this->varsteLocuitori = new int[populatie];
//			for (int i = 0; i < populatie; i++)
//			{
//				this->varsteLocuitori[i] = varsteLocuitori[i];
//			}
//		}
//		else {
//			this->populatie = 0;
//			this->varsteLocuitori = NULL;
//		}
//	}
//	Oras(const Oras& oras) : id(oras.id) {
//		this->nume = oras.nume;
//		this->populatie = oras.populatie;
//		this->suprafata = oras.suprafata;
//		this->varsteLocuitori = new int[populatie];
//		for (int i = 0; i < populatie; i++) {
//			this->varsteLocuitori[i] = oras.varsteLocuitori[i];
//		}
//	}
//
//	const Oras& operator= (const Oras& oras) {
//		if (this != &oras) {
//			if (this->varsteLocuitori != NULL)
//				delete[]this->varsteLocuitori;
//			this->nume = oras.nume;
//			this->populatie = oras.populatie;
//			this->suprafata = oras.suprafata;
//			this->varsteLocuitori = new int[populatie];
//			for (int i = 0; i < populatie; i++) {
//				this->varsteLocuitori[i] = oras.varsteLocuitori[i];
//			}
//		}
//		return *this;
//	}
//
//	Oras operator+(const Oras& oras) {
//		Oras aux;
//		aux.nume = this->nume;
//		aux.populatie = this->populatie + oras.populatie;
//		aux.suprafata = this->suprafata + oras.suprafata;
//		if (aux.varsteLocuitori != NULL)
//			delete[]aux.varsteLocuitori;
//		aux.varsteLocuitori = new int[this->populatie + oras.populatie];
//		for (int i = 0; i < this->populatie; i++)
//			aux.varsteLocuitori[i] = this->varsteLocuitori[i];
//		for (int j = this->populatie; j < aux.populatie; j++)
//			aux.varsteLocuitori[j] = oras.varsteLocuitori[j - this->populatie];
//		return aux;
//	}
//
//	~Oras() {
//		if (this->varsteLocuitori != NULL) {
//			delete[]this->varsteLocuitori;
//		}
//	}
//
//	float getVarstaMedie() {
//		int suma = 0;
//		if (this->populatie == 0)
//			return 0;
//		for (int i = 0; i < this->populatie; i++)
//			suma = suma + this->varsteLocuitori[i];
//		return suma / (float)populatie;
//	}
//
//	int getPopulatie() {
//		return this->populatie;
//	}
//
//	void addNouLocuitor(int varsta) {
//
//		int* aux = new int[this->populatie + 1];
//		for (int i = 0; i < this->populatie; i++)
//			aux[i] = this->varsteLocuitori[i];
//		aux[this->populatie] = varsta;
//
//		delete[]this->varsteLocuitori;
//		this->varsteLocuitori = aux;
//
//		this->populatie++;
//
//	}
//	void addNouNascut() {
//
//		addNouLocuitor(0);
//
//	}
//
//	void afisare() {
//		int i;
//		cout << "Orasul " << nume << " are id-ul " << id << ", se afla pe planeta " << planeta << ", are populatia de " << populatie << "si o suprafata de " << suprafata << ". Locuitorii orasului au varstele: ";
//		if (populatie == 0)
//			cout << "-";
//		else
//			for (i = 0; i < populatie; i++)
//				cout << varsteLocuitori[i] << " ";
//		cout << endl;
//
//	}
//
//	static void setPlaneta(string planeta) {
//		Oras::planeta = planeta;
//	}
//
//	static string getPlaneta()
//	{
//		return Oras::planeta;
//	}
//
//	void setNume(string nume) {
//		if (nume.length() > 3)
//			this->nume = nume;
//	}
//
//	string getNume()const
//	{
//		return this->nume;
//	}
//
//	int getId()
//	{
//		return this->id;
//	}
//
//	void setPopulatie(int populatie, int* varste) {
//		if (populatie > 0) {
//			this->populatie = populatie;
//			if (this->varsteLocuitori != NULL) {
//				delete[]this->varsteLocuitori;
//			}
//			varsteLocuitori = new int[this->populatie];
//			for (int i = 0; i < populatie; i++) {
//				this->varsteLocuitori[i] = varste[i];
//			}
//		}
//	}
//
//	int* getVarsteLocuitori() {
//		return varsteLocuitori;
//	}
//
//	int getVarstaLocuitor(int index) {
//		if (index >= 0 && index < this->populatie) {
//			return this->varsteLocuitori[index];
//		}
//	}
//
//	int& operator[](int index) {
//		if (index >= 0 && index < this->populatie) {
//			return this->varsteLocuitori[index];
//		}
//		else {
//			throw 404;
//		}
//	}
//	friend ofstream& operator<<(ofstream& out, const Oras& oras);
//	friend ostream& operator<<(ostream& out, const Oras& oras);
//	friend istream& operator>>(istream& in, Oras& oras)
//	{
//		cout << "Nume:";
//		in >> oras.nume;
//		cout << "\n Populatie:";
//		in >> oras.populatie;
//		cout << " \nSuprafata:";
//		in >> oras.suprafata;
//		if (oras.varsteLocuitori != NULL)
//		{
//			delete[]oras.varsteLocuitori;
//		}
//		oras.varsteLocuitori = new int[oras.populatie];
//		for (int i = 0; i < oras.populatie; i++)
//		{
//			cout << " Varsta locuitorului" << i + 1 << " : ";
//			in >> oras.varsteLocuitori[i];
//
//		}
//		return in;
//	}
//
//	operator int() {
//		return this->populatie;
//	}
//
//	explicit operator float() {
//		if (this->populatie == 0)
//		{
//			throw exception("Populatia este 0 !");
//		}
//		float s = 0;
//		for (int i = 0; i < this->populatie; i++)
//			s += this->varsteLocuitori[i];
//		return s / this->populatie;
//	}
//
//	float operator()()
//	{
//		if (suprafata == 0)
//		{
//			throw exception("Mesaj de eroare !");
//		}
//		return populatie / suprafata;
//	}
//
//	float operator()(int imigranti)
//	{
//		if (suprafata == 0)
//		{
//			throw 1;
//		}
//		return (populatie + imigranti) / suprafata;
//	}
//
//	Oras operator!() {
//		if (suprafata > 0) {
//			suprafata = 0;
//		}
//		else {
//			suprafata = 30;
//		}
//		return *this;
//	}
//	Oras& operator--() {
//		if (this->suprafata > 0) {
//			this->suprafata = this->suprafata - 1;
//		}
//		return *this;
//	}
//	Oras operator--(int n) {
//		Oras aux = *this;
//		if (this->suprafata > 0) {
//			this->suprafata = this->suprafata - 1;
//		}
//		return aux;
//	}
//	friend ifstream& operator>>(ifstream& in, Oras& oras);
//};
//string Oras::planeta = "Pamant";
//ostream& operator<<(ostream& out, const Oras& oras)
//{
//	out << "Orasul " << oras.getNume() << " are id-ul " << oras.id << ", se afla pe planeta " << oras.planeta << ", are populatia de " << oras.populatie << "si o suprafata de " << oras.suprafata << ". Locuitorii orasului au varstele: ";
//	if (oras.populatie == 0)
//		out << "-";
//	else
//		for (int i = 0; i < oras.populatie; i++)
//			out << oras.varsteLocuitori[i] << " ";
//	out << endl;
//	return out;
//}
//
//ofstream& operator<<(ofstream& out, const Oras& oras)
//{
//	out << oras.getNume() << endl << oras.populatie << endl << oras.suprafata << endl;
//
//	for (int i = 0; i < oras.populatie; i++)
//		out << oras.varsteLocuitori[i] << " ";
//	out << endl;
//	return out;
//}
//
//ifstream& operator>>(ifstream& in, Oras& oras) {
//	in >> oras.nume;
//	in >> oras.populatie;
//	in >> oras.suprafata;
//	if (oras.varsteLocuitori != NULL)
//		delete[]oras.varsteLocuitori;
//	oras.varsteLocuitori = new int[oras.populatie];
//	for (int i = 0; i < oras.populatie; i++)
//		in >> oras.varsteLocuitori[i];
//	return in;
//}
//
//class Tara {
//private:
//	int nrOrase;
//	City* *orase;
//public:
//	Tara() {
//		nrOrase = 3;
//		orase = new City*[3];
//		for (int i = 0; i < 3; i++) {
//			this->orase[i] = new Oras();
//		}
//	}
//	City*& operator[](int index) {
//		if (index >= 0 && index < this->nrOrase) {
//			return this->orase[index];
//		}
//		else {
//			throw 404;
//		}
//	}
//};
//
//
//class SmartCity : public Oras {
//private:
//	int varstaTehnologie;
//	char* numeTehnologie;
//public:
//
//	void printCity() {
//		cout << "In acest Smart city avem o tehnolgie de " << this->varstaTehnologie << " ani." << endl;
//	}
//
//	SmartCity() : Oras("SmartCity", 3445) {
//		this->varstaTehnologie = 10;
//		this->numeTehnologie = new char[strlen("Transport public electric") + 1];
//		strcpy_s(this->numeTehnologie, strlen("Transport public electric") + 1, "Transport public electric");
//	}
//
//	SmartCity(int varstaTehnologie, const char* numeTehnologie) :Oras() {
//		this->varstaTehnologie = varstaTehnologie;
//		this->numeTehnologie = new char[strlen(numeTehnologie) + 1];
//		strcpy_s(this->numeTehnologie, strlen(numeTehnologie) + 1, numeTehnologie);
//	}
//	SmartCity(int varstaTehnologie, const char* numeTehnologie, const char* nume, int poulatie, float suprafata, int* varste) :Oras(1, nume, poulatie, suprafata, varste) {
//		this->varstaTehnologie = varstaTehnologie;
//		this->numeTehnologie = new char[strlen(numeTehnologie) + 1];
//		strcpy_s(this->numeTehnologie, strlen(numeTehnologie) + 1, numeTehnologie);
//	}
//	SmartCity(const SmartCity& sc) :Oras(sc) {
//		this->varstaTehnologie = sc.varstaTehnologie;
//		this->numeTehnologie = new char[strlen(sc.numeTehnologie) + 1];
//		strcpy_s(this->numeTehnologie, strlen(sc.numeTehnologie) + 1, sc.numeTehnologie);
//	}
//	SmartCity operator=(const SmartCity& sc) {
//		if (this != &sc) {
//			Oras::operator=(sc);
//			this->varstaTehnologie = sc.varstaTehnologie;
//			if (this->numeTehnologie) {
//				delete[]this->numeTehnologie;
//			}
//			this->numeTehnologie = new char[strlen(sc.numeTehnologie) + 1];
//			strcpy_s(this->numeTehnologie, strlen(sc.numeTehnologie) + 1, sc.numeTehnologie);
//		}
//		return *this;
//	}
//
//	~SmartCity() {
//		if (this->numeTehnologie) {
//			delete[]this->numeTehnologie;
//		}
//	}
//
//	friend ostream& operator<<(ostream& ecran, const SmartCity& sc) {
//		ecran << (Oras)sc;
//		ecran << sc.numeTehnologie << " ";
//		ecran << sc.varstaTehnologie << endl;
//		return ecran;
//	}
//
//	friend istream& operator>>(istream& tast, SmartCity& sc) {
//		tast >> (Oras&)sc;
//		cout << "Varsta tehnologie:";
//		tast >> sc.varstaTehnologie;
//		if (sc.numeTehnologie)
//		{
//			delete[]sc.numeTehnologie;
//		}
//		cout << "Denumire tehnologie:";
//		char buffer[30];
//		tast >> buffer;
//		sc.numeTehnologie = new char[strlen(buffer) + 1];
//		strcpy_s(sc.numeTehnologie, strlen(buffer) + 1, buffer);
//		return tast;
//	}
//	//cate persoane erau nascute cand a fost implementata tehnogia din SmartCity?
//	int calculeazaPersoaneInVarsta() {
//		int nr = 0;
//		for (int i = 0; i < getPopulatie(); i++) {
//			if (getVarstaLocuitor(i) >= varstaTehnologie) {
//				nr++;
//			}
//		}
//
//		return nr;
//	}
//
//};
//
//void functiePrintare(City* p) {
//	p->printCity();
//}
//
//void functiePrintare(SmartCity sc) {
//	sc.printCity();
//}
//
//
//
////void functieScriere() {
////	string* siruri;
////	int nrSiruri = 3;
////	siruri = new string[nrSiruri];
////	siruri[0] = "Salut!";
////	siruri[1] = "Salut! Ce faci?";
////	siruri[2] = "Bine, mersi!";
////
////	fstream f("chat.bin", ios::binary | ios::out);
////	
////	f.write((char*)&nrSiruri, sizeof(int));
////	int lungime=siruri[0].length();
////	f.write((char*)&lungime, sizeof(int));
////	
////}
//
//class Municipiu :public City {
//public:
//	void printCity() {
//		cout << "Acesta este un municipiu.";
//	}
// };
//
//void main()
//{
//	////o clasa abstracta nu poate fi instantiata
//	////City c;
//
//	//City* pc = new Oras();
//	//pc->printCity();
//
//	//City *pc2 = new SmartCity();
//	//pc2->printCity();
//
//	Tara tara;
//	tara[0] = new Oras("Bucuresti", 345);
//	tara[1] = new SmartCity(7, "Senzori pe autobuze");
//	tara[2] = new Municipiu();
//
//	for (int i = 0; i < 3; i++) {
//		tara[i]->printCity();
//	}
//
//}