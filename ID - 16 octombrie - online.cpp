#include<iostream>


using namespace std;
//
//void citeste(int& nrElemente, int*& v) {
//	
//}
//
//void citeste(int nrElemente, int* v) {
//
//}
//
//void citeste(int nrElemente) {
//
//}

enum ZiLucratoare { Luni, Marti, Miercuri, Joi, Vineri };

string getStringZiLucratoare(ZiLucratoare zi) {
	switch (zi)
	{
	case Luni: 
		return "Luni";
	case Marti: 
		return "Marti";
	case Miercuri: 
		return "Miercuri";
	case Joi:
		return "Joi";
	case Vineri:
		return "Vineri";
	default:
			return "Alta zi";
	}
}


void main()
{
	string sir = "sir";
	sir.append(" de caractere");
	
	//strlen("sir");
	int a = 10;

	int* p = &a;

	int*& rp = p;

	(*p)--;

	int& r = a;
	r++;
	cout << a<<endl;

	ZiLucratoare zi = Luni;
	zi = ZiLucratoare(1);
	int val = ZiLucratoare::Miercuri;
	cout << val<<endl;

	if (zi == Marti) {
		cout << "Marti";
	}

	ZiLucratoare* zileMuncite;
	int nrZile = 3;
	zileMuncite = new ZiLucratoare[nrZile];
	
	for(int i=0;i<nrZile;i++){
		zileMuncite[i] = ZiLucratoare(i % 5);
	}
	//modificare vector
	ZiLucratoare* aux = new ZiLucratoare[nrZile + 1];
	for (int i = 0; i < nrZile; i++) {
		aux[i] = zileMuncite[i];
	}
	aux[nrZile] = Luni;
	zileMuncite = aux;
	delete[]zileMuncite;
	aux = NULL;
	nrZile++;

		//afisare vector
	cout << endl << endl;
	for (int i = 0; i < nrZile; i++) {
		cout << getStringZiLucratoare(zileMuncite[i])<<" ";
	}
	delete[]zileMuncite;
}