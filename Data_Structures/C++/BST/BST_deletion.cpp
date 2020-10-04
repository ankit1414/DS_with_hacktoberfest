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

void deleteNode(node* &root,int key){
    if(root == nullptr){
        cout<<"key not present"<<endl;
        return;
    }
    if(root->data < key){
        deleteNode(root->right,key);
    }else if(root->data > key){
        deleteNode(root->left,key);
    }else{
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
            return;
        }else if(root->left == nullptr){
            node* temp = root->right;
            if(temp->left==nullptr){
            }else{
                while(temp->left->left != nullptr){
                    temp = temp->left;
                }
                node* temp2 = temp->left;
                temp->left = temp2->right;
                temp = nullptr;
                temp = temp2;
                temp->right = root->right;
            }
            temp->left = root->left;
            root->left = nullptr;
            root->right = nullptr;
            delete root;
            root = nullptr;
            root = temp;
            return;
        }else if(root->right == nullptr){
            node* temp = root->left;
            if(temp->right==nullptr){
            }else{
                while(temp->right->right != nullptr){
                    temp = temp->right;
                }
                node* temp2 = temp->right;
                temp->right = temp2->left;
                temp = temp2;
                temp->left = root->left;
            }
            temp->right = root->right;
            root->left = nullptr;
            root->right = nullptr;
            delete root;
            root = nullptr;
            root = temp;
            return;
        }else{
            node* temp = root->right;
            if(temp->left==nullptr){
            }else{
                while(temp->left->left != nullptr){
                    temp = temp->left;
                }
                node* temp2 = temp->left;
                temp->left = temp2->right;
                temp = temp2;
                temp->right = root->right;
            }
            temp->left = root->left;
            root->left = nullptr;
            root->right = nullptr;
            delete root;
            root = nullptr;
            root = temp;
            return;
        }
    }
}

int main(){
    node* root = nullptr;
    buildBST(root);
    printIn(root);
    cout<<endl;
    // BFSprint(root);
    // cout<<endl;
    int data;
    cin>>data;
    deleteNode(root,data);
    printIn(root);
    return 0;
}
