//#include<iostream>
//
//using namespace std;
//
//struct FelDeMancare {
//	string denumire;
//	float gramaj;
//	bool vegan;
//};
//
//FelDeMancare citesteFelDeMacare() {
//	FelDeMancare fel;
//	cout << "Denumirea felului de mancare:";
//	cin >> fel.denumire;
//	cout << "Gramajul felului de mancare:";
//	cin >> fel.gramaj;
//	cout << "Este vegan? (0-NU, 1-DA)";
//	cin >> fel.vegan;
//	return fel;
// }
//
//void afisareFelDeMancare(FelDeMancare fel) {
//	cout << fel.denumire << " are o greutate de " << fel.gramaj << " grame. " << (fel.vegan ? "Este vegan." : "Nu este vegan")<<endl;
//}
//
//void modificaGramaj(float noulGramaj, FelDeMancare& fel) {
//	fel.gramaj = noulGramaj;
//}
//
//
//void nonInterschimbare(int a, int b) {
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
//void interschimbare(int& a, int& b) {
//	int aux = a;
//	a = b;
//	b = aux;
//}
//
//void main() {
//	//int x = 10;
//	//int y = 40;
//	//std::cout << "X=" << x << ", Y=" << y << std::endl;
//	////nonInterschimbare(x, y);
//	////std::cout << "X=" << x << ", Y=" << y << std::endl;
//	////interschimbare(&x, &y);
//	////std::cout << "X=" << x << ", Y=" << y << std::endl;
//	//interschimbare(x, y); 
//	//std::cout << "X=" << x << ", Y=" << y << std::endl;
//
//
//	FelDeMancare felMancare = citesteFelDeMacare();
//	afisareFelDeMancare(felMancare);
//	modificaGramaj(500, felMancare);
//	afisareFelDeMancare(felMancare);
//
//	FelDeMancare* pFelMancare;
//	pFelMancare = new FelDeMancare();
//	*pFelMancare = citesteFelDeMacare();
//	afisareFelDeMancare(*pFelMancare);
//}