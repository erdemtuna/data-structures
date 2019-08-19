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
    void print(std::ostream& os) const;
  private:
    static const std::size_t MAX_SIZE = 50;
    T list[MAX_SIZE];
    T* topPtr;
    std::size_t size;
};

template <class T>
Stack<T>::Stack(void) {
    topPtr = nullptr;
    size = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T>& copyStack) {
    topPtr = nullptr;
    size = 0;
    if(!copyStack.empty()) {
        for(std::size_t i=0; i<copyStack.size; i++) {
            push(copyStack.list[i]);
        }
    }

}

template <class T>
void Stack<T>::push(const T& item) {
    if(size == MAX_SIZE) {
        std::cerr << "Stack overflow. Can't push" << '\n';
    } else {
        if(topPtr == nullptr) {
            topPtr = list;
        } else {
            topPtr += 1;
        }
        size += 1;
        *topPtr = item;
    }
}

template <class T>
void Stack<T>::pop(void) {
    if(topPtr == nullptr) {
        std::cerr << "Stack is empty. Can't pop" << '\n';
    } else {
        if(topPtr == list) {
            topPtr = nullptr;
        } else {
            topPtr -= 1;
        }
        size -= 1;
    }
}

template <class T>
void Stack<T>::clear(void) {
    topPtr = nullptr;
    size = 0;
}

template <class T>
T Stack<T>::top(void)const {
    if(topPtr == nullptr) {
        std::cerr << "Stack is empty. No top element." << '\n';
    } else {
        return *topPtr;
    }
}

template <class T>
bool Stack<T>::empty(void) const {
    return (topPtr == nullptr);
}

template <class T>
bool Stack<T>::full(void) const {
    return (size == MAX_SIZE);
}

template <class T>
void Stack<T>::print(std::ostream& os) const {
    os << "size: " << size << '\n';
    if(size) {
        for (std::size_t i = 0; i < size; i++)
            os << *(topPtr - i) << '\n';
    } else {
        os << "Stack is empty, nothing to print." << '\n';
    }

}
