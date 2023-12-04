//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Interfata {
//	virtual string vorbeste() = 0;
//	virtual string ceMananca() = 0;
//};
//
//class Animal {
//private:
//	int nrPicioare;
//	float greutate;
//	int varsta;
//public:
//
//	Animal() {
//		this->nrPicioare = 4;
//		this->greutate = 1;
//		this->varsta = 1;
//	}
//	Animal(int nrPicioare, float greutate, int varsta) {
//		this->nrPicioare = nrPicioare;
//		this->greutate = greutate;
//		this->varsta = varsta;
//	}
//
//	Animal(const Animal& a) {
//		this->nrPicioare = a.nrPicioare;
//		this->greutate = a.greutate;
//		this->varsta = a.varsta;
//	}
//
//	void metodaImplementata() {
//
//	}
//
//	virtual string vorbeste() = 0;
//	virtual string ceMananca() = 0;
//};
//
//class Caine :public Animal {
//public:
//	Caine() :Animal() {
//
//	}
//	Caine(int nrPicioare, float greutate, int varsta) :Animal(nrPicioare, greutate, varsta) {
//
//	}
//
//	Caine(const Caine& caine) :Animal(caine) {
//
//	}
//	string vorbeste() {
//		return "Ham ham";
//	}
//	string ceMananca() {
//		return "Oase";
//	}
//};
//
//class Pisica :public Animal {
//private:
//	string nume;
//public:
//	Pisica() :Animal() {
//		this->nume = "Tommy";
//	}
//	Pisica(string nume, int nrPicioare, float greutate, int varsta) :Animal(nrPicioare, greutate, varsta) {
//		this->nume = nume;
//	}
//	string vorbeste() {
//		return "Miau miau";
//	}
//	string ceMananca() {
//		return "Peste";
//	}
//};
//
//
//
//void main() {
//	Animal* pet=new Pisica();
//	cout << pet->ceMananca();
//	cout << pet->vorbeste();
//
//	
//}