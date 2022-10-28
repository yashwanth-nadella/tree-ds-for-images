#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node * left;
	struct node * right;
	int data;
};
struct node* insert(struct node* root,int x);
void search (struct node* root,int x);
struct node* deletion(struct node* root,int x);
void preorder(struct node * root);
void postorder(struct node * root);
void inorder(struct node * root);
int findmin(struct node* root);
int main()
{
	int i,c=0,n,x;
	struct node * root;
	root = NULL;
	while(c!=7)
	{
	    printf("menu:\n1)insertion\n2)search\n3)deletion\n4)preorder\n5)postorder\n6)inorder\n7)exit\n");
	    scanf("%d",&c);
		switch(c)
		{
			case 1:{
				printf("enter number of elements to be inserted :\n");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("enter the element:\n");
					scanf("%d",&x);
					root=insert(root,x);
				}
				break;
			}
			case 2:{
				printf("enter element to be searched:\n");
				scanf("%d",&x);
				search(root,x);
				break;
			}
			case 3:{
				printf("enter element to be removed:\n");
				scanf("%d",&x);
				root=deletion(root,x);
				break;
			case 4:{
			    preorder(root);printf("\n");break;
			}
			case 5:{
			    postorder(root);printf("\n");break;
			}
			case 6:{
			    inorder(root);printf("\n");break;
			}
			default:{
			    printf("invalid choice\n");break;
			}
			}
		}
	}
}
struct node* insert(struct node* root,int x)
{
	struct node * temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
		return root;
	}
	if(root->data<x)
	{
		root->right= insert(root->right,x);
	}
	else
	{
		root->left= insert(root->left,x);
	}
	return root;
}
void search(struct node * root,int x)
{
    if(root==NULL)
    {
        printf("tree empty.\n");
        return;
    }
	if(root->data==x)
	{
		printf("element found\n");
		return;
	}
	else if(root->data<x)
	{
		if(root->right==NULL)
		{
			printf("element does not exist.\n"); return;
		}
		search(root->right,x);
	}
	else
	{
		if(root->left==NULL)
		{
			printf("element does not exist.\n"); return;
		}
		search(root->left,x);
	}
	return;
}
struct node* deletion(struct node* root,int x)
{
	if(root==NULL) return root;
	else if(root->data<x) root->right=deletion(root->right,x);
	else if(root->data>x) root->left=deletion(root->left,x);
	else
	{
		if(root->left==NULL && root->right==NULL)
			return NULL;
		else if(root->left==NULL)
			return root->right;
		else if(root->right==NULL)
			return root->left;
		else
		{
			root->data = findmin(root->right);
			deletion(root->right,root->data);
			return root->right;
		}
	}
}
int findmin(struct node* root)
{
	while(root!=NULL)
		root=root->left;
	return root->data;
}
void preorder(struct node * root)
{
	if(root==NULL) return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node * root)
{
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}
void inorder(struct node * root)
{
	if(root==NULL) return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
