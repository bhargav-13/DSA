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
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void reverseLevelOrder(node* root){
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
            s.push(temp);
        }
        else{
            s.push(temp);
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
    }

    while(!s.empty()){
        node* temp = s.top();
        s.pop();
        if(temp != NULL){
            cout << temp->data << " ";
        }
        else{
            cout << endl;
        }
    }
}

void BuildFromLevelorder(node* &root){
    queue<node*> q;
    cout << "enter data for root: ";
    int data;
    cin >> data;
    root = new node(data); 
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "enter left node for " << temp->data << ":" ;
        int ld;
        cin >> ld;
        if(ld!=-1){
            temp->left = new node(ld);
            q.push(temp->left);
        }
        cout << "enter right node for " << temp->data << ":" ;
        int rd;
        cin >> rd;
        if(rd!=-1){
            temp->right = new node(rd);
            q.push(temp->right);
        }  
    }
}


int height(node* root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);

    int ans = max(h1, h2) + 1;
    return ans;
}

int diameter(node* root){
    if(root == NULL){
        return 0;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left)+ height(root->right)+1;

    return max(op1, max(op2,op3)); 
}


int main(int argc, char const *argv[])
{
    node* root = NULL;

    //root = buildtree(root);
    BuildFromLevelorder(root);

    cout << "height is = " << height(root) << endl;

    levelorder(root);
    cout << endl;
    // reverseLevelOrder(root);
    cout << endl<< endl;
//    inorder(root);
    cout << endl;

    cout << height(root) << endl;


    return 0;
}


//10 5 15 3 7 12 17 