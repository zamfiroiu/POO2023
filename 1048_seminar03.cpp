#include<iostream>

using namespace std;

class FormaGeometrica {
public:
	string nume;
	char* culoare;
	float aria;
	int nrLaturi;

	FormaGeometrica() {
		(*this).nume = "Dreptunghi";
		this->culoare = new char[strlen("rosie") + 1];
		strcpy_s(culoare, strlen("rosie") + 1, "rosie");
		aria = 30;
		nrLaturi = 4;
	}

	~FormaGeometrica() {
		cout << "destructor"<<endl;
		if (this->culoare != NULL) {
			delete[]this->culoare;
		}
	}

	void modificaAria(float aria) {
		this->aria = aria;
	}

	void afisare() {
		cout << "Forma geometrica " << nume << " are aria de " << aria << ", contine " << nrLaturi << " laturi si are culoarea " << culoare << endl;
	}
};

FormaGeometrica initializareFormaGeometrica() {
	FormaGeometrica fg;
	fg.nume = "Dreptunghi";
	fg.culoare = new char[strlen("rosie") + 1];
	strcpy_s(fg.culoare, strlen("rosie") + 1, "rosie");
	fg.aria = 30;
	fg.nrLaturi = 4;
	return fg;
}

void main() {
	FormaGeometrica forma;
	//forma.afisare();
	//forma = initializareFormaGeometrica();
	forma.afisare();
	{
		FormaGeometrica forma2;
		forma2.afisare();
	}
	forma.modificaAria(200);
	forma.afisare();

	FormaGeometrica* forme = new FormaGeometrica[98];

	delete[]forme;

}