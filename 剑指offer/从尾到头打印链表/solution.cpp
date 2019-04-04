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
