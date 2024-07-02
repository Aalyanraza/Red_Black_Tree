
#include "pch.h"
#include <gtest/gtest.h>
#include "Red_Black_Tree.h"

TEST(display, ID) {
    taskManagementSystem taskSystem;
    // auto assign unique IDs to each Assignee
    //First name, Last Name, Address, DOB
    taskSystem.addAssignee("Maham", "Khurram", "Dha phase 2", "25/11/2002");  //This should get A001
    taskSystem.addAssignee("Laraib", "Fatima", "Dha phase 2", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Nuzhat", "ul", "Askari 14", "1/1/2001");

    std::stringstream actualOutput;
    taskSystem.displaybyID(actualOutput, "A002");

    //The expected output
    std::string expectedOutput = "Name: Laraib Fatima, Address: Dha phase 2, DOB: 11/2/2002, Assignee ID: A002\n";

    // Compare the actual output with the expected output
    ASSERT_EQ(actualOutput.str(), expectedOutput);

}

TEST(display, name) {
    taskManagementSystem taskSystem;
    // auto assign unique IDs to each Assignee
    taskSystem.addAssignee("Muhammad", "Ali", "I8", "2/11/2001");  //This should get A001
    taskSystem.addAssignee("Muhammad", "Shah", "Dha phase 1", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Muhammad", "Ali", "Askari 14", "1/1/2003");

    std::stringstream actualOutput;
    taskSystem.displaybyname(actualOutput, "Muhammad", "Ali");

    //The expected output
    std::string expectedOutput =
        "Name: Muhammad Ali, Address: I8, DOB: 2/11/2001, Assignee ID: A001\n"
        "Name: Muhammad Ali, Address: Askari 14, DOB: 1/1/2003, Assignee ID: A003\n";

    // Compare the actual output with the expected output
    ASSERT_EQ(actualOutput.str(), expectedOutput);

}
TEST(display, notask) {
    taskManagementSystem taskSystem;
    // auto assign unique IDs to each Assignee
    taskSystem.addAssignee("Muhammad", "Ali", "I8", "2/11/2001");  //This should get A001
    taskSystem.addAssignee("Muhammad", "Shah", "Dha phase 1", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Muhammad", "Ali", "Askari 14", "1/1/2003");

    taskSystem.addTask(102, "Fix Bug in Module B", 2, "A002");
    taskSystem.addTask(103, "Write Unit Tests", 1, "A003");


    std::stringstream actualOutput;
    taskSystem.AssigneeWithNoTask(actualOutput);

    //The expected output
    std::string expectedOutput = "Name: Muhammad Ali, Address: I8, DOB: 2/11/2001, Assignee ID: A001\n";

    // Compare the actual output with the expected output
    ASSERT_EQ(actualOutput.str(), expectedOutput);

}
TEST(display, shiftTask) {
    taskManagementSystem taskSystem;
    // auto assign unique IDs to each Assignee
    taskSystem.addAssignee("Mehar", "Azam", "I6", "2/11/2003");  //This should get A001
    taskSystem.addAssignee("Muhammad", "Hashim", "Dha phase 5", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Hashir", "Ather", "Askari 4", "1/1/2003");

    taskSystem.addTask(102, "Fix Bug in Module B", 2, "A002");
    taskSystem.addTask(103, "Write Unit Tests", 1, "A003");

    taskSystem.ShiftTask("A002", "A003"); //tasks of A002 will be shifted to A003 and A002 will be left with no tasks for the time being.
    std::stringstream actualOutput1;
    taskSystem.AssigneeWithNoTask(actualOutput1);

    //The expected output
    std::string expectedOutput1 =
        "Name: Mehar Azam, Address: I6, DOB: 2/11/2003, Assignee ID: A001\n"
        "Name: Muhammad Hashim, Address: Dha phase 5, DOB: 11/2/2002, Assignee ID: A002\n";

    std::stringstream actualOutput2;
    taskSystem.printTaskQueue(actualOutput2); //output should be displayed in order of highest to lowest priority

    //The expected output
    std::string expectedOutput2 =
        "Task ID: 103, Description: Write Unit Tests, Priority: 1, Assignee: Hashir (A003)\n"
        "Task ID: 102, Description: Fix Bug in Module B, Priority: 2, Assignee: Hashir (A003)\n"
        ;

    // Compare the actual output with the expected output
    ASSERT_EQ(actualOutput1.str(), expectedOutput1);
    ASSERT_EQ(actualOutput2.str(), expectedOutput2);

}
 

TEST(display, delete1) {
    taskManagementSystem taskSystem;
    // auto assign unique IDs to each Assignee
    taskSystem.addAssignee("Muhammad", "Ali", "I8", "2/11/2001");  //This should get A001
    taskSystem.addAssignee("Muhammad", "Shah", "Dha phase 1", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Muhammad", "Ali", "Askari 14", "1/1/2003");

    taskSystem.addTask(102, "Fix Bug in Module B", 2, "A002");
    taskSystem.addTask(103, "Write Unit Tests", 1, "A003");

    taskSystem.DeleteAssignee("A001");
    std::stringstream actualOutput;
    taskSystem.DisplayAssignee(actualOutput); //Dispay in order of IDs

    //The expected output
    std::string expectedOutput =
        "Name: Muhammad Shah, Address: Dha phase 1, DOB: 11/2/2002, Assignee ID: A002\n"
        "Name: Muhammad Ali, Address: Askari 14, DOB: 1/1/2003, Assignee ID: A003\n";

    // Compare the actual output with the expected output
    ASSERT_EQ(actualOutput.str(), expectedOutput);

}
TEST(display, delete2) {
    taskManagementSystem taskSystem;
    // auto assign unique IDs to each Assignee
    taskSystem.addAssignee("Muhammad", "Ali", "I8", "2/11/2001");  //This should get A001
    taskSystem.addAssignee("Muhammad", "Shah", "Dha phase 1", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Muhammad", "Ali", "Askari 14", "1/1/2003");

    taskSystem.addTask(102, "Fix Bug in Module B", 2, "A002");
    taskSystem.addTask(103, "Write Unit Tests", 1, "A003");

    taskSystem.DeleteAssignee("A002");
    std::stringstream actualOutput;
    taskSystem.DisplayAssignee(actualOutput); //Dispay in order of IDs

    //The expected output
    std::string expectedOutput =
        "Name: Muhammad Ali, Address: I8, DOB: 2/11/2001, Assignee ID: A001\n"
        "Name: Muhammad Shah, Address: Dha phase 1, DOB: 11/2/2002, Assignee ID: A002\n"
        "Name: Muhammad Ali, Address: Askari 14, DOB: 1/1/2003, Assignee ID: A003\n"; //Assignee will not be deleted if they have assigned tasks

    // Compare the actual output with the expected output
    ASSERT_EQ(actualOutput.str(), expectedOutput);

}
TEST(display, delete3) 
{
    taskManagementSystem taskSystem;

    taskSystem.addAssignee("Muhammad", "Ali", "I8", "2/11/2001");  //This should get A001
    taskSystem.addAssignee("Muhammad", "Shah", "Dha phase 1", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Muhammad", "Ali", "Askari 14", "1/1/2003");


    taskSystem.DeleteAssignee("A003");

    taskSystem.addAssignee("Hussain", "Ali", "Lalazar", "20/1/2001");  //This should get A004
    std::stringstream actualOutput;
    taskSystem.DisplayAssignee(actualOutput); //Dispay in order of IDs

    //The expected output
    std::string expectedOutput =
        "Name: Muhammad Ali, Address: I8, DOB: 2/11/2001, Assignee ID: A001\n"
        "Name: Muhammad Shah, Address: Dha phase 1, DOB: 11/2/2002, Assignee ID: A002\n"
        "Name: Hussain Ali, Address: Lalazar, DOB: 20/1/2001, Assignee ID: A004\n";

    // Compare the actual output with the expected output
    ASSERT_EQ(actualOutput.str(), expectedOutput);

}


TEST(display, inorderAssignee) {
    taskManagementSystem taskSystem;
    // auto assign unique IDs to each Assignee
    taskSystem.addAssignee("Muhammad", "Ali", "I8", "2/11/2001");  //This should get A001
    taskSystem.addAssignee("Muhammad", "Shah", "Dha phase 1", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Muhammad", "Ali", "Askari 14", "1/1/2003");
    taskSystem.addAssignee("Zahra", "Rida", "I6", "2/10/2000");
    taskSystem.addAssignee("Mukhtar", "Shah", "Dha phase 7", "1/2/2001");
    taskSystem.addAssignee("Hammad", "Ali", "Askari 4", "1/10/2002");

    taskSystem.DeleteAssignee("A002");
    std::stringstream actualOutput;
    taskSystem.AssigneeInOrder(actualOutput); //Dispay in order of IDs

    //The expected output
    std::string expectedOutput =
        "A001 (black)\n"
        "A003 (red)\n"
        "A004 (black)\n"
        "A005 (black)\n"
        "A006 (red)\n";

    // Compare the actual output with the expected output
    ASSERT_EQ(actualOutput.str(), expectedOutput);

}


TEST(updating, first) {
    taskManagementSystem taskSystem;
    // auto assign unique IDs to each Assignee
    taskSystem.addAssignee("Muhammad", "Ali", "I8", "2/11/2001");  //This should get A001
    taskSystem.addAssignee("Muhammad", "Shah", "Dha phase 1", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Muhammad", "Ali", "Askari 14", "1/1/2003");

    taskSystem.addTask(101, "Implement Feature A", 3, "A001");
    taskSystem.addTask(102, "Fix Bug in Module B", 2, "A002");
    taskSystem.addTask(103, "Write Unit Tests", 1, "A003");

    // Capture the actual output
    std::stringstream actualOutput;
    taskSystem.printTaskQueue(actualOutput);

    //The expected output
    std::string expectedOutput =
        "Task ID: 103, Description: Write Unit Tests, Priority: 1, Assignee: Muhammad (A003)\nTask ID: 102, Description: Fix Bug in Module B, Priority: 2, Assignee: Muhammad (A002)\nTask ID: 101, Description: Implement Feature A, Priority: 3, Assignee: Muhammad (A001)\n";
    //output should be displayed in order of highest to lowest priority

    // Compare the actual output with the expected output
    ASSERT_EQ(actualOutput.str(), expectedOutput);
}

TEST(updating, second) {
    taskManagementSystem taskSystem;
    taskSystem.addAssignee("Aaimlik", "Abbasi", "I6", "2/11/2003");  //This should get A001
    taskSystem.addAssignee("Amna", "Hashim", "Dha phase 5", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Huma", "Ather", "Askari 4", "1/1/2003");

    taskSystem.addTask(101, "Implement Feature A", 3, "A001");
    taskSystem.addTask(102, "Fix Bug in Module B", 2, "A002");
    taskSystem.addTask(103, "Write Unit Tests", 1, "A003");

    taskSystem.completeTask(102);
    taskSystem.updateTaskPriority(101, 2);

    // Capture the actual output
    std::stringstream actualOutput;
    taskSystem.printTaskQueue(actualOutput);

    // Define the expected output
    std::string expectedOutput = "Task ID: 103, Description: Write Unit Tests, Priority: 1, Assignee: Huma (A003)\n"
        "Task ID: 101, Description: Implement Feature A, Priority: 2, Assignee: Aaimlik (A001)\n";

    // Compare the actual output with the expected output
    ASSERT_EQ(actualOutput.str(), expectedOutput);
}

TEST(highestpriority, first) {
    taskManagementSystem taskSystem;

    taskSystem.addAssignee("Aaimlik", "Abbasi", "I6", "2/11/2003");  //This should get A001
    taskSystem.addAssignee("Amna", "Hashim", "Dha phase 5", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Huma", "Ather", "Askari 4", "1/1/2003");

    taskSystem.addTask(101, "Implement Feature A", 3, "A001");
    taskSystem.addTask(102, "Fix Bug in Module B", 2, "A002");
    taskSystem.addTask(103, "Write Unit Tests", 1, "A003");

    // Capture the actual output
    std::stringstream actualOutput;
    taskSystem.findHighestPriorityTask(actualOutput);

    // Define the expected output
    std::string expectedOutput = "Highest Priority Task: Task ID: 103, Description: Write Unit Tests, Priority: 1, Assignee: Huma (A003)\n";

    cout << actualOutput.str();
    cout << expectedOutput;
}


TEST(findingtasks, wusqa) {
    taskManagementSystem taskSystem;

    // Add tasks
    taskSystem.addAssignee("Wusqa", "Khan", "I6", "2/11/2003");  //This should get A001
    taskSystem.addAssignee("Amna", "Hashim", "Dha phase 5", "11/2/2002"); // A002 and so on.

    taskSystem.addTask(101, "Implement Feature A", 3, "A001");
    taskSystem.addTask(102, "Fix Bug in Module B", 2, "A002");
    taskSystem.addTask(103, "Write Unit Tests", 1, "A001");
    // Capture the actual output
    std::stringstream actualOutput;
    taskSystem.findTasksByAssignee("A001", actualOutput);

    cout << actualOutput.str() << endl;
    // Define the expected output
    std::string expectedOutput = "Tasks Assigned to \"Wusqa (A001)\":\n"
        "Task ID: 103, Description: Write Unit Tests, Priority: 1, Assignee: Wusqa (A001)\n"
        "Task ID: 101, Description: Implement Feature A, Priority: 3, Assignee: Wusqa (A001)\n";

    ASSERT_EQ(actualOutput.str(), expectedOutput);
}

TEST(counting, tasks) {
    taskManagementSystem taskSystem;

    taskSystem.addAssignee("Wusqa", "Khan", "I6", "2/11/2003");  //This should get A001
    taskSystem.addAssignee("Amna", "Hashim", "Dha phase 5", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Mehdi", "Khan", "I8", "2/11/2003");
    taskSystem.addAssignee("Hadi", "Hashim", "Dha phase 5", "14/2/2002");
    taskSystem.addAssignee("Haider", "Khan", "H11", "2/11/2002");
    taskSystem.addAssignee("Mesum", "Hashim", "Dha phase 1", "1/2/2002");

    // Add tasks
    taskSystem.addTask(101, "Implement Feature A", 2, "A001");
    taskSystem.addTask(102, "Fix Bug in Module B", 3, "A002");
    taskSystem.addTask(103, "Write Unit Tests", 1, "A003");
    taskSystem.addTask(104, "Dry run of Module D", 5, "A004");
    taskSystem.addTask(105, "Fix Bug in Module C", 4, "A005");
    taskSystem.addTask(106, "Rewrite the report", 6, "A006");

    // Capture the actual output
    std::stringstream actualOutput;
    taskSystem.countTotalTasks(actualOutput);

    // Define the expected output
    std::string expectedOutput = "Total Tasks in the System: 6\n";

    ASSERT_EQ(actualOutput.str(), expectedOutput);

}

TEST(displaying, completed_tasks) {
    taskManagementSystem taskSystem;

    taskSystem.addAssignee("Tanzeela", "Khan", "I6", "2/12/2003");  //This should get A001
    taskSystem.addAssignee("Farakh", "Hashim", "Dha phase 5", "1/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Rodaba", "Khan", "I5", "2/11/2003");
    taskSystem.addAssignee("Laila", "Hashim", "Dha phase 2", "11/2/2002");
    // Add tasks
    taskSystem.addTask(101, "Implement Feature A", 2, "A001");
    taskSystem.addTask(102, "Fix Bug in Module B", 3, "A002");
    taskSystem.addTask(103, "Implement Feature D", 1, "A003");
    taskSystem.addTask(104, "Fix Bug in Module F", 4, "A004");

    // Mark a task as completed
    taskSystem.completeTask(101);

    // Capture the actual output
    std::stringstream actualOutput;
    taskSystem.displayCompletedTasks(actualOutput);


    std::string expectedOutput = "Completed Tasks:\n"
        "Task ID: 101, Description: Implement Feature A, Priority: 2, Assignee: Tanzeela (A001)\n";

    ASSERT_EQ(actualOutput.str(), expectedOutput);
}


TEST(Searching, priorityrange) {
    taskManagementSystem taskSystem;

    taskSystem.addAssignee("Waqas", "Khan", "I6", "2/12/2003");  //This should get A001
    taskSystem.addAssignee("Hur", "Hashim", "Dha phase 4", "1/1/2002"); // A002 and so on.
    taskSystem.addAssignee("Hasan", "Khan", "I9", "2/11/2003");
    // Add tasks with various priority levels
    taskSystem.addTask(101, "Implement Feature A", 2, "A001");
    taskSystem.addTask(102, "Fix Bug in Module B", 3, "A002");
    taskSystem.addTask(103, "Write Unit Tests", 1, "A003");

    // Capture the actual output
    std::stringstream actualOutput;
    taskSystem.searchTasksByPriorityRange(1, 2, actualOutput);

    // Define the expected output
    std::string expectedOutput = "Tasks within Priority Range (1 to 2):\n"
        "Task ID: 103, Description: Write Unit Tests, Priority: 1, Assignee: Hasan (A003)\n"
        "Task ID: 101, Description: Implement Feature A, Priority: 2, Assignee: Waqas (A001)\n";

    // Compare the actual output with the expected output and display "PASS" or "FAIL"
    ASSERT_EQ(actualOutput.str(), expectedOutput);
}

TEST(display_tree, insertion)
{
    taskManagementSystem taskSystem;

    taskSystem.addAssignee("Riaz", "Khan", "I6", "2/12/2003");  //This should get A001
    taskSystem.addAssignee("Zulqurnain", "Hashim", "Dha phase 5", "1/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Hussain", "Khan", "I5", "2/11/2003");
    taskSystem.addAssignee("Laila", "Hashim", "Dha phase 2", "1/2/2002");
    taskSystem.addAssignee("Qasim", "Khan", "I6", "2/12/2000");
    taskSystem.addAssignee("Mustafa", "Hashim", "Dha phase 3", "1/2/2002");
    // Insert tasks
    taskSystem.addTask(101, "Task A", 3, "A001");
    taskSystem.addTask(102, "Task B", 2, "A002");
    taskSystem.addTask(103, "Task C", 1, "A003");
    taskSystem.addTask(104, "Task D", 4, "A004");
    taskSystem.addTask(105, "Task E", 5, "A005");
    taskSystem.addTask(106, "Task F", 6, "A006");
    //A tree would be created considering the priorities not the task number.

    // Capture the actual output
    std::stringstream actualOutput;
    taskSystem.PrintTreeInorder(actualOutput); //In Order Traversal with the color of that node

    // Define the expected output
    std::string expectedOutput =
        "103 (black)\n"
        "102 (black)\n"
        "101 (black)\n"
        "104 (red)\n"
        "105 (black)\n"
        "106 (red)\n";

    ASSERT_EQ(actualOutput.str(), expectedOutput);

}


TEST(display_tree, deletion)
{
    taskManagementSystem taskSystem;

    taskSystem.addAssignee("Riaz", "Khan", "I6", "2/12/2003");  //This should get A001
    taskSystem.addAssignee("Zulqurnain", "Hashim", "Dha phase 5", "1/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Hussain", "Khan", "I5", "2/11/2003");
    taskSystem.addAssignee("Laila", "Hashim", "Dha phase 2", "1/2/2002");
    taskSystem.addAssignee("Qasim", "Khan", "I8", "2/12/2000");
    taskSystem.addAssignee("Mustafa", "Hashim", "Dha phase 2", "1/2/2002");
    taskSystem.addAssignee("Reem", "Khayar", "I6", "2/2/2003");
    taskSystem.addAssignee("Badr", "Sheik", "Dha phase 5", "1/2/2002");
    taskSystem.addAssignee("Eesha", "Anwar", "I5", "2/1/2003");
    taskSystem.addAssignee("Fawad", "Hashim", "Dha phase 2", "1/2/2002");
    taskSystem.addAssignee("Khizar", "Khan", "I6", "22/2/2000");
    taskSystem.addAssignee("Yahya", "Hashim", "Dha phase 3", "1/2/2002");
    // Insert tasks
    taskSystem.addTask(101, "Task A", 7, "A001");
    taskSystem.addTask(102, "Task B", 6, "A002");
    taskSystem.addTask(103, "Task C", 3, "A003");
    taskSystem.addTask(104, "Task D", 11, "A004");
    taskSystem.addTask(105, "Task E", 12, "A005");
    taskSystem.addTask(106, "Task F", 2, "A006");
    taskSystem.addTask(107, "Task G", 10, "A007");
    taskSystem.addTask(108, "Task H", 4, "A008");
    taskSystem.addTask(109, "Task I", 8, "A009");
    taskSystem.addTask(110, "Task J", 1, "A010");
    taskSystem.addTask(111, "Task K", 9, "A011");
    taskSystem.addTask(112, "Task L", 5, "A012");
    //A tree would be created considering the priorities not the task number.

    // Delete a task
    taskSystem.deleteTask(102);

    // Capture the actual output
    std::stringstream actualOutput;
    taskSystem.PrintTreeInorder(actualOutput); //In Order Traversal with the color of that node

    // Define the expected output after deleting the task
    std::string expectedOutput =
        "110 (red)\n"
        "106 (black)\n"
        "103 (black)\n"
        "108 (black)\n"
        "112 (black)\n"
        "101 (black)\n"
        "109 (red)\n"
        "111 (red)\n"
        "107 (black)\n"
        "104 (black)\n"
        "105 (black)\n";

    ASSERT_EQ(actualOutput.str(), expectedOutput);
}


TEST(display_tree, UpdateTaskPriorities) {
    taskManagementSystem taskSystem;

    taskSystem.addAssignee("Musa", "Khan", "I6", "2/12/2003");  //This should get A001
    taskSystem.addAssignee("Isa", "Hashim", "Dha phase 5", "1/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Hussain", "Khan", "I5", "2/11/2003");
    taskSystem.addAssignee("Shahzaib", "Hashim", "Dha phase 2", "1/2/2002");
    taskSystem.addAssignee("Qasim", "Khan", "I8", "2/12/2000");
    taskSystem.addAssignee("Rida", "Hashim", "Dha phase 2", "1/2/2002");
    // Add tasks
    taskSystem.addTask(101, "Task A", 7, "A001");
    taskSystem.addTask(102, "Task B", 6, "A002");
    taskSystem.addTask(103, "Task C", 3, "A003");
    taskSystem.addTask(104, "Task A", 5, "A004");
    taskSystem.addTask(105, "Task B", 4, "A005");
    taskSystem.addTask(106, "Task C", 1, "A006");

    // Display the initial tree
    std::stringstream initialTreeOutput;
    taskSystem.PrintTreeInorder(initialTreeOutput); //In Order Traversal with the color of that node
    taskSystem.updateTaskPriority(105, 2);


    // Display the updated tree
    std::stringstream updatedTreeOutput; //In Order Traversal with the color of that node
    taskSystem.PrintTreeInorder(updatedTreeOutput);

    // Define the expected output
    std::string expectedInitialTreeOutput =
        "106 (red)\n"
        "103 (black)\n"
        "105 (red)\n"
        "104 (black)\n"
        "102 (black)\n"
        "101 (black)\n";

    std::string expectedUpdatedTreeOutput =
        "106 (black)\n"
        "105 (red)\n"
        "103 (red)\n"
        "104 (black)\n"
        "102 (black)\n"
        "101 (black)\n";

    // Check if the initial tree and updated tree match the expected output
    ASSERT_EQ(initialTreeOutput.str(), expectedInitialTreeOutput);
    ASSERT_EQ(updatedTreeOutput.str(), expectedUpdatedTreeOutput);
}

TEST(display_tree, samepriority) {
    taskManagementSystem taskSystem;

    taskSystem.addAssignee("Musa", "Khan", "I6", "2/12/2003");  //This should get A001
    taskSystem.addAssignee("Isa", "Hashim", "Dha phase 5", "1/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Hussain", "Khan", "I5", "2/11/2003");
    taskSystem.addAssignee("Shahzaib", "Hashim", "Dha phase 2", "1/2/2002");
    taskSystem.addAssignee("Qasim", "Khan", "I8", "2/12/2000");
    taskSystem.addAssignee("Rida", "Hashim", "Dha phase 2", "1/2/2002");
    taskSystem.addAssignee("Ali", "Shah", "I8", "1/2/2003");

    // Add tasks
    taskSystem.addTask(101, "Task A", 7, "A001");
    taskSystem.addTask(102, "Task B", 6, "A002");
    taskSystem.addTask(103, "Task C", 3, "A003");
    taskSystem.addTask(104, "Task A", 5, "A004");
    taskSystem.addTask(105, "Task B", 4, "A005");
    taskSystem.addTask(106, "Task C", 1, "A006");
    taskSystem.addTask(107, "Task D", 3, "A007");

    // Display the tree
    std::stringstream TreeOutput;
    taskSystem.PrintTreeInorder(TreeOutput); //In Order Traversal with the color of that node
    //in case of same priority tasks, arrange them wrt task id, in ascending order.

    // Define the expected output
    std::string expectedInitialTreeOutput =
        "106 (red)\n"
        "103 (black)\n"
        "107 (red)\n"
        "105 (red)\n"
        "104 (black)\n"
        "102 (black)\n"
        "101 (black)\n";


    // Check if the tree match the expected output
    ASSERT_EQ(TreeOutput.str(), expectedInitialTreeOutput);
}




int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
