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
