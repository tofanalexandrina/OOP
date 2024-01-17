#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//lucru cu fisiere

class Person {
public:
    Person() : name(nullptr), age(0), id(nullptr) {}
    Person(const string& n, int a, const string& i) : age(a) {
        name = new char[n.size() + 1];
        strcpy_s(name, n.size() + 1, n.c_str());
        id = new char[i.size() + 1];
        strcpy_s(id, i.size() + 1, i.c_str());
    }

    // Destructor pentru a elibera memoria alocata dinamic
    ~Person() {
        delete[] name;
        delete[] id;
    }

    // Funcție de serializare
    void Serialize(ofstream& ofs) const {
        size_t nameLength = strlen(name) + 1;
        //write(const char*, count(cati octeti))
        //luam adresa si facem cast de la pointer de tip de date de dinainte la char*
        ofs.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength)); // Scriem lungimea numelui
        //scriem numele
        ofs.write(name, nameLength);
        ofs.write(reinterpret_cast<const char*>(&age), sizeof(age));
        size_t idLength = strlen(id) + 1;
        ofs.write(reinterpret_cast<const char*>(&idLength), sizeof(id));
        ofs.write(id, idLength);
    }

    // Funcție de deserializare
    void Deserialize(ifstream& ifs) {
        //astept sa il citesc
        size_t nameLength;
        //citesc lungimea, urmeaza sa scriu la adresa nameLength
        //read(char*, count)
        ifs.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength)); // Citim lungimea numelui
        //vrem sa suprascriem
        delete[] name;
        //alocam spatiu de memorie pentru ce urmeaza sa scriu
        name = new char[nameLength];
        ifs.read(name, nameLength);
        ifs.read(reinterpret_cast<char*>(&age), sizeof(age));
        size_t idLength;
        ifs.read(reinterpret_cast<char*>(&idLength), sizeof(idLength));
        delete[] id;
        id = new char[idLength];
        ifs.read(id, idLength);
    }

    void DisplayInfo() const {
        cout << "Name: " << name << ", Age: " << age <<", Id: "<<id<< endl;
    }

private:
    char* name;
    int age;
    char* id;
};

int main() {
    // Salvare obiect într-un fișier binar
    {
        //mod de scriere
        ofstream outputFile("person.dat", ios::binary);
        //important
        if (!outputFile) {
            cerr << "Error opening file for writing." << endl;
            return 1;
        }

        Person personToSave("John Doe", 25, "6031224803913");
        personToSave.Serialize(outputFile);

        cout << "Object saved successfully." << endl;
    }

    // Restaurare obiect din fișier binar
    {
        ifstream inputFile("person.dat", ios::binary);
        if (!inputFile) {
            cerr << "Error opening file for reading." << endl;
            return 1;
        }

        Person restoredPerson;
        restoredPerson.Deserialize(inputFile);

        cout << "Object restored successfully." << endl;
        restoredPerson.DisplayInfo();
    }

    return 0;
}
