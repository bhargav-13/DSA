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

node* buildtree(node* root){
    int data;
     cout << "enter data: ";
     cin >> data;

    root = new node(data);
    
    if(data == -1){
        return NULL;
    }
    
    cout << "Enter data left of " << data <<":-" << endl;
    root->left = buildtree(root->left);
    cout << "Enter data right of " << data <<":-" << endl;
    root->right = buildtree(root->right);
    return root; 
    
}

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

}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    else{
        int lheight = height(root->left);
        int rheight = height(root->right);

        if(lheight > rheight){
            return lheight+1;
        }
        else{
            return rheight+1;
        }
    }
}

void Reverselevelorder(node* root){
    int h = height(root);

    for(int i=h; i>=1; i--){
        cout << "reverse order:" << endl;
        levelorder(root);
    }
}

int main(int argc, char const *argv[])
{
    node* root = NULL;

    root = buildtree(root);

    cout << "height is = " << height(root) << endl;

    // levelorder(root);
    Reverselevelorder(root);

    return 0;
}
