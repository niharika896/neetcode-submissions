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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* node = &dummy;
        int carry = 0;
        int sum;
        while (l1 && l2) {
            ListNode* newNode = new ListNode();
            sum = l1->val + l2->val + carry;
            newNode->val = (sum % 10);
            node->next = newNode;
            node = newNode;
            carry = sum / 10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            ListNode* newNode = new ListNode();
            sum=l1->val+carry;
            newNode->val = (sum % 10);
            node->next = newNode;
            node = newNode;
            carry = sum / 10;
            l1=l1->next;
        }
        while(l2){
            ListNode* newNode = new ListNode();
            sum=l2->val+carry;
            newNode->val = (sum % 10);
            node->next = newNode;
            node = newNode;
            carry = sum / 10;
            l2=l2->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            node->next=newNode;
        }
        return dummy.next;
    }
};
