#include<iostream>

using namespace std;
//1. functii template
//2. clase template
//3. doua template-uri
//4. mostenire de clasa template
//5. relatie has-a cu clasa template

template <typename T> 
T produs(T a, T b) {
	return a * b;
}

string operator*(string a, string b) {
	string aux;
	aux = a +  " - " + "\n" + " - " + b;
	return aux;
}

class Diamant {
private:
	int nrFatete;
	string tipTaietura;
public:
	Diamant() {
		this->nrFatete = 5;
		this->tipTaietura = "cubica";
	}
	friend ostream& operator<<(ostream& o, const Diamant& d) {
		o << d.nrFatete << " " << d.tipTaietura << endl;
		return o;
	}
};


template<typename T>
class Bijuterie
{	private:
	string nume;
	int nrPietre;
	T* pietre;

public:
	Bijuterie()
	{
		this->nume = "Inel";
		this->nrPietre = 2;
		this->pietre = new T[this->nrPietre];
	}

	Bijuterie(const Bijuterie& bij)
	{
		this->nume = bij.nume;
		this->nrPietre = bij.nrPietre;
		this->pietre = new T[bij.nrPietre];
		for (int i = 0; i < this->nrPietre; i++)
		{
			this->pietre[i] = bij.pietre[i];
		}
	}

	Bijuterie operator=(const Bijuterie& bij)
	{
		if (this != &bij)
		{
			this->nume = bij.nume;
			this->nrPietre = bij.nrPietre;
			if (this->pietre != NULL)
			{
				delete[]this->pietre;


				this->pietre = new T[bij.nrPietre];
				for (int i = 0; i < this->nrPietre; i++)
				{
					this->pietre[i] = bij.pietre[i];
				}
			}
		}
		return *this;
	}

	~Bijuterie()
	{
		if (this->pietre != NULL)
		{
			delete[]pietre;
		}
	}



	string getNume()
	{
		return this->nume;
	}

	T& operator[](int index)
	{
		if (index >= 0 && index < this->nrPietre)
		{
			return pietre[index];
		}
	}
};

template<typename T>
class BijuterieDeLux :public Bijuterie<T> {
private:
	string materialDeBaza;
public:
	BijuterieDeLux() :Bijuterie<T>() {
		this->materialDeBaza = "Aur";
	}
	BijuterieDeLux& operator=(const BijuterieDeLux& b) {
		Bijuterie<T>::operator=(b);
		this->materialDeBaza = b.materialDeBaza;
	}
};

void main() {
	/*int a, b;
	float c, d;
	a = 10;
	b = 15;
	c = 10.2;
	d = 15.5;
	cout << produs(a, b);
	cout << endl << produs(c, d);
	cout << endl << produs<float>(a, d);
	string c1 = "cuvant1";
	string c2 = "cuvant2";
	cout<<endl<<produs(c1, c2);*/

	Bijuterie<int> bij ;
	bij[0] = 3;
	cout << bij[0];


	Bijuterie<Diamant> bijuterie;
	cout <<endl<< bijuterie[0]<<endl;


	BijuterieDeLux<Diamant> bijuterieDeLux;


}