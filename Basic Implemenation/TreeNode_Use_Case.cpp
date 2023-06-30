#include<iostream>
#include"TreeNode_Class.cpp"
using namespace std;

void PrintTree(TreeNode<int>* root){
    cout<<root->data<<" : ";
    
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<" ";
    }
    for(int i=0;i<root->children.size();i++){
        cout<<endl;
        PrintTree(root->children[i]);
    }
}

TreeNode<int>* InputTree(){
    cout<<"Enter data for the node"<<endl;
    int data;
    cin>>data;
    TreeNode<int>* root = new TreeNode<int>(data);
    cout<<"Enter number of children of "<<data<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>* newRoot = InputTree();
        root->children.push_back(newRoot);
    }
    return root;
}

int main(){
    // TreeNode<int>* root=new TreeNode<int>(1);
    // TreeNode<int>* node1=new TreeNode<int>(2);
    // TreeNode<int>* node2=new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    TreeNode<int>* root =InputTree();
    cout<<"Your Tree is: "<<endl;
    PrintTree(root);
}