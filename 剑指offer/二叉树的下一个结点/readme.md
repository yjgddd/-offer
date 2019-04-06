# 题目链接
[二叉树的下一个结点](https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
给定一个二叉树和其中的一个点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
# 解题思路
三种情况分析：
1、该结点为空，返回NULL

2、如果该结点的右子树不为空，则右子树的最左子结点即为中序遍历的下一个结点。

3、如果右子树为空，则找该结点的父节点，如果当前结点是父结点的左子结点，则下一个结点即其左结点，否则不断向上遍历，直到找到一个是它父亲结点的左子结点的结点，如果这样的结点存在，那么它的父亲结点就是我们要找到下一个结点，如果遍历到根节点仍然不存在，则结点没有下一个结点，返回NULL。
# C++代码
```
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        TreeLinkNode* pNext=NULL;
        if(pNode==NULL) return NULL;
        if(pNode->right!=NULL)//右子树不为空
        { 
            pNext=pNode->right;
            while(pNext->left!=NULL)
            pNext=pNext->left;//找右子树的最左结点
        }
        else if(pNode->next!=NULL)//父节点不为空
        {
            TreeLinkNode* pCurrent=pNode;
            TreeLinkNode* pParent=pNode->next;
            while(pParent!=NULL&&pParent->right==pCurrent)//找是父亲结点左结点的结点
            {
                pCurrent=pParent;
                pParent=pParent->next;
            }
            pNext=pParent;//返回该结点的父亲结点
        }
       return pNext;
    }
};
```
