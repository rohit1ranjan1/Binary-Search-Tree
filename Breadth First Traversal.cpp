#include<iostream>
#include<queue>
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
void level_Order(){
    queue<bstnode*> q;
    bstnode* current=root;
    q.push(current);
    cout<<"Breadth First traversal is:";
    //while there's atleast one discovered node
    while(!q.empty()){
        current=q.front();
        cout<<"\n"<<current->data;
        
        if(current->left!=nullptr)
        q.push(current->left);
        
        if(current->right!=nullptr)
        q.push(current->right);
        
        q.pop();               //removing element at the front
    }
}
int main(){
    insert(15);
    insert(10);
    insert(20);
    insert(12);
    insert(25);
    level_Order();   
}

/*
Breadth First traversal is:
15
10
20
12
25

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
    level_Order();
}

Breadth First traversal is:
15
10
20
8
12
17
25
1
9
19
18
*/
