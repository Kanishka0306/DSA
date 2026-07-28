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
    ListNode* FindNth_Node (  ListNode*  temp , int k){
        int count =1;
        while (temp!=NULL){
            if (count==k) return temp;
            temp=temp->next;
            count++;
        }
        return temp;
    } 
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || k==0 || head->next == NULL) return head;

        ListNode* tail = head;
        int len = 1;
        while (tail->next!=NULL){
            tail = tail->next;
            len++;
        } 
        if (k % len ==0 ) return head;
        k=k%len;

        //join the last node to head then len-k node ko points to NULL (or break the LL or circular LL formed)
        tail->next = head;
        ListNode* NewLastNode = FindNth_Node(head , len-k);

        head = NewLastNode->next;
        NewLastNode->next = NULL;

        return head;
    }
};