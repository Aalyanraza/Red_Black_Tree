#pragma once
#include <iostream>
using namespace std;



class Assignee
{
public:
    string FirstName, Last_Name, address, DOB, id;
    Assignee(string f = "", string l = "", string a = "", string b = "", int count=1) : FirstName(f), Last_Name(l), address(a), DOB(b)
    {
        if (count < 10)
            id = "A00" + to_string(count);
        else if (count < 100)
            id = "A0" + to_string(count);
        else
            id = "A" + to_string(count);
        
    }
};

class Task
{
public:
    int TaskID;
    int PriorityLevel;
    bool completed;
    string Description;
    string AssigneeID;

    Task(int t = 0, string d = "", int p = 0, string a = "") : TaskID(t), Description(d), PriorityLevel(p), AssigneeID(a), completed(0) { }
};

template <typename T>
struct Node
{
    T data;
    string color;
    Node* parent;
    Node* left;
    Node* right;

    Node(T val, string c = "red", Node* p = NULL, Node* l = NULL, Node* r = NULL) : data(val), color(c), parent(p), left(l), right(r) {}
};

class taskManagementSystem
{
public:
    int assigneeid;

    Node<Assignee>* root1;
    Node<Task>* root2;

    bool ll;
    bool rr;
    bool lr;
    bool rl;

    taskManagementSystem()
    {
        assigneeid = 1;
        root1 = NULL;
        root2 = NULL;
        ll = lr = rr = rl = 0;
    }
   
    // Addition
        // Assignee
    void leftRotate(Node<Assignee>* x) 
    {
        Node<Assignee>* y = x->right;
        x->right = y->left;
        if (y->left) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root1 = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }
    void rightRotate(Node<Assignee>* x) 
    {
        Node<Assignee>* y = x->left;
        x->left = y->right;
        if (y->right) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) 
        {
            root1 = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }
    void insertFix(Node<Assignee>* k) {
        Node<Assignee>* u;
        while (k->parent->color == "red") {
            
            if (k->parent == k->parent->parent->right) {

                
                u = k->parent->parent->left;

                if (u) {
                    if (u->color == "red") {
                        u->color = "black";
                        k->parent->color = "black";
                        k->parent->parent->color = "red";
                        k = k->parent->parent;
                    }
                    else {
                        if (k == k->parent->left) {
                            k = k->parent;
                            rightRotate(k);
                        }
                        k->parent->color = "black";
                        k->parent->parent->color = "red";
                        leftRotate(k->parent->parent);
                    }
                }
                else {

                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = "black";
                    k->parent->parent->color = "red";
                    leftRotate(k->parent->parent);


                }
            }
            else {
                u = k->parent->parent->right;

                if (u) {
                    if (u->color == "red") {
                        u->color = "black";
                        k->parent->color = "black";
                        k->parent->parent->color = "red";
                        k = k->parent->parent;
                    }
                    else {
                        if (k == k->parent->right) {
                            k = k->parent;
                            leftRotate(k);
                        }
                        k->parent->color = "black";
                        k->parent->parent->color = "red";
                        rightRotate(k->parent->parent);
                    }
                }
                else {


                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = "black";
                    k->parent->parent->color = "red";
                    rightRotate(k->parent->parent);


                }
            }
            if (k == root1) {
                break;
            }
        }
        root1->color = "black";
    }
    void insert(Assignee key) 
    {
        Node<Assignee>* node = new Node<Assignee>(key);

        Node<Assignee>* y = nullptr;
        Node<Assignee>* x = root1;

        while (x) 
        {
            y = x;
            if (node->data.id < x->data.id) 
            {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr) 
        {
            root1 = node;
        }
        else if (node->data.id < y->data.id) 
        {
            y->left = node;
        }
        else {
            y->right = node;
        }

        if (node->parent == nullptr) 
        {
            node->color = "black";
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        insertFix(node);
    }
    void addAssignee(string f, string l, string a, string b)
    {
        Assignee temp(f, l, a, b, assigneeid++);
        insert(temp);

    }

        // Task
    void leftRotate(Node<Task>* x)
    {
        Node<Task>* y = x->right;
        x->right = y->left;
        if (y->left) 
        {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root2 = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }
    void rightRotate(Node<Task>* x)
    {
        Node<Task>* y = x->left;
        x->left = y->right;
        if (y->right) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr)
        {
            root2 = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }
    void insertFix(Node<Task>* k) 
    {
        Node<Task>* u;
        while (k->parent->color == "red") {

            if (k->parent == k->parent->parent->right) {


                u = k->parent->parent->left;

                if (u) {
                    if (u->color == "red") {
                        u->color = "black";
                        k->parent->color = "black";
                        k->parent->parent->color = "red";
                        k = k->parent->parent;
                    }
                    else {
                        if (k == k->parent->left) {
                            k = k->parent;
                            rightRotate(k);
                        }
                        k->parent->color = "black";
                        k->parent->parent->color = "red";
                        leftRotate(k->parent->parent);
                    }
                }
                else {

                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = "black";
                    k->parent->parent->color = "red";
                    leftRotate(k->parent->parent);


                }
            }
            else {
                u = k->parent->parent->right;

                if (u) {
                    if (u->color == "red") {
                        u->color = "black";
                        k->parent->color = "black";
                        k->parent->parent->color = "red";
                        k = k->parent->parent;
                    }
                    else {
                        if (k == k->parent->right) {
                            k = k->parent;
                            leftRotate(k);
                        }
                        k->parent->color = "black";
                        k->parent->parent->color = "red";
                        rightRotate(k->parent->parent);
                    }
                }
                else {


                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = "black";
                    k->parent->parent->color = "red";
                    rightRotate(k->parent->parent);


                }
            }
            if (k == root2) {
                break;
            }
        }
        root2->color = "black";
    }
    void insert(Task key)
    {
        Node<Task>* node = new Node<Task>(key);

        Node<Task>* y = nullptr;
        Node<Task>* x = root2;

        while (x)
        {
            y = x;
            if (node->data.PriorityLevel < x->data.PriorityLevel)
            {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr)
        {
            root2 = node;
        }
        else if (node->data.PriorityLevel< y->data.PriorityLevel)
        {
            y->left = node;
        }
        else {
            y->right = node;
        }

        if (node->parent == nullptr)
        {
            node->color = "black";
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        insertFix(node);
    }
    void addTask(int t = 0, string d = "", int p = 0, string a = "")
    {
        Task temp(t, d, p, a);
        insert(temp);
    }

    // Deletion
        // Assignee
    Node<Assignee>* maximum(Node<Assignee>* node) {
        while (node->right && node->right->data.address != "-1") {
            node = node->right;
        }
        return node;
    }
    void transplant(Node<Assignee>*& root, Node<Assignee>* u, Node<Assignee>* v) {
        if (u->parent == nullptr) {
            root = v;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
        }
        else {
            u->parent->right = v;
        }
        if (v != nullptr) {
            v->parent = u->parent;
        }
    }
    Node<Assignee>* searchAssigneeNode(Node<Assignee>* root, const string& key) {
        while (root != nullptr && key != root->data.id) {
            if (key < root->data.id) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return root;
    }
    void deletingnullnode(Node<Assignee>* T) {
        if (T) {
            deletingnullnode(T->left);
            deletingnullnode(T->right);

            // Check and delete left child
            if (T->left && T->left->data.address == "-1") {
                delete T->left;
                T->left = nullptr;
            }

            // Check and delete right child
            if (T->right && T->right->data.address == "-1") {
                delete T->right;
                T->right = nullptr;
            }
        }
    }
    void addingnullnodes(Node<Assignee>* T) {
        if (T) {
            addingnullnodes(T->left);
            addingnullnodes(T->right);
            if (T->left == nullptr) 
            {
                Assignee t1("-1", "-1", "-1", "-1");
                T->left = new Node<Assignee>(t1);
                T->left->color = "black";
                T->left->parent = T;
            }
            if (T->right == nullptr) 
            {
                Assignee t1("-1", "-1", "-1", "-1");
                T->right = new Node<Assignee>(t1);
                T->right->color = "black";
                T->right->parent = T;
            }
        }
    }

    void DeleteAssignee(const string& key) {
        if (TaskExistsForAssignee(root2, key)) 
        {
            return;
        }

        DeleteAssigneeHelper(root1, key);
    }
    void DeleteAssigneeHelper(Node<Assignee>* root, const string& key) {
        Node<Assignee>* nodeToDelete = searchAssigneeNode(root, key);

        if (nodeToDelete == nullptr)
            return;

        Node<Assignee>* temp = nodeToDelete;
        Node<Assignee>* y = temp;
        string tempColor = y ? y->color : "black";

        addingnullnodes(root1);

        if (nodeToDelete->left == nullptr && nodeToDelete->parent->left== nodeToDelete)
        {
            temp = nodeToDelete->right;
            transplant(root1, nodeToDelete, nodeToDelete->right);
        }
        else if (nodeToDelete->right == nullptr && nodeToDelete->parent->right == nodeToDelete) {
            temp = nodeToDelete->left;
            transplant(root1, nodeToDelete, nodeToDelete->left);
        }
        else {
            y = maximum(nodeToDelete->left);
            tempColor = y ? y->color : "black";
            temp = y->left;

            if (y->parent != nodeToDelete)  {
                transplant(root1, y, y->left);
                y->left = nodeToDelete->left;
                if (y->left) {
                    y->left->parent = y;
                }
            }

            transplant(root1, nodeToDelete, y);
            y->right = nodeToDelete->right;
            if (y->right) {
                y->right->parent = y;
            }
            y->color = nodeToDelete->color;
           
        }


        if (tempColor == "black" && temp)
            DeleteAssigneeFix(temp);

        deletingnullnode(root1);
        delete nodeToDelete;
    }
    void DeleteAssigneeFix(Node<Assignee>* x)
    {
        while (x != root1 && x->color=="black")
        {   
            if (x == x->parent->left)
            {
                Node<Assignee>* sibling = x->parent->right;

                if (sibling != nullptr)
                {
                    if (sibling->color == "red")
                    {
                        sibling->color = "black";
                        x->parent->color = "red";
                        leftRotate(x->parent);
                        sibling = x->parent->right;
                    }

                    if ((sibling->left->color == "black" && sibling->right->color == "black"))
                    {
                        sibling->color = "red";
                        x = x->parent;
                    }
                    else
                    {
                        if (sibling->right->color == "black")
                        {
                            if (sibling->left != nullptr)
                                sibling->left->color = "black";
                            if (sibling != nullptr)
                                sibling->color = "red";
                            rightRotate(sibling);
                            sibling = x->parent->right;
                        }
                        if (sibling->right->color == "red")
                        {
                            sibling->color == x->parent->color;
                            x->parent->color = "black";
                            sibling->right->color = "black";
                            leftRotate(x->parent);
                            x = root1;
                        }
                    }
                }
            }
            else
            {
                Node<Assignee>* sibling = x->parent->left;

                if (sibling != nullptr)
                {
                    if (sibling->color == "red")
                    {
                        sibling->color = "black";
                        x->parent->color = "red";
                        rightRotate(x->parent);
                        sibling = x->parent->left;
                    }

                    if ((sibling->right->color == "black" && sibling->left->color == "black"))
                    {
                        sibling->color = "red";
                        x = x->parent;
                    }
                    else
                    {
                        if (sibling->left->color == "black")
                        {
                            if (sibling->right != nullptr)
                                sibling->right->color = "black";
                            if (sibling != nullptr)
                                sibling->color = "red";

                            leftRotate(sibling);
                            sibling = x->parent->left;
                        }
                        if (sibling->left->color == "red")
                        {
                            sibling->color = x->parent->color;
                            x->parent->color = "black";
                            sibling->left->color = "black";
                            rightRotate(x->parent);
                            x = root1;
                        }
                    }
                }
            }
        }
        if (x != nullptr) {
            x->color = "black";
        }
    }

        // Task
    Node<Task>* maximum(Node<Task>* node) {
        while (node->right && node->right->data.Description != "-1") {
            node = node->right;
        }
        return node;
    }
    void transplant(Node<Task>*& root, Node<Task>* u, Node<Task>* v) {
        if (u->parent == nullptr) {
            root = v;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
        }
        else {
            u->parent->right = v;
        }
        if (v != nullptr) {
            v->parent = u->parent;
        }
    }
    Node<Task>* searchTaskNode(Node<Task>* root, const int key) 
    {
        while (root != nullptr && key != root->data.TaskID) {
            if (key > root->data.TaskID) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return root;
    }
    void deletingnullnode(Node<Task>* T) {
        if (T) {
            deletingnullnode(T->left);
            deletingnullnode(T->right);

            // Check and delete left child
            if (T->left && T->left->data.Description == "-1") {
                delete T->left;
                T->left = nullptr;
            }

            // Check and delete right child
            if (T->right && T->right->data.Description == "-1") {
                delete T->right;
                T->right = nullptr;
            }
        }
    }
    void addingnullnodes(Node<Task>* T) {
        if (T) {
            addingnullnodes(T->left);
            addingnullnodes(T->right);
            if (T->left == nullptr)
            {
                Task t1(-1, "-1", -1, "-1");
                T->left = new Node<Task>(t1);
                T->left->color = "black";
                T->left->parent = T;
            }
            if (T->right == nullptr)
            {
                Task t1(-1, "-1", -1, "-1");
                T->right = new Node<Task>(t1);
                T->right->color = "black";
                T->right->parent = T;
            }
        }
    }

    void deleteTask(const int key) 
    {

        deleteTaskHelper(root2, key);
    }
    void deleteTaskHelper(Node<Task>* root, const int key) {
        Node<Task>* nodeToDelete = searchTaskNode(root, key);

        if (nodeToDelete == nullptr)
            return;

        Node<Task>* temp = nodeToDelete;
        Node<Task>* y = temp;
        string tempColor = y ? y->color : "black";

        addingnullnodes(root1);

        if (nodeToDelete->left == nullptr && nodeToDelete->parent->left == nodeToDelete)
        {
            temp = nodeToDelete->right;
            transplant(root2, nodeToDelete, nodeToDelete->right);
        }
        else if (nodeToDelete->right == nullptr && nodeToDelete->parent->right == nodeToDelete) {
            temp = nodeToDelete->left;
            transplant(root2, nodeToDelete, nodeToDelete->left);
        }
        else {
            y = maximum(nodeToDelete->left);
            tempColor = y ? y->color : "black";
            temp = y->left;

            if (y->parent != nodeToDelete) {
                transplant(root2, y, y->left);
                y->left = nodeToDelete->left;
                if (y->left) {
                    y->left->parent = y;
                }
            }

            transplant(root2, nodeToDelete, y);
            y->right = nodeToDelete->right;
            if (y->right) {
                y->right->parent = y;
            }
            y->color = nodeToDelete->color;

        }


        if (tempColor == "black" && temp)
            deleteTaskFix(temp);

        deletingnullnode(root1);
        delete nodeToDelete;
    }
    void deleteTaskFix(Node<Task>* x)
    {
        while (x != root2 && x->color == "black")
        {
            if (x == x->parent->left)
            {
                Node<Task>* sibling = x->parent->right;

                if (sibling != nullptr)
                {
                    if (sibling->color == "red")
                    {
                        sibling->color = "black";
                        x->parent->color = "red";
                        leftRotate(x->parent);
                        sibling = x->parent->right;
                    }

                    if ((sibling->left->color == "black" && sibling->right->color == "black"))
                    {
                        sibling->color = "red";
                        x = x->parent;
                    }
                    else
                    {
                        if (sibling->right->color == "black")
                        {
                            if (sibling->left != nullptr)
                                sibling->left->color = "black";
                            if (sibling != nullptr)
                                sibling->color = "red";
                            rightRotate(sibling);
                            sibling = x->parent->right;
                        }
                        if (sibling->right->color == "red")
                        {
                            sibling->color == x->parent->color;
                            x->parent->color = "black";
                            sibling->right->color = "black";
                            leftRotate(x->parent);
                            x = root2;
                        }
                    }
                }
            }
            else
            {
                Node<Task>* sibling = x->parent->left;

                if (sibling != nullptr)
                {
                    if (sibling->color == "red")
                    {
                        sibling->color = "black";
                        x->parent->color = "red";
                        rightRotate(x->parent);
                        sibling = x->parent->left;
                    }

                    if ((sibling->right->color == "black" && sibling->left->color == "black"))
                    {
                        sibling->color = "red";
                        x = x->parent;
                    }
                    else
                    {
                        if (sibling->left->color == "black")
                        {
                            if (sibling->right != nullptr)
                                sibling->right->color = "black";
                            if (sibling != nullptr)
                                sibling->color = "red";

                            leftRotate(sibling);
                            sibling = x->parent->left;
                        }
                        if (sibling->left->color == "red")
                        {
                            sibling->color = x->parent->color;
                            x->parent->color = "black";
                            sibling->left->color = "black";
                            rightRotate(x->parent);
                            x = root2;
                        }
                    }
                }
            }
        }
        if (x != nullptr) {
            x->color = "black";
        }
    }

    // Task Exists
    bool TaskExistsForAssignee(Node<Task>* taskNode, const string& assigneeID)
    {
        if (taskNode == nullptr)
            return false;
       
        if (TaskExistsForAssignee(taskNode->left, assigneeID))
            return true;

        if (taskNode->data.AssigneeID == assigneeID)
            return true;

        return TaskExistsForAssignee(taskNode->right, assigneeID);
    }
    void AssigneeWithNoTask(ostream& outputStream)
    {
        AssigneeWithNoTaskHelper(root1, root2, outputStream);
    }
    bool AssigneeWithNoTaskHelper(Node<Assignee>* assigneeNode, Node<Task>* taskNode, ostream& outputStream)
    {
        if (assigneeNode)
        {
            AssigneeWithNoTaskHelper(assigneeNode->left, taskNode, outputStream);

            if (!TaskExistsForAssignee(taskNode, assigneeNode->data.id))
                outputStream << "Name: " << assigneeNode->data.FirstName << " " << assigneeNode->data.Last_Name << ", Address: " << assigneeNode->data.address << ", DOB: " << assigneeNode->data.DOB << ", Assignee ID: " << assigneeNode->data.id << "\n";

            AssigneeWithNoTaskHelper(assigneeNode->right, taskNode, outputStream);
        }
        return true;
    }

    // Shift Task
    void ShiftTask(const string name1, const string name2)
    {
        ShiftTaskHelper(name1, name2, root2);
    }
    void ShiftTaskHelper(const string name1, const string name2, Node<Task>* root)
    {
        if (root)
        {
            ShiftTaskHelper(name1, name2, root->left);

            if (root->data.AssigneeID == name1)
                root->data.AssigneeID = name2;

            ShiftTaskHelper(name1, name2, root->right);
        }

    }
       
    // Displays
    void displaybyID(ostream& outputStream, const string& assigneeID)
    {
        displaybyIDHelper(outputStream, assigneeID, root1);
    }
    void displaybyIDHelper(ostream& outputStream, const string& assigneeID, Node<Assignee>* ptr)
    {
        if (ptr == nullptr) {
            return;
        }

        displaybyIDHelper(outputStream, assigneeID, ptr->left);

        // Display the data if the Assignee ID matches
        if (ptr->data.id == assigneeID) {
            outputStream << "Name: " << ptr->data.FirstName << " " << ptr->data.Last_Name << ", Address: " << ptr->data.address << ", DOB: " << ptr->data.DOB << ", Assignee ID: " << ptr->data.id << "\n";
        }

        // Traverse the right subtree
        displaybyIDHelper(outputStream, assigneeID, ptr->right);
    }

    void displaybyname(ostream& outputStream, const string& name1, const string& name2)
    {
        displaybynameHelper(outputStream, name1,  name2, root1);
    }
    void displaybynameHelper(ostream& outputStream, const string& name1, const string& name2, Node<Assignee>* ptr)
    {
        if (ptr == nullptr) {
            return;
        }

        displaybynameHelper(outputStream, name1, name2, ptr->left);

        if (ptr->data.FirstName == name1 && ptr->data.Last_Name == name2) {
            outputStream << "Name: " << ptr->data.FirstName << " " << ptr->data.Last_Name << ", Address: " << ptr->data.address << ", DOB: " << ptr->data.DOB << ", Assignee ID: " << ptr->data.id << "\n";
        }

        displaybynameHelper(outputStream, name1, name2, ptr->right);
    }

    void printTaskQueue(ostream& outputStream)
    {
        printTaskQueueHelper(outputStream, root2, root1);
    }
    void printTaskQueueHelper(ostream& outputStream, Node<Task>* taskNode, Node<Assignee>* assigneeRoot)
    {
        if (taskNode)
        {
            printTaskQueueHelper(outputStream, taskNode->left, assigneeRoot);

            if (!taskNode->data.completed) 
            {
                string assigneeName = findAssigneeName(taskNode->data.AssigneeID, assigneeRoot);
                outputStream << "Task ID: " << taskNode->data.TaskID << ", Description: " << taskNode->data.Description << ", Priority: " << taskNode->data.PriorityLevel << ", Assignee: " << assigneeName << " (" << taskNode->data.AssigneeID << ")\n";
            }
            printTaskQueueHelper(outputStream, taskNode->right, assigneeRoot);
        }
    }
    
    void displayCompletedTasks(ostream& outputStream)
    {
        outputStream << "Completed Tasks:\n";
        displayCompletedTasksHelper(outputStream, root2, root1);
    }
    void displayCompletedTasksHelper(ostream& outputStream, Node<Task>* taskNode, Node<Assignee>* assigneeRoot)
    {
        if (taskNode)
        {
            displayCompletedTasksHelper(outputStream, taskNode->left, assigneeRoot);

            if (taskNode->data.completed)
            {
                string assigneeName = findAssigneeName(taskNode->data.AssigneeID, assigneeRoot);
                outputStream << "Task ID: " << taskNode->data.TaskID << ", Description: " << taskNode->data.Description << ", Priority: " << taskNode->data.PriorityLevel << ", Assignee: " << assigneeName << " (" << taskNode->data.AssigneeID << ")\n";
            }
            displayCompletedTasksHelper(outputStream, taskNode->right, assigneeRoot);
        }
    }

    void PrintTreeInorder(ostream& outputStream)
    {
        PrintTreeInorderHelper(root2, outputStream);
    }
    void PrintTreeInorderHelper(Node<Task>* node, ostream& outputStream)
    {
        if (node == nullptr)
            return;

        PrintTreeInorderHelper(node->left, outputStream);

        outputStream << node->data.TaskID << " (" << node->color << ")\n";

        PrintTreeInorderHelper(node->right, outputStream);
    }

    void DisplayAssignee(ostream& outputStream) const {
        InorderTraversal(root1, outputStream);
    }
    void InorderTraversal(Node<Assignee>* node, ostream& outputStream) const {
        if (node) {
            InorderTraversal(node->left, outputStream);
            outputStream << "Name: " << node->data.FirstName << " " << node->data.Last_Name
                << ", Address: " << node->data.address << ", DOB: " << node->data.DOB
                << ", Assignee ID: " << node->data.id << "\n";
            InorderTraversal(node->right, outputStream);
        }
    }

    void inOrderAssignees(Node<Assignee>* node, std::stringstream& output) 
    {
        if (node == nullptr) 
            return;

        inOrderAssignees(node->left, output);
        output << node->data.id << " (" << node->color << ")\n";
        inOrderAssignees(node->right, output);
    }

    void taskManagementSystem::AssigneeInOrder(std::stringstream& output) 
    {
        inOrderAssignees(root1, output);
    }

    // Complete Task And update priority
    void completeTask(int taskID)
    {
        completeTaskHelper(root2, taskID);
    }
    void completeTaskHelper(Node<Task>* taskNode, int taskID)
    {
        if (taskNode)
        {
            completeTaskHelper(taskNode->left, taskID);

            if (taskNode->data.TaskID == taskID)
                taskNode->data.completed = true;

            completeTaskHelper(taskNode->right, taskID);
        }
    }
   
    void updateTaskPriority(int taskID, int newpriority)
    {
        Node<Task> temp = *searchTaskNode(root2, taskID);
        
            // Delete the old task
            deleteTask(taskID);
            string des;
            des = temp.data.Description;
            string des1;
            des1= temp.data.AssigneeID;
            // Add a new task with updated priority
            addTask(taskID, des, newpriority, des1);
        
    }



    // Find Task By AssigneeID
    
    void findTasksByAssignee(string name1, ostream& outputStream)
    {
        string assigneeName = findAssigneeName(name1, root1);
        outputStream << "Tasks Assigned to \"" << assigneeName << " (" << name1 << ")\":\n";
        findTasksByAssigneeHelper(name1, outputStream, root2);
    }
    void findTasksByAssigneeHelper(string name1, ostream& outputStream, Node<Task>* taskNode)
    {
        if (taskNode)
        {
            findTasksByAssigneeHelper(name1, outputStream ,taskNode->left);

            if (taskNode->data.AssigneeID == name1)
            {
                string assigneeName = findAssigneeName(name1, root1);
                outputStream<< "Task ID: " << taskNode->data.TaskID << ", Description: " << taskNode->data.Description << ", Priority: " << taskNode->data.PriorityLevel << ", Assignee: " << assigneeName << " (" << taskNode->data.AssigneeID << ")\n";
            }

            findTasksByAssigneeHelper(name1, outputStream, taskNode->right);
        }
    }
    
    // Count Tasks
    void countTotalTasks(ostream& outputStream)
    {
        outputStream << "Total Tasks in the System: " << countTotalTasksHelper(root2) << "\n";
    }
    int countTotalTasksHelper(const Node<Task>* node) const 
    {
        if (node == nullptr) {
            return 0;
        }

        return 1 + countTotalTasksHelper(node->left) + countTotalTasksHelper(node->right);
    }
    
    // Priority Range
    void searchTasksByPriorityRange(int minPriority, int maxPriority, ostream& outputStream) const 
    {
        outputStream << "Tasks within Priority Range ("<<minPriority<<" to "<<maxPriority<<"):\n";
        searchTasksByPriorityRangeHelper(root2, minPriority, maxPriority, outputStream);
    }
    void searchTasksByPriorityRangeHelper(const Node<Task>* node, int minPriority, int maxPriority, std::ostream& outputStream) const {
        if (node) 
        {
            searchTasksByPriorityRangeHelper(node->left, minPriority, maxPriority, outputStream);

            if (node->data.PriorityLevel >= minPriority && node->data.PriorityLevel <= maxPriority)
            {
                string assigneeName = findAssigneeName(node->data.AssigneeID, root1);
                outputStream << "Task ID: " << node->data.TaskID << ", Description: " << node->data.Description << ", Priority: " << node->data.PriorityLevel << ", Assignee: " << assigneeName << " (" << node->data.AssigneeID << ")\n";
            }

            searchTasksByPriorityRangeHelper(node->right, minPriority, maxPriority, outputStream);
        }
    }

    // Highest Priority
   
    void findHighestPriorityTask(ostream& outputStream)
    {
        Node<Task>* highestPriorityTask = root2;
        while (highestPriorityTask->left)
            highestPriorityTask = highestPriorityTask->left;

        if (highestPriorityTask)
        {
            string assigneeName = findAssigneeName(highestPriorityTask->data.AssigneeID, root1);

            outputStream << "Highest Priority Task: Task ID - " << highestPriorityTask->data.TaskID << ", Description - " << highestPriorityTask->data.Description << ", Priority - " << highestPriorityTask->data.PriorityLevel << ", Assignee - " << assigneeName << " (" << highestPriorityTask->data.AssigneeID << ")\n";
        }
    }

    // Find Assignee Name based on Assignee ID 
    string findAssigneeName(const string& assigneeID, Node<Assignee>* assigneeRoot) const
    {
        if (!assigneeRoot)
            return "";

        if (assigneeID == assigneeRoot->data.id)
            return assigneeRoot->data.FirstName;

        if (assigneeID < assigneeRoot->data.id)
            return findAssigneeName(assigneeID, assigneeRoot->left);
        else
            return findAssigneeName(assigneeID, assigneeRoot->right);
    }
};
    