#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

void levelorder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL); 
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    
}


node* insert(node* &root, int d){
    
    if(root == NULL){
        root = new node(d);
        return root;
    }
    
    if(root->data > d){
        root->left = insert(root->left, d);
    }
    else{
        root->right = insert(root->right, d);
    }

    return root;
}

void takeinput(node* &root){
    
    int data;
    cin >> data;
    while(data != -1){
    insert(root, data);
    cin >> data;
    }
}

node* minVal(node* root){
    node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

node* deleteNode(node* root, int x){
    if(root == NULL){
        return root;
    }
    if(root->data == x){
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);    
        }

    }
    else if(root->data > x){
        root->left = deleteNode(root->left, x);
        return root;
    }
    else{
        root->right = deleteNode(root->right, x);
        return root;
    }
    return root;
}



int main(int argc, char const *argv[])
{
    node* root = NULL;
    cout << "insert root value: ";
    takeinput(root);
    cout << endl << "printing" << endl;
    levelorder(root);
    cout << "inorder" << endl;
    inorder(root);

    deleteNode(root, 50);
    cout << "printing" << endl;
    levelorder(root);
    cout << "inorder" << endl;
    inorder(root);

    cout << "Preorder" << endl;
    preorder(root);
    return 0;
}


// 50 20 70 10 30 90 110 -1