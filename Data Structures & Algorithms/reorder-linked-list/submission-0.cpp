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
    void reorderList(ListNode* head) {
        //find middle
        //reversse second half
        //merge the first and second half of the list

        ListNode* slow = head;
        ListNode* fast = head;

        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow at middle
        //create second half as a l.l
        ListNode* second = slow->next;
        slow->next = nullptr;

        //revese the l.l
        ListNode* prev = nullptr;
        ListNode* curr = second;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = next;
        }
        second = prev;
        //merger one one element of each starting with first half
        ListNode* first = head;
        while(first && second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
