#include <iostream>
#include <queue>

using namespace std;

typedef struct node{
    int n;
    struct node *left;
    struct node *right;
}Node;

Node *addTree(Node* root,int n){
    if(root == NULL){
        Node *tmpPtr = new Node;
        tmpPtr->n = n;
        tmpPtr->left = tmpPtr->right = NULL;

        return tmpPtr;
    }

    if(root->n < n){        //右子樹
        root->right = addTree(root->right,n);
    }
    else {                  //左子樹
        root->left = addTree(root->left,n);
    }

    return root;
}

void printNode(Node *root){
    if(root == NULL)return;

    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node *tmpPtr = q.front();
        q.pop();
        cout << tmpPtr->n << " ";

        if(tmpPtr->left != NULL)
            q.push(tmpPtr->left);
        if(tmpPtr->right != NULL)
            q.push(tmpPtr->right);
    }
}

int main(int argc, char const *argv[])
{
    int n, choose;
    Node *headPtr = NULL;
    while(true){
        cin >> n;
        if(cin.eof())break;

        headPtr = addTree(headPtr,n);        

        printNode(headPtr);
        cout << endl;
    }
    
    return 0;
}
