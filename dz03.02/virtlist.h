#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

class Equation {
public:
    virtual void solve() = 0; 
    virtual ~Equation() {} 
};

class LinearEquation : public Equation {
private:
    double a, b;  

public:
    LinearEquation(double a, double b) : a(a), b(b) {}

    void solve() override {
        if (a == 0) {
            if (b == 0) {
                cout << "Безліч коренів (рівняння тотожне)\n";
            }
            else {
                cout << "Рівняння не має коренів\n";
            }
        }
        else {
            double x = -b / a;
            cout << "Один корінь рівняння: x = " << x << endl;
        }
    }
};

class QuadraticEquation : public Equation {
private:
    double a, b, c;

public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    void solve() override {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Два корені рівняння: x1 = " << x1 << ", x2 = " << x2 << endl;
        }
        else if (discriminant == 0) {
            double x = -b / (2 * a);
            cout << "Один корінь рівняння: x = " << x << endl;
        }
        else {
            cout << "Рівняння не має дійсних коренів\n";
        }
    }
};

