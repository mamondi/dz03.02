#include "virtlist.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int maxSize = 100; 
    Shape* shapes[maxSize];
    int shapeCount = 0;

    while (true) {
        cout << "Оберіть дію:\n1. Додати фігуру\n2. Показати всі фігури\n3. Зберегти у файл\n4. Завантажити з файлу\n5. Вийти\n";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Оберіть тип фігури:\n1. Квадрат\n2. Прямокутник\n3. Коло\n4. Еліпс\n";
            int type;
            cin >> type;

            Shape* newShape = nullptr;

            switch (type) {
            case 1: {
                double x, y, side;
                cout << "Введіть координати лівої верхньої точки та довжину сторони квадрата:\n";
                cin >> x >> y >> side;
                newShape = new Square(x, y, side);
                break;
            }
            case 2: {
                double x, y, width, height;
                cout << "Введіть координати лівої верхньої точки та розміри прямокутника:\n";
                cin >> x >> y >> width >> height;
                newShape = new Rectangle(x, y, width, height);
                break;
            }
            case 3: {
                double x, y, radius;
                cout << "Введіть координати центра та радіус кола:\n";
                cin >> x >> y >> radius;
                newShape = new Circle(x, y, radius);
                break;
            }
            case 4: {
                double x, y, majorAxis, minorAxis;
                cout << "Введіть координати лівої верхньої точки, велику та малу вісі еліпса:\n";
                cin >> x >> y >> majorAxis >> minorAxis;
                newShape = new Ellipse(x, y, majorAxis, minorAxis);
                break;
            }
            default:
                cout << "Неправильний вибір\n";
                break;
            }

            if (newShape != nullptr && shapeCount < maxSize) {
                shapes[shapeCount++] = newShape;
                cout << "Фігура додана\n";
            }
            else if (newShape != nullptr) {
                cout << "Максимальна кількість фігур досягнута\n";
                delete newShape;
            }

            break;
        }
        case 2:
            for (int i = 0; i < shapeCount; ++i) {
                shapes[i]->Show();
            }
            break;
        case 3: {
            ofstream outFile("shapes.txt");

            if (!outFile.is_open()) {
                cout << "Помилка відкриття файлу\n";
                break;
            }

            for (int i = 0; i < shapeCount; ++i) {
                shapes[i]->Save(outFile);
            }

            outFile.close();
            cout << "Фігури збережено у файл\n";
            break;
        }
        case 4: {
            ifstream inFile("shapes.txt");

            if (!inFile.is_open()) {
                cout << "Файл не знайдено. Створення нового файлу.\n";
                break;
            }

            for (int i = 0; i < shapeCount; ++i) {
                delete shapes[i];
            }

            shapeCount = 0;

            while (!inFile.eof() && shapeCount < maxSize) {
                string type;
                inFile >> type;

                Shape* loadedShape = nullptr;

                if (type == "Square") {
                    double x, y, side;
                    inFile >> x >> y >> side;
                    loadedShape = new Square(x, y, side);
                }
                else if (type == "Rectangle") {
                    double x, y, width, height;
                    inFile >> x >> y >> width >> height;
                    loadedShape = new Rectangle(x, y, width, height);
                }
                else if (type == "Circle") {
                    double x, y, radius;
                    inFile >> x >> y >> radius;
                    loadedShape = new Circle(x, y, radius);
                }
                else if (type == "Ellipse") {
                    double x, y, majorAxis, minorAxis;
                    inFile >> x >> y >> majorAxis >> minorAxis;
                    loadedShape = new Ellipse(x, y, majorAxis, minorAxis);
                }

                if (loadedShape != nullptr) {
                    shapes[shapeCount++] = loadedShape;
                }
            }

            inFile.close();
            cout << "Фігури завантажено з файлу\n";
            break;
        }
        case 5:
            for (int i = 0; i < shapeCount; ++i) {
                shapes[i]->Show();
            }

            for (int i = 0; i < shapeCount; ++i) {
                delete shapes[i];
            }

            return 0;
        default:
            cout << "Неправильний вибір\n";
            break;
        }
    }

    return 0;
}