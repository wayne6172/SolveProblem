#include <cstdio>

struct Node{
    int val;
    struct Node *next;
};

int data[10][2][16] = {
    {{0,1,1,1 ,0,1,1,1 ,0,1,1,1 ,0,1,1,1},{0,0,0,0,0,0,0,0}},
    {{0,0,1,0 ,0,0,0,0 ,0,0,1,0 ,0,0,0,0},{0,1,0,0,0,1,0,0}},
    {{0,1,1,1 ,0,1,0,0 ,1,1,1,1 ,1,0,0,1},{0,0,0,1,0,1,0,0}},
    {{0,1,1,1 ,0,1,0,1 ,0,1,1,1 ,0,1,0,1},{0,0,0,1,0,0,0,1}},
    {{1,0,0,1 ,0,0,1,0 ,0,1,0,0 ,0,0,0,1},{0,0,1,1,1,0,0,1}},//4
    {{1,1,1,1 ,1,0,0,1 ,0,1,1,1 ,1,0,1,1},{0,0,0,1,0,0,0,1}},
    {{0,0,0,1 ,0,0,0,1 ,0,1,1,1 ,0,1,0,0},{0,1,0,1,0,0,0,1}},
    {{0,1,1,1 ,0,1,0,0 ,0,1,0,0 ,0,0,0,1},{0,0,0,1,1,0,0,0}},
    {{0,1,1,1 ,0,1,0,1 ,0,1,1,1 ,0,1,0,1},{0,0,0,1,0,0,0,1}},
    {{0,1,1,1 ,0,1,0,0 ,0,1,0,0 ,0,0,0,1},{0,0,0,1,1,0,0,1}}
};

Node *createAns(int k,int t){
    Node* headPtr = NULL;
    Node* nowPtr = NULL;
    Node* temp;
    if(t == 0){
        for(int i = 0; i < 16; i++){
            temp = new Node;
            temp->val = data[k][t][i];
            temp->next = NULL;

            if(headPtr == NULL)
                headPtr = temp;
            else 
                nowPtr->next = temp;
            nowPtr = temp;
        }
    }
    else {
        for(int i = 0; i < 8; i++){
            temp = new Node;
            temp->val = data[k][t][i];
            temp->next = NULL;

            if(headPtr == NULL)
                headPtr = temp;
            else 
                nowPtr->next = temp;
            nowPtr = temp;
        }
    }

    return headPtr;
}

Node* createTest(int graph[][5],int t){
    Node* headPtr = NULL;
    Node* nowPtr = NULL;
    Node* temp;
    
    if(t == 0){
        
    }
    else {

    }
}

int main(int argc, char const *argv[])
{
    Node *ansHead[10][2];
    Node *test[2];

    for(int i = 0; i < 10; i++){
        ansHead[i][0] = createAns(i,0); // 0 表外
        ansHead[i][1] = createAns(i,1);
    }

    int T, test[5][5];
    scanf("%d",&T);
    while(T--){
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                scanf("%d",&test[i][j]);
        
        test[0] = createTest(test,0);
        test[1] = createTest(test,1);
    }

    return 0;
}
