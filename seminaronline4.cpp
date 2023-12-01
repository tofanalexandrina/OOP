#include <iostream>
#include <string>

using namespace std;

enum finantare //tag-uri pentru valori numerice
{
	TAXA = 1,
	BUGET = 2,
	BUGET_BURSA = 3
};


class Student
{
	string nume;
	char* adresa;
	int varsta;
	int an_studii;
public: //poate fi accesat direct tot ce e pana la private
	

	//constructori
	Student() 
	{
		/*this->note = nullptr;
		this->adresa = nullptr;
		this->nume = "";*/

	}
	//constructor cu parametri
	Student(string _nume, char* _adresa, int _varsta, int _an_studii, int* _note, int _numar_materii, string _numar_matricol, finantare _finantare) :
		nume(_nume), varsta(_varsta), an_studii(_an_studii), numar_matricol(_numar_matricol), finantare(_finantare), numar_materii(_numar_materii)
	{
		this->adresa = new char[strlen(_adresa) + 1];
		strcpy_s(this->adresa, strlen(_adresa) + 1, _adresa);

		this->set_note(_note, _numar_materii);
		/*this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];   
		}*/ 
	}

	// Implementarea constructorului de copiere va rezolva problema care genereaza exceptiile lansate la executia destructorului - incercarea de a 
				//dezaloca a doua oara aceeasi zona de memorie care a fost anterior dezalocata
	// Aceasta implementare apeleazza constructorul cu parametri. In cadrul constructorului cu parametri alocarea memoriei este facuta corect pentru cele doua variabile membre de tip pointer

	/*
	Student(const Student& student):
		Student(student.nume, student.adresa, student.varsta, student.an_studii, student.note, student.numar_materii, student.numar_matricol, student.finantare)
	{

	}
	*/

	//Sa se implementeze constructorul de copiere fara a apela constructorul cu parametri astfel incat:
   //				- copierea valorilor (in noul obiect) sa se realizeze corect  
   //              - dezalocarea memoriei sa se realizeze fara a genera exceptii

   /*
   Student(const Student& student)
   {

   }
   */

   //setters
	void set_note(int* _note, int _numar_materii)
	{
		this->numar_materii = _numar_materii;
		//this->note = _note; shallow copy

		if (this->note != nullptr)
			delete[] this->note;
		this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];
		}
	}

	void set_numar_matricol(string _nr_matricol)
	{
		this->numar_matricol = _nr_matricol;
	}

	void set_finantare(finantare _finantare)
	{
		this->finantare = _finantare;
	}

	void set_nume(string _nume) {
		this->nume = _nume;
	}

	void set_adresa(char* _adresa) {
		this->adresa = _adresa;
	}

	void set_varsta(int _varsta) {
		this->varsta = _varsta;
	}

	void set_an_studii(int _an_studii) {
		this->an_studii = _an_studii;
	}


	//getters
	int* get_note() { return this->note; }
	string get_numar_matricol() { return this->numar_matricol; }
	finantare get_finantare() { return this->finantare; }
	int get_numar_materii() { return this->numar_materii; }


	//destructor
	~Student()
	{
		delete[] this->adresa;
		delete[] this->note;
	}
private: //nu pot fi accesati direct, vezi linia 124
	int* note;
	string numar_matricol;
	finantare finantare;
	int numar_materii;


};


//exemple vizibilitate - constructori/destructori/metode/atribute
//exemplu constructor de copiere

int main()
{
	Student s0; 
	//s0.numar_matricol = "UGb8798";

	s0.set_nume("AnghelMihai");
	s0.set_adresa((char*)"Bucuresti, sector 3");
	s0.set_varsta(20);
	s0.set_an_studii(2);

	//de ce este generata eroarea?
	// deoarece membrul note e privat
	//s0.note = new int[20];

	s0.set_numar_matricol("A689867");
	s0.set_finantare(finantare::BUGET_BURSA);

	// discutie eroare invalid heap pointer
	int note[10] = { 9,10,10,10,8,9,7,10,5,10 };
	s0.set_note(note, 10);

	//int note[10] = { 6,10,7,10,8,9,7,10,5,10 };
	//s0.set_note(note, 10);


	Student s1 = Student("Popescu I", (char*)"Bucuresti, Sector 1", 21, 2, note, 10, "A689867", finantare::BUGET_BURSA);

	/*Student s2 = s1;
	s2.nume = "Ionescu C";*/
}
