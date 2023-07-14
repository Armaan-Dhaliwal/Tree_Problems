#include<iostream>
#include"TreeNode_Class.cpp"
#include<queue>
using namespace std;

TreeNode<int>* DeleteLeaf(TreeNode<int>* root){
    
    if(root->children.size()==0){
        return NULL;
    }

    for(int i=0;i<root->children.size();i++){
        root->children[i] = DeleteLeaf(root->children[i]);
    }
    return root;
}

TreeNode<int>* InputTree(){
    queue<TreeNode<int>*> q;
    cout<<"Enter data for root node: "<<endl;
    int data;
    cin>>data;
    TreeNode<int>* root = new TreeNode<int>(data);
    q.push(root);
    while(!q.empty()){
        cout<<"Enter number of children for "<<q.front()->data<<endl;
        int n;
        cin>>n;
        
        for(int i=0;i<n;i++){
            cout<<"enter "<<(i+1)<<" Node: "<<endl;
            int val;
            cin>>val;
            TreeNode<int>* temp= new TreeNode<int>(val);
            q.push(temp);
            q.front()->children.push_back(temp);
        }
        q.pop();
    }
    return root;
}

void Post_Order(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        Post_Order(root->children[i]);
    }
    cout<<root->data<<" ";
}

int main(){
    TreeNode<int>* root =InputTree();
    root=DeleteLeaf(root);
    Post_Order(root);
}

//1 3 2 3 4 0 3 6 7 8 0 0 0 0