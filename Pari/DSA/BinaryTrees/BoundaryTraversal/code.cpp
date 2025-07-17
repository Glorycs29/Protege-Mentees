//link- https://www.naukri.com/code360/problems/boundary-traversal-of-binary-tree_790725?leftPanelTabValue=SUBMISSION
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;
 
        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/


//1 
void left(TreeNode<int>* root, vector<int>&ans){
    //base case
    if(root==NULL || root->left ==NULL && root->right==NULL){
        return ;

    }
    ans.push_back(root->data); //forward order-> that is why pushing back before calling recursion to its(left/right)
    if(root->left) left(root->left, ans);
    else{
        left(root->right, ans);
    }
}

//2 inorder
void inorder(TreeNode<int> * root, vector<int>& ans){
    if(root->left==NULL && root->right==NULL) {
        ans.push_back(root->data);
        return;
    }
    //since left to right order 
    if(root->left)  inorder(root->left, ans);
    if(root->right) inorder(root-> right, ans);
}
//3->reverse right

void reverseright(TreeNode<int>* root, vector<int>& ans){
    //base case

    if(root==NULL || root->left ==NULL && root->right==NULL) return ;

    if(root->right) {
        reverseright(root->right, ans);   
    }
    else 
        reverseright(root->left, ans);
     ans.push_back(root->data);

}   
vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int>ans;
    ans.push_back(root->data);
//IF MAIN ROOT's left or right doesnt exist then its whole side traversal wont be there
	//1st
   
    left(root->left, ans);

    //2nd
    inorder(root, ans);
    //3rd
    reverseright(root->right,ans);

return ans;
}



       1
    2.    3
4        5.  6
                7
