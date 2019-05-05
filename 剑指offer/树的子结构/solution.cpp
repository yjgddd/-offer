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
