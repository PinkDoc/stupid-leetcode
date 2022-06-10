#include "bits.hpp"

struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
                        val(x), next(NULL) {
        }
};

class Solution {
public:
  ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
    if (pHead1 == nullptr)
      return pHead2;
    if (pHead2 == nullptr)
      return pHead1;

    ListNode *p1 = pHead1, *p2 = pHead2;
    ListNode *temp = nullptr;
    ListNode *ret = nullptr;
    ListNode *tail = nullptr;
    while (p1 && p2) {
      if (p1->val > p2->val) {
        temp = p2;
        p2 = p2->next;
      } else {
        temp = p1;
        p1 = p1->next;
      }

      cout << temp->val << " ";

      if (!ret) {
        ret = temp;
        tail = temp;
      } else {
        tail->next = temp;
        temp->next = nullptr;
        tail = tail->next;
      }
    }

    temp = !p1 ? p2 : p1;

    if (temp) {
      tail->next = temp;
    }

    return ret;
  }
};