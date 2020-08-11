#include <cstdio>
#include <cstdlib>

struct node{
    int val;
    struct node *left,*right;
};

//理論上要考慮一種當樹裡以有相同val存在，但在此先忽略
node* insert(node* root,int val){
    if(root == NULL){
        node* temp = new node;
        temp->val = val;
        temp->left = temp->right = NULL;

        return temp;
    }
    else {
        if(val < root->val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
    }
}

void inorder(node* root){
    if(root == NULL)return;

    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

void destroyTree(node* root){
    if(root == NULL)return;

    destroyTree(root->left);
    destroyTree(root->left);

    delete root;
}

node* search(node* headPtr,int val){
    if(headPtr == NULL)return NULL;

    if(headPtr->val == val)return headPtr;
    else if(headPtr->val < val)return search(headPtr->right,val);
    else return search(headPtr->left,val);
    
}

node* findLeftMax(node* root, node*& target){
    if(root->right == NULL){
        target = root;
        return root->left;
    }
    else {
        root->right = findLeftMax(root->right,target);
        return root;
    }
}

//先找到刪除位置，再使用findLeftMax找左子樹最大，以target取得左子樹最大後，用findLeftMax的return值更新樹
//最後將target取代刪除點
node* remove(node* root,int val){
    if(root->val == val){
        node* target = NULL;
        if(root->left == NULL){
            target = root->right;
            delete root;
            return target;
        }
        else {
            findLeftMax(root->left, target);

            target->left = root->left;
            target->right = root->right;
        
            delete root;
            return target;
        }
    }
    else if(root->val < val)
        root->right = remove(root->right, val);
    else
        root->left = remove(root->left,val);
    return root;
}

int main(int argc, char const *argv[])
{
    /* 取得亂數測試資料 */
    int array[30];
    for(int i = 0; i < 20; i++)
        array[i] = rand() % 100;

    /* 建樹 */
    node *headPtr = NULL;

    for(int i = 0; i < 20; i++)
        headPtr = insert(headPtr,array[i]);

    /* 顯示結果，在此先用inorder，而何謂inorder及為何inorder會顯示排序結果，此仔細思考 */

    inorder(headPtr);
    printf("\n");

    /* 刪除節點 */

    node* target;
    for(int i = 0; i < 5; i++){
        printf("delete %d: ",array[i]);

        target = search(headPtr,array[i]);
        if(target == NULL)
            printf("%d 該點不存在樹中\n",array[i]);   
        else headPtr = remove(headPtr, array[i]);

        inorder(headPtr);
        printf("\n");
    }
    /* 釋放記憶體也很重要，但也很簡單 */

    destroyTree(headPtr);
    headPtr = NULL;

    return 0;
}
