//#include<iostream>
//#include<iomanip>
//#include<windows.h>
//
//using namespace std;
//
//
//ostream& green(ostream& out)
//{
//	HANDLE standardOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(standardOutput, FOREGROUND_GREEN);
//	return out;
//}
//
//ostream& blue(ostream& out)
//{
//	HANDLE standardOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(standardOutput, FOREGROUND_BLUE);
//	return out;
//}
//
//ostream& afisarePret(ostream& out) {
//	out << setiosflags(ios::fixed);
//	out << setprecision(4);
//	out << setw(20);
//	out << setfill('*');
//	return out;
//}
//
//
//void main() {
//	float pret = 1190.36;
//	//cout << "Pret:" << afisarePret << pret << endl;;
//	cout << green << "Text"<<blue<<endl;
//}