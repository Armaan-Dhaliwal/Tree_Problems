#include<iostream>
#include"TreeNode_Class.cpp"
#include<queue>
#include<climits>   
using namespace std;

class Ans{
    public:
    int max;
    int s_max;

    Ans(){
        max=-1;
        s_max=-1;
    }
};

Ans* Second_largest(TreeNode<int>* root){
    Ans* ans=new Ans;
    if(ans->max==-1){
        ans->max=root->data;
    }

    for(int i=0;i<root->children.size();i++){
        Ans* temp = Second_largest(root->children[i]);
        if(temp->max>ans->max){
            int ans_temp=ans->max;
            ans->max=temp->max;
            if(ans->s_max==-1){
                if(temp->s_max==-1){
                    ans->s_max=ans_temp;
                }
                else{
                    if(ans_temp>temp->s_max){
                        ans->s_max=ans_temp;
                    }
                    else{
                        ans->s_max=temp->s_max;
                    }
                }
            }
            else{
                if(ans->s_max>ans_temp){
                    ans->s_max=ans->s_max;
                }
                else{
                    ans->s_max=ans_temp;
                }
            }
        }
        else{
            ans->max=ans->max;
            if(ans->s_max>temp->max){
                ans->s_max=ans->s_max;
            }
            else{
                ans->s_max=temp->max;
            }
        }
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
    Ans* res = Second_largest(root);
    cout<<"Your answer is: "<<res->s_max<<endl;

}