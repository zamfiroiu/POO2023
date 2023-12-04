//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class A {
//public:
//	string metoda1() {
//		return "A";
//	}
//	virtual string metoda2() {
//		return "A. Virtual";
//	}
//};
//
//class B :public A {
//public:
//	virtual string metoda1() {
//		return "B";
//	}
//	string metoda2() {
//		return "B. Virtual din A";
//	}
//};
//
//class C :public B {
//public:
//	string metoda1() {
//		return "C. virtual din B";
//	}
//	string metoda2() {
//		return "C. Virtual din A";
//	}
//};
//
//class D :public A {
//public :
//	string metoda2() {
//		return "Am apelat D";
//	}
//};
//
//void main() {
//
//	//A*a = new C();
//	//cout << a->metoda1() << endl;
//	//cout << a->metoda2() << endl;
//
//	//cout << endl;
//
//	//B*b = new C();
//	//cout << b->metoda1() << endl;
//	//cout << b->metoda2() << endl;
//
//	int nr = 11;
//	A**vector = new A*[nr];
//	vector[0] = new B();
//	vector[1] = new C();
//	vector[2] = new B();
//	vector[3] = new D();
//	vector[4] = new C();
//	vector[5] = new C();
//	vector[6] = new C();
//	vector[7] = new B();
//	vector[8] = new C();
//	vector[9] = new B();
//	vector[10] = new D();
//
//	for (int i = 0; i < nr; i++) {
//		cout << vector[i]->metoda1()<<endl;
//	}
//}