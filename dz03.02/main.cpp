#include "virtlist.h"

int main() {
    //приклад використання функцій згенерований чатом гпт
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Equation* equation1 = new LinearEquation(2, -4);
    Equation* equation2 = new QuadraticEquation(1, -3, 2);

    cout << "Рівняння 1 (лінійне): ";
    equation1->solve();

    cout << "\nРівняння 2 (квадратне): ";
    equation2->solve();

    delete equation1;
    delete equation2;

    return 0;
}