#include <iostream>
#include <string>

using namespace std;

class Pet {
protected:
    string name;

public:
    Pet(const string& petName) : name(petName) {}

    virtual void Sound() const = 0;

    void Show() const {
        cout << "Name: " << name << endl;
    }

    virtual void Type() const = 0;

    virtual ~Pet() {}
};


class Dog : public Pet {
public:
    Dog(const string& name) : Pet(name) {}

    void Sound() const override {
        cout << "Woof! Woof!" << endl;
    }

    void Type() const override {
        cout << "Type: Dog" << endl;
    }
};

class Cat : public Pet {
public:
    Cat(const string& name) : Pet(name) {}

    void Sound() const override {
        cout << "Meow! Meow!" << endl;
    }

    void Type() const override {
        cout << "Type: Cat" << endl;
    }
};

class Parrot : public Pet {
public:
    Parrot(const string& name) : Pet(name) {}

    void Sound() const override {
        cout << "Squawk! Squawk!" << endl;
    }

    void Type() const override {
        cout << "Type: Parrot" << endl;
    }
};

class Hamster : public Pet {
public:
    Hamster(const string& name) : Pet(name) {}

    void Sound() const override {
        cout << "Squeak! Squeak!" << endl;
    }

    void Type() const override {
        cout << "Type: Hamster" << endl;
    }
};

