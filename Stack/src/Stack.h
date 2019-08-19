#include <stdlib.h>
#include <iostream>

template <class T>
class Stack {
  public:
    Stack(void);
    Stack(const Stack<T>& copyStack);
    void push(const T& item);
    void pop(void);
    void clear(void);
    T top(void) const;
    bool empty(void) const;
    bool full(void) const;
    void print(void) const;
  private:
    static const int MAX = 50;
    T list[MAX];
    int topPtr;
};

template <class T>
Stack<T>::Stack(void) {
    this->topPtr = -1;
}

template <class T>
Stack<T>::Stack(const Stack<T>& copyStack) {
    this->topPtr = -1;
    if(!copyStack.empty()){
        for(int i=0; i<=49; i++) {
            this->push(copyStack.list[i]);
        }
    }
}

template <class T>
void Stack<T>::push(const T& item) {

    if(this->topPtr == this->MAX - 1) {
        std::cerr << "Stack overflow. Can't push" << '\n';
    } else {
        this->topPtr += 1;
        this->list[topPtr] = item;
    }
}

template <class T>
void Stack<T>::pop(void) {
    if(this->topPtr < 0) {
        std::cerr << "Stack is empty. Can't pop" << '\n';
    } else {
        this->topPtr -= 1;
    }
}

template <class T>
void Stack<T>::clear(void) {
    this->topPtr = -1;
}

template <class T>
T Stack<T>::top(void)const {
    if(this->topPtr < 0) {
        std::cerr << "Stack is empty. No top element." << '\n';
    } else {
        return this->list[topPtr];
    }
}

template <class T>
bool Stack<T>::empty(void) const {
    return (this->topPtr == -1);
}

template <class T>
bool Stack<T>::full(void) const {
    return (this->topPtr == this->MAX -1);
}

template <class T>
void Stack<T>::print(void) const {
    for (int i = this->topPtr; i >= 0; i--)
        std::cout << this->list[i] << '\n';
}
