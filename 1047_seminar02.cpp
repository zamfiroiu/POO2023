//#include<iostream>
////machiaj
//
//using namespace std;
//
//struct ProdusMachiaj {
//	float pret;
//	int cantitate;
//	string producator;
//};
//
//ProdusMachiaj citesteProdusMachiaj() {
//	ProdusMachiaj produs;
//	cout << "Pretul produsului de machiaj:";
//	cin >> produs.pret;
//	cout << "Cantitatea produsului de machiaj:";
//	cin >> produs.cantitate;
//	cout << "producatorul produsului de machiaj:";
//	cin >> produs.producator;
//	return produs;
//}
//
//void afisareProdusMachiaj(ProdusMachiaj produs) {
//	cout << produs.producator << " are o cantitate de " << produs.cantitate << " grame si costa " << produs.pret << " RON." << endl;
//}
//
//void modificaPret(ProdusMachiaj& produs, float noulPret) {
//	produs.pret = noulPret;
//}
//
//void interschimbare(int a, int b) {
//	int aux = a;
//	a = b;
//	b = aux;
//}
//
//void interschimbare(int* a, int* b) {
//	int aux = *a;
//	*a = *b;
//	*b = aux;
//}
//
//void interschimbareReferinta(int& a, int& b) {
//	int aux = a;
//	a = b;
//	b = aux;
//}
//
//
//
//void main() {
//	//int x = 20;
//	//int y = 70;
//	//std::cout << "X= " << x << ", Y=" << y << std::endl;
//	///*interschimbare(x, y);
//	//std::cout << "X= " << x << ", Y=" << y << std::endl;
//	//interschimbare(&x, &y);
//	//std::cout << "X= " << x << ", Y=" << y << std::endl;*/
//
//	//interschimbareReferinta(x, y);
//	//std::cout << "X= " << x << ", Y=" << y << std::endl;
//
//	ProdusMachiaj produs = citesteProdusMachiaj();
//	afisareProdusMachiaj(produs);
//	modificaPret(produs, 144845);
//	afisareProdusMachiaj(produs);
//}