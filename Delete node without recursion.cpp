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
void deleteNode(int num){
    bstnode* temp=root;
    bstnode* prev;
    
    if(temp==nullptr){
            cout<<"\nNode not in tree!";
            return;
        }
        
    while(temp!=nullptr){
        if(temp==nullptr){
            cout<<"\nNode not in tree!";
            return;
        }
        else if(num==temp->data){
            if(temp->left!=nullptr && temp->right!=nullptr){       //case 3:Two children
                bstnode* current=temp;
                prev=temp;
                temp=temp->right;
                while(temp->left!=nullptr){
                    current=temp;
                    temp=temp->left;
                }
                prev->data=temp->data;
            }
            
            else if(temp->right==nullptr && temp->left==nullptr){  //case 1: No child
                if(temp->data<prev->data)
                prev->left==nullptr;
                else
                prev->right==nullptr;
            }
            
             if (temp->left == NULL || temp->right == NULL) {
                         bstnode* newCurr;  //case 2: One child
 
        // if the left child does not exist.
        if (temp->left == NULL)
            newCurr = temp->right;
        else
            newCurr = temp->left;
                 
        if (temp == prev->left)
            prev->left = newCurr;
        else
            prev->right = newCurr;
    }
            
            delete temp;
            temp=nullptr;
            cout<<"\nNode deleted...";
            
        }
        else if(num<temp->data){
            prev=temp;
            temp=temp->left;
        }
        else{
            prev=temp;
            temp=temp->right;
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
    preorder_Traveral();  
    deleteNode(20);
    preorder_Traveral(); 
}


/*
Preorder Traveral of BST is: 15 10 8 1 9 12 20 17 19 18 25
Node deleted...
Preorder Traveral of BST is: 15 10 8 1 9 12 25 17 19 18

int main(){
    insert(15);
    insert(10);
    insert(20);
    insert(12);
    insert(25);
    preorder_Traveral();  
    deleteNode(10);
    preorder_Traveral(); 
}
Preorder Traveral of BST is: 15 10 12 20 25
Node deleted...
Preorder Traveral of BST is: 15 12 20 25
*/
