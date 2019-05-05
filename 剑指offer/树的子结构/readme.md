# 题目链接
[牛客网剑指offer-树的子结构](https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
# 解题思路
第一步，递归调用HasSubtree,判断树1的根节点、根节点的左子树中、根节点的右子树中是否包含子树2。

第二步是判断，isSubtree判断树1中以R为根节点的子树是不是和树2是相同结构，也是用递归，如果根节点不相同，那么显然以R为根节点的子树和树2不是相同结构，
如果相同则递归的判断它们的左右子节点是否相同。如果树2为空则返回true,树1为空树2不为空返回false。
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
    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2==NULL) return true;
        if(pRoot1==NULL) return false;
        if(pRoot1->val==pRoot2->val) return isSubtree(pRoot1->left,pRoot2->left)&&isSubtree(pRoot1->right,pRoot2->right);
        else return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==NULL||pRoot2==NULL) return false;
        else 
        {
           return isSubtree(pRoot1,pRoot2)||HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
        }
    }
};
```
# 参考
[剑指offer-名企面试官精讲典型编程题(第二版)]

[牛客网讨论区]
