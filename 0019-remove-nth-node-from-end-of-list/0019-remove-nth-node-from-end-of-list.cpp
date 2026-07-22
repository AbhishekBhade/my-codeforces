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
        // Edge case: empty list
        if (!head) return nullptr;

        // Step 1: Count total nodes
        int cnt = 0;
        ListNode* temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }

        // CHANGE: Handle case where we remove the head node
        // If n equals total count, we're removing the first node
        if (n == cnt) {
            ListNode* newHead = head->next;
            delete head;  // Optional: free memory
            return newHead;
        }

        // Step 2: Find the node before the one to remove
        temp = head;
        int stepsToTarget = cnt - n - 1;  // Changed from 'cnt - n' to skip one more
        for (int i = 0; i < stepsToTarget; i++) {
            temp = temp->next;
        }

        // Step 3: Remove the nth node from end
        ListNode* toRemove = temp->next;
        temp->next = temp->next->next;
        delete toRemove;  // Optional: free memory

        return head;
    }
};