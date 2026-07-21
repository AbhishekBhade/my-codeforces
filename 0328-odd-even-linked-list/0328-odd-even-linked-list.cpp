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
        if (head == NULL || head->next == NULL) return head;
        vector<int> pog;
        ListNode* temp=head;
        while(temp!=NULL){
            pog.push_back(temp->val);
            
            if(temp->next!=NULL){
                temp=temp->next->next;
            }
            else{
                break;
            }
        }
        temp=head->next;
        while(temp!=NULL){
            pog.push_back(temp->val);
            if(temp->next!=NULL){
                temp=temp->next->next;
            }
            else{
                break;
            }
        }
        temp=head;
        int cnt=0;
        while(temp!=NULL){
            temp->val=pog[cnt];
            cnt++;
            temp=temp->next;
        }
        return head;
    }
};