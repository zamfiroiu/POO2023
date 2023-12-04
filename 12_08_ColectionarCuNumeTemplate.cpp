//#include<iostream>
//
//using namespace std;
//
//template<typename T>
//class Colectionar {
//	int nrObiecte;
//	T* obiecte;
//public:
//	Colectionar() {
//		nrObiecte = 0;
//		obiecte = NULL;
//	}
//	Colectionar(int nrObiecte, T*obiecte) {
//		this->nrObiecte = nrObiecte;
//		if (obiecte != NULL) {
//			this->obiecte = new T[nrObiecte];
//			for (int i = 0; i < nrObiecte; i++) {
//				this->obiecte[i] = obiecte[i];
//			}
//		}
//		else {
//			this->obiecte = NULL;
//		}
//	}
//
//	Colectionar(const Colectionar &col)
//	{
//		this->nrObiecte = col.nrObiecte;
//		if (col.obiecte != NULL) {
//			this->obiecte = new T[col.nrObiecte];
//			for (int i = 0; i < col.nrObiecte; i++)
//			{
//				this->obiecte[i] = col.obiecte[i];
//			}
//		}
//		else {
//			this->obiecte = NULL;
//		}
//	}
//	Colectionar operator=(const Colectionar &c) {
//		this->nrObiecte = c.nrObiecte;
//		if (c.obiecte != NULL) {
//			if (this->obiecte != NULL) {
//				delete[]this->obiecte;
//			}
//			this->obiecte = new T[c.nrObiecte];
//			for (int i = 0; i < c.nrObiecte; i++)
//			{
//				this->obiecte[i] = c.obiecte[i];
//			}
//		}
//		else {
//			this->obiecte = NULL;
//		}
//		return *this;
//	}
//	float calculareValoareColectie() {
//		float sum = 0;
//		for (int i = 0; i < this->nrObiecte; i++) {
//			sum = sum + this->obiecte[i];
//		}
//		return sum;
//	}
//};
//
//class Timbru {
//	int an;
//	string tara;
//	float pret;
//
//public:
//
//	Timbru() :an(0), tara("Romania"), pret(10) {};
//	Timbru(int an, string tara, float pret) {
//		this->an = an;
//		this->tara = tara;
//		this->pret = pret;
//	}
//	float getPret() {
//		return pret;
//	}
//
//	operator float() {
//		return this->pret;
//	}
//
//	Timbru operator+(Timbru t) {
//		Timbru timbru = *this;
//		timbru.pret = this->pret + t.pret;
//		return timbru;
//	}
//};
//
//template<class T>
//class ColectionarCuNume :public Colectionar<T> {
//private:
//	string nume;
//public:
//};
//
//
//void main() {
//
//	Colectionar<int> colectie;
//	cout<<colectie.calculareValoareColectie();
//
//	Colectionar<Timbru>colectieTimbre(2,new Timbru[2]);
//	cout << colectieTimbre.calculareValoareColectie();
//
//	ColectionarCuNume<Timbru> cn;
//
//}