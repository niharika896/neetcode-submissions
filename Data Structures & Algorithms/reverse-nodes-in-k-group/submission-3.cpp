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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int count = 0;
        while (curr) {
            count++;
            curr = curr->next;
        }
        curr = head;
        ListNode* newHead;
        ListNode* prevTail = curr;
        for (int i = 0; i < (count / k); i++) {
            ListNode* currTail;
            prev = nullptr;
            for (int j = 0; j < k; j++) {
                if (j == 0) currTail = curr;
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;

                if (i == 0 && j == k - 1) {
                    newHead = prev;
                }
            }
            if (i != 0) {
                prevTail->next = prev;
                prevTail = currTail;
                // cout << "printing the tail value" << prev->val << '\n';
                // cout << "printing the prevtail value" << prevTail->val << '\n';
                // cout << "i=" << i << '\n';
            }
        }

        // if (prevTail) cout << "printing the prevtail value" << prevTail->val << '\n';
        // if (curr) cout << "printing the curr value" << curr->val << '\n';
        if (prevTail) prevTail->next = curr;
        return newHead;
    }
};
