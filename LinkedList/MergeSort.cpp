#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* merge(ListNode* L1, ListNode* L2) {
    // create a dummy node ("p") with val 0 (why? -> to create new link list)
    ListNode* p = new ListNode();
    ListNode* dummy = p;
    // iterate through L1 and L2
    //               dummy* (pointer)
    //                 |
    // for first time [0] ->
    //                 |
    //                p (node)
    while(L1 && L2) {
      if(L1->val < L2->val) {
        dummy->next = L1;
        L1 = L1->next;
      } else {
        dummy->next = L2;
        L2 = L2->next;
      }
      dummy = dummy->next;
    }

    if (L1) dummy->next = L1;
    if (L2) dummy->next = L2;

    return p->next;
  }

  ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *prev = NULL, *slow = head, *fast = head;

    // find the middle of a link list
    // slow will catch the mid because
    // fast is moving with a speed double than slow
    while(fast != NULL && fast->next != NULL ) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // break the link list from mid (prev pointer)
    prev->next = NULL;

    // pass head to mid (previous of slow {which is NULL})
    ListNode* L1 = sortList(head);
    // pass mid + 1 (slow) to end
    ListNode* L2 = sortList(slow);

    // merge the array
    return merge(L1, L2);
  }
};

// This main function is for testing purpose only
int main() {
  ListNode *head = new ListNode(1);
  ListNode *p = head;
  int n, t;
  cin >> n;
  while(n--) {
    cin>>t;
    p->next = new ListNode(t);
    p = p->next;
  }
  head = head->next;
  Solution sol;
  ListNode *ans = sol.sortList(head);
  string s = "";
  cout << "[";
  while(ans != NULL) {
    cout <<s<< ans->val;
    ans = ans->next;
    s = ", ";
  }
  cout << "]";
  return 0;
}
