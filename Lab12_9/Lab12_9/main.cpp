#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    TreeNode* findMinNode(TreeNode* node) {
        if (node == nullptr)
            return nullptr;
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    TreeNode* remove(TreeNode* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->data) {
            node->left = remove(node->left, value);
        }
        else if (value > node->data) {
            node->right = remove(node->right, value);
        }
        else {
            // Case 1: No child
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // Case 2: One child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Two children
            TreeNode* temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    int getHeight(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    void printLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* current = q.front();
                q.pop();
                cout << current->data << " ";
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
            cout << endl;
        }
    }

    TreeNode* balanceTreeUtil(TreeNode* node) {
        if (node == nullptr)
            return nullptr;

        vector<TreeNode*> nodes;
        storeInorder(node, nodes);

        return buildTree(nodes, 0, nodes.size() - 1);
    }

    void storeInorder(TreeNode* node, vector<TreeNode*>& nodes) {
        if (node == nullptr)
            return;
        storeInorder(node->left, nodes);
        nodes.push_back(node);
        storeInorder(node->right, nodes);
    }

    TreeNode* buildTree(vector<TreeNode*>& nodes, int start, int end) {
        if (start > end)
            return nullptr;

        int mid = (start + end) / 2;
        TreeNode* root = nodes[mid];

        root->left = buildTree(nodes, start, mid - 1);
        root->right = buildTree(nodes, mid + 1, end);

        return root;
    }

    TreeNode* removeLeafNodeUtil(TreeNode* node) {
        if (node == nullptr)
            return nullptr;
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        node->left = removeLeafNodeUtil(node->left);
        node->right = removeLeafNodeUtil(node->right);
        return node;
    }

    TreeNode* removeNodeWithOneChildUtil(TreeNode* node) {
        if (node == nullptr)
            return nullptr;
        if (node->left == nullptr && node->right != nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        if (node->left != nullptr && node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }
        node->left = removeNodeWithOneChildUtil(node->left);
        node->right = removeNodeWithOneChildUtil(node->right);
        return node;
    }

    TreeNode* removeNodeWithTwoChildrenUtil(TreeNode* node) {
        if (node == nullptr)
            return nullptr;
        if (node->left != nullptr && node->right != nullptr) {
            TreeNode* successor = findSuccessor(node->right);
            node->data = successor->data;
            node->right = remove(node->right, successor->data);
        }
        return node;
    }

    TreeNode* findSuccessor(TreeNode* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    TreeNode* removeSubtreeUtil(TreeNode* node) {
        if (node == nullptr)
            return nullptr;
        node->left = removeSubtreeUtil(node->left);
        node->right = removeSubtreeUtil(node->right);
        delete node;
        return nullptr;
    }

    TreeNode* findMinElement(TreeNode* node) {
        if (node == nullptr)
            return nullptr;
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    void processTree(TreeNode* node) {
        cout << "Processing the binary search tree..." << endl;
        cout << "Finding the first element with minimum value (inorder traversal): ";
        TreeNode* minNode = findMinElement(node);
        if (minNode != nullptr) {
            cout << "[" << minNode->data << "]" << endl;
        }
        else {
            cout << "The binary search tree is empty." << endl;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void createTree(int* arr, int size) {
        for (int i = 0; i < size; ++i) {
            root = insert(root, arr[i]);
        }
    }

    void display() {
        cout << "Binary Search Tree (Inorder Traversal): ";
        inorderTraversal(root);
        cout << endl;
    }

    void addOrderedElement(int value) {
        root = insert(root, value);
    }

    void balanceTree() {
        root = balanceTreeUtil(root);
        cout << "Balancing the binary search tree..." << endl;
    }

    void removeLeafNode() {
        root = removeLeafNodeUtil(root);
        cout << "Removing leaf node from the binary search tree..." << endl;
    }

    void removeNodeWithOneChild() {
        root = removeNodeWithOneChildUtil(root);
        cout << "Removing node with one child from the binary search tree..." << endl;
    }

    void removeNodeWithTwoChildren() {
        root = removeNodeWithTwoChildrenUtil(root);
        cout << "Removing node with two children from the binary search tree..." << endl;
    }

    void removeSubtree() {
        root = removeSubtreeUtil(root);
        cout << "Removing subtree from the binary search tree..." << endl;
    }

    void processTree() {
        cout << "Processing the binary search tree..." << endl;
        cout << "Finding the first element with minimum value (inorder traversal): ";
        processTree(root);
        cout << endl;
    }

    void displayLevelOrder() {
        cout << "Binary Search Tree (Level Order Traversal):" << endl;
        printLevelOrder(root);
    }
};

void displayMenu() {
    cout << "\nBinary Search Tree Operations:\n";
    cout << "1. Create a binary search tree with predefined elements\n";
    cout << "2. Display the binary search tree (inorder traversal)\n";
    cout << "3. Create a binary search tree with specified elements\n";
    cout << "4. Add an element to the binary search tree (preserving order)\n";
    cout << "5. Balance the binary search tree\n";
    cout << "6. Remove a leaf node from the binary search tree\n";
    cout << "7. Remove a node with one child from the binary search tree\n";
    cout << "8. Remove a node with two children from the binary search tree\n";
    cout << "9. Remove a subtree from the binary search tree\n";
    cout << "10. Process the binary search tree\n";
    cout << "11. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    BinarySearchTree bst;
    int arr[] = { 50, 30, 70, 20, 40, 60, 80 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            bst.createTree(arr, size);
            cout << "Binary search tree created with predefined elements.\n";
            break;
        case 2:
            bst.display();
            break;
        case 3: {
            int n;
            cout << "Enter the number of elements: ";
            cin >> n;
            int* elements = new int[n];
            cout << "Enter the elements: ";
            for (int i = 0; i < n; ++i) {
                cin >> elements[i];
            }
            bst.createTree(elements, n);
            cout << "Binary search tree created with specified elements.\n";
            delete[] elements;
            break;
        }
        case 4: {
            int element;
            cout << "Enter the element to add: ";
            cin >> element;
            bst.addOrderedElement(element);
            cout << "Element added to the binary search tree (preserving order).\n";
            break;
        }
        case 5:
            bst.balanceTree();
            break;
        case 6:
            bst.removeLeafNode();
            break;
        case 7:
            bst.removeNodeWithOneChild();
            break;
        case 8:
            bst.removeNodeWithTwoChildren();
            break;
        case 9:
            bst.removeSubtree();
            break;
        case 10:
            bst.processTree();
            break;
        case 11:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 11);

    return 0;
}
