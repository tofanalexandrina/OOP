#include <iostream>
#include <string>

using namespace std;

class A {
	string attrA;

public:
	A(string attrA){
		this->attrA = attrA;
	}

	virtual string show() {
		return "I'm A!";
	}
};

class B : public A {
	string attrB="";
	A** all = nullptr;
public:
	B(string attrA, string attrB):A(attrA), attrB(attrB){}
	string show() override{
		return "I'm B!";
	 }
};

int main() {
	A** vect = new A * [4];
	vect[0] = new A("fdnkvj");
	vect[1] = new B("fdhvbk", "fjbv");
	vect[2] = new B("fdksk", "jdsbk");
	vect[3] = new A("jdbskj");
	cout << vect[0]->show() << endl;
	cout<<vect[1]->show() << endl;
	cout<<vect[2]->show() << endl;
	cout<<vect[3]->show() << endl;
}