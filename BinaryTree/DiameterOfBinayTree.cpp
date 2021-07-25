#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
  public:
    // Approach 1 O(n^2)
    int height(Node *node) {
      if (node == NULL) return 0;
      return 1 + max(height(node->left), height(node->right));
    }

    int diameter1(Node* root) {
      if(root == NULL) return 0;

      int ld = diameter1(root->left);
      int rd = diameter1(root->right);
      int f = height(root->left) + height(root->right) + 1;

      return max(f, max(ld, rd));
    }

    // Approach 2 O(n)
    // Instead of calling height (which is recursive itself) on every
    // recursive call of diameter, calculate the height with diameter
    // call
    pair<int /*height*/, int /*diameter*/> findDiameter(Node* root) {
      if (root == NULL) return {0, 0};

      pair<int, int> ld = findDiameter(root->left);
      pair<int, int> rd = findDiameter(root->right);

      pair<int, int> p;
      // calculate height and store
      p.first = max(ld.first, rd.first) + 1;
      int f = ld.first + rd.first + 1;
      p.second = max(f, max(ld.second, rd.second));
      return p;
    }
    int diameter(Node* root) {
        return findDiameter(root).second;
    }
};

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}