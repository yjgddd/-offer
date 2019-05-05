# 题目链接
[牛客网剑指offer-二叉树的镜像](https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
# 解题思路
先前序遍历这个树的每个节点，如果遍历的节点有子节点，就交换它的两个子节点。当交换所有非叶节点的左右子节点后，就得到了树的镜像。
# C++代码
```cpp
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
    void Mirror(TreeNode *pRoot) {
       if(pRoot==NULL) return;
       if(pRoot->left==NULL&&pRoot->right==NULL) return;
        TreeNode *pTemp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=pTemp;
        if(pRoot->left) Mirror(pRoot->left);
        if(pRoot->right) Mirror(pRoot->right);
    }
};
```
# 参考
[剑指offer-名企面试官精讲典型编程题（第2版）]

