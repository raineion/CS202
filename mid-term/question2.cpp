#include <iostream>
using namespace std;

// Encapsulation Example
class Car {
private:
    int speed; // Private member variable to store the speed of the car
    string color; // Private member variable to store the color of the car

public:
    // Constructor to initialize the speed and color of the car
    Car(int s, string c) : speed(s), color(c) {}

    // Method to increase the speed of the car
    void accelerate() {
        speed += 5;
    }

    // Method to decrease the speed of the car
    void brake() {
        speed -= 5;
    }

    // Getter method to retrieve the current speed of the car
    int getSpeed() const {
        return speed;
    }
};

// Inheritance Example
class ElectricCar : public Car {
private:
    int batteryLevel; // Private member variable to store the battery level of the electric car

public:
    // Constructor to initialize the speed, color, and battery level of the electric car
    // Calls the constructor of the base class Car to initialize the speed and color
    ElectricCar(int s, string c, int b) : Car(s, c), batteryLevel(b) {}

    // Method to increase the battery level of the electric car
    void charge() {
        batteryLevel += 10;
    }

    // Getter method to retrieve the current battery level of the electric car
    int getBatteryLevel() const {
        return batteryLevel;
    }
};

// Polymorphism Example
class Animal {
public:
    // Virtual method to be overridden by derived classes to make a sound
    virtual void makeSound() const {
        cout << "Some generic animal sound" << endl;
    }
};

// Derived class Dog from base class Animal
class Dog : public Animal {
public:
    // Override the makeSound method to provide the specific sound for a dog
    void makeSound() const override {
        cout << "Bark" << endl;
    }
};

// Derived class Cat from base class Animal
class Cat : public Animal {
public:
    // Override the makeSound method to provide the specific sound for a cat
    void makeSound() const override {
        cout << "Meow" << endl;
    }
};

// Function to demonstrate polymorphism by calling the makeSound method on an Animal reference
void playSound(const Animal& animal) {
    animal.makeSound(); // Calls the appropriate makeSound method based on the actual object type
}

int main() {
    // Test Encapsulation
    // Create a Car object with initial speed 0 and color "Red"
    Car myCar(0, "Red");
    // Accelerate the car and print its speed
    myCar.accelerate();
    cout << "Car speed: " << myCar.getSpeed() << endl;

    // Test Inheritance
    // Create an ElectricCar object with initial speed 0, color "Blue", and battery level 100
    ElectricCar myElectricCar(0, "Blue", 100);
    // Charge the electric car and print its battery level
    myElectricCar.charge();
    cout << "Electric car battery level: " << myElectricCar.getBatteryLevel() << endl;

    // Test Polymorphism
    // Create Dog and Cat objects
    Dog myDog;
    Cat myCat;
    // Play sound for both Dog and Cat using the playSound function
    playSound(myDog); // Outputs "Bark" because myDog is a Dog object
    playSound(myCat); // Outputs "Meow" because myCat is a Cat object

    return 0;
}
