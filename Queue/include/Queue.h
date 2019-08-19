#include <stdlib.h>
#include <iostream>

template <class T>
class Queue {
	public:
		Queue(void);
		Queue(Queue<T>& copyQueue);
		bool empty(void) const;
		std::size_t size(void) const;
		void clear(void);
		T front(void) const;
		void pop(void);
		void push(T& item);
		void print(std::ostream& os);
	private:
	    static const std::size_t MAX_SIZE = 50;
	    T list[MAX_SIZE];
	    T* frontPtr;
	    T* backPtr;
	    std::size_t sizeQ;
};

template <class T>
Queue<T>::Queue(void) {
	frontPtr = nullptr;
	backPtr = nullptr;
	sizeQ = 0;
}

template <class T>
Queue<T>::Queue(Queue<T>& copyQueue) {
	frontPtr = nullptr;
	backPtr = nullptr;
	sizeQ = 0;
    if(copyQueue.backPtr >= copyQueue.frontPtr){
		for(T* i = copyQueue.frontPtr; i <= copyQueue.backPtr; i++){
			push(*i);
		}
	}
	else {
		for(T* i = copyQueue.frontPtr; i <= (copyQueue.list + MAX_SIZE -1); i++){
			push(*i);

		}
		for(T* i = copyQueue.list; i <= copyQueue.backPtr; i++) {
			push(*i);
		}
	}
}

template <class T>
bool Queue<T>::empty(void) const {
	return (sizeQ == 0);
}

template <class T>
std::size_t Queue<T>::size(void) const {
	return sizeQ;
}


template <class T>
void Queue<T>::clear(void) {
	frontPtr = nullptr;
	backPtr = nullptr;
	sizeQ = 0;
}

template <class T>
T Queue<T>::front(void) const {
	if(frontPtr == nullptr) {
		std::cerr << "Queue is empty. No front value" << '\n';
	}
	else {
		return *frontPtr;
	}
}

template <class T>
void Queue<T>::pop(void) {
	if(sizeQ == 0) {
		std::cerr << "Queue is empty. Can't pop." << '\n';
	}
	else{
		frontPtr = list + ((frontPtr - list + 1) % MAX_SIZE);
		sizeQ -= 1;
	}
}

template <class T>
void Queue<T>::push(T& item) {
	if(sizeQ == MAX_SIZE) {
		std::cerr << "Queue is full. Can't push" << '\n';
	}
	else{
		if(sizeQ == 0) {
			frontPtr = backPtr = list;
		}
		else {
			backPtr = list + ((backPtr - list + 1) % MAX_SIZE);
		}
		*backPtr = item;
		sizeQ += 1;
	}
}

template <class T>
void Queue<T>::print(std::ostream& os) {
	if(backPtr >=frontPtr){
		for(T* i = frontPtr; i <= backPtr; i++){
                os << *i <<	'\n';
		}
	}
	else {
		for(T* i = frontPtr; i <= (list + MAX_SIZE -1); i++){
			os << *i <<	'\n';
		}
		for(T* i = list; i <= backPtr; i++) {
			os << *i <<	'\n';
		}
	}
}
