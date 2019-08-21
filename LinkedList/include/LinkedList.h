#include "../../Node/include/Node.h"

template<class T>
class LinkedList {
  public:
    LinkedList(void); //c'tor
    LinkedList(const LinkedList<T>& copyList); //copy c'tor
    ~LinkedList(void); //d'tor

    void insertAt(const T& item); //insert node at currPtr position
    void insertAfter(const T& item); //insert node after currPtr position
    void insertHead(const T& item); //insert node at headPtr position
    void insertTail(const T& item); //insert node at tailPtr position

    void removeAt(void); //remove the node at currPtr position
    void removeHead(void); // remove the head node

    void clear(void); //returns list to initial case
    void freeNode(Node<T>* node); //free dynamic memory of a node

    std::size_t size(void) const; //size of the list
    bool empty(void) const; //the list is empty or not
    T nodeData(Node<T>* node) const; //retrieve the input node data

    void moveToHead(void);//move currPtr to headPtr position
    void moveToTail(void); //move currPtr to tailPtr position
    void moveToPos(int n); //move currPtr to nth position
    int getPos(void) const; //the position of the currPtr

    void print(std::ostream& os); //prints the LinkedList and private variables

  private:
    void init(void); //initializes private variables
    Node<T>* headPtr; //ptr to head node
    Node<T>* tailPtr; //ptr to tail node
    Node<T>* currPtr; //ptr to current node
    Node<T>* prevPtr; //ptr to previous node
    std::size_t sizeL; //size of the linked list
    Node<T>* newNode(const T& item); //allocate dynamic node
    Node<T>* newNode(const T& item, Node<T>* nextNode); //allocate dynamic node
};

/**
	*  @brief  Initializes class variables.
	*  @param  void.
	*  @return  void.
	*
	*  The init function sets all pointer to nullptr and sizeL to 0.
	*/
template <class T>
void LinkedList<T>::init(void) {
    //ptr init
    headPtr = nullptr;
    tailPtr = nullptr;
    currPtr = nullptr;
    prevPtr = nullptr;
    //sizeL init
    sizeL = 0;
}

/**
	*  @brief  Default constructor.
	*  @param  void.
	*  @return  void.
	*
	*  The constructor uses init function to initialize variables.
	*/
template <class T>
LinkedList<T>::LinkedList(void) {
    init();
}

/**
	*  @brief  Copy constructor.
	*  @param  copyList  The list to be copied.
	*  @return  void.
	*
	*  The copy constructor deepcopies the copyList to the object.
	*/
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyList) {
    init();
    Node<T>* tempPtr = copyList.headPtr;
    for(std::size_t cnt=0; cnt<copyList.sizeL; cnt++) {
        insertAfter(copyList.nodeData(tempPtr));
        tempPtr = tempPtr->next();
    }
    moveToPos(copyList.getPos());
}

/**
	*  @brief  Default destructor.
	*  @param  void.
	*  @return  void.
	*
	*  The destructor uses clear function to release allocated memory.
	*/
template <class T>
LinkedList<T>::~LinkedList(void) {
    clear();
}

/**
	*  @brief  Insert node to the LinkedList.
	*  @param  item  Data to be stored in the node.
	*  @return  void.
	*
	*  The insertAt function inserts a node to the location pointed by
	*  currPtr. The nodes following the currPtr are shifted whereas
	*  the nodes before the currPtr remain same.
	*
	*  If currPtr is pointing head or the LinkedList is empty,
	*  the function uses insertHead function.The LinkedList grows
	*  dynamically.
	*
	*  As a result of this function the currPtr points to the newly
	*  inserted node.
	*/
template <class T>
void LinkedList<T>::insertAt(const T& item) {
    if((currPtr == headPtr) || empty()) {
        insertHead(item);
    } else {
        Node<T>* tempPtr = newNode(item); //get a new node
        prevPtr->insertNext(tempPtr); //insert it after prevPtr
        currPtr = tempPtr; //arrange currPtr
        sizeL += 1; //sizeL increments
    }
}

/**
	*  @brief  Insert node to the LinkedList.
	*  @param  item  Data to be stored in the node.
	*  @return  void.
	*
	*  The insertAfter function inserts a node to the next of location
	*  pointed by currPtr. The nodes following the currPtr are shifted
	*  whereas the node currPtr and preceding nodes remain same.
	*
	*  If currPtr is pointing tail, the function uses insertTail
	*  function. The LinkedList grows dynamically.
	*
	*  If the LinkedList is empty, the function uses insertHead
	*  function.
	*
	*  As a result of this function the currPtr points to the newly
	*  inserted node.
	*/
template <class T>
void LinkedList<T>::insertAfter(const T& item) {
    if(empty()) {
        insertHead(item);
    } else if(currPtr == tailPtr) {
        insertTail(item);
    } else {
        Node<T>* tempPtr = newNode(item); //get a new node
        currPtr->insertNext(tempPtr); //insert it after prevPtr
        prevPtr = currPtr; //arrange prevPtr
        currPtr = tempPtr; //arrange currPtr
        sizeL += 1; //sizeL increments
    }
}

/**
	*  @brief  Insert node to the head of the LinkedList.
	*  @param  item  Data to be stored in the node.
	*  @return  void.
	*
	*  The insertHead function inserts a node to the head location
	*  of the LinkedList. The nodes following the headPtr are shifted.
	*
	*  As a result of this function the currPtr points to the newly
	*  inserted head node.
	*/
template <class T>
void LinkedList<T>::insertHead(const T& item) {
    if(empty()) {
        Node<T>* tempPtr = newNode(item); //get a new node
        headPtr = currPtr = tailPtr = tempPtr; /* arrange headPtr, currPtr,
                                                tailPtr */
        sizeL = 1; //sizeL is 1
    } else {
        Node<T>* tempPtr = newNode(item, headPtr); //get a new node
        headPtr = currPtr = tempPtr; // arrange headPtr, currPtr
        prevPtr = nullptr; //arrange prevPtr
        sizeL += 1; //sizeL increments
    }
}

/**
	*  @brief  Insert node to the tail of the LinkedList.
	*  @param  item  Data to be stored in the node.
	*  @return  void.
	*
	*  The insertTail function inserts a node to the tail location
	*  of the LinkedList.
	*
	*  If the LinkedList empty, insertTail function uses insertHead function.
	*
	*  As a result of this function the currPtr points to the newly
	*  inserted tail node.
	*/
template <class T>
void LinkedList<T>::insertTail(const T& item) {
    if(empty()) {
        insertHead(item);
    } else {
        Node<T>* tempPtr = newNode(item); //get a new node
        prevPtr = tailPtr;
        tailPtr->insertNext(tempPtr); //insert it after tailPtr
        currPtr = tailPtr = tempPtr; //arrange currPtr, tailPtr
        sizeL += 1; //sizeL increments
    }
}

/**
	*  @brief  Remove the node pointed by currPtr.
	*  @param  void.
	*  @return  void.
	*
	*  The removeAt function removes the node pointed by currPtr. The node
	*  following is the new currPtr and is chained to prevPtr.
	*
    *  If the currPtr points to head, removeAt function uses
	*  removeHead function.
	*
	*  If currPtr points to tail, the preceding node is the new currPtr.
	*
	*  If the LinkedList becomes empty after removal,
	*  the variables are reset to initial states.
	*
    *
	*/
template <class T>
void LinkedList<T>::removeAt(void) {
    if(empty()) {
        std::cerr << "The LinkedList empty. Can't remove current node." << '\n';
    } else if(size() == 1) {
        clear();
    } else if(currPtr == headPtr) {
        removeHead();
    } else if(currPtr == tailPtr) {
        freeNode(currPtr); //delete currPtr
        tailPtr = prevPtr; //arrange tailPtr
        sizeL -= 1; // decrement sizeL
        moveToTail(); // move currPtr to tailPtr
    } else {
        Node<T>* tempPtr = currPtr->next(); //hold next of currPtr
        currPtr->insertNext(prevPtr); /* insert prevPtr to the next of currPtr.
                                        currPtr is out of list */
        freeNode(currPtr); //delete currPtr
        currPtr = tempPtr; //arrange currPtr
        sizeL -= 1;
    }

}

/**
	*  @brief  Remove the node pointed by headPtr.
	*  @param  void.
	*  @return  void.
	*
	*  The removeHead function removes the node pointed by headPtr. The node
	*  following is the new headPtr.
	*
	*  If the currPtr points to head, currPtr is updated to new headPtr.
    *
    *  If the prevPtr points to head, prevPtr is updated as nullptr.
	*/
template <class T>
void LinkedList<T>::removeHead(void) {
    if(empty()) {
        std::cerr << "The LinkedList empty. Can't remove head  node." << '\n';
    } else if(size() == 1) {
        clear();
    } else if(currPtr == headPtr) {
        Node<T>* tempPtr = headPtr->next(); //hold next of headPtr
        freeNode(headPtr); //delete headPtr
        headPtr = tempPtr; //arrange headPtr
        sizeL -= 1; //decrements sizeL

        currPtr = headPtr; //arrange currPtr
    } else if (prevPtr == headPtr) {
        Node<T>* tempPtr = headPtr->next(); //hold next of headPtr
        freeNode(headPtr); //delete headPtr
        headPtr = tempPtr; //arrange headPtr
        sizeL -= 1; //decrements sizeL

        prevPtr = nullptr; //arrange currPtr
    } else {
        Node<T>* tempPtr = headPtr->next(); //hold next of headPtr
        freeNode(headPtr); //delete headPtr
        headPtr = tempPtr; //arrange headPtr
        sizeL -= 1; //decrements sizeL
    }
}

/**
	*  @brief  Returns the LinkedList to its initial state.
	*  @param  void.
	*  @return  void.
	*
	*  The clear function deletes all nodes in the LinkedList and returns
	*  all variables to their initial state.
	*/
template <class T>
void LinkedList<T>::clear(void) {
    moveToHead();
    Node<T>* tempPtr;
    for(std::size_t cnt=0; cnt<sizeL; cnt++) {
        tempPtr = currPtr->next();  //hold next of currPtr
        freeNode(currPtr); //delete currPtr
        currPtr = tempPtr; //arrange currPtr
    }
    init();
}

/**
	*  @brief  Releases allocated dynamic memory of a node.
	*  @param  node  The pointer to the target node.
	*  @return  void.
	*/
template <class T>
void LinkedList<T>::freeNode(Node<T>* node) {
    delete node;
}

/**
	*  @brief  Returns the LinkedList size.
	*  @param  void.
	*  @return  size
	*/
template <class T>
std::size_t LinkedList<T>::size(void) const {
    return sizeL;
}

/**
	*  @brief  Returns true if the LinkedList empty,
    *  @brief  false otherwise.
	*  @param  void.
	*  @return  Boolean value true or false.
	*/
template <class T>
bool LinkedList<T>::empty(void) const {
    return (sizeL == 0);
}

/**
	*  @brief  Returns the data stored in the specified node.
	*  @param  node  The target node.
	*  @return  The data stored in the node of type T.
	*/
template <class T>
T LinkedList<T>::nodeData(Node<T>* node) const {
    return node->getData();
}

/**
	*  @brief  Move currPtr to headPtr.
	*  @param  void.
	*  @return  void.
	*
	*  The moveToHead function moves currPtr to headPtr.
	*/
template <class T>
void LinkedList<T>::moveToHead(void) {
    currPtr = headPtr;
    prevPtr = nullptr;
}

/**
	*  @brief  Move currPtr to tailPtr.
	*  @param  void.
	*  @return  void.
	*
	*  The moveToTail function uses moveToHead function with
	*  parameter (sizeL - 1) to move currPtr to tailPtr.
	*/
template<class T>
void LinkedList<T>::moveToTail(void) {
    moveToPos(sizeL - 1);
}

/**
	*  @brief  Move currPtr to nth node of the LinkedList.
	*  @param  n  Position of the target node where n € [0 , sizeL - 1].
	*  @return  void.
	*
	*  The moveToPos function iterates over the LinkedList nodes to move
	*  currPtr to the nth node of the LinkedList. n is in
	*  the range of [0 , sizeL - 1].
	*
	*  The moveToPos function uses moveToHead function to move currPtr
	*  to headPtr.
	*/
template <class T>
void LinkedList<T>::moveToPos(int n) {
    moveToHead();
    for(int cnt=0; cnt<n; cnt++) {
        prevPtr = currPtr;
        currPtr = currPtr->next();
    }
}

/**
	*  @brief  Returns the position of the currPtr
	*  @param  void.
	*  @return  Integer representing position of the currPtr.
	*
	*  The getPost function iterates over the list until reaches the currPtr.
	*  Then returns the position of the currPtr as int.
	*/
template <class T>
int LinkedList<T>::getPos(void) const {
    Node<T>* tempPtr = headPtr;
    int cnt;
    for(cnt=0; tempPtr!=currPtr; cnt++) {
        tempPtr = tempPtr->next();
    }
    return cnt;
}

/**
    *  @brief  Creates a dynamic Node of type T.
    *  @param  item  Data to be stored in the new node.
    *  @return  void.
    *
    *  Returns a pointer to node created dynamically. The new node's data is
    *  item of type T. The new node's next pointer is nullptr.
    */
template <class T>
Node<T>* LinkedList<T>::newNode(const T& item) {
    Node<T>* tempPtr = nullptr;
    tempPtr = new Node<T>(item);
    if(tempPtr == nullptr) {
        std::cerr << "Memory allocation for new node is failed" << '\n';
        return nullptr;
    } else {
        return tempPtr;
    }
}

/**
    *  @brief  Creates a dynamic Node of type T.
    *  @param  item  Data to be stored in the new node.
    *  @param  nextNode  The next node of the new node.
    *  @return  void.
    *
    *  Returns a pointer to node created dynamically. The new node's data is
    *  item of type T. The new node's next pointer is nextNode of type T.
    */
template <class T>
Node<T>* LinkedList<T>::newNode(const T& item, Node<T>* nextNode) {
    Node<T>* tempPtr = nullptr;
    tempPtr = new Node<T>(item, nextNode);
    if(tempPtr == nullptr) {
        std::cerr << "Memory allocation for new node is failed" << '\n';
        return nullptr;
    } else {
        return tempPtr;
    }
}

/**
	*  @brief  Prints the LinkedList nodes together with private variables.
	*  @param  os  The printing medium.
	*  @return  void.
	*/
template <class T>
void LinkedList<T>::print(std::ostream& os) {
    os << "Class Variables:\n";
    //headPtr
    if(headPtr == nullptr)
        os << "headPtr: " << "nullptr" << " | ";
    else
        os << "headPtr: " << headPtr << ' '  << nodeData(headPtr) << " | ";
    //prevPtr
    if(prevPtr == nullptr)
        os << "prevPtr: " << "nullptr" << '\n';
    else
        os << "prevPtr: " << prevPtr << ' '  << nodeData(prevPtr) << '\n';
    //tailPtr
    if(tailPtr == nullptr)
        os << "tailPtr: " << "nullptr" << " | ";
    else
        os << "tailPtr: " << tailPtr << ' ' << nodeData(tailPtr) << " | ";
    //currPtr
    if(currPtr == nullptr)
        os << "currPtr: " << "nullptr" << '\n';
    else
        os << "currPtr: " << currPtr << ' '<< nodeData(currPtr) << '\n';

    //sizeL
    os << "sizeL: " << sizeL << '\n';
    Node<T>* tempPtr = headPtr;
    for(std::size_t cnt=0; cnt<sizeL; cnt++) {
        os << nodeData(tempPtr) << " -> ";
        tempPtr = tempPtr->next();
    }
    os << '\n';
}
