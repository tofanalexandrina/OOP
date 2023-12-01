//adaugati destructor
//constructor de copiere

#include <iostream>
#include <string>
using namespace std;


class Masina {
	string marca;
	char* model;
	string nr_inmatriculare;
	static int total_masini_fabricate;

public:

	Masina(string p_marca, char* p_model, string p_nr_inmatriculare) {
		this->marca =p_marca;
		this->model = new char[strlen(p_model) + 1];
		strcpy_s(this->model, strlen(p_model) + 1, p_model);
		this->nr_inmatriculare = nr_inmatriculare;

		incrementMasini();
	}
	Masina() {
		string marca = "";
		char* model = nullptr;
		string nr_inmatriculare = "";
	}

	void set_marca(string marca) {
		this->marca = marca;
	}

	void set_model(char* model) {
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}

	void set_nr_inmatriculare(string nr) {
		this->nr_inmatriculare = nr_inmatriculare;
	}

	void muta(string marca, char* model, string nr_inmatriculare) {
		this->marca = marca;
		this->model = model;
		this->nr_inmatriculare = nr_inmatriculare;
	}
	static void incrementMasini() {
		Masina::total_masini_fabricate++;

	}

	string get_marca() { return this->marca; }
	char* get_model() { char* copy = new char[strlen(this->model) + 1];
	strcpy_s(copy, strlen(this->model) + 1, this->model);
	return copy;
	}
	string get_nr_inmatriculare() { return this->nr_inmatriculare; }


	~Masina() {
		delete[] this->model;
	}
};



int Masina::total_masini_fabricate = 0;

int main() {
	Masina m1("Toyota", (char*)"Lexus", "CTI330");
	Masina::incrementMasini;
	Masina m2("Ford", (char*)"Focus", "CBA123");

	char* dslk = m1.get_model();
	cout << dslk;
	delete[] dslk;

	
}