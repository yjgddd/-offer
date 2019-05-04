# 题目链接
[牛客网剑指offer-合并两个排序的链表](https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
# 解题思路
如果链表1是空，则返回的是链表2，如果链表2为空，返回的是链表1.
如果两个链表均不为空，那么新链表的头结点是两个链表头结点较小的一个，两个链表中剩下的结点排序过程依然如此，每次找到较小的作为头结点，链接到剩下排序好的链表，是一个递归的过程。
# C++代码
```cpp
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL) return pHead2;
        else if(pHead2==NULL) return pHead1;
        else if(pHead1->val<pHead2->val)//链表1的头结点较小，那么链表1的头结点将是合并后链表的头结点。
        {
            pHead1->next= Merge(pHead1->next,pHead2);
            return pHead1;
        }
        else////链表2的头结点较小，那么链表2的头结点将是合并后链表的头结点。
        { 
            pHead2->next= Merge(pHead1,pHead2->next);
            return pHead2;
        }
        
    }
};
```
