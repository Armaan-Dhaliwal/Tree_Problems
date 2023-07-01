#include<iostream>
#include"TreeNode_Class.cpp"
#include<queue>
using namespace std;


bool Identity(TreeNode<int>* root1, TreeNode<int>*root2){
    bool res = false;
    
    if(root1->data==root2->data){      
        if(root1->children.size()==root2->children.size()){
            res=true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
    for(int i=0;i<root1->children.size();i++){
                res = (Identity(root1->children[i], root2->children[i]));
                if(res==false){
                    break;
                }
            }
    return res;
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
    TreeNode<int>* root1 =InputTree();
    TreeNode<int>* root2 =InputTree();
    
    if(Identity(root1,root2)){
        cout<<"Structurally identical "<<endl;
    }
    else{
        cout<<"Not structurally identical "<<endl;
    }
}