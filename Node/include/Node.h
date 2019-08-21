template <class T>
class Node {
  public:
    Node(const T& item);
    Node(const T& item, Node<T>* nextNode);
    Node<T>* next(void) const;
    void insertNext(Node<T>* nextNode);
    Node<T>* removeNext(void);
    T getData(void) const;
    void changeData(T& item);
  private:
    T data;
    Node<T>* nextPtr;
};

/**
	*  @brief  Default constructor.
	*  @param  item  Data to be stored in the node.
	*  @return  void.
	*
	*  The constructor initializes variables.
	*/
template <class T>
Node<T>::Node(const T& item) {
    data = item;
    nextPtr = nullptr;
}

/**
	*  @brief  Default constructor.
	*  @param  item  Data to be stored in the node.
	*  @param  nextNode   The next node of the node.
	*  @return  void.
	*
	*  The constructor initializes variables.
	*/
template <class T>
Node<T>::Node(const T& item, Node<T>* nextNode) {
    data = item;
    nextPtr = nextNode;
}

/**
	*  @brief  Returns the next node of the node.
	*  @param  void.
	*  @return  Node pointer of type T.
	*/
template <class T>
Node<T>* Node<T>::next(void) const {
    return nextPtr;
}

/**
	*  @brief  Inserts a node after the node.
	*  @param  nextNode  Pointer to the node to be inserted.
	*  @return  void.
	*
	*  Inserts the nextNode after the node and chains nextNode to the
	*  old next of the node.
	*
	*/
template <class T>
void Node<T>::insertNext(Node<T>* nextNode) {
    nextNode->nextPtr = nextPtr;
    nextPtr = nextNode;
}

/**
	*  @brief  Removes the nextPtr field of the node.
	*  @param  void.
	*  @return  Node of type T.
	*
	*  Removes the nextPtr field and equates it to nullptr.
	*  Returns the removed pointer.
	*
	*/
template <class T>
Node<T>* Node<T>::removeNext(void) {
    Node<T>* removedPtr = nextPtr;
    nextPtr = nullptr;
    return removedPtr;
}

/**
	*  @brief  Retrieves the node data.
	*  @param  void.
	*  @return  Data of type T.
	*/
template <class T>
T Node<T>::getData(void) const {
    return data;
}

/**
	*  @brief  Changes the node data.
	*  @param  item  The new data of the node.
	*  @return  void.
	*/
template <class T>
void Node<T>::changeData(T& item) {
    data = item;
}
