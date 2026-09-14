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
        ListNode* currHead = reverseLL(head);
        ListNode* curr = currHead;
        if(n == 1){
            ListNode* temp = currHead;
            currHead = currHead->next;
            delete(temp);
            return reverseLL(currHead);
        }
        int tempNo = 1;
        ListNode* prev = NULL;
        while(curr){
            if(tempNo < n - 1){
                curr = curr->next;
                tempNo++;
            }else if(tempNo == n - 1){
                prev = curr;
                break;
            }
        }
        if(prev && prev->next){
            ListNode* nodeToBeRemoved = prev->next;
            prev->next = nodeToBeRemoved->next;
            delete(nodeToBeRemoved);
        }
        return reverseLL(currHead);
    }
};
