#include <iostream>
#include <string>

using namespace std;

class Carte {
private:
	char* titlu;
	string autor;
	int nr_pagini;
	double pret;
	bool electronica;
	int* nr_cuv_pag;

public:
	//constructor cu parametri
	Carte(char* _titlu, string _autor, int _nr_pagini, double _pret, bool _electronica, int* _nr_cuv_pag)
	{
		autor = _autor;
		nr_pagini = _nr_pagini;
		pret = _pret;
		electronica = _electronica;

		this->titlu = new char[strlen(_titlu) + 1];
		strcpy_s(this->titlu, strlen(_titlu) + 1, _titlu);

		this->set_nr_cuv_pag(_nr_cuv_pag, _nr_pagini);

	}

	//constructor de copiere
	Carte(const Carte& carte) {
		this->titlu = new char[strlen(carte.titlu) + 1];
		autor = carte.autor;
		nr_pagini = carte.nr_pagini;
		pret = carte.pret;
		electronica = carte.electronica;
		this->nr_cuv_pag = new int[carte.nr_pagini];
		for (int i = 0; i < carte.nr_pagini; i++) {
			this->nr_cuv_pag[i] = carte.nr_cuv_pag[i];
		};

	}

	// definire constructor
	Carte() {
		titlu = nullptr;
		autor = "";
		nr_pagini = 0;
		pret = 0.0;
		electronica = false;
		nr_cuv_pag = nullptr;
	}



	//setters
	void set_nr_cuv_pag(int* _nr_cuv_pag, int _nr_pagini) {
		this->nr_pagini = _nr_pagini;
		if (this->nr_cuv_pag != nullptr)
			delete this->nr_cuv_pag;
		this->nr_cuv_pag = new int[_nr_pagini];
		for (int i = 0; i < _nr_pagini; i++)
		{
			this->nr_cuv_pag[i] = _nr_cuv_pag[i];
		}

	}

	void set_nr_pagini(int _nr_pagini) {
		this->nr_pagini = _nr_pagini;
	}

	void set_titlu(char* _titlu) {
		this->titlu = _titlu;
	}

	void set_autor(string _autor) {
		this->autor = _autor;
		
	}

	void set_pret(int _pret) {
		this->pret = _pret;
	}

	void set_electronica(bool _electronica) {
		this->electronica = _electronica;
	}

	//getters
	char* get_titlu() { return this->titlu; }
	int get_nr_pagini() { return this->nr_pagini; }
	int* get_nr_cuv_pag() { return this->nr_cuv_pag; }
	int get_pret() { return this->pret; }
	string get_autor() { return this->autor; };
	bool get_electronica() { return this->electronica; }

	
	

	//destructor
	~Carte() {
		delete[] this->nr_cuv_pag;
		delete[] this->titlu;
	}
}; 



int main() {

	//nu mergea si am facut un constructor default in care am inintializat atributele
	Carte c1;
	c1.set_titlu((char*)"Dune");
	c1.set_autor("Frank Herbert");
	c1.set_nr_pagini(566);
	c1.set_pret(109.90);
	c1.set_electronica(false);
	int nr_cuv_pag[5] = {1, 2, 3, 4, 5};
	c1.set_nr_cuv_pag(nr_cuv_pag, 5);

}