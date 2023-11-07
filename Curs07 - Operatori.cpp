//#include<iostream>
//
//using namespace std;
//
//class Scara {
//private:
//	//char* culoare;
//	static float gravitatie;
//	const int id;
//public:
//	int nrTrepte;
//	float* latimeTrepte;
//public:
//	float inaltime;
//	float greutate;
//	bool rulanta;
//
//	class Treapta {
//	private:
//		int greutateTreapta;
//	public:
//		string culoare;
//	};
//
//	float* getLatimeTrepte() {
//		return this->latimeTrepte;
//	}
//
//	float& operator[](int index) {
//		if (index >= 0 && index < this->nrTrepte) {
//			return this->latimeTrepte[index];
//		}
//		else {
//			//todo: aruncam exceptie;
//		}
//	}
//
//	void afiseazaActiune() {  //afiseazaActiune(Scara* this)
//		if (this->rulanta == true) {
//			cout << "Scara este rulanta";
//		}
//		else {
//			cout << "Trebuie sa urci la pas!";
//		}
//	}
//
//	static void schimbaGravitatie(float nouaG) {
//		gravitatie = nouaG;
//	}
//	Scara() : nrTrepte(10), inaltime(2),
//		greutate(5),rulanta(false),id(0){
//		this->latimeTrepte = new float[nrTrepte];
//		for (int i = 0; i < nrTrepte; i++) {
//			this->latimeTrepte[i] = nrTrepte - i;
//		}
//	}
//
//	Scara(int nrTrepte, int inaltime):id(0) {
//		this->nrTrepte = nrTrepte;
//		this->inaltime = inaltime;
//		this->greutate = 5;
//		this->rulanta = false;
//		this->latimeTrepte = new float[nrTrepte];
//		for (int i = 0; i < nrTrepte; i++) {
//			this->latimeTrepte[i] = nrTrepte - i;
//		}
//	}
//
//
//	Scara(float nouaGreutate,int inaltimeS):nrTrepte(10),
//		inaltime(inaltimeS),greutate(nouaGreutate),
//		rulanta(false),id(0) {
//		this->latimeTrepte = new float[nrTrepte];
//		for (int i = 0; i < nrTrepte; i++) {
//			this->latimeTrepte[i] = nrTrepte - i;
//		}
//	}
//
//	Scara(int nrTrepte, float inaltime, const int idNou, float* latime):id(idNou) {
//		this->nrTrepte = nrTrepte;
//		this->inaltime = inaltime;
//		this->greutate = 5;
//		this->rulanta = false;
//		this->latimeTrepte = new float[nrTrepte];
//		for (int i = 0; i < nrTrepte; i++) {
//			this->latimeTrepte[i] = latime[i];
//		}
//	}
//
//	 Scara(const Scara &s):id(s.id) {
//		this->nrTrepte = s.nrTrepte;
//		this->inaltime = s.inaltime;
//		this->greutate = s.greutate;
//		this->rulanta = s.rulanta;
//		this->latimeTrepte = new float[this->nrTrepte];
//		for (int i = 0; i < this->nrTrepte; i++) {
//			this->latimeTrepte[i] = s.latimeTrepte[i];
//		}
//	}
//
//
//	 Scara& operator=(const Scara& s2) {
//		 if (this != &s2) {
//			 this->nrTrepte = s2.nrTrepte;
//			 this->inaltime = s2.inaltime;
//			 this->greutate = s2.greutate;
//			 this->rulanta = s2.rulanta;
//			 if (this->latimeTrepte != NULL) {
//				 delete[]this->latimeTrepte;
//			 }
//			 this->latimeTrepte = new float[this->nrTrepte];
//			 for (int i = 0; i < this->nrTrepte; i++) {
//				 this->latimeTrepte[i] = s2.latimeTrepte[i];
//			 }
//		 }
//		 return *this;
//	 }
//
//
//	~Scara() {
//		if (this->latimeTrepte != NULL) {
//			delete[]this->latimeTrepte;
//		}
//	}
//
//	int getNrTrepte() {
//		return this->nrTrepte;
//	}
//
//	void setNrTrepte(int nrTrepte) {
//		if (nrTrepte = 2) {
//			this->nrTrepte = nrTrepte;
//		}
//	}
//
//	Scara operator+(Scara s) {
//		Scara aux = *this;
//		aux.inaltime = this->inaltime + s.inaltime;
//		aux.greutate = this->greutate + s.greutate;
//		aux.nrTrepte = this->nrTrepte + s.nrTrepte;
//		if (aux.latimeTrepte != NULL) {
//			delete[]aux.latimeTrepte;
//		}
//		aux.latimeTrepte = new float[aux.nrTrepte];
//		for (int i = 0;i< this->nrTrepte; i++) {
//			aux.latimeTrepte[i] = this->latimeTrepte[i];
//		}
//		for (int i = this->nrTrepte; i < aux.nrTrepte; i++) {
//			aux.latimeTrepte[i] = s.latimeTrepte[i-this->nrTrepte];
//		}
//
//		return aux;
//	}
//
//	Scara operator+=(const Scara& s) {
//		this->inaltime += s.inaltime;
//		this->greutate += s.greutate;
//		int auxNrTrepte = this->nrTrepte + s.nrTrepte;
//		float* auxLatimeTrepte = new float[auxNrTrepte];
//		for (int i = 0; i < this->nrTrepte; i++) {
//			auxLatimeTrepte[i] = this->latimeTrepte[i];
//		}
//		for (int i = this->nrTrepte; i < auxNrTrepte; i++) {
//			auxLatimeTrepte[i] = s.latimeTrepte[i - this->nrTrepte];
//		}
//		this->nrTrepte = auxNrTrepte;
//		if (this->latimeTrepte != NULL) {
//			delete[]this->latimeTrepte;
//		}
//		this->latimeTrepte = auxLatimeTrepte;
//		return *this;
//	}
//
//	Scara operator+(int greutate) const {
//		Scara aux = *this;
//		aux.greutate = this->greutate + greutate;
//		return aux;
//	}
//
//	friend Scara operator+(int greutate, const Scara& s) {
//		Scara aux = s;
//		aux.greutate = s.greutate + greutate;
//		return aux;
//	}
//
//	bool operator>(Scara s) {
//		return this->greutate > s.greutate && this->inaltime > s.inaltime;
//	}
//	bool operator>=(Scara s) {
//		return this->greutate >= s.greutate;
//	}
//	bool operator<(Scara s) {
//		return this->greutate < s.greutate;
//	}
//
//	//
//
//	////int nrTrepte;
//	//float* latimeTrepte;
//
//	friend ostream& operator<<(ostream& monitor, const Scara &s) {
//		monitor << "Inaltime: " << s.inaltime << " ";
//		monitor << "Greutate: " << s.greutate<<endl;
//		monitor << "Nr trepte" <<s.nrTrepte<< endl;
//		monitor << "Latimea acestora: ";
//		for (int i = 0; i < s.nrTrepte; i++) {
//			monitor << s.latimeTrepte[i] << ", ";
//		}
//		monitor << endl;
//		monitor << (s.rulanta ? "Scara este rulanta" : "Scara de piatra");
//		return monitor;
//	}
//
//	friend istream& operator>>(istream& tastatura, Scara& s) {
//		//char aux[100];
//		//cout << "culoare:";
//		//tastatura >> aux;
//		//if (s.culoare != NULL) {
//		//	delete[]s.culoare;
//		//}
//		//s.culoare = new char[strlen(aux) + 1];
//		//strcpy_s(s.culoare, strlen(aux) + 1, aux);
//
//		cout << "Inaltime:";
//		tastatura >> s.inaltime;
//		cout << "greutate: ";
//		tastatura >> s.greutate;
//		cout << "cate trepte avem:";
//		tastatura >> s.nrTrepte;
//		if (s.latimeTrepte != NULL) {
//			delete[]s.latimeTrepte;
//		}
//		s.latimeTrepte = new float[s.nrTrepte];
//		for (int i = 0; i < s.nrTrepte; i++) {
//			cout << "latimea treptei " << i + 1 << ":";
//			tastatura >> s.latimeTrepte[i];
//		}
//		cout << "Este rulanta: 0- NU, orice altceva -DA";
//		tastatura >> s.rulanta;
//		return tastatura;
//	}
//
//	//pre
//	Scara operator++() {
//		this->inaltime += 10;
//		return *this;
//	}
//
//	Scara operator++(int) {
//		Scara stareInitiala = *this;
//		this->inaltime += 10;
//		return stareInitiala;
//	}
//
//	explicit operator int() {
//		return this->nrTrepte;
//	}
//
//	explicit operator float() {
//		return this->inaltime;
//	}
//
//	operator double() {
//		float suma = 0;
//		for (int i = 0; i < this->nrTrepte; i++) {
//			suma += this->latimeTrepte[i];
//		}
//		if (this->nrTrepte > 0) {
//			return suma / this->nrTrepte;
//		}
//		else {
//			return 0;
//		}
//	}
//
//	float operator()() {
//		float s = 0;
//		for (int i = 0; i < this->nrTrepte; i++) {
//			s += this->latimeTrepte[i];
//		}
//
//		return s;
//	}
//
//	float operator()(int start, int stop) {
//		if (start >= 0 && start < this->nrTrepte &&
//			stop >= 0 && stop < this->nrTrepte &&
//			start < stop) {
//
//			float s = 0;
//			for (int i = start; i < stop; i++) {
//				s += this->latimeTrepte[i];
//			}
//			return s;
//		}
//		else {
//			return 0;
//		}
//	}
//
//	float operator()(int stop) {
//		//return (*this)(0, stop);
//		//return this->operator()(0, stop);
//
//		Scara aux = *this;
//		return aux(0, stop);
//	}
//
//	Scara operator!() const{
//		Scara aux = *this;
//		aux.rulanta = !aux.rulanta;
//		return aux;
//	}
//
//
//};
//float Scara::gravitatie = 9.81;
//
//void functie1(const Scara& scara) {
//
//}
//
//Scara& functie2() {
//	Scara s;
//
//	return s;
//}
//
//
//class Muncitor {
//public:
//	string nume;
//	Scara scara;
//
//	void folosesteScara() {
//		scara.nrTrepte;
//	}
//};
//
//void main() {
//	//Scara scara(5.3f);
//	float* latimeTrepte = new float[2] {30, 45};
//	Scara scara2(2,4,100,latimeTrepte);
//
//
//
//	{
//		Scara scara3;
//	}
//	Scara* scari = new Scara[10];
//
//	delete[]scari;
//
//
//
//	//scara.nrTrepte = 10;
//	scara2.afiseazaActiune();
//	Scara::schimbaGravitatie(9.9);
//
//	Scara scara4 = scara2;
//	scara4.latimeTrepte[0] = 20;
//	scara2.latimeTrepte[0] = 80;
//	cout <<endl<< scara4.latimeTrepte[0];
//
//
//	Scara scara5;
//
//	scara5 = scara2;
//	scara5.operator=(scara2);
//
//	int i, j;
//	i = j = 0;
//
//	scara4 = scara5 = scara2;
//
//	scara2 = scara2;
//
//	Scara::Treapta treapta;
//	Muncitor muncitor;
//	muncitor.scara.nrTrepte=9;
//
//	int a1 = 7;
//	int a2 = 8;
//	int rezultat = a1 + a2;
//
//	scara5 = scara2 + scara4;
//	scara5.afiseazaActiune();
//	scara5 = scara2 + 10;
//	scara5.afiseazaActiune();
//	scara5 = 10 + scara2;
//	scara2 += scara5;
//
//	cout << scara2;
//	cin >> scara2;
//	cout << scara2;
//
//	scara5 = ++scara2;
//	scara5 = scara2++;
//
//	cout << scara5.getLatimeTrepte()[1];
//	cout << scara5[1];
//	scara5[1] = 50;
//
//	cout << scara5;
//
//	//*operator<< - de terminat
//	//*operator>>
//	//*operator++
//	//*operator[]
//	//*operator de cast
//	//operator!
//	//operator()
//
//	int valIntreg = 10;
//	float valReala = valIntreg;
//	valReala = 10.8;
//	valIntreg = valReala;
//
//	valIntreg = (int)scara5;//nrTrepte
//	valReala = (float)scara5;//inaltime
//	double valDouble = scara5;//latime medie
//
//	cout << valIntreg << endl << valReala << endl << valDouble << endl;
//
//	cout<<scara5();
//	cout<<scara5(2);
//	cout<<scara5(1, 4);
//
//	scara2 = !scara5;
//	cout << !scara5;
//}