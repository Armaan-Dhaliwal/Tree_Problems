#include<iostream>
#include"TreeNode_Class.cpp"
#include<queue>
using namespace std;

void At_Depth(TreeNode<int>* root, int k){
    if(k==0){
        cout<<root->data<<" ";
    }

    for(int i=0;i<root->children.size();i++){
        At_Depth(root->children[i],k-1);
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
    int k;
    cout<<"Enter depht: "<<endl;
    cin>>k;
    At_Depth(root,k);

}