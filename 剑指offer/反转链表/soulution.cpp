/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//迭代AC代码
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
//递归AC代码
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
