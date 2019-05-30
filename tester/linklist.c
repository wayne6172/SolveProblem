#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int val;
    struct node *next;
}Node;


Node* insertOne(Node*, int);
Node* insertMany(Node*);
Node* removeOne(Node*, int);
Node* removeMany(Node*);
Node* removeAll(Node*);
Node* transfer(Node*);
Node* listSort(Node*);
void printList(Node*);

int main(int argc, char const *argv[])
{
    int effort, exit = 0;
    Node* headPtr = NULL;

    while(1){
        printf("\n請輸入欲操作的代碼，0:離開、1:新增、2:刪除、3:倒轉、4:排序、5:全刪除  ");

        scanf("%d", &effort);

        switch (effort)
        {
            case 0:
                exit = 1;
                break;
            case 1:
                headPtr = insertMany(headPtr);
                break;
            case 2:
                headPtr = removeMany(headPtr);
                break;
            case 3:
                headPtr = transfer(headPtr);
                break;
            case 4:
                headPtr = listSort(headPtr);
                break;
            case 5:
                headPtr = removeAll(headPtr);
                break;
            default:
                printf("輸入代號不存在，請重試\n");
                break;
        }

        printList(headPtr);
        if(exit == 1)break;
    }

    return 0;
}

Node* insertOne(Node* headPtr, int val){
    Node* newNode = (Node *)malloc(sizeof(Node)), *nowPtr = headPtr;

    newNode->val = val;
    newNode->next = NULL;

    if(headPtr == NULL)
        return newNode;
    else{
        while(nowPtr->next != NULL)
            nowPtr = nowPtr->next;
        nowPtr->next = newNode;

        return headPtr;
    }
}

Node* insertMany(Node* headPtr){
    char input[50000], *p;

    printf("\n請輸入欲新增的值，若多筆可由空格格開，輸入按下Enter即可 ");
    fflush(stdin);
    gets(input);

    p = strtok(input," ");
    while(p != NULL){
        headPtr = insertOne(headPtr,atoi(p));
        p = strtok(NULL, " ");
    }

    return headPtr;
}

Node* removeOne(Node* headPtr, int val){
    Node *nowPtr = headPtr, *frontPtr = NULL;

    while(nowPtr != NULL && nowPtr->val != val){
        frontPtr = nowPtr;
        nowPtr = nowPtr->next;
    }

    if(nowPtr == NULL)
        printf("%d 不在List中!\n",val);
    else {
        if(frontPtr == NULL)
            headPtr = headPtr->next;
        else
            frontPtr->next = nowPtr->next;

        free(nowPtr);
    }

    return headPtr;
}

Node* removeMany(Node* headPtr){
    char input[50000], *p;

    printf("\n請輸入欲刪除的值，若多筆可由空格格開，輸入按下Enter即可 ");
    fflush(stdin);
    gets(input);

    p = strtok(input," ");
    while(p != NULL){
        headPtr = removeOne(headPtr,atoi(p));
        p = strtok(NULL, " ");
    }

    return headPtr;
}

Node* transfer(Node* headPtr){
    if(headPtr == NULL)
        return NULL;

    Node *nowPtr = headPtr, *frontPtr = NULL, *nextPtr = headPtr->next;

    while(nextPtr != NULL){
        nowPtr->next = frontPtr;

        frontPtr = nowPtr;
        nowPtr = nextPtr;
        nextPtr = nextPtr->next;
    }

    nowPtr->next = frontPtr;
    return nowPtr;
}

Node* listSort(Node *headPtr){
    if(headPtr == NULL)
        return NULL;

    Node *newHeadPtr = NULL, *sortNowPtr, *sortFrontPtr, *maxFrontPtr, *maxNowPtr, *newTailPtr = NULL;

    while(headPtr != NULL){
        sortNowPtr = headPtr->next;
        sortFrontPtr = headPtr;
        maxNowPtr = headPtr;
        maxFrontPtr = NULL;

        while(sortNowPtr != NULL){
            if(sortNowPtr->val < maxNowPtr->val){
                maxFrontPtr = sortFrontPtr;
                maxNowPtr = sortNowPtr;
            }

            sortFrontPtr = sortNowPtr;
            sortNowPtr = sortNowPtr->next;
        }

        if(maxFrontPtr == NULL){
            if(newHeadPtr == NULL){
                newHeadPtr = maxNowPtr;
                newTailPtr = maxNowPtr;
            }
            else {
                newTailPtr->next = maxNowPtr;
                newTailPtr = maxNowPtr;
            }

            headPtr = headPtr->next;
        }
        else {
            if(newHeadPtr == NULL){
                newHeadPtr = maxNowPtr;
                newTailPtr = maxNowPtr;
            }
            else {
                newTailPtr->next = maxNowPtr;
                newTailPtr = maxNowPtr;
            }

            maxFrontPtr->next = maxNowPtr->next;
        }

    }

    newTailPtr->next = NULL;
    return newHeadPtr;
}

Node* removeAll(Node* headPtr){
    Node *curPtr = headPtr, *temp = NULL;

    while(curPtr != NULL){
        temp = curPtr;
        curPtr = curPtr->next;

        free(temp);
    }

    return NULL;
}

void printList(Node *headPtr){
    Node *nowPtr = headPtr;

    printf("\n目前List裡面有... ");
    while(nowPtr != NULL){
        printf(" %d", nowPtr->val);
        nowPtr = nowPtr->next;
    }

    printf("\n");
}