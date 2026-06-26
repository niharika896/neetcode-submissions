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
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }
        int torem = count - n;
        temp = head;
        ListNode* prev = nullptr;
        while (torem--) {
            prev = temp;
            temp = temp->next;
        }
        if (prev) {
            prev->next = temp->next;
        }else{
            head=temp->next;
        }
        // temp->next = nullptr;
        delete temp;
        return head;
    }
};
