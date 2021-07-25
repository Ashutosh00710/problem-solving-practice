#include<bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryTree {
    private:
        T data;
        BinaryTree<T> *left;
        BinaryTree<T> *right;
    public:
        BinaryTree() {
            left = right = NULL;
        }
        BinaryTree(T d) {
            data = d;
            left = right = NULL;
        }
        BinaryTree(T d, BinaryTree<T> *l, BinaryTree<T> *r) {
            data = d;
            left = l;
            right = r;
        }
        void setData(T d) {
            data = d;
        }
        T getData() {
            return data;
        }
        void setLeft(BinaryTree<T> *l) {
            left = l;
        }
        void setRight(BinaryTree<T> *r) {
            right = r;
        }
        BinaryTree<T> *getLeft() {
            return left;
        }
        BinaryTree<T> *getRight() {
            return right;
        }
        void print() {
            if (left != NULL) {
                left->print();
            }
            cout << data << " ";
            if (right != NULL) {
                right->print();
            }
        }
};

// function to print the tree in inorder
// (left, root, right)
template <typename T>
void inorder(BinaryTree<T> *root) {
    if (root != NULL) {
        inorder(root->getLeft());
        cout << root->getData() << " ";
        inorder(root->getRight());
    }
}

template <typename T>
void inorderIterative(BinaryTree<T> *root) {
    stack<BinaryTree<T>*> stack;

    // start from the root node (set current node to the root node)
    BinaryTree<T>* curr = root;

    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != nullptr) {
            stack.push(curr);
            curr = curr->left;
        } else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";

            curr = curr->right;
        }
    }
}

// function to print the tree in preorder
// (root, left, right)
template <typename T>
void preorder(BinaryTree<T> *root) {
    if (root != NULL) {
        cout << root->getData() << " ";
        preorder(root->getLeft());
        preorder(root->getRight());
    }
}

template<typename T>
void preorderIterative(BinaryTree<T> root) {
    // return if the tree is empty
    if (root == nullptr)
    return;

    // create an empty stack and push the root node
    stack<BinaryTree<T>*> stack;
    stack.push(root);

    // loop till stack is empty
    while (!stack.empty())
    {
        // pop a node from the stack and print it
        BinaryTree<T>* curr = stack.top();
        stack.pop();

        cout << curr->data << " ";

        // push the right child of the popped node into the stack
        if (curr->right) {
            stack.push(curr->right);
        }

        // push the left child of the popped node into the stack
        if (curr->left) {
            stack.push(curr->left);
        }

        // the right child must be pushed first so that the left child
        // is processed first (LIFO order)
    }
}

// function to print the tree in postorder
// (left, right, root)
template <typename T>
void postorder(BinaryTree<T> *root) {
    if (root == NULL) return;
    postorder(root->getLeft());
    postorder(root->getRight());
    cout << root->getData() << " ";
}

template <typename T>
void postorderIterative(BinaryTree<T> *root) {
    // create an empty stack and push the root node
    stack<BinaryTree<T>*> s;
    s.push(root);

    // create another stack to store postorder traversal
    stack<int> out;

    // loop till stack is empty
    while (!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        BinaryTree<T>* curr = s.top();
        s.pop();

        out.push(curr->data);

        // push the left and right child of the popped node into the stack
        if (curr->left) {
            s.push(curr->left);
        }

        if (curr->right) {
            s.push(curr->right);
        }
    }

    // print postorder traversal
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}

// function to print the tree in levelorder
// (root, left, right)
template <typename T>
void levelorder(BinaryTree<T> *root) {
    if (root == NULL) return;
    queue<BinaryTree<T> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTree<T> *temp = q.front();
        q.pop();
        cout << temp->getData() << " ";
        if (temp->getLeft() != NULL) {
            q.push(temp->getLeft());
        }
        if (temp->getRight() != NULL) {
            q.push(temp->getRight());
        }
    }
}

// create a main() to run the program
int main() {
    BinaryTree<int> *root = new BinaryTree<int>(1);
    BinaryTree<int> *node1 = new BinaryTree<int>(2);
    BinaryTree<int> *node2 = new BinaryTree<int>(3);
    BinaryTree<int> *node3 = new BinaryTree<int>(4);
    BinaryTree<int> *node4 = new BinaryTree<int>(5);
    BinaryTree<int> *node5 = new BinaryTree<int>(6);
    BinaryTree<int> *node6 = new BinaryTree<int>(7);
    BinaryTree<int> *node7 = new BinaryTree<int>(8);
    BinaryTree<int> *node8 = new BinaryTree<int>(9);
    BinaryTree<int> *node9 = new BinaryTree<int>(10);
    BinaryTree<int> *node10 = new BinaryTree<int>(11);
    BinaryTree<int> *node11 = new BinaryTree<int>(12);
    BinaryTree<int> *node12 = new BinaryTree<int>(13);

    root->setLeft(node1);
    root->setRight(node2);
    node1->setLeft(node3);
    node1->setRight(node4);
    node2->setLeft(node5);
    node2->setRight(node6);
    node3->setLeft(node7);
    node3->setRight(node8);
    node4->setLeft(node9);
    node4->setRight(node10);
    node5->setLeft(node11);
    node5->setRight(node12);
    node6->setLeft(NULL);
    node6->setRight(NULL);
    node7->setLeft(NULL);
    node7->setRight(NULL);
    node8->setLeft(NULL);
    node8->setRight(NULL);
    node9->setLeft(NULL);
    node9->setRight(NULL);
    node10->setLeft(NULL);
    node10->setRight(NULL);
    node11->setLeft(NULL);
    node11->setRight(NULL);
    node12->setLeft(NULL);
    node12->setRight(NULL);
    cout << "Inorder traversal of the tree is: ";
    inorder(root);
    cout << endl;
    cout << "Preorder traversal of the tree is: ";
    preorder(root);
    cout << endl;
    cout << "Postorder traversal of the tree is: ";
    postorder(root);
    cout << endl;
    return 0;
}
