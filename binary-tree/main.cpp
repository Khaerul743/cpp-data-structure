#include <iostream>

using namespace std;

struct Node{
    char label;
    Node* parent;
    Node* left;
    Node* right;
};

void createNewTree(Node* &root,char label){
    if(root != NULL){
        cout<<"Root gagal dibuat!!"<<endl;
    }else{
        root = new Node();
        root->label = label;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout<<"Root berhasil dibuat"<<endl;
    }
}

Node* insertLeft(Node* node,char label){
    if(node->left != NULL){
        cout<<"sudah ada yang menempati"<<endl;
        return NULL;
    }else{
        Node* newNode = new Node();
        newNode->label = label;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = node;
        node->left = newNode;
        cout<<"berhasil : "<<node->label<<" adalah orang tua dari "<<newNode->label<<endl;
        return newNode;
    }
}

Node* insertRight(Node* nodeParent,char label){
    if(nodeParent->right != NULL){
        cout<<"sudah ada anak kanan"<<endl;
        return NULL;
    }else{
        Node* newNode = new Node();
        newNode->label = label;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = nodeParent;
        nodeParent->right = newNode;
        cout<<"berhasil : "<<nodeParent->label<<" adalah orang tua dari "<<newNode->label<<endl;
        return newNode;
    }
}

int main(){
    Node* root = NULL;
    Node* B;
    Node* C;
    createNewTree(root,'A');
    cout<<root->label<<endl;

    B = insertLeft(root,'B');
    C = insertRight(root,'C');
    return 0;
}