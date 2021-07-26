#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}

// ---------------------------- FOR LEFT VIEW -----------------------------
void leftView(Node *root, vector<int>& ans, int level, int &maxLevel) {
  if(root == NULL) return;

  if(maxLevel < level) {
    ans.push_back(root->data);
    maxLevel = level;
  }

  leftView(root->left, ans, level + 1, maxLevel);
  leftView(root->right, ans, level + 1, maxLevel);
}

// Approach 1 O(n^2)
vector<int> leftView(Node *root) {
  vector<int> ans;
  int maxLevel = 0;
  leftView(root, ans, 1, maxLevel);
  return ans;
}

// Approach 2 O(n)
vector<int> leftView2(Node *root) {
  queue<Node*> q;
  vector<int> ans;
  q.push(root);

  while(!q.empty()) {
    // number of nodes at current level
    int n = q.size();

    // Traverse all nodes of current level
    for (int i = 1; i <= n; i++) {
      Node* temp = q.front();
      q.pop();

      // Print the left most element
      // at the level
      if (i == 1) ans.push_back(temp->data);

      // Add left node to queue
      if (root->left) q.push(root->left);
      // Add right node to queue
      if (root->right) q.push(root->right);
    }
  }
  return ans;
}

// ---------------------------- FOR RIGHT VIEW -----------------------------
void rightView(Node* root, vector<int>& ans, int level, int &maxLevel) {
  if (root == NULL) return;

  if(maxLevel < level) {
    ans.push_back(root->data);
    maxLevel = level;
  }

  rightView(root->right, ans, level + 1, maxLevel);
  rightView(root->left, ans, level + 1, maxLevel);
}

vector<int> rightView(Node *root) {
  vector<int> ans;
  int maxLevel = 0;
  rightView(root, ans, 1, maxLevel);
  return ans;
}

// ---------------------------- FOR TOP VIEW -----------------------------

vector<vector<int>> verticalOrderTraversal(Node *root) {
    vector<vector<int>> ans;
    queue<pair<Node*, int /*horizontal level*/>> q;
    map<int, vector<int> /*nodes on horizontal level*/> m;
    q.push({root, 0});
    int maxHl = 0, minHl = 0;
    while(!q.empty()) {
        int size = q.size();
        // Traverse all nodes of current level
        while (size--) {
            // Get the current node
            pair<Node*, int> removePair = q.front();
            q.pop();

            // Get the current node's horizontal level to update minimun and maximun horizontal level
            maxHl = max(maxHl, removePair.second);
            minHl = min(minHl, removePair.second);

            // Add the current node to the map
            m[removePair.second].push_back(removePair.first->data);

            // Add left node to queue
            if(removePair.first->left) {
                q.push({removePair.first->left, removePair.second - 1});
            }

            // Add right node to queue
            if(removePair.first->right) {
              q.push({removePair.first->right, removePair.second + 1});
            }
        }
    }

    // Traverse the map to get the vertical order traversal
    for (int i = minHl; i <= maxHl; i++) {
        ans.push_back(m[i]);
    }

    // Return the vertical order traversal
    return ans;
}

vector<int> topView(Node *root) {
    vector<int> ans;
    queue<pair<Node*, int>> q;
    map<int, vector<int>> m;
    q.push({root, 0});
    int maxHl = 0, minHl = 0;
    while(!q.empty()) {
        int size = q.size();
        while (size--) {
            pair<Node*, int> removePair = q.front();
            q.pop();

            maxHl = max(maxHl, removePair.second);
            minHl = min(minHl, removePair.second);

            m[removePair.second].push_back(removePair.first->data);

            if(removePair.first->left) {
                q.push({removePair.first->left, removePair.second - 1});
            }

            if(removePair.first->right) {
              q.push({removePair.first->right, removePair.second + 1});
            }
        }
    }

    for (int i = minHl; i <= maxHl; i++) {
        ans.push_back(m[i][0]);
    }
    return ans;
}
