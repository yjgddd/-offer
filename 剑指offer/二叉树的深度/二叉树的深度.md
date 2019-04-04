# 题目描述
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
# 解题思路
递归，如果根结点为空，深度为0，否则返回左子树深度和右子树深度的较大值（递归调用求深度函数），再加1
# C++代码
```
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
      if(pRoot==NULL) return 0;
      else return max(TreeDepth(pRoot->left),TreeDepth(pRoot->right))+1;
    }
};
```
