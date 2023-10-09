#include<iostream>

using namespace std;

struct Cafea {
	string aroma;
	float cantitate;
	float pret;
};

Cafea citesteCafea() {
	Cafea c;
	cout << "Aroma cafelei:";
	cin >> c.aroma;
	cout << "Cantitatea de cafea:";
	cin >> c.cantitate;
	cout << "Pretul cafelei:";
	cin >> c.pret;
	return c;
}

void afiseazaCafea(Cafea c) {
	cout << "Aroma: " << c.aroma << ", Cantitate: " << c.cantitate << ", costa " << c.pret << " RON." << endl;
}

void modificaPretCafea(Cafea& c,float adaos) {
	c.pret = c.pret + adaos;
}

void interschimbarePrinValoare(int a, int b) {
	int c = a;
	a = b;
	b = c;
}

void interschimbare(int* a, int* b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

void interschimbare(int& a, int& b) {
	int aux = a;
	a = b;
	b = aux;
}
void main() {
	//int x = 50;
	//int y = 20;
	//std::cout << "x= " << x << ", Y=" << y << std::endl;
	///*interschimbare(x, y);
	//std::cout << "x= " << x << ", Y=" << y << std::endl;*/

	////interschimbare(&x, &y);
	////std::cout << "X= " << x << ", Y=" << y << std::endl;

	//interschimbare(x, y);


	//Cafea cafea = citesteCafea();
	//afiseazaCafea(cafea);
	//modificaPretCafea(cafea, 2);
	//afiseazaCafea(cafea);

	Cafea* pCafea;
	pCafea = new Cafea();

	*pCafea=citesteCafea();
	modificaPretCafea(*pCafea, 3);
	afiseazaCafea(*pCafea);
	
}