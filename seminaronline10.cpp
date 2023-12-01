//Sa se implementeze o clasa Spital conform urmatoarelor cerinte
//clasa are cel putin urmatoarele atribute
//cif - cod de identificare fiscala - se atribuie valoare la crearea obiectului si apoi nu mai poate fi modificata - valoare de tip sir de caractere
//nume - sir de caractere
//adresa - sir de caractere
//medici - vector de valori string alocat dinamic => avem nevoie de nrMedici
//nrSpitale(va retine nr de spitale - obiecte de tip Spital - instantiate vreodata - static int

//se vor implementa
//constructor fara parametri
//constructor cu toti parametrii necesari instantiereii unui obiect complet
//constructor de copiere
//destructor
//metode get si set
//supraincarcare operator =
//supraincarcare operatori de citire si scriere din/in consola
//supraincarcare operator de indexare - returneaza medicul de pe o pozitie data -- atat in mod scriere cat si in mod citire
//supraincarcare operator !
//cast explicit int - returneaza numarul de spitale instantiate

//cel putin unul dintre atributele de tip sir de caractere trebuie sa fie de tip char*



#include <iostream>
#include<string>
using namespace std;

class Spital {
	const string cif;
	char* nume;
	string adresa;
	string* medici;
	int nrMedici;
	static int nrSpitale;

public:
	//CONSTRUCTOR FARA PARAMETRI - INCLUS CONST - INCLUS STATIC 
	Spital():cif("") {
		this->nume = nullptr;
		this->adresa = "";
		this->medici = nullptr;
		this->nrMedici = 0;
		Spital::nrSpitale++;
	}

	//CONSTRUCTOR CU PARAMETRI - INCLUS CONST - INCLUS STATIC
	Spital(string cif, const char* nume, string adresa, const string* medici, int nrMedici):cif(cif) {
		this->adresa = adresa;
		this->nrMedici = nrMedici;

		if (nume != nullptr) {
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else {
			this->nume = nullptr;
		}

		this->medici = new string[nrMedici];
		for (int i = 0; i < nrMedici; i++) {
			this->medici[i] = medici[i];
		}

		Spital::nrSpitale++;

	}

	//CONSTRUCTOR DE COPIERE - INCLUS CONST - INCLUS STATIC
	Spital(Spital& s):cif(s.cif) { //: Spital(s.cif, s.nume, s.adresa, s.medici, s.nrMedici)
		this->adresa = s.adresa;
		this->nrMedici = s.nrMedici;

		if (s.nume != nullptr) {
			this->nume = new char[strlen(s.nume) + 1];
			strcpy_s(this->nume, strlen(s.nume) + 1, s.nume);
		}
		else {
			this->nume = nullptr;
		}

		this->medici = new string[s.nrMedici];
		for (int i = 0; i < s.nrMedici; i++) {
			this->medici[i] = s.medici[i];
		}

		Spital::nrSpitale++;

	}

	//SUPRAINCARCARE OPERATOR =
	Spital& operator=(Spital& s) {
		if (this == &s)
			return *this;

		delete[]this->nume;
		this->nume = new char[strlen(s.nume) + 1];
		strcpy_s(this->nume, strlen(s.nume) + 1, s.nume);

		delete[] this->medici;
		this->medici = new string[s.nrMedici];
		for (int i = 0; i < s.nrMedici; i++) {
			this->medici[i] = s.medici[i];
		}
		this->nrMedici = s.nrMedici;
		this->adresa = s.adresa;

		return *this;
	}

	void setNume(const char* nume) {
		if (nume != nullptr) {
			delete[] this->nume;
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else {
			this->nume = nullptr;
		}
	}

	void setAdresa(string adresa) {
		this->adresa = adresa;
	}

	void setMedici(const string* medici, int nrMedici) {
		if (medici != nullptr&& nrMedici>0) {
			delete[] this->medici;
			this->nrMedici = nrMedici;
			this->medici = new string[nrMedici];
			for (int i = 0; i < nrMedici; i++) {
				this->medici[i] = medici[i];
			}
		}
		else {
			this->medici = nullptr;
			this->nrMedici = 0;
		}
	}

	char* getNume() {
		char* copy = new char[strlen(this->nume)+1];
		strcpy_s(copy, strlen(this->nume) + 1, this->nume);
		return copy;
	}

	string* getMedici() {
		string* copy = new string[this->nrMedici];
		for (int i = 0; i < this->nrMedici; i++) {
			this->medici[i] = copy[i];
		}
		return copy;

	}

	static int getnrSpitale() {
		return nrSpitale;
	}





	friend ostream& operator<<(ostream& out, Spital s);
	friend istream& operator>>(istream& in, Spital& s);

	~Spital() {
		delete[] this->nume;
		delete[] this->medici;
		Spital::nrSpitale--; //-> daca cerinta ar fi ca nrSpitale sa retina spitalele active
		//obiecte instantiate care nu au fost sterse
	}



};

ostream& operator<<(ostream& out, Spital s) {
	out <<"CIF: "<< s.cif << endl;
	out <<"Nume: "<< s.nume << endl;
	out <<"Adresa: "<< s.adresa << endl;
	out <<"Nr medici: "<< s.nrMedici << endl;
	for (int i = 0; i < s.nrMedici; i++) 
		out << s.medici[i] << " ";
	out << endl;
	
	return out;
}

istream& operator>>(istream& in, Spital& s) {
	char* tmp = new char[256];
	cout << "Nume: ";
	in.getline(tmp, 256);
	s.setNume(tmp);

	cout << "Adresa: ";
	in.getline(tmp, 256);
	s.setAdresa(tmp);

	cout << "Nr medici: ";
	int tmpNr;
	in >> tmpNr;
	in.getline(tmp, 256);

	cout << "Numele pentru " << tmpNr << " medici: ";
	string* medici = new string[tmpNr];
	for (int i = 0; i < tmpNr; i++) {

		in.getline(tmp, 256);
		medici[i] = (string)tmp;
	}
	s.setMedici(medici, tmpNr);

	return in;
}



//!!initializare atribut static
int Spital::nrSpitale = 0;

int main()
{
	//instantiere constructor fara parametri
	//Spital s1;

	string* medici = new string[3];
	medici[0] = "medic 1";
	medici[1] = "medic 2";
	medici[2] = "medic 3";

	Spital s1, s2("RO123", "Floreasca", "Bucuresti", medici, 3);
	s2 = s2;

	s1 = s2;
	s1.setNume("Alt nume");

	cout << s2;
	Spital s3=s2;
   
	//cin >> s3;

	cout << Spital::getnrSpitale() << endl;
}

