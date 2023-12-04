//#include<iostream>
//using namespace std;
//
//class Baza { 
//public:
//	int atributBaza;
//	virtual int Metoda1(int a) 
//	{
//		atributBaza = a;
//		cout << a;
//		return atributBaza;
//	}
//}; 
//
//class Derivat : public Baza 
//{ 
//public:
//	int atributNou; 
//	Derivat():Baza() {
//		atributNou = 0;
//	}
//	int Metoda1(int a) 
//	{
//		atributNou = 2 * a;
//		cout << 3 * a;
//		return atributNou;
//	}
//};
//
//
//void main() {
//
//	//Baza b;
//	//Derivat d;
//
//	//b = d;
//	//cout << b.Metoda1(2)<<endl;
//
//	Baza* p1 = new Baza();;
//	Derivat *p2 = new Derivat();
//
//	p1 = p2;
//	
//	p1->Metoda1(5);
//	//cout << p1->Metoda1(2)<<endl;
//}