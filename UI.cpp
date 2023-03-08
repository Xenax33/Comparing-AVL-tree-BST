#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cmath>
#include <windows.h>
#include "class.cpp"
using namespace std;

class UI
{
public:
    string option;

    string MainMenu()
    {
        cout << "1. Binary Search Tree" << endl;
        cout << "2. AVL Tree" << endl;
        cout << "3. Exit" << endl;
        cin >> option;
        return option;
    }

    string LoadTree()
    {
        cout << "1. Load 100 Records" << endl;
        cout << "2. Load 1000 Records" << endl;
        cout << "3. Load 10000 Records" << endl;
        cout << "4. Load 100000 Records" << endl;
        cout << "5. Back" << endl;
        cin >> option;
        return option;
    }

    string SubMenu()
    {
        cout << "1. Insert a New Record" << endl;
        cout << "2. Retrieve a Record" << endl;
        cout << "3. Update a Record" << endl;
        cout << "4. Delete a Record" << endl;
        cout << "5. Traverse the Tree" << endl;
        cout << "6. Back" << endl;
        cin >> option;
        return option;
    }

    string TraversalMenu()
    {
        cout << "1. Breath First Traversal" << endl;
        cout << "2. In Order" << endl;
        cout << "3. Post Order" << endl;
        cout << "4. Pre Order" << endl;
        cout << "5. Back" << endl;
        cin >> option;
        return option;
    }

    TreeNode *option1()
    {
        TreeNode *tree = new TreeNode();
        cout << "Index: ";
        cin >> tree->Index;
        cout << "Customer Id: ";
        cin >> tree->CustomerId;
        cout << "Firt Name: ";
        cin >> tree->FirstName;
        cout << "Last Name: ";
        cin >> tree->LastName;
        cout << "Company: ";
        cin >> tree->Company;
        cout << "City: ";
        cin >> tree->City;
        cout << "Country: ";
        cin >> tree->City;
        cout << "Phone 1: ";
        cin >> tree->Phone1;
        cout << "Phone 2: ";
        cin >> tree->Phone2;
        cout << "Email: ";
        cin >> tree->Email;
        cout << "Subscription Date: ";
        cin >> tree->SubscriptionDate;
        cout << "Website: ";
        cin >> tree->Website;
        return tree;
    }

    void PrintTree(TreeNode *tree)
    {
        if (tree == NULL)
        {
            cout << "No Record Found" << endl;
        }
        else
        {
            cout << "DATA: " << endl;
            cout << "Index: " << tree->Index << endl;
            cout << "First Name: " << tree->FirstName << endl;
            cout << "Last Name: " << tree->LastName << endl;
            cout << "Comapny: " << tree->Company << endl;
            cout << "City: " << tree->City << endl;
            cout << "Country: " << tree->Country << endl;
            cout << "Phone 1: " << tree->Phone1 << endl;
            cout << "Phone 2: " << tree->Phone2 << endl;
            cout << "Email: " << tree->Email << endl;
            cout << "Subscription Date: " << tree->SubscriptionDate << endl;
            cout << "Website: " << tree->Website << endl;
        }
    }

    void Update(TreeNode *tree)
    {
        cout << "Customer Id: ";
        cin >> tree->CustomerId;
        cout << "Firt Name: ";
        cin >> tree->FirstName;
        cout << "Last Name: ";
        cin >> tree->LastName;
        cout << "Company: ";
        cin >> tree->Company;
        cout << "City: ";
        cin >> tree->City;
        cout << "Country: ";
        cin >> tree->City;
        cout << "Phone 1: ";
        cin >> tree->Phone1;
        cout << "Phone 2: ";
        cin >> tree->Phone2;
        cout << "Email: ";
        cin >> tree->Email;
        cout << "Subscription Date: ";
        cin >> tree->SubscriptionDate;
        cout << "Website: ";
        cin >> tree->Website;
        clearscreen();
    }

    int UpadteRecord()
    {
        int index;
        cout << "Enter Index of the Record: ";
        cin >> index;
        return index;
    }

    void clearscreen()
    {
        cout << "Enter Any Key to Continue...." << endl;
        getch();
        system("cls");
    }

    void PrintBFS(queue<TreeNode *> q)
    {
        while (!q.empty())
        {
            cout << q.front()->Index << endl;
            q.pop();
        }
        cout << "DONE" << endl;
        clearscreen();
    }
};
