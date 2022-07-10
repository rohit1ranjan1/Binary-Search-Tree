#include<iostream>
#include<stack>
using namespace std;
struct bstnode{
    int data;
    bstnode* left;
    bstnode* right;
};
bstnode* root=nullptr;
bstnode* newNode(int data){
    bstnode* node=new bstnode();
    node->data=data;
    node->left=node->right=nullptr;
    return node;
}
void insert(int data){
    if(root==nullptr){
        root=newNode(data);
        return;
    }
    bstnode* temp=root;
    while(temp!=NULL){
        if(data<=temp->data){
            if(temp->left==nullptr){
                temp->left=newNode(data);
                return;
            }
            else
            temp=temp->left;
        }
        else{
            if(temp->right==nullptr){
                temp->right=newNode(data);
                return;
            }
            else
            temp=temp->right;
        }
    }
}
void preorder_Traveral(){
    stack<bstnode*> s;
    bstnode* temp=root;
    cout<<"\nPreorder Traveral of BST is: "<<temp->data;
    s.push(temp);
    while(temp->left!=nullptr){
        temp=temp->left;
        cout<<" "<<temp->data;
        s.push(temp);
    }
    while(!s.empty()){
        temp=s.top();
        if((temp->left==nullptr && temp->right==nullptr) || (temp->right==nullptr))
        s.pop();
        
        else if(temp->right!=nullptr){
            s.pop();
            temp=temp->right;
            cout<<" "<<temp->data;
            s.push(temp);
            while(temp->left!=nullptr){
                temp=temp->left;
                cout<<" "<<temp->data;
                s.push(temp);
            }
        }
    }
}
void inOrder()
{
    stack<bstnode *> s;
    bstnode *curr = root;
 cout<<"\nInorder Traversal:"; 
    while (curr != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the
           curr Node */
           
        while (curr !=  NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }
 
        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();
 
        cout<<curr->data << " ";
 
        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;
 
    } /* end of while */
}
void inorderSuccessor(int num){
    stack<bstnode*> s;
    bstnode* temp=root;
    bstnode* curr;
    if(num<temp->data){
        while(num<temp->data){
            s.push(temp);
            temp=temp->left;
        }
            curr=s.top();
            cout<<"\nInorder Successor is: "<<curr->data;
    }
    else{
        while(num>=temp->data)
        temp=temp->right;
        
         if(num<temp->data){
        while(num<temp->data){
            s.push(temp);
            temp=temp->left;
        }
            curr=s.top();
            cout<<"\nInorder Successor is: "<<curr->data;
    }
        while(temp->left!=nullptr)
            temp=temp->left;
            
        cout<<"\nInorder Successor is: "<<temp->data;
    }
    
}
int main(){
    insert(15);
    insert(10);
    insert(20);
    insert(8);
    insert(12);
    insert(25);
    insert(17);
    insert(19);
    insert(18);
    insert(1);
    insert(9);
    preorder_Traveral();  
    inOrder();
    inorderSuccessor(8);
}

/*
Preorder Traveral of BST is: 15 10 8 1 9 12 20 17 19 18 25
Inorder Traversal:1 8 9 10 12 15 17 18 19 20 25 
Inorder Successor is: 10
*/
