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
//class Moneda {
//	int valoare;
//	int an;
//public:
//	Moneda(int val, int an) {
//		this->valoare = val;
//		this->an = an;
//	}
//	bool operator<(Moneda m) {
//		return this->valoare < m.valoare;
//	}
//	operator float() {
//		return valoare;
//	}
//
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
//template<typename T>
//class AsociatieColectionari {
//private:
//	int nrColectionari;
//	Colectionar<T>*colectionari;
//
//public:
//	//...etc
//
//
//
//};
//
//void main() {
//
//	AsociatieColectionari<Timbru> asociatieColectionariTimbre;
//	AsociatieColectionari<Moneda> asociatieColectionariMonezi;
//
//}