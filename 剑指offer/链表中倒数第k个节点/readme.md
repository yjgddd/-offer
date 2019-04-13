# 题目链接

[牛客网剑指offer-链表中倒数第k个节点](https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

# 题目描述
输入一个链表，输出该链表中倒数第k个结点。
# 解题思路
常规的想法是先遍历一遍求链表的长度len,倒数第k个节点也就是整数第len-k+1个节点，再遍历找到这个节点，因此需要遍历链表两次。

其实遍历链表一次就可以实现了，做法是定义两个指针，开始都初始化为链表头结点，第一个指针先从头节点走k-1步，从第k步开始，两个指针一起开始遍历链表，那么两
个指针的距离始终是k-1，当第一个指针走到链表的尾节点时候，第二个指针刚好指向倒数第k个节点。

为了保证代码的鲁棒性，需要考虑pListHead为空、k为0、k的值比链表长度大三种特殊情况，此时返回空指针。
# C++代码
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
       ListNode* p1=pListHead,*p2=pListHead;
       if(pListHead==NULL||k==0) return NULL;
       for(unsigned int i=1;i<k;i++)
       {
           if(p1->next!=NULL) p1=p1->next;
           else return NULL;
       }    
       while(p1->next!=NULL)
       {
           p1=p1->next;
           p2=p2->next;
       }
       return p2;
    }
};
```
