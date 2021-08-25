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


// 2 -> 4
// 5 -> 6

// cases:
// 2
// 5 -> 6

// 2 -> 4
// 5

// 2 -> 4
// 5 -> 6

// 2
// 5
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = NULL;
    ListNode* result = NULL;
    int nextAdd = 0;
    bool begin = true;
    while(l1->next != NULL && l2->next != NULL){
      int val = (l1->val + l2->val + nextAdd) % 10;
      nextAdd = (l1->val + l2->val + nextAdd) / 10;
      ListNode *current = new ListNode(val);

      if(begin){
        head = current;
        result = head;
        begin = false;
      } else {
        result->next = current;
        result = result->next;
      }

      l1 = l1->next;
      l2 = l2->next;
    }

    int va = (l1->val + l2->val + nextAdd) % 10;
    nextAdd = (l1->val + l2->val + nextAdd) / 10;
    ListNode *current = new ListNode(va);

    if(begin){
      head = current;
      result = head;
      begin = false;
    } else {
      result->next = current;
      result = result->next;
    }

    l1 = l1->next;
    l2 = l2->next;

    if(l1 == NULL && l2 == NULL){
      if(nextAdd != 0){
        ListNode *n = new ListNode(nextAdd);
        result->next = n;
      }

      return head;
    }

    while(l1 != NULL || l2 != NULL){
      int val = ((l1 == NULL? 0: l1->val) + (l2 == NULL? 0: l2->val) + nextAdd) % 10;
      nextAdd = ((l1 == NULL? 0: l1->val) + (l2 == NULL? 0: l2->val) + nextAdd) / 10;
      ListNode* l = new ListNode(val);
      result->next = l;

      l1 == NULL? l1 = NULL: l1 =  l1->next;
      l2 == NULL? l2 = NULL: l2 =  l2->next;
      result = result->next;
    }

    if(nextAdd != 0){
      ListNode* ll = new ListNode(nextAdd);
      result->next = ll;
    }

    return head;
  }
};
