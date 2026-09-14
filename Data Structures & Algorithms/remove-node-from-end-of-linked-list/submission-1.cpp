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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //using reverse concept. =>intiution 1
        // ListNode* currHead = reverseLL(head);
        // ListNode* curr = currHead;
        // if(n == 1){
        //     ListNode* temp = currHead;
        //     currHead = currHead->next;
        //     delete(temp);
        //     return reverseLL(currHead);
        // }
        // int tempNo = 1;
        // ListNode* prev = NULL;
        // while(curr){
        //     if(tempNo < n - 1){
        //         curr = curr->next;
        //         tempNo++;
        //     }else if(tempNo == n - 1){
        //         prev = curr;
        //         break;
        //     }
        // }
        // if(prev && prev->next){
        //     ListNode* nodeToBeRemoved = prev->next;
        //     prev->next = nodeToBeRemoved->next;
        //     delete(nodeToBeRemoved);
        // }
        // return reverseLL(currHead);

        //optimal=>using slow and fast

        ListNode* slow = head;
        ListNode* fast = head;
        
        for(int i = 0 ; i < n ; ++i){
            fast = fast->next;
        }
        if(!fast){
            ListNode* temp = head;
            head = head->next;
            delete(temp);
            return head;
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);
        return head;
    }
};
