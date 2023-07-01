#include<iostream>
#include"TreeNode_Class.cpp"
#include<queue>
using namespace std;

int MaxSumNode(TreeNode<int>* root,int &index){
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }

    for(int i=0;i<root->children.size();i++){
        if(sum<MaxSumNode(root->children[i],index)){
            sum=MaxSumNode(root->children[i],index);
            index=root->children[i]->data;
        }
    }
    return sum;
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
    int index=root->data;
    cout<<"Required Node: "<<" with sum: "<<MaxSumNode(root,index)<<" is "<<index<<endl;

}