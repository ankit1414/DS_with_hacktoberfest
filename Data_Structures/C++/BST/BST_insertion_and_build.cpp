#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

void insert(node* &root,int d){
    if(d==-1){return;}
    if(root == nullptr){
        root = new node(d);
        return;
    }
    if(root->data <= d){
        insert(root->right,d);
        return;
    }
    if(root->data > d){
        insert(root->left,d);
        return;
    }
}

void buildBST(node* &root){
    int d;
    cin>>d;
    if(d==-1){
        return;
    }
    root = new node(d);
    while(d!=-1){
        cin>>d;
        insert(root,d);
    }
}

void printIn(node* root){
    if(root==nullptr){
        return;
    }
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

void BFSprint(node* root){
    if(root == nullptr){
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(nullptr);
    while(q.front()!=nullptr){
        node* temp = q.front();
        if(temp->left != nullptr){
            q.push(temp->left);
        }
        if(temp->right != nullptr){
            q.push(temp->right);
        }
        cout<<temp->data<<" ";
        q.pop();
        if(q.front()==nullptr){
            q.pop();
            cout<<endl;
            q.push(nullptr);
        }
    }
}

int main(){
    node* root = nullptr;
    buildBST(root);
    printIn(root);
    cout<<endl;
    BFSprint(root);
    cout<<endl;
    return 0;
}
