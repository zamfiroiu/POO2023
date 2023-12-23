//#include<iostream>
//
//
//using namespace std;
////1. functii template
////2. clase template
////3. doua template-uri
////4. mostenire de clasa template
////5. relatie has-a cu clasa template
//
//
//class Cod {
//private:
//	int nrPersonal;
//public:
//	Cod() {
//		this->nrPersonal = 3;
//	}
//	friend ostream& operator<<(ostream& o, const Cod& c) {
//		o << c.nrPersonal << endl;
//		return o;
//	}
//};
//
//float operator/(string x, int y) 
//{
//	return x.length() / (float)y;
//
//}
//
//template <class T>
//T suma(T a, T b) 
//{
//	return a + b;
//}
//
//
// template <class T>
// float medie(T a, T b) 
// {
//	 return suma(a, b) / 2;
// }
// template <class T>
// class Colectionar {
// private:
//	 int nrObiecte;
//	 T* obiecte;
// public:
//	 Colectionar() {
//		 this->nrObiecte = 2;
//		 this->obiecte = new T[nrObiecte];
//	 }
//	 Colectionar(const Colectionar& p) {
//		 this->nrObiecte = p.nrObiecte;
//		 this->obiecte = new T[p.nrObiecte];
//		 for (int i = 0; i < nrObiecte; i++)
//			 this->obiecte[i] = p.obiecte[i];
//	 }
//	 Colectionar operator=(const Colectionar& p) {
//		 if (this != &p) {
//			 this->nrObiecte = p.nrObiecte;
//			 if (this->obiecte != NULL)
//				 delete[]this->obiecte;
//			 this->obiecte = new T[p.nrObiecte];
//			 for (int i = 0; i < nrObiecte; i++)
//				 this->obiecte[i] = p.obiecte[i];
//		 }
//		 return *this;
//	 }
//	 T& operator[](int index) {
//		 if (index <= nrObiecte)
//			 return obiecte[index];
//	 }
//	 ~Colectionar() {
//		 if (this->obiecte != NULL)
//			 delete[]this->obiecte;
//	 }
// };
//
// template<class T>
// class Muzeu {
// private:
//	 Colectionar<T> colectionar;
// public:
//	 Muzeu() {
//
//	 }
//
//	 Colectionar<T> getColectionar() {
//		 return this->colectionar();
//	 }
//
//	 void setColectionar(Colectionar<T> c) {
//		 this->colectionar = c;
//	 }
// };
//
//
//void main()
//{
//	/*int a = 10;
//	int b=5;
//	cout << suma(a, b) << endl;
//	cout <<medie<float>(a, b) << endl;
//	string c = "Am facut";
//	string d = " Secret Santa";
//	cout << suma(c, d) << endl;
//	cout << medie(c, d) << endl;*/
//
//	Colectionar <float>numereReale;
//	numereReale[0] = 3.14;
//	cout << numereReale[0]<<endl;
//
//	Colectionar <Cod> colectieCoduri;
//	colectieCoduri[1] = Cod();
//	cout << colectieCoduri[1]<<endl;
//}