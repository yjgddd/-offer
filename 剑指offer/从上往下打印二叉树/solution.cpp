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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
          vector<int> ans;
          queue<TreeNode* > q;
          if(root==NULL) return ans;
          else 
          {
              q.push(root);
              while(!q.empty())
              {
                  ans.push_back(q.front()->val);
                  if(q.front()->left) q.push(q.front()->left);
                  if(q.front()->right) q.push(q.front()->right);
                  q.pop();
              }
          }
          return ans;
    }
};
