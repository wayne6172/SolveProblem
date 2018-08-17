#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

typedef struct Node{
	int val;
	struct Node* left;
	struct Node* right;
};

int Space=0;

void Print(Node* root){
	if(root==NULL)return;
	printf("%s%d",Space==0 ? "" : " ",root->val);
	Space++;
	Print(root->left);
	Print(root->right);
}

int main()
{
   	int x,out=0,L,R;
   	
   	while(true){
   		Node *root=NULL;
   		queue<Node*> q;
   		Node *itemPtr = new Node;
   		itemPtr->left=itemPtr->right=NULL;
   		root=itemPtr;
   		q.push(itemPtr);
   		
	   	while(!q.empty()){
	   		
	   		if(scanf("%d",&x)==EOF){
	   			out=1;
	   			break;
	   		}
	   		else {
	   			Node *tmpPtr = q.front();
	   			tmpPtr->val = x;
	   			scanf("%d%d",&L,&R);
	   			
	   			if(L){
	   				itemPtr = new Node;
   					itemPtr->left=itemPtr->right=NULL;
   					tmpPtr->left=itemPtr;
   					q.push(itemPtr);
	   			}
	   			if(R){
	   				itemPtr = new Node;
   					itemPtr->left=itemPtr->right=NULL;
   					tmpPtr->right=itemPtr;
   					q.push(itemPtr);
	   			}
	   			q.pop();
	   		}
	   	}
	   	if(out)break;
	   	Space=0;
	   	Print(root);
	   	printf("\n");
   	}
   	
    return 0;
}
