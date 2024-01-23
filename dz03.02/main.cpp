#include "virtlist.h"

int main() {
    List* stack = new Stack();
    stack->insert(1);
    stack->insert(2);
    stack->insert(3);

    cout << "Stack Elements: ";
    for (int i = 0; i < 3; ++i) {
        cout << stack->remove() << " ";
    }
    cout << endl;

    delete stack;

    List* queue = new Queue();
    queue->insert(1);
    queue->insert(2);
    queue->insert(3);

    cout << "Queue Elements: ";
    for (int i = 0; i < 3; ++i) {
        cout << queue->remove() << " ";
    }
    cout << endl;

    delete queue;

    return 0;
}