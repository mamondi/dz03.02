#include "virtlist.h"

int main() {
    Dog dog("Buddy");
    Cat cat("Whiskers");
    Parrot parrot("Polly");
    Hamster hamster("Fluffy");

    dog.Show();
    dog.Sound();
    dog.Type();
    cout << endl;

    cat.Show();
    cat.Sound();
    cat.Type();
    cout << endl;

    parrot.Show();
    parrot.Sound();
    parrot.Type();
    cout << endl;

    hamster.Show();
    hamster.Sound();
    hamster.Type();

    return 0;
}