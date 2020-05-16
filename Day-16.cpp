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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return head;
        
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* tempSecond = head->next;
        
        while(second->next)
        {
            ListNode* third = second->next;
            second->next = third->next;
            third->next = tempSecond;
            first->next = third;
            if(!second->next)
                return head;
            
            second = second->next;
            first = first->next;
        }
        return head;
    }
};
