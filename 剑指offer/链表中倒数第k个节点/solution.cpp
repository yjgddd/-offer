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
