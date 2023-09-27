#include<iostream>

struct Animal {
	float greutate;
	char* specie;
	char gen;
	int varsta;
	bool esteCarnivor;
};


void main() {
	Animal animal;
	animal.greutate = 300;
	//animal.specie = (char*)malloc(strlen("Cal") + 1);
	animal.specie = new char[strlen("Cal") + 1];
	strcpy_s(animal.specie, strlen("Cal") + 1, "Cal");
	animal.gen = 'M';
	animal.varsta = 3;
	animal.esteCarnivor = false;

	std::cout << animal.specie << " are o greutate de " << animal.greutate << " kg, varsta de " << animal.varsta<<" ani.";
	
	//if (animal.esteCarnivor) {
	//	std::cout << "Este carnivor";
	//}
	//else {
	//	std::cout << "Nu este carnivor";
	//}

	std::cout << (animal.esteCarnivor ? "Este carnivor" : "Nu este carnivor");
}