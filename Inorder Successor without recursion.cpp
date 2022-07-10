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
    bstnode* temp=root;
    bstnode* prev;
    if(num<temp->data){
        while(num<temp->data){
            prev=temp;
            temp=temp->left;
        }
        if(temp->right==nullptr){
            cout<<"\n"<<prev->data;
        }
        else{
            temp=temp->right;
            while(temp->left!=nullptr){
                temp=temp->left;
            }
            cout<<"\n"<<temp->data;
        }
            
    }
    else{
        while(num>temp->data){
            prev=temp;
            temp=temp->right;
        }
        if(num<temp->data){
            while(num<temp->data){
            prev=temp;
            temp=temp->left;
        }
        if(temp->right==nullptr)
         cout<<"\n"<<prev->data;
        else{
            temp=temp->right;
            while(temp->left!=nullptr)
            temp=temp->left;
            cout<<"\n"<<temp->data;
        }
        }
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
    inOrder();
    inorderSuccessor(17);
}
/*
Inorder Traversal:1 8 9 10 12 15 17 18 19 20 25 
18
*/
