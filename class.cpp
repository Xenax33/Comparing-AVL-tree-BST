#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <chrono>
using namespace std;

struct TreeNode
{
    int Index;
    string CustomerId;
    string FirstName;
    string LastName;
    string Company;
    string City;
    string Country;
    string Phone1;
    string Phone2;
    string Email;
    string SubscriptionDate;
    string Website;
    int height;

    TreeNode *left;
    TreeNode *right;
};

class BinaryTree
{
public:
    TreeNode *root;

    BinaryTree()
    {
        root = NULL;
    }

    void inorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->Index << ',';
        inorder(root->right);
    }

    TreeNode *inorderSuccessor(TreeNode *root)
    {
        TreeNode *temp = root;
        while (temp && temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    TreeNode *deleteInBST(TreeNode *root, int key)
    {
        if (key < root->Index)
        {
            root->left = deleteInBST(root->left, key);
        }
        else if (key > root->Index)
        {
            root->right = deleteInBST(root->right, key);
        }
        else
        {
            if (root->left == NULL)
            {
                TreeNode *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                TreeNode *temp = root->left;
                free(root);
                return temp;
            }
            TreeNode *temp = inorderSuccessor(root->right);
            root->Index = temp->Index;
            root->right = deleteInBST(root->right, temp->Index);
        }
        return root;
    }

    TreeNode *SearchFromTree(int Index)
    {
        TreeNode *temp = root;
        while (true)
        {
            if (temp == NULL)
            {
                break;
            }
            if (Index > temp->Index)
            {
                temp = temp->right;
            }
            else if (Index < temp->Index)
            {
                temp = temp->left;
            }
            else if (Index == temp->Index)
            {
                break;
            }
        }
        return temp;
    }

    void InsertIntoTree(TreeNode *tree)
    {
        TreeNode *temp = root;
        if (root == NULL)
        {
            root = tree;
        }
        else
        {
            while (true)
            {
                if (tree->Index > temp->Index)
                {
                    if (temp->right != NULL)
                    {
                        temp = temp->right;
                    }
                    else
                    {
                        temp->right = tree;
                        break;
                    }
                }
                else if (tree->Index < temp->Index)
                {
                    if (temp->left != NULL)
                    {
                        temp = temp->left;
                    }
                    else
                    {
                        temp->left = tree;
                        break;
                    }
                }
            }
        }
    }

    void ReadFromFile(string path)
    {
        ifstream data(path);
        string line;
        int count = 0;
        while (getline(data, line))
        {
            int count1 = 0;
            string array[13];
            stringstream lineStream(line);
            string cell;
            while (std::getline(lineStream, cell, ','))
            {
                array[count1] = cell;
                count1++;
            }
            count1 = 0;
            if (count > 0)
            {
                TreeNode *tree = new TreeNode();
                tree->Index = stoi(array[0]);
                tree->CustomerId = array[1];
                tree->FirstName = array[2];
                tree->LastName = array[3];
                tree->Company = array[4];
                tree->City = array[5];
                tree->Country = array[6];
                tree->Phone1 = array[7];
                tree->Phone2 = array[8];
                tree->Email = array[9];
                tree->SubscriptionDate = array[10];
                tree->Website = array[11];
                tree->left == NULL;
                tree->right == NULL;
                InsertIntoTree(tree);
            }
            count++;
        }
    }

    void ClearTree()
    {
        this->root = NULL;
    }

    void BreathFirstTraversal()
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            cout << q.front()->Index << " ";
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }

    void InOrderTraversal()
    {
        stack<TreeNode *> stack;
        TreeNode *temp = root;
        while (!stack.empty() || temp != NULL)
        {
            if (temp != NULL)
            {
                stack.push(temp);
                temp = temp->left;
            }
            else
            {
                temp = stack.top();
                stack.pop();
                cout << temp->Index << " ";
                temp = temp->right;
            }
        }
    }

    void PostOrderTraversal()
    {
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            TreeNode *temp = s1.top();
            s2.push(temp);
            s1.pop();
            if (temp->left != NULL)
                s1.push(temp->left);
            if (temp->right != NULL)
                s1.push(temp->right);
        }
        while (!s2.empty())
        {
            cout << s2.top()->Index << " ";
            s2.pop();
        }
    }

    void PreOrderTraversal()
    {
        stack<TreeNode *> stack;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *temp = stack.top();
            stack.pop();
            cout << temp->Index << " ";
            if (temp->right != NULL)
                stack.push(temp->right);
            if (temp->left != NULL)
                stack.push(temp->left);
        }
    }
};

class AVLtree
{
public:
    TreeNode *root;

    AVLtree()
    {
        root = NULL;
    }

    void ClearTree()
    {
        this->root = NULL;
    }

    int height(TreeNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        return height(node->left) - height(node->right);
    }

    int max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        return b;
    }

    TreeNode *rightRotate(TreeNode *x)
    {
        TreeNode *y = x->left;
        TreeNode *T2 = y->right;
        y->right = x;
        x->left = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    TreeNode *leftRotate(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    stack<TreeNode *> insert(TreeNode *node)
    {
        stack<TreeNode *> s;
        if (root == NULL)
        {
            root = node;
            return s;
        }
        TreeNode *prev = root;
        TreeNode *next = root;
        while (next != NULL)
        {
            prev = next;
            s.push(next);
            if (node->Index < prev->Index)
            {
                next = prev->left;
            }
            else
            {
                next = prev->right;
            }
        }
        s.push(node);
        if (node->Index >= prev->Index)
            prev->right = node;
        else
            prev->left = node;
        return s;
    }

    void rotate(stack<TreeNode *> s, TreeNode *node)
    {
        TreeNode *temp;
        TreeNode *temp1;
        while (!s.empty())
        {
            temp = s.top();
            bool isBalanceChanged = false;
            temp->height = max(height(temp->left), height(temp->right)) + 1;
            int balanceFactor = getBalanceFactor(temp);
            if (balanceFactor > 1)
            {
                if (node->Index < temp->left->Index)
                    temp1 = rightRotate(temp);
                else if (node->Index > temp->left->Index)
                {
                    temp->left = leftRotate(temp->left);
                    temp1 = rightRotate(temp);
                }
                isBalanceChanged = true;
            }
            if (balanceFactor < -1)
            {
                if (node->Index > temp->right->Index)
                    temp1 = leftRotate(temp);
                else if (node->Index < temp->right->Index)
                {
                    temp->right = rightRotate(temp->right);
                    temp1 = leftRotate(temp);
                }
                isBalanceChanged = true;
            }
            s.pop();
            if (isBalanceChanged)
            {
                if (s.empty())
                    root = temp1;
                else
                {
                    if (s.top()->left == temp)
                        s.top()->left = temp1;
                    else
                        s.top()->right = temp1;
                }
            }
        }
    }

    void insertionWithRotation(TreeNode *node)
    {
        stack<TreeNode *> s = insert(node);
        rotate(s, node);
    }

    void inorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->Index << ',';
        inorder(root->right);
    }

    TreeNode *inorderSuccessor(TreeNode *root)
    {
        TreeNode *temp = root;
        while (temp && temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    TreeNode *deleteInAVL(TreeNode *root, int key)
    {
        if (key < root->Index)
        {
            root->left = deleteInAVL(root->left, key);
        }
        else if (key > root->Index)
        {
            root->right = deleteInAVL(root->right, key);
        }
        else
        {
            if (root->left == NULL)
            {
                TreeNode *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                TreeNode *temp = root->left;
                free(root);
                return temp;
            }
            TreeNode *temp = inorderSuccessor(root->right);
            root->Index = temp->Index;
            root->right = deleteInAVL(root->right, temp->Index);
        }
        return root;
    }

    stack<TreeNode *> DeleteFromAVL(TreeNode *tree)
    {
    }

    void DeletionWithRotation(TreeNode *node)
    {
    }

    void ReadFromFile(string path)
    {
        ifstream data(path);
        string line;
        int count = 0;
        while (getline(data, line))
        {
            int count1 = 0;
            string array[13];
            stringstream lineStream(line);
            string cell;
            while (std::getline(lineStream, cell, ','))
            {
                array[count1] = cell;
                count1++;
            }
            count1 = 0;
            if (count > 0)
            {
                TreeNode *tree = new TreeNode();
                tree->Index = stoi(array[0]);
                tree->CustomerId = array[1];
                tree->FirstName = array[2];
                tree->LastName = array[3];
                tree->Company = array[4];
                tree->City = array[5];
                tree->Country = array[6];
                tree->Phone1 = array[7];
                tree->Phone2 = array[8];
                tree->Email = array[9];
                tree->SubscriptionDate = array[10];
                tree->Website = array[11];
                tree->left == NULL;
                tree->right == NULL;
                insertionWithRotation(tree);
            }
            count++;
        }
    }

    TreeNode *SearchFromTree(int Index)
    {
        TreeNode *temp = root;
        while (true)
        {
            if (temp == NULL)
            {
                break;
            }
            if (Index > temp->Index)
            {
                temp = temp->right;
            }
            else if (Index < temp->Index)
            {
                temp = temp->left;
            }
            else if (Index == temp->Index)
            {
                break;
            }
        }
        return temp;
    }
    void BreathFirstTraversal()
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            cout << q.front()->Index << " ";
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }

    void InOrderTraversal()
    {
        stack<TreeNode *> stack;
        TreeNode *temp = root;
        while (!stack.empty() || temp != NULL)
        {
            if (temp != NULL)
            {
                stack.push(temp);
                temp = temp->left;
            }
            else
            {
                temp = stack.top();
                stack.pop();
                cout << temp->Index << " ";
                temp = temp->right;
            }
        }
    }

    void PostOrderTraversal()
    {
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            TreeNode *temp = s1.top();
            s2.push(temp);
            s1.pop();
            if (temp->left != NULL)
                s1.push(temp->left);
            if (temp->right != NULL)
                s1.push(temp->right);
        }
        while (!s2.empty())
        {
            cout << s2.top()->Index << " ";
            s2.pop();
        }
    }

    void PreOrderTraversal()
    {
        stack<TreeNode *> stack;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *temp = stack.top();
            stack.pop();
            cout << temp->Index << " ";
            if (temp->right != NULL)
                stack.push(temp->right);
            if (temp->left != NULL)
                stack.push(temp->left);
        }
    }
};