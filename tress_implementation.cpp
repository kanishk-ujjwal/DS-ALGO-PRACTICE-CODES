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

    treenode* built_tree(treenode* root)
    {
        int data;
        cin>>data;

        if(data==-1)
            return NULL;

        if(root==NULL)
        root=new treenode(data);

        root->left=built_tree(root->left);
        root->right=built_tree(root->right);
        return root;

    }

    void preorder(treenode* root)
    {
        //NLR
        if(root==NULL)
        {
            cout<<"NULL"<<"->";
            return;
        }
        cout<<root->val<<"->";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(treenode* root)
    {
        //LNR
        if(root==NULL)
            return;
        inorder(root->left);
        cout<<root->val<<"->";
        inorder(root->right);
    }
    void postorder(treenode* root)
    {
        //LRN
        if(root==NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<"->";

    }

    void levelorder(treenode* root)
    {
        queue<treenode*>q;
        q.push(root);
        while(!q.empty())
        {
            int k=0;
            int n=q.size();
            while(k<n)
            {
            treenode* node=q.front();
            q.pop();
            k++;
            cout<<node->val<<"->";
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
            }
            cout<<endl;
        }
    }
    int sum_nodes(treenode* root)
    {
        if(root==NULL)
            return 0;
        int total=0;
        int leftsum=sum_nodes(root->left);
        int rightsum=sum_nodes(root->right);
        total+=leftsum+rightsum+root->val;
        return total;

    }
    int height(treenode* root)
    {
        int total=0;
        if(root==NULL)
            return -1;
        int countleft=height(root->left);
        int countright=height(root->right);
        total=1+max(countleft,countright);
        return total;
    }
    pair<bool,int> htbalanced(treenode* root)
    {
        pair<bool,int> val;
        if(root==NULL)
        {
            val.first=true;
            val.second=-1;
            return val;
        }

        pair<bool,int> leftcall=htbalanced(root->left);
        pair<bool,int> rightcall=htbalanced(root->right);

        if(leftcall.first==false or rightcall.first==false)
        {
            val.first=false;
            return val;
        }
        int myht=1+max(leftcall.second,rightcall.second);
        val.second=myht;
        if(abs(leftcall.second-rightcall.second)>1)
        {
            val.first=false;
            return val;
        }
        val.first=true;
        return val;

    }

    void printpath(treenode* root,string ans)
    {
        if(root->left==NULL and root->right==NULL)
        {
            ans+=to_string(root->val);
            cout<<ans<<endl;
            return;
        }
        //cout<<root->val<<"->";
        printpath(root->left,ans+to_string(root->val));
        printpath(root->right,ans+to_string(root->val));
    }
    int countnode(treenode* root)
    {
        if(root==NULL)
            return 0;
        int countleft=countnode(root->left);
        int countright=countnode(root->right);
        return countleft+countright+1;
    }
    int dia(treenode* root)
    {

        if(root==NULL)
            return 0;
        int maxval=0;
        int leftht=dia(root->left);
        int rightht=dia(root->right);
        int ans=rightht+leftht+2;
        maxval=max(maxval,ans);
        return maxval;
    }

int main()
{
    treenode* root=NULL;
    root=built_tree(root);
 //   levelorder(root);
    cout<<dia(root)<<endl;
   // cout<<height(root)<<endl;
//   pair<bool,int>ans=htbalanced(root);
//   if(ans.first)
//    cout<<"balanced"<<endl;
//   else
//    cout<<"unbalanced"<<endl;
   // printpath(root,"");
}

//input : 8 5 3 -1 -1 9 -1 -1 10 5 -1 -1 7 -1 -1
