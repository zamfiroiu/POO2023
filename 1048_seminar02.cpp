#include<iostream>

using namespace std;

struct Raft {
	string culoare;
	int nrProduse;
	float greutate;
};

Raft citesteRaft() {
	Raft r;
	cout << "Culoarea raftului:";
	cin >> r.culoare;
	cout << "Greutatea raftului:";
	cin >> r.greutate;
	cout << "Numarul de produse de pe raft:";
	cin >> r.nrProduse;
	return r;
}

void afiseazaRaft(Raft raft) {
	cout << "Raftul de culoare " << raft.culoare << " are o greutate de " << raft.greutate << " kg si pe el avem " << raft.nrProduse << " produse" << endl;
}

void modificaGreutate(Raft& raft, float greutateNoua){
	raft.greutate = greutateNoua;
}

void interschimbare(int a, int b) {
	int aux = a;
	a = b;
	b = aux;
}

void interschimbare(int* a, int* b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

void interschimbareReferinta(int& a, int& b) {
	int aux = a;
	a = b;
	b = aux;
}

void main() {
	//int x = 45;
	//int y = 80;
	//std::cout << "X=" << x << " Y=" << y << std::endl;
	////interschimbare(x, y);
	////std::cout << "X=" << x << " Y=" << y << std::endl;

	////interschimbare(&x, &y);
	////std::cout << "X=" << x << " Y=" << y << std::endl;
	//interschimbareReferinta(x, y);
	//std::cout << "X=" << x << " Y=" << y << std::endl;

	Raft raft = citesteRaft();
	afiseazaRaft(raft);
	modificaGreutate(raft, 190);
	afiseazaRaft(raft);
}