#include<iostream>
#include"TreeNode_Class.cpp"
#include<queue>
using namespace std;

bool Find_ele(TreeNode<int>* root, int x){
    bool result=false;
    if(root->data==x){
        return true;
    }

    for(int i=0;i<root->children.size();i++){
        result=Find_ele(root->children[i],  x);
        if(result==true){
            break;
        }
    }
    return result;
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
    cout<<"Enter the element you want to search: "<<endl;
    int x;
    cin>>x;
    if(Find_ele(root,x)){
        cout<<"Element found "<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }

}