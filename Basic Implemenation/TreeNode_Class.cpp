#include<iostream>
#include<vector>
using namespace std;
template <typename T>

class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*> children;

    TreeNode(int x){
        this->data = x;

    }
};