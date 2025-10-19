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
    ListNode* reverseList(ListNode* head) {
        // Iterative version
        //  ListNode* prev = nullptr;
        //  ListNode* curr = head;

        // while(curr != nullptr){
        //     ListNode* next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        // }
        // return prev;
        // recursive version
        while (head == nullptr || head->next == nullptr)
            return head;

        ListNode* newNode = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newNode;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow, *fast;
        slow = fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseList(slow->next);
        ListNode* first, *second;
        first = head;
        second = newHead;
        while(second){
            if(first->val != second->val){
                reverseList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseList(newHead);
        return true;
    }
};