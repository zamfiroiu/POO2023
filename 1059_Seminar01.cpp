#include<iostream>

struct Pisica {
	int varsta;
	char gen;
	char* nume;
	bool arePar;
	float greutate;
};

void main()  {
	std::cout << "Hello, 1059";
	Pisica pisica;
	pisica.varsta = 2;
	pisica.gen = 'M';
	pisica.nume = new char[strlen("Caju") + 1];
	strcpy_s(pisica.nume, strlen("Caju") + 1, "Caju");
	pisica.arePar = false;
	pisica.greutate = 2.4;

	std::cout << pisica.nume << " " << pisica.gen << std::endl <<
		pisica.greutate << " varsta: " << pisica.varsta<<std::endl;
	std::cout << (pisica.arePar ? "" : "nu") << " are par.";

	Pisica* pointer;
	pointer = new Pisica();
	(*pointer).varsta = 3;
	pointer->varsta = 3;//dereferentiere+accesare

}