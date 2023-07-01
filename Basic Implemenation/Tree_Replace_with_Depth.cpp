#include<iostream>
#include"TreeNode_Class.cpp"
#include<queue>
using namespace std;

void Replace_Depth(TreeNode<int>* root,int depth){
    root->data=depth;
    // if(root->children.size()>0){
    //     depth+=1;
    // }
    for(int i=0;i<root->children.size();i++){
        Replace_Depth(root->children[i],depth+1);
    }
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

void PrintTree(TreeNode<int>* root){
    queue<TreeNode<int>*> q;
    cout<<root->data<<endl;
    
    for(int i=0;i<root->children.size();i++){
        q.push(root->children[i]);
    }
    TreeNode<int>* temp = new TreeNode<int>(-1);
    q.push(temp);
    while(!q.empty()){
        if(q.front()->data==-1){
            cout<<endl;
            q.pop();
            
        }
        if(q.empty()){
            break;
         }
        cout<< q.front()->data<<" ";

        for(int i=0;i<q.front()->children.size();i++){
            q.push(q.front()->children[i]);
        }
        if(q.front()->children.size()>0){
            q.push(temp);
        }
        q.pop();
    
    }

}

int main(){
    TreeNode<int>* root =InputTree();
    Replace_Depth(root,0);
    cout<<"Your Tree is: "<<endl;
    PrintTree(root);
}