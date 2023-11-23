//#include<iostream>
//#include<fstream>
//using namespace std;
// 
//class Padure {
//private:
//
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
//	explicit operator float() {
//		float aux = 0;
//		if(nrCopaci>0)
//		{
//			for (int i = 0; i < nrCopaci; i++)
//				aux = aux + varsteCopaci[i];
//			aux = aux / nrCopaci;
//		}
//		return aux;
//	}
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
//	operator string(){
//		return this->nume;
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
//
//	Padure operator++()
//	{
//		for (int i = 0; i < this->nrCopaci; i++)
//		{
//			this->varsteCopaci[i]++;
//		}
//		return *this;
//	}
//
//	Padure operator++(int)
//	{
//		Padure aux = *this;
//		for (int i = 0; i < this->nrCopaci; i++)
//		{
//			this->varsteCopaci[i]++;
//		}
//		return aux;
//	}
//
//	int& operator[](int index) {
//		if (index >= 0 && index < this->nrCopaci) {
//			return this->varsteCopaci[index];
//		}
//		else throw 404;
//	}
//	Padure operator+=(int varsta) {
//		int* varsteCopaci = new int[nrCopaci + 1];
//		for (int i = 0; i < nrCopaci; i++) {
//			varsteCopaci[i] = this->varsteCopaci[i];
//		}
//		varsteCopaci[nrCopaci] = varsta;
//		nrCopaci++;
//		if (this->varsteCopaci != NULL) {
//			delete[]this->varsteCopaci;
//		}
//		this->varsteCopaci = varsteCopaci;
//		return *this;
//	}
//	friend ofstream& operator<<(ofstream& fisier, const Padure& padure) {
//		fisier << padure.getNume() << endl << padure.gradDefrisare<<endl<< padure.nrCopaci <<endl;
//		if (padure.varsteCopaci != NULL) {
//			for (int i = 0; i < padure.nrCopaci; i++) {
//				fisier << padure.varsteCopaci[i] << " ";
//			}
//		}
//		fisier << endl;
//		return fisier;
//}
//	friend ifstream& operator>>(ifstream& mouse, Padure& padure) {
//		int a;
//		mouse >> padure.nume;
//		mouse >> a;
//		mouse >> padure.nrCopaci;
//		if (padure.varsteCopaci != NULL)
//		{
//			delete[]padure.varsteCopaci;
//		}
//		if (padure.nrCopaci > 0)
//		{
//			padure.varsteCopaci = new int[padure.nrCopaci];
//			for (int i = 0; i < padure.nrCopaci; i++) {
//				
//				mouse >> padure.varsteCopaci[i];
//			}
//		}
//		else {
//			
//			padure.varsteCopaci = NULL;
//		}
//		return mouse;
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
//class TaraCuPaduri {
//private:
//	int nrPaduri;
//	Padure* paduri;
//
//public:
//	TaraCuPaduri() {
//		this->nrPaduri = 3;
//		this->paduri = new Padure[3];
//	}
//
//	Padure& operator[](int index) {
//		if (index >= 0 && index < this->nrPaduri) {
//			return this->paduri[index];
//		}
//	}
//	~TaraCuPaduri() {
//		if (this->paduri) {
//			delete[]this->paduri;
//		}
//	}
//
//};
//
//void main() {
//
//	/*TaraCuPaduri tara;
//	Padure padure;
//	cin >> padure;
//	tara[1] = padure;
//	cout << tara[1].getNume()<<endl;
//	cout << tara[1][0]<<endl;*/
//	//Padure padure;
//	/*cin >> padure;
//	ofstream g("Padure.txt", ios::app);
//	g << padure;
//	g.close();*/
//	//ifstream f("Padure.txt", ios::in);
//	//f >> padure;
//	//cout << padure;
//	//f >> padure;
//	//cout << padure;
//	
//	int valoareIntreaga = 20;
//	char sir[40] = "text salvat in fisier binar";
//
//	//fstream fis("fisier.bin", ios::out | ios::binary);
//	////metoda gresita de scriere in fisiere binare
//	////fis << valoareIntreaga << sir;
//
//	////metoda corecta de scriere in fisiere binare
//	//fis.write((char*)&valoareIntreaga, sizeof(int));
//	//int lungime = strlen(sir) + 1;
//	//fis.write((char*)&lungime, sizeof(int));
//	//fis.write((char*)sir, lungime);
//
//	//fis.close();
//
//	/*fstream citire("fisier.bin", ios::binary | ios::in);
//	citire.read((char*)&valoareIntreaga, sizeof(int));
//	int lungime;
//	citire.read((char*)&lungime, sizeof(int));
//	char* pSir = new char[lungime];
//	citire.read((char*)pSir, lungime);
//
//	citire.close();
//	cout << pSir << " " << valoareIntreaga << endl;
//
//	delete[]pSir;*/
//
//
//	Padure p;
//	cin >> p;
//	fstream f("paduri.bin", ios::binary | ios::out);
//
//	//metoda  1 gresita de scriere a unui obiect in fisier binar
//	//f << p;
//
//	//metoda  2 gresita de scriere a unui obiect in fisier binar
//	f.write((char*)&p, sizeof(Padure));
//	f.close();
//
//
//	fstream g("paduri.bin", ios::binary | ios::in);
//
//	//metoda gresita de citire a unui obiect din fisier binar
//	Padure p2;
//	g.read((char*)&p2, sizeof(Padure));
//	cout << p2;
//
//	//pentru obiecte trebuie realizate metode de scriere si citire din fisiere binare
//	//in aceste metode trebuie scrise/citite atribute individual
//}