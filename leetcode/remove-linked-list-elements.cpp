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
  ListNode* removeElements(ListNode* head, int val) {

    ListNode* previous = NULL;
    ListNode* current = head;
    ListNode* new_head = head;

    //loop invariant: there's no val behind me && head updated
    while(current != NULL){

      if(current -> val == val){
        // head
        if(previous == NULL){
          new_head = current -> next;
          current = new_head;
        } else {
          ListNode* next = current -> next;
          previous -> next = next;
          current = current -> next;
        }
        continue;
      }

      previous = current;
      current = current -> next;

    }

    return new_head;
  }
};
