// NOTE: The "Bad way" codes are commented so the compiler will not raise an error for redifinition of classes in both "Correct way" and "Bad way". If you want to test any of the "Bad way" codes, make sure to comment the "Correct way" code and uncomment the corresponding "Bad way" code of the same principal.

#include <iostream>
#include <vector>

using namespace std;

// What is SOLID: SOLIID is a set of five OOP(Object-Oriented Programming) design principals that help create better codes which are flexible, scalable and maintainable.

// SOLID stands for:
/*
S -> Single Responsibility Principle (SRP)
O -> Open/Closed Principle (OCP)
L -> Liskov Substitution Principle (LSP)
I -> Interface Segregation Principle (ISP)
D -> Dependency Inversion Principle (DIP)
*/


/* 
1. Single Responsibility Principle (SRP):
A class should only have one reason to change, simply means it has one job or responsibility.
*/

// Bad way: The Employee class handles responsibility of both calculating salary and saving to the database, so it needs to be modified if salary calculation logic or database changes; This violates SRP.

/*
class Employee {
public:
    void calculateSalary() {
        cout << "Calculating salary." << endl;
    }
    void saveToDatabase() {
        cout << "Saving to database." << endl;
    }
};

*/

// Correct way: Now both classes have separate responsibilities to handle, SalaryCalculator calculates Salary and EmployeeDatabase works in saving to the database. This makes it easier to modify and maintain.

class SalaryCalculator {
public:
    void calculateSalary() {
        cout << "Calculating salary." << endl;
    }
};

class EmployeeDatabase {
public:
    void saveToDatabase() {
        cout << "Saving to database." << endl;
    }
};


/*
2. Open/Closed Principle (OCP): A class should be open for extending, but closed for modification. You should be able to add new functionality to it without changing its existing code.
*/

// Bad way: You need to modify the AreaCalculator class whenever you add a new shape (e.g., Rectangle or Triangle).

/*
class Shape {
public:
    enum class ShapeType { Circle, Square };
    ShapeType type;
};

class AreaCalculator {
public:
    double calculateArea(Shape &shape) {
        if (shape.type == Shape::ShapeType::Circle) {
            // example code
            return 3.14159 * 5 * 5;
        } else if (shape.type == Shape::ShapeType::Square) {
            // example code
            return 4 * 4;
        }
    }
};

*/

// Correct way: Use polymorphism, allowing new shapes to be added without changing the AreaCalculator class's existing code.

class Shape {
public:
    virtual double calculateArea() const = 0;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double calculateArea() const override {
        return side * side;
    }
};

class AreaCalculator {
public:
    double calculateArea(const Shape &shape) {
        return shape.calculateArea();
    }
};


/*
3. Liskov Substitution Principle (LSP):
Objects of a superclass should be replaceable with objects of a subclass without affecting the correctness of the program.
*/

// Bad way: Ostrich inherits from Bird but cannot fly, so this violates the principle.

/*
class Bird {
public:
    virtual void fly() = 0;
};

class Sparrow : public Bird {
public:
    void fly() override {
        cout << "Sparrow is flying!" << endl;
    }
};

class Ostrich : public Bird {
public:
    void fly() override {
        // Ostriches can't fly, so this is wrong!
        cout << "Ostriches can't fly!" << endl;
    }
};

*/

// Correct way: Use a more common and general method (move), which applies to both birds that fly and also those that don't.

class Bird {
public:
    virtual void move() = 0;
};

class Sparrow : public Bird {
public:
    void move() override {
        cout << "Sparrow is flying!" << endl;
    }
};

class Ostrich : public Bird {
public:
    void move() override {
        cout << "Ostrich is walking!" << endl;
    }
};


/*
4. Interface Segregation Principle (ISP):
A class shouldn't be forced to implement interfaces it doesn't use. You should prefer many small and specific interfaces over one large and general-purpose interface.
*/

// Bad way: The Robot class is forced to implement a method it doesn't need (eat), violating ISP.

/*
class IWorker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
};

class Worker : public IWorker {
public:
    void work() override {
        cout << "Worker is working!" << endl;
    }

    void eat() override {
        cout << "Worker is eating!" << endl;
    }
};

class Robot : public IWorker {
public:
    void work() override {
        cout << "Robot is working!" << endl;
    }

    void eat() override {
        // Robots don't eat, but still must implement this method
        cout << "Robot doesn't eat!" << endl;
    }
};

*/

// Correct way: Split interfaces into smaller ones, allowing classes to implement only what they need instead of everything.

class IWorkable {
public:
    virtual void work() = 0;
};

class IEatable {
public:
    virtual void eat() = 0;
};

class Worker : public IWorkable, public IEatable {
public:
    void work() override {
        cout << "Worker is working!" << endl;
    }

    void eat() override {
        cout << "Worker is eating!" << endl;
    }
};

class Robot : public IWorkable {
public:
    void work() override {
        cout << "Robot is working!" << endl;
    }
    // No need to implement eat() since robots don't eat
};


/*
5. Dependency Inversion Principle (DIP):
High-level modules should not depend on low-level modules. Both should depend on abstractions. Furthermore, abstractions should not depend on details. Details should depend on abstractions.
*/

// Bad way: The Switch class directly depends on the LightBulb class, violating DIP.

/*
class LightBulb {
public:
    void turnOn() {
        cout << "Lightbulb is on!" << endl;
    }

    void turnOff() {
        cout << "Lightbulb is off!" << endl;
    }
};

class Switch {
    LightBulb bulb;
public:
    void operate() {
        bulb.turnOn();  // Tightly connected to LightBulb and needs to be modified for other devices
    }
};

*/

// Correct way: Use abstractions so that the Switch class can control any device (LightBulb, Fan, Heater etc.).

class Switchable {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class LightBulb : public Switchable {
public:
    void turnOn() override {
        cout << "Lightbulb is on!" << endl;
    }

    void turnOff() override {
        cout << "Lightbulb is off!" << endl;
    }
};

class Fan : public Switchable {
public:
    void turnOn() override {
        cout << "Fan is on!" << endl;
    }

    void turnOff() override {
        cout << "Fan is off!" << endl;
    }
};

class Switch {
    Switchable &device;
public:
    Switch(Switchable &device) : device(device) {}

    void operate() {
        device.turnOn();  // No direct dependency on LightBulb, works for Fan as well
    }
};

int main() {
    // Usage of all class-functions
    SalaryCalculator salaryCalc;
    EmployeeDatabase empDB;
    Circle circle(5.00);
    Square square(4.00);
    Sparrow sparrow;
    Ostrich ostrich;
    Worker worker;
    Robot robot;
    LightBulb light;
    Fan fan;
    
    salaryCalc.calculateSalary();
    empDB.saveToDatabase();
    cout << circle.calculateArea() << endl;
    cout << square.calculateArea() << endl;
    sparrow.move();
    ostrich.move();
    worker.work();
    worker.eat();
    robot.work();
    light.turnOn();
    light.turnOff();
    fan.turnOn();
    fan.turnOff();
    return 0;
}