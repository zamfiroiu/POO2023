//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//
//using namespace std;
//
//class Videoproiector {
//private:
//	const int id;
//	char* producator;
//	string model;
//	float greutate;
//	static int TVA;
//	float pret;
//public:
//	Videoproiector():id(0) {
//		this->producator = new char[strlen("Acer") + 1];
//		strcpy_s(this->producator, strlen("Acer") + 1, "Acer");
//		this->model = "G5Video";
//		this->greutate = 4.5;
//		this->pret = 2000;
//	}
//
//	Videoproiector(int id, const char* producator,
//	string model, float greutate, float pret) :id(id) {
//		this->producator = new char[strlen(producator) + 1];
//		strcpy_s(this->producator, strlen(producator) + 1, producator);
//		this->model = model;
//		this->greutate = greutate;
//		this->pret = pret;
//	}
//	Videoproiector(const Videoproiector &v) :id(id) {
//		this->producator = new char[strlen(v.producator) + 1];
//		strcpy_s(this->producator, strlen(v.producator) + 1,v.producator);
//		this->model = v.model;
//		this->greutate = v.greutate;
//		this->pret = v.pret;
//	}
//	Videoproiector operator=(const Videoproiector& v) {
//		if (&v != this) {
//			if (this->producator != NULL) { delete[]this->producator; }
//
//			this->producator = new char[strlen(v.producator) + 1];
//			strcpy_s(this->producator, strlen(v.producator) + 1, v.producator);
//			this->model = v.model;
//			this->greutate = v.greutate;
//			this->pret = v.pret;
//		}
//		return *this;
//	}
//	~Videoproiector() {
//		if (this->producator != NULL) { delete[]this->producator; }
//	}
//	float medie() {
//		if (this->producator != NULL && strlen(producator)>=0) {
//			float sum = 0.0;
//			for (int i = 0; i < strlen(this->producator); i++) {
//				sum += producator[i];
//			}
//			return sum / (float)strlen(this->producator);
//		}
//		else {
//			return 0;
//		}
//	}
//	float getGreutate() {
//		return this->greutate;
//	}
//	void setGreutate(float greutate) {
//		this->greutate = greutate;
//	}
//	char* getProducator() {
//		return producator;
//	}
//	void setProducator(const char* producator) {
//		if (this->producator != NULL) { delete[]this->producator ;}
//		this->producator = new char[strlen(producator) + 1];
//		strcpy_s(this->producator,strlen(producator)+1,producator );
//	}
//	int operator%(int nr) {
//		return (int)(this->medie()* strlen(this->producator)) % nr;
//	}
//	explicit operator int() {
//		return this->model.length();
//	}
//	operator float() {
//		return this->greutate;
//	}
//	char* operator()() {
//		char* aux = new char[strlen(this->producator) + this->model.length() + 4];
//		strcpy(aux, this->producator);
//		strcpy(aux + strlen(this->producator), " - ");
//		strcpy(aux + strlen(this->producator) + 3, this->model.c_str());
//		return aux;
//	}
//	string operator()(const char* sir) {
//		string aux = string(producator);
//		aux += string(sir);
//		aux += model;
//		return aux;
//	}
//	Videoproiector operator!() {
//		if (this->pret > 0) {
//			this->pret = 0;
//		}
//		else {
//			this->pret = this->TVA * 100;
//		}
//		return *this;
//	}
//	float getPret() {
//		return this->pret;
//	}
//};
//
//int Videoproiector::TVA = 19;
//
//void main() {
//	Videoproiector video1;
//	Videoproiector video2(10, "ABCDE", "Video", 12.3, 350.2);
//	Videoproiector video3 = video2;
//	video1 = video2;
//	cout<<video2.medie()<<endl;
//	cout << video2 % 4;
//	int a =(int)video2;
//	float b = video1;
//	cout << a << " " << b << endl;
//	cout << video2()<<endl;
//	cout << video2(" AND ")<<endl;
//	video1 = !video1;
//	cout << video1.getPret()<<endl;
//	!video1;
//	cout << video1.getPret() << endl;
//}