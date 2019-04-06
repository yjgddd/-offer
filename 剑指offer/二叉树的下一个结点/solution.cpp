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
