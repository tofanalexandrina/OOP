#include <iostream>
#include <string>

using namespace std;

class Date {
	int day;
	int month;
	int year;

public:
	Date(): day(0), month(0), year(0){}
	Date(int d, int m, int y): day(d), month(m), year(y){}
};

//has a
class Person {
	string name;
	string CNP;
	Date birthday;
	string* addresses;
	int addrCount;
public:
	Person() {
		this->name = "";
		this->CNP = "";
		Date d;
		this->birthday = d;
		this->addresses = nullptr;
		this->addrCount = 0;
	}

	Person(string name, string CNP, Date birthday, string* addresses, int addrCount) : name(name), CNP(CNP), addrCount(addrCount) {
		this->birthday = birthday;
		this->addresses = new string[addrCount];
		for (int i = 0; i < addrCount; i++) {
			this->addresses[i] = addresses[i];
		}
	}
	//Constructor de copiere
	Person(const Person& p) : name(p.name), CNP(p.CNP), addrCount(p.addrCount) {
		this->birthday = p.birthday;
		this->addresses = new string[p.addrCount];
		for (int i = 0; i < p.addrCount; i++) {
			this->addresses[i] = p.addresses[i];
		}
	}
	//Operator =
	Person& operator= (const Person& p){
		if (this == &p)
		delete[] addresses;
			return *this;
		this->name = p.name;
		this->CNP = p.CNP;
		this->addrCount = p.addrCount;
		this->birthday = p.birthday;
		this->addresses = new string[p.addrCount];
		for (int i = 0; i < p.addrCount; i++) {
			this->addresses[i] = p.addresses[i];
		}
		return *this;
	}
	//Destructor
	~Person() {
		delete[] addresses;
	}

};

//is a derivare, student mosteneste tot din persoana
class Student : Person {
	int registrationNr;
	float* grades;
	int nrGrades;
	bool scolarship;

public:
	Student(): Person(){
		this->registrationNr = 0;
		this->grades = nullptr;
		this->nrGrades = 0;
		this->scolarship = false;
	}

	Student(string name, string CNP, Date birthday, string* addresses, int addrCount, int registrationNr, float* grades, int nrGrades, bool scolarship):
		Person(name, CNP, birthday, addresses, addrCount), registrationNr(registrationNr), nrGrades(nrGrades), scolarship(scolarship) {
		this->grades = new float[nrGrades];
		for (int i = 0; i < nrGrades; i++) {
			this->grades[i] = grades[i];
		}
	}

	//constr de copiere
	Student (const Student& s) :
		Person(s), nrGrades(s.nrGrades), scolarship(s.scolarship) {
		this->grades = new float[s.nrGrades];
		for (int i = 0; i < s.nrGrades; i++) {
			this->grades[i] = s.grades[i];
		}
	}
	//op=
	Student& operator=(const Student& s) {
		if (this != &s)
			return *this;
		delete[] grades;
		Person(s);
		this->nrGrades = s.nrGrades;
		this->scolarship = s.scolarship;
		this->grades = new float[s.nrGrades];
		for (int i = 0; i < s.nrGrades; i++) {
			this->grades[i] = s.grades[i];
		}
		return *this;
	}
	//destructor
	~Student() {
		delete[] grades;
	}
};


//Has a 1 la mai multi
class University {
	string name="";
	string address="";
	Student* students=nullptr;
	int studentsCount=0;

public:
	University(string name, string address, Student* students, int studentsCount){
		this->name = name;
		this->address = address;
		this->studentsCount = studentsCount;
		//n-am supraincarcat operator =
		//daca implementam destructorul pe grades am avea exceptie - incercam sa stergem de 2 ori aceeasi zona de memorie
		this->students = new Student[studentsCount];
		for (int i = 0; i < studentsCount; i++) {
			this->students[i] = students[i];
		}
	}

	University(const University& u) {
		this->name = u.name;
		this->address = u.address;
		this->studentsCount = u.studentsCount;
		this->students = new Student[u.studentsCount];
		for (int i = 0; i < u.studentsCount; i++) {
			this->students[i] = u.students[i];
		}
	}

	University& operator=(const University& u) {
		if (this != &u) {
			delete[] this->students;
			this->name = u.name;
			this->address = u.address;
			this->studentsCount = u.studentsCount;
			this->students = new Student[u.studentsCount];
			for (int i = 0; i < u.studentsCount; i++) {
				this->students[i] = u.students[i];
			}
		}
		return *this;
	}

	~University() {
		delete[] this->students;
	}
};

int main() {
	Date d1;
	Date d2(6, 12, 2023);

	Person p1;
	string* addresses = new string[3];
	addresses[0] = "..Bucuresti";
	addresses[1] = "..Arad";
	addresses[2] = "..Constanta";
	
	Person p2("Popescu Andrei", "1920505252516", d2, addresses, 3);

	Student s1;

	float grades[]{6, 7, 2, 8, 9};
	Student s2("Popescu Andrei", "1920505252516", d2, addresses, 3, 124, grades, 5, true);
	Student s3("Andresan Andrei", "1920505252516", d2, addresses, 3, 124, grades, 5, true);

	Student* students = new Student[3];
	students[0] = s1;
	students[1] = s2;
	students[2] = s3;

	University u1("ASE", "Bucuresti", students, 3);
	return 0;
}