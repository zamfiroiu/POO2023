//#include<iostream>
//
//using namespace std;
//
//class Baza {
//public:
//	virtual void mananca() = 0;
//};
//
//class Derivata :public Baza {
//private:
//	void eat() {
//		cout << "eat something";
//	}
//public:
//	void mananca() {
//		eat();
//	}
//};
//
//void main() {
//	Baza* b = new Derivata();
//	b->mananca();
//}