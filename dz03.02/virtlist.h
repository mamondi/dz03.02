#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

class Shape {
public:
    virtual void Show() const = 0;
    virtual void Save(ofstream& file) const = 0;
    virtual void Load(ifstream& file) = 0;
    virtual ~Shape() {}
};

class Square : public Shape {
private:
    double x, y, side;

public:
    Square(double x, double y, double side) : x(x), y(y), side(side) {}

    void Show() const override {
        cout << "Квадрат: Ліва верхня точка (" << x << ", " << y << "), Довжина сторони: " << side << endl;
    }

    void Save(ofstream& file) const override {
        file << "Square " << x << " " << y << " " << side << endl;
    }

    void Load(ifstream& file) override {
        file >> x >> y >> side;
    }
};

class Rectangle : public Shape {
private:
    double x, y, width, height;

public:
    Rectangle(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {}

    void Show() const override {
        cout << "Прямокутник: Ліва верхня точка (" << x << ", " << y << "), Ширина: " << width << ", Висота: " << height << endl;
    }

    void Save(ofstream& file) const override {
        file << "Rectangle " << x << " " << y << " " << width << " " << height << endl;
    }

    void Load(ifstream& file) override {
        file >> x >> y >> width >> height;
    }
};

class Circle : public Shape {
private:
    double x, y, radius;

public:
    Circle(double x, double y, double radius) : x(x), y(y), radius(radius) {}

    void Show() const override {
        cout << "Коло: Центр (" << x << ", " << y << "), Радіус: " << radius << endl;
    }

    void Save(ofstream& file) const override {
        file << "Circle " << x << " " << y << " " << radius << endl;
    }

    void Load(ifstream& file) override {
        file >> x >> y >> radius;
    }
};

class Ellipse : public Shape {
private:
    double x, y, majorAxis, minorAxis;

public:
    Ellipse(double x, double y, double majorAxis, double minorAxis) : x(x), y(y), majorAxis(majorAxis), minorAxis(minorAxis) {}

    void Show() const override {
        cout << "Еліпс: Ліва верхня точка (" << x << ", " << y << "), Велика вісь: " << majorAxis << ", Мала вісь: " << minorAxis << endl;
    }

    void Save(ofstream& file) const override {
        file << "Ellipse " << x << " " << y << " " << majorAxis << " " << minorAxis << endl;
    }

    void Load(ifstream& file) override {
        file >> x >> y >> majorAxis >> minorAxis;
    }
};
