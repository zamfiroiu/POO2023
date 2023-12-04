//#include<iostream>
//
//using namespace std;
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
//
//};
//
//template<typename TIP>
//bool comparare(TIP p1, TIP p2) {
//	return p1 < p2;
//}
//
//template<typename T>
//T suma(T a, T b) {
//	return a + b;
//}
//
//
//void main() {
//	int a = 5;
//	int b = 6;
//	if (comparare(a, b)) {
//		cout << "a este mai mic";
//	}
//	else {
//		cout << "b este mai mic";
//	}
//
//	Moneda m1(50, 2005);
//	Moneda m2(10, 2020);
//
//	if (comparare(m1, m2)) {
//		cout << "m1 este mai mic";
//	}
//	else {
//		cout << "m2 este mai mic";
//	}
//
//	//suma(m1, m2);
//}