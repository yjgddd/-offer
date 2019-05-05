# 题目链接
[牛客网剑指offer-从上往下打印二叉树](https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=11175&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
# 解题思路
即二叉树的层次遍历。可以用队列实现。先把根节点入队列，节点出队列(即加入到返回结果中)时候，将其左右子节点入队列，那么出队列的顺序即层次遍历。

&emsp;&emsp; 8
   
&emsp; 6&emsp; 10
 
&emsp;5 7&emsp; 9 11

比如如上二叉树，按照层次打印的过程

打印8，队列中保存6,10

打印结点6，队列中10，并加入5,7

打印10，队列为5,7,9,11

打印5，队列为7,9,11

打印7，队列为9,11

打印9，队列为11

打印11，队列为空

题目是保存的打印顺序，即8,6,10,5,7,9,11，层次遍历的结果。
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
```
# 参考
[剑指offer-名企面试官精讲典型编程题(第2版)]
