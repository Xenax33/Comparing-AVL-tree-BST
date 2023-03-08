#include "UI.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;

main()
{
    UI ui;
    BinaryTree BinarySearchTree;
    AVLtree AVLtree;
    string option, option1;
    string path;
    string op3, op, op1, op2, opt;
    while (true)
    {
        // MAIN MENU
        option = ui.MainMenu();
        if (option == "1")
        {
            while (true)
            {
                option1 = ui.LoadTree();
                if (option1 == "1")
                {
                    path = "customers-100.csv";
                    auto start = chrono::steady_clock::now();
                    BinarySearchTree.ReadFromFile(path);
                    auto end = chrono::steady_clock::now();
                    auto diff = end - start;
                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                    ui.clearscreen();
                    while (true)
                    {
                        op = ui.SubMenu();
                        // INSERT A RECORD
                        if (op == "1")
                        {
                            auto start = chrono::steady_clock::now();
                            TreeNode *temp = ui.option1();
                            TreeNode *temp1 = BinarySearchTree.SearchFromTree(temp->Index);
                            if (temp1 != NULL)
                            {
                                cout << "Index Already Exists" << endl;
                                ui.clearscreen();
                            }
                            else
                            {
                                BinarySearchTree.InsertIntoTree(temp);
                                auto end = chrono::steady_clock::now();
                                auto diff = end - start;
                                cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                ui.clearscreen();
                            }
                        }
                        // RETRIEVE A RECORD
                        else if (op == "2")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.PrintTree(BinarySearchTree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // UPDATE RECORD
                        else if (op == "3")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.Update(BinarySearchTree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // DELETE RECORD
                        else if (op == "4")
                        {
                            auto start = chrono::steady_clock::now();
                            int index = ui.UpadteRecord();
                            BinarySearchTree.deleteInBST(BinarySearchTree.root, index);
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // TRAVERSE THE TREE
                        else if (op == "5")
                        {
                            while (true)
                            {
                                opt = ui.TraversalMenu();
                                // BREATHFRIST TRAVERSAL
                                if (opt == "1")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.BreathFirstTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // INORDER TRAVERSAL
                                else if (opt == "2")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.InOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // POSTORDER TRAVERSAL
                                else if (opt == "3")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.PostOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // PREORDER TRAVERSAL
                                else if (opt == "4")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.PreOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                else if (opt == "5")
                                {
                                    ui.clearscreen();
                                    break;
                                }
                                else
                                {
                                    ui.clearscreen();
                                }
                            }
                        }
                        else if (op == "6")
                        {
                            ui.clearscreen();
                            BinarySearchTree.ClearTree();
                            break;
                        }
                        else
                        {
                            ui.clearscreen();
                        }
                    }
                }
                else if (option1 == "2")
                {
                    path = "customers-1000.csv";
                    auto start = chrono::steady_clock::now();
                    BinarySearchTree.ReadFromFile(path);
                    auto end = chrono::steady_clock::now();
                    auto diff = end - start;
                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                    ui.clearscreen();
                    while (true)
                    {
                        op = ui.SubMenu();
                        // INSERT A RECORD
                        if (op == "1")
                        {
                            auto start = chrono::steady_clock::now();
                            TreeNode *temp = ui.option1();
                            TreeNode *temp1 = BinarySearchTree.SearchFromTree(temp->Index);
                            if (temp1 != NULL)
                            {
                                cout << "Index Already Exists" << endl;
                                ui.clearscreen();
                            }
                            else
                            {
                                BinarySearchTree.InsertIntoTree(temp);
                                auto end = chrono::steady_clock::now();
                                auto diff = end - start;
                                cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                ui.clearscreen();
                            }
                        }
                        // RETRIEVE A RECORD
                        else if (op == "2")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.PrintTree(BinarySearchTree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // UPDATE RECORD
                        else if (op == "3")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.Update(BinarySearchTree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // DELETE RECORD
                        else if (op == "4")
                        {
                            auto start = chrono::steady_clock::now();
                            int index = ui.UpadteRecord();
                            BinarySearchTree.deleteInBST(BinarySearchTree.root, index);
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // TRAVERSE THE TREE
                        else if (op == "5")
                        {
                            while (true)
                            {
                                opt = ui.TraversalMenu();
                                // BREATHFRIST TRAVERSAL
                                if (opt == "1")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.BreathFirstTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // INORDER TRAVERSAL
                                else if (opt == "2")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.InOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // POSTORDER TRAVERSAL
                                else if (opt == "3")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.PostOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // PREORDER TRAVERSAL
                                else if (opt == "4")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.PreOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                else if (opt == "5")
                                {
                                    ui.clearscreen();
                                    break;
                                }
                                else
                                {
                                    ui.clearscreen();
                                }
                            }
                        }
                        else if (op == "6")
                        {
                            ui.clearscreen();
                            BinarySearchTree.ClearTree();
                            break;
                        }
                        else
                        {
                            ui.clearscreen();
                        }
                    }
                }
                else if (option1 == "3")
                {
                    path = "customers-10000.csv";
                    auto start = chrono::steady_clock::now();
                    BinarySearchTree.ReadFromFile(path);
                    auto end = chrono::steady_clock::now();
                    auto diff = end - start;
                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                    ui.clearscreen();
                    while (true)
                    {
                        op = ui.SubMenu();
                        // INSERT A RECORD
                        if (op == "1")
                        {
                            auto start = chrono::steady_clock::now();
                            TreeNode *temp = ui.option1();
                            TreeNode *temp1 = BinarySearchTree.SearchFromTree(temp->Index);
                            if (temp1 != NULL)
                            {
                                cout << "Index Already Exists" << endl;
                                ui.clearscreen();
                            }
                            else
                            {
                                BinarySearchTree.InsertIntoTree(temp);
                                auto end = chrono::steady_clock::now();
                                auto diff = end - start;
                                cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                ui.clearscreen();
                            }
                        }
                        // RETRIEVE A RECORD
                        else if (op == "2")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.PrintTree(BinarySearchTree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // UPDATE RECORD
                        else if (op == "3")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.Update(BinarySearchTree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // DELETE RECORD
                        else if (op == "4")
                        {
                            auto start = chrono::steady_clock::now();
                            int index = ui.UpadteRecord();
                            BinarySearchTree.deleteInBST(BinarySearchTree.root, index);
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // TRAVERSE THE TREE
                        else if (op == "5")
                        {
                            while (true)
                            {
                                opt = ui.TraversalMenu();
                                // BREATHFRIST TRAVERSAL
                                if (opt == "1")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.BreathFirstTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // INORDER TRAVERSAL
                                else if (opt == "2")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.InOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // POSTORDER TRAVERSAL
                                else if (opt == "3")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.PostOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // PREORDER TRAVERSAL
                                else if (opt == "4")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.PreOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                else if (opt == "5")
                                {
                                    ui.clearscreen();
                                    break;
                                }
                                else
                                {
                                    ui.clearscreen();
                                }
                            }
                        }
                        else if (op == "6")
                        {
                            ui.clearscreen();
                            BinarySearchTree.ClearTree();
                            break;
                        }
                        else
                        {
                            ui.clearscreen();
                        }
                    }
                }
                else if (option1 == "4")
                {
                    path = "customers-100000.csv";
                    BinarySearchTree.ReadFromFile(path);
                    while (true)
                    {
                        op = ui.SubMenu();
                        // INSERT A RECORD
                        if (op == "1")
                        {
                            auto start = chrono::steady_clock::now();
                            TreeNode *temp = ui.option1();
                            TreeNode *temp1 = BinarySearchTree.SearchFromTree(temp->Index);
                            if (temp1 != NULL)
                            {
                                cout << "Index Already Exists" << endl;
                                ui.clearscreen();
                            }
                            else
                            {
                                BinarySearchTree.InsertIntoTree(temp);
                                auto end = chrono::steady_clock::now();
                                auto diff = end - start;
                                cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                ui.clearscreen();
                            }
                        }
                        // RETRIEVE A RECORD
                        else if (op == "2")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.PrintTree(BinarySearchTree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // UPDATE RECORD
                        else if (op == "3")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.Update(BinarySearchTree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // DELETE RECORD
                        else if (op == "4")
                        {
                            auto start = chrono::steady_clock::now();
                            int index = ui.UpadteRecord();
                            BinarySearchTree.deleteInBST(BinarySearchTree.root, index);
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // TRAVERSE THE TREE
                        else if (op == "5")
                        {
                            while (true)
                            {
                                opt = ui.TraversalMenu();
                                // BREATHFRIST TRAVERSAL
                                if (opt == "1")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.BreathFirstTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // INORDER TRAVERSAL
                                else if (opt == "2")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.InOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // POSTORDER TRAVERSAL
                                else if (opt == "3")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.PostOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // PREORDER TRAVERSAL
                                else if (opt == "4")
                                {
                                    auto start = chrono::steady_clock::now();
                                    BinarySearchTree.PreOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                else if (opt == "5")
                                {
                                    ui.clearscreen();
                                    break;
                                }
                                else
                                {
                                    ui.clearscreen();
                                }
                            }
                        }
                        else if (op == "6")
                        {
                            ui.clearscreen();
                            BinarySearchTree.ClearTree();
                            break;
                        }
                        else
                        {
                            ui.clearscreen();
                        }
                    }
                }
                else if (option1 == "5")
                {
                    ui.clearscreen();
                    break;
                }
                else
                {
                    ui.clearscreen();
                }
            }
        }

        //________________________________ AVL TREE________________________________//
        else if (option == "2")
        {
            while (true)
            {
                option1 = ui.LoadTree();
                if (option1 == "1")
                {
                    path = "customers-100.csv";
                    auto start = chrono::steady_clock::now();
                    AVLtree.ReadFromFile(path);
                    auto end = chrono::steady_clock::now();
                    auto diff = end - start;
                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                    ui.clearscreen();
                    while (true)
                    {
                        op = ui.SubMenu();
                        // INSERT A RECORD
                        if (op == "1")
                        {
                            auto start = chrono::steady_clock::now();
                            TreeNode *temp = ui.option1();
                            TreeNode *temp1 = AVLtree.SearchFromTree(temp->Index);
                            if (temp1 != NULL)
                            {
                                cout << "Index Already Exists" << endl;
                            }
                            else
                            {
                                AVLtree.insertionWithRotation(temp);
                                auto end = chrono::steady_clock::now();
                                auto diff = end - start;
                                cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            }
                            ui.clearscreen();
                        }
                        // RETRIEVE A RECORD
                        else if (op == "2")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.PrintTree(AVLtree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // UPDATE RECORD
                        else if (op == "3")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.Update(AVLtree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // DELETE RECORD
                        else if (op == "4")
                        {
                            auto start = chrono::steady_clock::now();
                            int index = ui.UpadteRecord();
                            BinarySearchTree.deleteInBST(BinarySearchTree.root, index);
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // TRAVERSE THE TREE
                        else if (op == "5")
                        {
                            while (true)
                            {
                                opt = ui.TraversalMenu();
                                // BREATHFRIST TRAVERSAL
                                if (opt == "1")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.BreathFirstTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // INORDER TRAVERSAL
                                else if (opt == "2")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.InOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // POSTORDER TRAVERSAL
                                else if (opt == "3")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.PostOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // PREORDER TRAVERSAL
                                else if (opt == "4")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.PreOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                else if (opt == "5")
                                {
                                    ui.clearscreen();
                                    break;
                                }
                                else
                                {
                                    ui.clearscreen();
                                }
                            }
                        }
                        else if (op == "6")
                        {
                            ui.clearscreen();
                            AVLtree.ClearTree();
                            break;
                        }
                        else
                        {
                            ui.clearscreen();
                        }
                    }
                }
                else if (option1 == "2")
                {
                    path = "customers-1000.csv";
                    auto start = chrono::steady_clock::now();
                    AVLtree.ReadFromFile(path);
                    auto end = chrono::steady_clock::now();
                    auto diff = end - start;
                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                    ui.clearscreen();
                    while (true)
                    {
                        op = ui.SubMenu();
                        // INSERT A RECORD
                        if (op == "1")
                        {
                            auto start = chrono::steady_clock::now();
                            TreeNode *temp = ui.option1();
                            TreeNode *temp1 = AVLtree.SearchFromTree(temp->Index);
                            if (temp1 != NULL)
                            {
                                cout << "Index Already Exists" << endl;
                            }
                            else
                            {
                                AVLtree.insertionWithRotation(temp);
                                auto end = chrono::steady_clock::now();
                                auto diff = end - start;
                                cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            }
                            ui.clearscreen();
                        }
                        // RETRIEVE A RECORD
                        else if (op == "2")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.PrintTree(AVLtree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // UPDATE RECORD
                        else if (op == "3")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.Update(AVLtree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // DELETE RECORD
                        else if (op == "4")
                        {
                            auto start = chrono::steady_clock::now();
                            int index = ui.UpadteRecord();
                            BinarySearchTree.deleteInBST(BinarySearchTree.root, index);
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // TRAVERSE THE TREE
                        else if (op == "5")
                        {
                            while (true)
                            {
                                opt = ui.TraversalMenu();
                                // BREATHFRIST TRAVERSAL
                                if (opt == "1")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.BreathFirstTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // INORDER TRAVERSAL
                                else if (opt == "2")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.InOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // POSTORDER TRAVERSAL
                                else if (opt == "3")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.PostOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // PREORDER TRAVERSAL
                                else if (opt == "4")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.PreOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                else if (opt == "5")
                                {
                                    ui.clearscreen();
                                    break;
                                }
                                else
                                {
                                    ui.clearscreen();
                                }
                            }
                        }
                        else if (op == "6")
                        {
                            ui.clearscreen();
                            AVLtree.ClearTree();
                            break;
                        }
                        else
                        {
                            ui.clearscreen();
                        }
                    }
                }
                else if (option1 == "3")
                {
                    path = "customers-10000.csv";
                    auto start = chrono::steady_clock::now();
                    AVLtree.ReadFromFile(path);
                    auto end = chrono::steady_clock::now();
                    auto diff = end - start;
                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                    ui.clearscreen();
                    while (true)
                    {
                        op = ui.SubMenu();
                        // INSERT A RECORD
                        if (op == "1")
                        {
                            auto start = chrono::steady_clock::now();
                            TreeNode *temp = ui.option1();
                            TreeNode *temp1 = AVLtree.SearchFromTree(temp->Index);
                            if (temp1 != NULL)
                            {
                                cout << "Index Already Exists" << endl;
                            }
                            else
                            {
                                AVLtree.insertionWithRotation(temp);
                                auto end = chrono::steady_clock::now();
                                auto diff = end - start;
                                cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            }
                            ui.clearscreen();
                        }
                        // RETRIEVE A RECORD
                        else if (op == "2")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.PrintTree(AVLtree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // UPDATE RECORD
                        else if (op == "3")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.Update(AVLtree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // DELETE RECORD
                        else if (op == "4")
                        {
                            auto start = chrono::steady_clock::now();
                            int index = ui.UpadteRecord();
                            BinarySearchTree.deleteInBST(BinarySearchTree.root, index);
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // TRAVERSE THE TREE
                        else if (op == "5")
                        {
                            while (true)
                            {
                                opt = ui.TraversalMenu();
                                // BREATHFRIST TRAVERSAL
                                if (opt == "1")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.BreathFirstTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // INORDER TRAVERSAL
                                else if (opt == "2")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.InOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // POSTORDER TRAVERSAL
                                else if (opt == "3")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.PostOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // PREORDER TRAVERSAL
                                else if (opt == "4")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.PreOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                else if (opt == "5")
                                {
                                    ui.clearscreen();
                                    break;
                                }
                                else
                                {
                                    ui.clearscreen();
                                }
                            }
                        }
                        else if (op == "6")
                        {
                            ui.clearscreen();
                            AVLtree.ClearTree();
                            break;
                        }
                        else
                        {
                            ui.clearscreen();
                        }
                    }
                }
                else if (option1 == "4")
                {
                    path = "customers-100000.csv";
                    auto start = chrono::steady_clock::now();
                    AVLtree.ReadFromFile(path);
                    auto end = chrono::steady_clock::now();
                    auto diff = end - start;
                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                    ui.clearscreen();
                    while (true)
                    {
                        op = ui.SubMenu();
                        // INSERT A RECORD
                        if (op == "1")
                        {
                            auto start = chrono::steady_clock::now();
                            TreeNode *temp = ui.option1();
                            TreeNode *temp1 = AVLtree.SearchFromTree(temp->Index);
                            if (temp1 != NULL)
                            {
                                cout << "Index Already Exists" << endl;
                            }
                            else
                            {
                                AVLtree.insertionWithRotation(temp);
                                auto end = chrono::steady_clock::now();
                                auto diff = end - start;
                                cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            }
                            ui.clearscreen();
                        }
                        // RETRIEVE A RECORD
                        else if (op == "2")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.PrintTree(AVLtree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // UPDATE RECORD
                        else if (op == "3")
                        {
                            auto start = chrono::steady_clock::now();
                            ui.Update(AVLtree.SearchFromTree(ui.UpadteRecord()));
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // DELETE RECORD
                        else if (op == "4")
                        {
                            auto start = chrono::steady_clock::now();
                            int index = ui.UpadteRecord();
                            BinarySearchTree.deleteInBST(BinarySearchTree.root, index);
                            auto end = chrono::steady_clock::now();
                            auto diff = end - start;
                            cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                            ui.clearscreen();
                        }
                        // TRAVERSE THE TREE
                        else if (op == "5")
                        {
                            while (true)
                            {
                                opt = ui.TraversalMenu();
                                // BREATHFRIST TRAVERSAL
                                if (opt == "1")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.BreathFirstTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // INORDER TRAVERSAL
                                else if (opt == "2")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.InOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // POSTORDER TRAVERSAL
                                else if (opt == "3")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.PostOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                // PREORDER TRAVERSAL
                                else if (opt == "4")
                                {
                                    auto start = chrono::steady_clock::now();
                                    AVLtree.PreOrderTraversal();
                                    auto end = chrono::steady_clock::now();
                                    auto diff = end - start;
                                    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
                                    ui.clearscreen();
                                }
                                else if (opt == "5")
                                {
                                    ui.clearscreen();
                                    break;
                                }
                                else
                                {
                                    ui.clearscreen();
                                }
                            }
                        }
                        else if (op == "6")
                        {
                            ui.clearscreen();
                            AVLtree.ClearTree();
                            break;
                        }
                        else
                        {
                            ui.clearscreen();
                        }
                    }
                }
                else if (option1 == "5")
                {
                    ui.clearscreen();
                    break;
                }
                else
                {
                    ui.clearscreen();
                }
            }
        }
        else if (option == "3")
        {
            ui.clearscreen();
            break;
        }
        else
        {
            ui.clearscreen();
        }
    }
}