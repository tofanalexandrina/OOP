#include <iostream>

#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Shape {
public:
    // Constructor
    Shape(const string& name) : name_(name) {}

    // Pure virtual function to calculate area (abstract method)
    //pur virtuala, deoarece implementarea nu ar avea sens aici
    virtual double CalculateArea() const = 0;

    // Virtual function to display shape information
    virtual void DisplayDetails() const {
        cout << "Shape: " << name_ << endl;
    }
    //pentru a le putea accesa din clasa derivata
protected:
    string name_;
};

// Derived class for a circle
class Circle : public Shape {
public:
    // Constructor
    Circle(const string& name, double radius) : Shape(name), radius_(radius) {}

    // Override method to calculate the area of a circle
    double CalculateArea() const override {
        return 3.14 * radius_ * radius_;
    }

    // Override method to display information about the circle
    //override ca sa se stie ca e metoda virtuala, good practice
    void DisplayDetails() const override {
        Shape::DisplayDetails();
        cout << "Type: Circle\nRadius: " << radius_ << endl;
    }

private:
    double radius_;
};

// Derived class for a rectangle
class Rectangle : public Shape {
public:
    // Constructor
    Rectangle(const string& name, double length, double width)
        : Shape(name), length_(length), width_(width) {}

    // Override method to calculate the area of a rectangle
    double CalculateArea() const override {
        return length_ * width_;
    }

    // Override method to display information about the rectangle
    void DisplayDetails() const override {
        //scope operator
        Shape::DisplayDetails();
        cout << "Type: Rectangle\nLength: " << length_ << "\nWidth: " << width_ << endl;
    }

private:
    double length_;
    double width_;
};

int main() {
    // Creating an object of type Circle and calling virtual methods
    Circle circle("My Circle", 5.0);
    circle.DisplayDetails();
    cout << "Area: " << circle.CalculateArea() << endl;

    cout << "\n------------------------\n";

    // Creating an object of type Rectangle and calling virtual methods
    Rectangle rectangle("My Rectangle", 4.0, 6.0);
    rectangle.DisplayDetails();
    cout << "Area: " << rectangle.CalculateArea() << endl;


    //implementare seminar:
    Shape* s1, * s2;
    s1 = new Circle("New circle", 6.0);
    s1->DisplayDetails();
    cout << "Cerc: " << s1->CalculateArea() << endl;
    
    s2 = new Rectangle("New rectangle", 5.0, 7.0);
    s2->DisplayDetails();
    cout << "Rectangle: " << s2->CalculateArea() << endl;


    return 0;
}
