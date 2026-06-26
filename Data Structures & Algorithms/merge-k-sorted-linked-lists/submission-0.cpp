/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    void mergeTwo(ListNode*& l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* node = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                node->next=l1;
                l1=l1->next;
            }else{
                node->next=l2;
                l2=l2->next;
            }
            node=node->next;
        }
        if(l1){
            node->next=l1;
        }
        if(l2){
            node->next=l2;
        }
        if(node->next)l1=dummy.next;
    }

   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())return nullptr;
        int n = lists.size();
        for (int i = 1; i < n; i++) {
            mergeTwo(lists[0], lists[i]);
        }
        return lists[0];
    }
};
