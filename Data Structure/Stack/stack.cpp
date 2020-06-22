//Implementation of stack using Array

/* Stack is a linear data structure which follow a particular order in which the operations
 are performed. The Order may be LIFO or FILO. */

#include <iostream>
using namespace std;

const int MAX_SIZE = 10000;

class Stack {
    public:
        Stack();
        ~Stack();
        void push(int n);
        void pop();
        int top();
        bool isEmpty() const;
        void print() const;
    private:
        int* array [MAX_SIZE];
        int curNum;
};

Stack::Stack() {
    curNum = 0;
}

Stack::~Stack() {
    for (int i = 0; i < curNum; ++i) 
        delete array[i];
}

void Stack::push(int n) {
    if (curNum >= MAX_SIZE) {
        cout << "reached maximum capacity...can't add an element\n";
        return;
    }
    array[curNum] = new int(n);
    curNum++;
}

void Stack::pop() {
    delete array[curNum];
    curNum--;
}

int Stack::top() {
    return *array[curNum];
}

void Stack::print() const{
    for (int i = 0; i < curNum; ++i) 
        cout << *array[i] << endl;
}

bool Stack::isEmpty() const{
    return curNum == 0;
}

int main () {
    Stack stack;
    stack.push(5);
    stack.print();
    stack.pop();
}