#include <cstdio>
#include <cstring>

struct node{
    int val,leftVal,rightVal;
    struct node *left, *right, *parent;
}Node[100000];

struct node* createTree(int left,int right,struct node* parent){
    int mid = (left + right) / 2;
    if(left == right){
        Node[left].parent = parent;
        Node[left].leftVal = Node[left].rightVal = left;
        return &Node[left];
    }
    else {
        struct node* temp = new struct node;
        temp->left = createTree(left,mid,temp);
        temp->right = createTree(mid+1,right,temp);
        temp->parent = parent;
        temp->leftVal = left;
        temp->rightVal = right;
        temp->val = temp->left->val * temp->right->val;

        return temp;
    }
}

void clear(struct node* root){
    if(root->leftVal != root->rightVal){
        clear(root->left);
        clear(root->right);
        delete root;
    }
}

void change(struct node* root,int pos,int val){
    if(root->leftVal == pos && root->rightVal == pos){
        root->val = val;
    }
    else {
        int mid = (root->leftVal + root->rightVal) / 2;
        if(pos <= mid)change(root->left,pos,val);
        else change(root->right,pos,val);

        root->val = root->left->val * root->right->val;
    }
}

int find(struct node* root, int left, int right){
    if(root->leftVal == root->rightVal)
        return root->val;
    
    if(left == root->leftVal && right == root->rightVal)
        return root->val;

    int mid = (root->leftVal + root->rightVal) / 2;

    if(right <= mid)
        return find(root->left,left,right);
    else if(left > mid)
        return find(root->right,left,right);
    else {
        int leftVal = find(root->left, left, mid);
        int rightVal = find(root->right, mid + 1, right);
        return leftVal * rightVal;
    }
}

int main(int argc, char const *argv[])
{
    struct node *root;
    int N,K,temp,a,b;
    char input[2];
    while(~scanf("%d%d",&N,&K)){
        memset(Node,0,sizeof(Node));

        for(int i = 0; i < N; i++){
            scanf("%d",&temp);
            if(temp < 0)Node[i].val = -1;
            else if(temp == 0)Node[i].val = 0;
            else Node[i].val = 1;
        }

        root = createTree(0,N - 1,NULL);

        while(K--){
            scanf("%s %d %d",input,&a,&b);
            if(input[0] == 'C'){
                a--;
                if(b > 0) change(root,a,1);
                else if(b == 0) change(root,a,0);
                else change(root,a,-1);
            }
            else {
                int ans = find(root,a - 1,b - 1);
                if(ans > 0)printf("+");
                else if(ans == 0)printf("0");
                else printf("-");
            }
        }
        printf("\n");
        clear(root);
        root = NULL;
    }
    return 0;
}
