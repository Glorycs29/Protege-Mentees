#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;
		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
bool pathintree(TreeNode<int> *root, vector<int>& path, int x){
	if(root==NULL) return false;
	path.push_back(root->data);

	if(root->data==x) {
		return true;
		}
	bool left=pathintree(root->left, path, x);
	if(left==true) return true;
	bool right=pathintree(root->right, path, x);
	if(right==true) return true;
	path.pop_back();
	return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
	vector<int> answer;
	pathintree(root,answer, x);
	return answer;
}
