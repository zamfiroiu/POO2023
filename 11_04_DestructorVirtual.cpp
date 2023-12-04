//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Animal {
//private:
//	char* rasa;
//	int nrPicioare;
//	float greutate;
//	int varsta;
//public:
//
//	Animal() {
//		rasa = NULL;
//		this->nrPicioare = 4;
//		this->greutate = 1;
//		this->varsta = 1;
//	}
//	Animal(const char* rasa, int nrPicioare, float greutate, int varsta) {
//		this->rasa = new char[strlen(rasa) + 1];
//		strcpy(this->rasa, rasa);
//		this->nrPicioare = nrPicioare;
//		this->greutate = greutate;
//		this->varsta = varsta;
//	}
//
//	Animal(const Animal& a) {
//		this->rasa = new char[strlen(a.rasa) + 1];
//		strcpy(this->rasa, a.rasa);
//		this->nrPicioare = a.nrPicioare;
//		this->greutate = a.greutate;
//		this->varsta = a.varsta;
//	}
//
//	Animal& operator=(const Animal& a) {
//		if (this->rasa != NULL) {
//			delete[]this->rasa;
//		}
//		this->rasa = new char[strlen(a.rasa) + 1];
//		strcpy(this->rasa, a.rasa);
//		this->nrPicioare = a.nrPicioare;
//		this->greutate = a.greutate;
//		this->varsta = a.varsta;
//	}
//
//	 virtual ~Animal() {
//		if (this->rasa != NULL) {
//			delete[]this->rasa;
//		}
//	}
//
//
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
//	Caine(const char* rasa, int nrPicioare, float greutate, int varsta) :Animal(rasa, nrPicioare, greutate, varsta) {
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
//	char* nume;
//public:
//	Pisica() :Animal() {
//		nume = NULL;
//	}
//	Pisica(const char* nume, const char* rasa, int nrPicioare, float greutate, int varsta)
//		:Animal(rasa, nrPicioare, greutate, varsta)
//	{
//		this->nume = new char[strlen(nume) + 1];
//		strcpy(this->nume, nume);
//	}
//	string vorbeste() {
//		return "Miau miau";
//	}
//	string ceMananca() {
//		return "Peste";
//	}
//	~Pisica() {
//		if (nume != NULL) {
//			delete[]this->nume;
//		}
//	}
//};
//
//
//
//void main() {
//
//	Animal*	pet= new Pisica("Tom", "Birmaneza", 4, 6, 2);
//	
//	cout << pet->ceMananca() << endl;
//
//	delete pet;
//}