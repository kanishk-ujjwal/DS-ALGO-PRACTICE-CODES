#include<bits/stdc++.h>
using namespace std;

class treenode
{
public:
    int val;
    treenode* left;
    treenode* right;
    treenode(int data)
    {
        this->val=data;
        this->left=NULL;
        this->right=NULL;
    }
};
treenode* built_bst(treenode* root, int data)
{
    if(root==NULL)
    {
        root=new treenode(data);
        return root;
    }
    if(data>root->val)
    {
        root->right=built_bst(root->right,data);
    }
    else
        root->left=built_bst(root->left,data);
    return root;

}

treenode* insert(treenode* root)
{
    int data;
    cin>>data;

    while(data!=-1)
    {
        root=built_bst(root,data);
        cin>>data;
    }
    return root;
}

void inorder(treenode* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->val<<"->";
    inorder(root->right);
}

bool isbst(treenode* root, int minval=INT_MIN, int maxval=INT_MAX)
{
    if(root==NULL)
        return true;
    bool leftbst=isbst(root->left,minval,root->val);
    bool rightbst=isbst(root->right,root->val,maxval);
    if(leftbst and rightbst and root->val<maxval and root->val>minval)
        return true;
    return false;

}
class largestbst
{
public:
    bool isbst;
    int size;
    int maxval;
    int minval;
};

largestbst helper(treenode* root)
{
    largestbst ans;
    if(root==NULL)
    {
        ans.isbst=true;
        ans.size=0;
        ans.maxval=INT_MIN;
        ans.minval=INT_MAX;
        return ans;
    }

    largestbst leftcall=helper(root->left);
    largestbst rightcall=helper(root->right);

    if(leftcall.isbst== false or rightcall.isbst==false or root->val >rightcall.minval or root->val< leftcall.maxval)
    {
        ans.isbst=false;
        ans.size=max(leftcall.size,rightcall.size);
        return ans;
    }
    ans.isbst=true;
    ans.size=1+leftcall.size+rightcall.size;
    if(root->left!=NULL)
    {
        ans.minval=leftcall.minval;
    }
    else
    {
        ans.minval=root->val;
    }
    if(root->right!=NULL)
    {
        ans.maxval=rightcall.maxval;
    }
    else
    {
        ans.maxval=root->val;
    }
    return ans;
}

int preorderindx=0;
treenode* treefrompreandinorder(int pre[],int in[],int start, int end)
{
    if(start>end)
        return NULL;
    int data=pre[preorderindx];
    treenode* root=new treenode(data);
    int indx=0;
    while(in[indx]!=data)
    {
        indx++;
    }
    preorderindx++;

    root->left=treefrompreandinorder(pre,in,start,indx-1);
    root->right=treefrompreandinorder(pre,in,indx+1,end);

    return root;

}
int main()
{
    treenode*root=NULL;
    root=insert(root);
    inorder(root);
    cout<<endl;
   // bool a=isbst(root);
    cout<<isbst(root)<<endl;

}

//input:12 7 8 6 3 17 14 19 -1
