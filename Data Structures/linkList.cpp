#include <iostream>

using namespace std;

typedef struct node{
    int n;
    struct node *next;
}Node;

Node* addList(Node *headPtr,int n){
    Node *curPtr = headPtr;
    Node *prePtr = NULL;

    while(curPtr != NULL && curPtr->n <= n){
        prePtr = curPtr;
        curPtr = curPtr->next;
    }

    Node *tmpPtr = new Node;
    tmpPtr->n = n;
    tmpPtr->next = NULL;

    if(prePtr == NULL){
        tmpPtr->next = headPtr;
        return tmpPtr;
    }
    else prePtr->next = tmpPtr;
    tmpPtr->next = curPtr;

    return headPtr;
}

Node* removeList(Node* headPtr,int n){
    Node *curPtr = headPtr;
    Node *prePtr = NULL;
    Node *tmpPtr;

    while(curPtr != NULL && curPtr->n != n){
        prePtr = curPtr;
        curPtr = curPtr->next;
    }

    if(curPtr == NULL)return headPtr;

    if(prePtr == NULL){
        tmpPtr = curPtr->next;
        delete curPtr;
        return tmpPtr;
    }
    else {
        prePtr->next = curPtr->next;
        delete curPtr;
    }

    return headPtr;
}

void printNode(Node *headPtr){
    Node *curPtr = headPtr;
    while(curPtr != NULL){
        cout << curPtr->n << " ";
        curPtr = curPtr->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int n, choose;
    Node *headPtr = NULL;
    while(true){
        cin >> choose >> n;
        if(cin.eof())break;

        if(choose == 1){
            headPtr = addList(headPtr,n);
        }
        else if(choose == 2){
            headPtr = removeList(headPtr,n);
        }

        printNode(headPtr);
    }
    
    return 0;
}
