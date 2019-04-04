# 题目链接
[牛客网剑指offer-反转链表](https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
输入一个链表，反转链表后，输出新链表的表头。
# 解题思路
典型题目，可以用递归和迭代两种方法,见代码
# C++代码
## 迭代AC代码
```
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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* L=NULL,*M=NULL,*R=pHead;
        if(pHead==NULL) return pHead;
        while(R->next!=NULL)
        {
            L=M;
            M=R;
            R=R->next;
            M->next=L;
        }
        R->next=M;
        return R;
    }
};
```
## 递归AC代码
```
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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* newHead;
        if(pHead==NULL||pHead->next==NULL) return pHead;
        else newHead=ReverseList(pHead->next);
        pHead->next->next=pHead;
        pHead->next=NULL;
        return newHead;
    }
};
```

## 类似题目
[Leetcode206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

