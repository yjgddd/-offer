# 题目链接
[牛客网剑指offer-从尾到头打印链表](https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
# 解题思路
可以用栈，先从头到尾将链表结点值保存在一个栈中，再出栈保存在需要返回的ArrayList,根据栈的先进后出特点，返回的即链表从尾到头
# C++代码
```
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector <int> Array;
        stack <int> stk;
        while(head!=NULL)
        {
            stk.push(head->val);
            head=head->next;
        }
        while(!stk.empty())
        {
            Array.push_back(stk.top());
            stk.pop();
        }
        return Array;
    }
};
```
