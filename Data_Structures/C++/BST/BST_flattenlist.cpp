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

class List{
    public:
    node* head;
    node* tail;
    List(){
        head = nullptr;
        tail = nullptr;
    }
};

List flattenTree(node* &root){
    List l;
    if(root == nullptr){return l;}
    if(root->left == nullptr && root->right == nullptr){
        l.head = root;
        l.tail = root;
        return l;
    }
    List leftl = flattenTree(root->left);
    List rightl = flattenTree(root->right);
    if(leftl.tail!=nullptr){
        leftl.tail->right = root;
        l.head = leftl.head;
    }else{
        l.head = root;
    }
    if(rightl.head!=nullptr){
        root->right = rightl.head;
        l.tail = rightl.tail;
    }else{
        l.tail = root;
    }
    return l;
}

int main(){
    node* root = nullptr;
    buildBST(root);
    printIn(root);
    cout<<endl;
    // BFSprint(root);
    // cout<<endl;
    List ll = flattenTree(root);
    node* temp = ll.head;
    while(temp!=nullptr){
        cout<<temp->data<<",";
        temp = temp->right;
    }
    return 0;
}
