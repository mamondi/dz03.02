#include <iostream>

using namespace std;

class List {
public:
    virtual void insert(int value) = 0;
    virtual int remove() = 0;
    virtual ~List() {}
};

class Stack : public List {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* top;
public:
    Stack() : top(nullptr) {}

    void insert(int value) override {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int remove() override {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

class Queue : public List {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void insert(int value) override {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int remove() override {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int value = front->data;
        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return value;
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

