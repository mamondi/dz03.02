#include "virtlist.h"

int main() {
    //������� ������������ ������� ������������ ����� ���
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Equation* equation1 = new LinearEquation(2, -4);
    Equation* equation2 = new QuadraticEquation(1, -3, 2);

    cout << "г������ 1 (������): ";
    equation1->solve();

    cout << "\nг������ 2 (���������): ";
    equation2->solve();

    delete equation1;
    delete equation2;

    return 0;
}