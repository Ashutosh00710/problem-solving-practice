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
    // using iteration
    ListNode* reverseList(ListNode* head) {
        ListNode *current = head, *previous = NULL, *next = NULL;
        while(current) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }

    // using recursion
    ListNode* reverseListR(ListNode* head) {
        // if head is null, return head
        if(head == NULL || head->next == NULL) return head;
        // recursively reverse the rest of the list
        // and then connect the reversed list to the head
        // of the original list
        ListNode *previous = reverseList(head->next);
        // example:
        //                      head->next->next
        //                        ___⬇____
        //                       ⬇      ⬆
        // [1] -> [2] -> [3] -> [4] -> [5]
        //                             ⬆
        //                           head
        head->next->next = head;
        head->next = NULL;
        return previous;
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
  ListNode *ans = sol.reverseListR(head);
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