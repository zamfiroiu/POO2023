//#include<iostream>
//
//using namespace std;
////1. functii template
////2. clase template
////3. doua template-uri
////4. mostenire de clasa template
////5. relatie has-a cu clasa template
//
//float operator/(string s1, float a) {
//	return (s1.length()) / a;
//}
//
//template <class t1>
//t1 adunare(t1 p1, t1 p2) {
//	return p1 + p2;
//	}
//
//template <class t1> 
//float medie(t1 p1, t1 p2) {
//
//	return adunare (p1, p2) / 2.0;
//}
//
//class Figurina {
//	string nume;
//	int inaltime;
//public:
//	Figurina() {
//		this->nume = "Spider man";
//		this->inaltime = 16;
//	}
//
//	friend ostream& operator<<(ostream& o, const Figurina& f) {
//		o << f.nume << " " << f.inaltime << endl;
//		return o;
//	}
//
//};
//
//
//
//template <class t2>
//class Colectie {
//private:
//	string denumire;
//	int numarObiecte;
//	t2** obiecte;
//public:
//	Colectie() {
//		this->denumire = "Colectie";
//		this->numarObiecte = 2;
//		this->obiecte = new t2*[2];
//		for (int i = 0; i < 2; i++) {
//			obiecte[i] = new t2();
//		}
//	}
//	Colectie(const Colectie& c) {
//		this->denumire = c.denumire;
//		this->numarObiecte = c.numarObiecte;
//		this->obiecte = new t2 * [this->numarObiecte];
//		for (int i = 0; i < this->numarObiecte; i++) {
//			this->obiecte[i] = c.obiecte[i];
//		}
//	}
//	~Colectie() {
//		delete[]this->obiecte;
//	}
//	Colectie operator=(const Colectie& c) {
//		if (this != &c) {
//			this->denumire = c.denumire;
//			this->numarObiecte = c.numarObiecte;
//			if (this->obiecte) {
//				delete[]this->obiecte; 
//			}
//			this->obiecte = new t2 * [this->numarObiecte];
//			for (int i = 0; i < this->numarObiecte; i++) {
//				this->obiecte[i] = c.obiecte[i];
//			}
//		}
//		return *this;
//	}
//	string getDenumire() {
//		return this->denumire;
//	}
//	t2& operator[](int index) {
//		if (index >= 0 && index < this->numarObiecte) {
//			return *(this->obiecte[index]);
//		}
//	}
//};
//
//
//template<class T>
//class ColectiePublica :public Colectie<T> {
//private:
//	string adresaExpunere;
//public:
//	ColectiePublica() :Colectie<T>() {
//		this->adresaExpunere = "Piata romana";
//	}
//	ColectiePublica operator=(const ColectiePublica& cp) {
//		Colectie<T>::operator=(cp);
//		this->adresaExpunere = cp.adresaExpunere;
//	}
//};
//
//void main() {
//	//int a = 5, b = 6;
//	//cout << adunare(a, b) << endl;
//	//cout << medie(a, b) << endl;
//	//string s1 = "abcde0";
//	//string s2 = "fghijk0";
//	//cout << adunare(s1, s2) << endl;
//
//	//cout << medie(s1, s2);
//	Colectie<float> col1;
//	col1[0] = 23.4;
//	cout << col1[0]<<endl;
//
//	Colectie<Figurina> colectieFigurine;
//
//	Figurina f1;
//	colectieFigurine[1] = f1;
//	cout << colectieFigurine[1];
//
//
//	ColectiePublica<Figurina> colectiePublica;
//
//
//}