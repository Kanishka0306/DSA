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
    ListNode* FindKthNode(ListNode*  temp, int k){
        int count=1;
        while(temp!=NULL){
            if(count==k) return temp;
            count++;
            temp = temp->next;
        }
         return NULL;
    }
    ListNode* reverseLinkedList (ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevnode = NULL;

        while (temp!=NULL){
            ListNode* KthNode = FindKthNode(temp , k);
            if(KthNode == NULL) {
                if(prevnode) prevnode->next=temp;
                break;
            }
            ListNode* nextnode = KthNode->next;
            KthNode->next = NULL;
            reverseLinkedList(temp);
            if(temp==head) head = KthNode;
            else{
                prevnode->next =KthNode;
                } 
            prevnode = temp;
            temp=nextnode;
            }
        return head;
        
    }
};