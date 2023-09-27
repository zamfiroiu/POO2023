#include<iostream>

struct Student {
	int varsta;
	float medie;
	char *nume;
	char initialaTata;
	bool esteLaBuget;
};

void main() {
	Student student;
	student.varsta = 20;
	student.medie = 9.87;
	//student.nume = (char*)malloc(strlen("Ion") + 1);
	student.nume = new char[strlen("Ion") + 1];
	strcpy_s(student.nume, strlen("Ion") + 1, "Ion");
	student.initialaTata = 'I';
	student.esteLaBuget = true;

	std::cout << student.nume<<" "<<student.initialaTata << ". are varsta de " << student.varsta << " ani, media=" << student.medie<<". ";

	//if (student.esteLaBuget) {
	//	std::cout << "Este la buget";
	//}
	//else {
	//	std::cout << "Nu este la buget";
	//}

	std::cout << (student.esteLaBuget ? "Este la buget." : "Nu este la buget.");
}