#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
  Node *temp = root;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates(Node *head)
    {
      unordered_set<int> s;
      Node *current = head, *next_next = NULL, *prev = head;
      while(current != NULL) {
          if(s.find(current->data) != s.end()) {
              next_next = prev->next->next;
              free(prev->next);
              prev->next = next_next;
          } else {
              s.insert(current->data);
              prev = current;
          }
          current = prev->next;
      }
      return head;
    }

    //Function to remove duplicates from sorted linked list.
    Node *removeSortedDuplicates(Node *head)
    {
      Node *current = head, *next_next = NULL;
      int prev = 0;
      while(current->next != NULL) {
          if (current->data == current->next->data) {
              next_next = current->next->next;
              free(current->next);
              current->next = next_next;
          } else {
              current = current->next;
          }
      }
      return head;
    }
};

int main() {
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}

	  Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;

	}
	return 0;
}
