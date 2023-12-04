//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class ExceptieImpartire : public exception
//{
//private:
//	string mesaj;
//public:
//	ExceptieImpartire(string msg) {
//		mesaj = msg;
//	}
//	string getMesaj() {
//		return mesaj;
//	}
//
//};
//
//class ClasaCuExceptii {
//public:
//	ClasaCuExceptii()  {
//		//throw 7.6;
//	}
//
//	int sumaNumerePozitive(int a, int b){
//		if (a < 0 ) {
//			throw 708;
//		}
//		else if (b < 0) {
//			throw 709;
//		}
//		return a + b;
//	}
//
//	float impartire(float a, float b)  {
//		if (b == 0) { //
//			throw new ExceptieImpartire("Impartire la 0");
//		}
//		return a / b;
//	}
//};
//
//void main() {
//	ClasaCuExceptii* pc = NULL;
//	try {
//		ClasaCuExceptii cce;
//		pc=new ClasaCuExceptii();
//		cout<<cce.sumaNumerePozitive(9,7)<<endl;
//		cout << cce.impartire(8, 0)<<endl;
//		//....aici
//	}
//	catch (int codEroare) {
//		cout << codEroare;
//	}
//	//catch (ExceptieImpartire exI) {
//	//	cout << exI.getMesaj()<<" prin valoare"<<endl;
//	//}
//	//catch (ExceptieImpartire* exP) {
//	//	cout << exP->getMesaj() << " prin pointer." << endl;
//	//}
//	catch (exception* ex) {
//		cout << "Exceptie";
//	}
//	catch (double a) {
//
//	}
//	catch (...) {
//		cout << "A aparut o problema necunoscuta.";
//	}
//
//	if (pc!=NULL) {
//		delete pc;
//	}
//
//
//}