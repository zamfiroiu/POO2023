#include<iostream>

void main() {

	int* pointer;
	int a;
	pointer = new int(10);
	std::cout << &a<<std::endl;
	*pointer = 7;
	std::cout << pointer<<std::endl;
	//std::cout << &pointer << std::endl;
	//std::cout << *pointer << std::endl;

	//int** pp = &pointer;
	//std::cout << pp;
	delete pointer;
	std::cout << pointer << std::endl;

	//int* vector = new int[3];
	//int v[100];
	//for (int i = 0; i < 3; i++) {
	//	vector[i] = i + 1;
	//}

	//std::cout << *(vector + 0) << " ";
	//std::cout << *(vector + 1) << " ";
	//std::cout << *(vector + 2) << " ";

	//delete[]vector;
}