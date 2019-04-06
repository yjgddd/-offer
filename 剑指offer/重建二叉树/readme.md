# 题目链接
[牛客网剑指offer-重建二叉树](https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
# 解题思路
前序遍历的第一个结点是根结点，在中序遍历中找到该结点，则在中序遍历找到的根节点的左边所有数字即左子树上的结点，右边所有数字即右子树上的所有结点，且可以
知道左右子树结点的个数，在前序遍历中，在根结点后相同左子树结点个数是左子树的先序遍历，再往后找相同右子树结点数目即右子树的前序遍历。因此可以得到左子树
的前序遍历和中序遍历、右子树的前序遍历和中序遍历。那么递归调用构造树函数即可。
# C++代码
```
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
         if(pre.empty()||vin.empty()||pre.size()!=vin.size()) return NULL;
         else return costruct(pre,vin,0,0,vin.size()-1);
    }
    //构造函数，参数依次为前序遍历序列、中序遍历序列、前序遍历的起点、中序遍历的起点、中序遍历的终点，递归调用的参数变化易错
    TreeNode* costruct(vector<int> pre,vector<int> vin,int prestr,int instr,int inend){
        if(instr>inend) return NULL;
        TreeNode* root=new TreeNode(pre[prestr]);
        for(int i=instr;i<=inend;i++)
        {
            if(vin[i]==pre[prestr]) //找到中序遍历中的跟结点
            {
                root->left=costruct(pre,vin,prestr+1,instr,i-1);//递归构造左子树
                root->right=costruct(pre,vin,prestr+i-instr+1,i+1,inend);//递归构造右子树
                break;
            }
        }
        return root;
    }
};
```
