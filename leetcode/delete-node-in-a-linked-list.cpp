/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  void deleteNode(ListNode* node) {
    ListNode* next = node -> next;

    //swapping value
    int aux = next -> val;
    next -> val = node -> val;
    node -> val = aux;

    node -> next = next -> next;
  }
};
