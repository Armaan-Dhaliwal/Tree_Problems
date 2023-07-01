#include<iostream>
#include"TreeNode_Class.cpp"
#include<queue>
using namespace std;

void Next_Greater(TreeNode<int>* root, int x, int &diff, int &index){

    if(root->data>x && diff>(root->data-x)){
        diff=root->data-x;
        index=root->data;
    }

    for(int i=0;i<root->children.size();i++){
        Next_Greater(root->children[i],x,diff,index);
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



int main(){
    TreeNode<int>* root =InputTree();
    cout<<"Enter your number :"<<endl;
    int n;
    cin>>n;
    int diff=99999;
    int index=-1;
    Next_Greater(root,n,diff,index);
    cout<<"number is: "<<index<<endl;

}