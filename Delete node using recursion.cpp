#include<iostream>
using namespace std;
struct bstnode{
    int data;
    bstnode* left;
    bstnode* right;
};
bstnode* findMin(bstnode* root)
{
	while(root->left != NULL) 
	root = root->left;
	return root;
}
bstnode* Delete(bstnode* root, int num){
    if(root==nullptr)
    return root;
    
    else if(num<root->data)
    Delete(root->left, num);
    
    else if(num>root->data)
    Delete(root->right, num);
    
    else{
        if(root->left==nullptr && root->right==nullptr){ //case 1:No child
            delete root;
            root=nullptr;
        }
        else if(root->left==nullptr){       //case 2:One child
            bstnode* temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==nullptr){
            bstnode* temp=root;
            root=root->left;
            delete temp;
        }
        else{                         //case 3:Two children
            bstnode *temp=findMin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data); //Delete duplicate node
        }
    }
    cout<<"\nNode deleted...";
    return root;
}
void Inorder(bstnode *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}
 
// Function to Insert Node in a Binary Search Tree
bstnode* Insert(bstnode *root,char data) {
	if(root == NULL) {
		root = new bstnode();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}

int main() {
	/*Code To Test the logic
	  Creating an example tree
	        5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
	bstnode* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4); 
	root = Insert(root,1); root = Insert(root,11);
	
	cout<<"Inorder: ";
	Inorder(root);

	// Deleting node with value 5, change this value to test other cases
	root = Delete(root,5);

	//Print Nodes in Inorder
	cout<<"\nInorder: ";
	Inorder(root);
	cout<<"\n";
}

/*
Inorder: 1 3 4 5 10 11 
Node deleted...
Node deleted...
Inorder: 1 3 4 10 11 
*/
