#include<iostream>
#include<fstream>
using namespace std;

//int sum(int a, int b) {
//	return a + b;
//}
//
//float sum(float a, float b) {
//	return a + b;
//}
//
//string sum(string a, string b) {
//	return a + b;
//}

template <class T>
T sum(T a, T b) {
	return a + b;
}

template <class Ty>
Ty diferenta(Ty a, Ty b) {
	return a - b;
}


class Calculator {
private:
	int nrComponete;
public:
	Calculator() {
		this->nrComponete = 2;
	}
	Calculator(int nr) {
		this->nrComponete = nr;
	}
	friend ostream& operator<<(ostream& o, const Calculator& c) {
		o <<"Numar componente: " << c.nrComponete << endl;
		return o;
	}

	Calculator operator+(const Calculator& c) {
		Calculator aux;
		aux.nrComponete = this->nrComponete + c.nrComponete;
		return aux;
	}
};

template<typename T> 
class Colectie {
private:
	int nrElemente;
	T* elemente;
public:
	Colectie() {
		this->nrElemente = 3;
		this->elemente = new T[nrElemente];
	}
	int getNrElemente(){
		return this->nrElemente;
	}
	~Colectie() {
		if (elemente != NULL) {
			delete[]elemente;
		}
	}
	Colectie(const Colectie& c) {
		this->nrElemente = c.nrElemente;
		this->elemente = new T[c.nrElemente];
		for (int i = 0; i < c.nrElemente; i++) {
			this->elemente[i] = c.elemente[i];
		}
	}
	Colectie operator=(const Colectie& c) {
		if (this != &c) {
			this->nrElemente = c.nrElemente;
			if (this->elemente != NULL)
				delete[]this->elemente;
			this->elemente = new T[c.nrElemente];
			for (int i = 0; i < c.nrElemente; i++) {
				this->elemente[i] = c.elemente[i];
			}
		}
		return *this;
	}

	T& operator[](int index) {
		if (index >= 0 && index < this->nrElemente) {
			return this->elemente[index];
		}
	}
};


template <class T1, class T2>
class Colectionar {
private:
	Colectie<T1> colectiePrimara;
	Colectie<T2> colectieSecundara;
public:
	Colectionar():colectiePrimara(),colectieSecundara() {

	}
};


class ColectionarStabilit {
private:
	Colectie<Calculator> calculatoare;
	Colectie<int> numereIntregi;
};


void main() {
	//int a = 3, b = 5;
	//cout << sum(a, b) << endl;

	//float c=3.8;
	//float d=5.9;
	//cout << sum(c, d) << endl;

	//string s1 = "Crina are";
	//string s2 = " mere";
	//cout << sum(s1, s2) << endl;

	//Calculator c1;
	//Calculator c2;
	//cout << sum(c1, c2)<<endl;


	Colectie<float> c;

	Colectie<Calculator> calculatoare;

	cout << calculatoare[0];
	Calculator calculator(6);
	calculatoare[1] = calculator;

	cout << calculatoare[1];

	ColectionarStabilit cs;

	Colectionar<Calculator, int>c1;
	Colectionar<int, double> c2;
}