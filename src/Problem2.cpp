/*
Given a Sorted Doubly Linked List and a Binary Search Tree , Check if they are identical or not .
The DLL will have nodes of type node_dll
Note :
A DLL can be represented as a BST in many forms ,And if a dll and any one of the forms is given as input you
need to return 1 otherwise 0. 

->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

Example 0:
DLL:1->5->8
BST(All 3 return 1):
    5         8      1
   / \       /        \
  1   8     5          5
           /            \
          1              8
Returns 1
    8
   / \
  5   1
Returns 0
Example 1:
DLL : 1->5
BST : 
5
 \
 10
Returns 0

Example 2:
DLL:1->3->5-9->11
BST:
    5
   / \
  1   11
   \  /      
    3 9

Returns 1

Example 3:
DLL: 1->5->7->10->12->15->20
BST:
        10
        /\
       5  15
      /\  / \
     1  7 12 20
Returns 1

Note 2 :
Unequal Length BST and DLL should return 0;
Return -1 for NULL inputs

Difficulty : Medium +
*/
#include <stdlib.h>
#include <stdio.h>

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node * todll(struct node *root);
int com(struct node_dll *head, struct node *h);
int is_identical(struct node_dll *head, struct node *root){
	if(head==NULL||root==NULL)
		return -1;
	int len1=1,len2=0;
	struct node *r,*h=root;
	struct node_dll *a;
	if (root->left != NULL){
		r = root->left;
		for (r; r != NULL; r = r->left)
		{
			len1++;
		}
	}
	if (root->left != NULL&&root->left->right != NULL){
		r = root->left->right;
		for (r; r != NULL; r = r->right){
			len1++;
		}
	}
	if (root->right != NULL){
		r = root->right;
		for (r; r != NULL; r = r->right){
			len1++;
		}
	}
	if (root->right != NULL&&root->right->left != NULL){
		r = root->right->left;
		for (r; r != NULL; r = r->left){
			len1++;
		}
	}
	for (a = head; a != NULL; a = a->next, len2++);
	if (len1 != len2)
		return 0;
	h = todll(root);
	for (h; h->left != NULL;)
		h = h->left;
	int z=com(head, h);
	return z;
}
int com(struct node_dll *head, struct node *h)
{
	for (; head != NULL || h != NULL; head = head->next, h = h->right)
	{
		if (head->data != h->data)
			return 0;
	}
	return 1;
}
struct node * todll(struct node *root)
{
	if (root == NULL)
		return root;
	if (root->left != NULL)
	{
		struct node *l = todll(root->left);
		for (l; l->right != NULL; l = l->right);
		l->right = root;
		root->left = l;
	}
	if (root->right != NULL)
	{
		struct node *r = todll(root->right);
		for (r; r->left != NULL; r = r->left);
		r->left = root;
		root->right = r;
	}
	return root;
}






