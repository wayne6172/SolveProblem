#include <iostream>

using namespace std;

template<class ItemType>
class List{
private:
    typedef struct node{
        ItemType val;
        struct node *next;
        node(ItemType _val){
            val = _val;
            next = NULL;
        }
    }Node;

    Node *headPtr, *tailPtr;
    int length;
    
public:
    List();
    void push_back(ItemType);
    void push_front(ItemType);
    void printList();
    int getLength();
};

template<class ItemType>
List<ItemType>::List() : headPtr(NULL), tailPtr(NULL), length(0){}

template<class ItemType>
void List<ItemType>::push_back(ItemType item){
    Node *newNode = new Node(item);

    if(headPtr == NULL){
        this->headPtr = newNode;
        this->tailPtr = newNode;
    }
    else {
        this->tailPtr->next = newNode;
        this->tailPtr = newNode;
    }

    this->length++;
}

template<class ItemType>
void List<ItemType>::push_front(ItemType item){
    Node *newNode = new Node(item);

    if(headPtr == NULL)
        this->tailPtr = newNode;
    else {
        newNode->next = this->headPtr;
        this->headPtr = newNode;
    }

    this->length++;
}

template<class ItemType>
void List<ItemType>::printList(){
    Node *curPtr = this->headPtr;

    while(curPtr != NULL){
        cout << curPtr->val << " ";
        curPtr = curPtr->next;
    }
    cout << endl;
}

template<class ItemType>
int List<ItemType>::getLength(){
    return this->length;
}

int main(int argc, char const *argv[])
{
    List<int> list;
    List<double> listD;

    list.push_back(5);
    list.push_back(3);
    list.push_back(4);
    list.push_front(6);
    
    list.printList();
    cout << list.getLength() << endl;
    

    listD.push_back(5.3);
    listD.push_back(3.14);
    listD.push_back(4.2);
    listD.push_front(6.7);
    listD.push_front(9.7);
    
    listD.printList();
    cout << listD.getLength() << endl;
    

    return 0;
}
