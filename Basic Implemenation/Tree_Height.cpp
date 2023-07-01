#include<iostream>
#include"TreeNode_Class.cpp"
#include<queue>
using namespace std;

int TreeHeight(TreeNode<int>* root){
    int ans=0;
    if(root->children.size()>0){
        ans+=1;
    }
    for(int i=0;i<root->children.size();i++){
        ans+=TreeHeight(root->children[i]);
    }
    return ans;
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
    cout<<"Height of your tree is: "<<TreeHeight(root)+1<<endl;

}