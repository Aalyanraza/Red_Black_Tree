# Task Management System with Red-Black Tree Implementation

This project implements a Task Management System using Red-Black Trees for efficient task and assignee management. It provides a comprehensive set of features to handle tasks assigned to project team members.

## Features

- **Add Assignee**: Allows adding new assignees with details such as First Name, Last Name, Address, and Date of Birth. Assignee IDs are automatically generated.
  
- **Search Assignee by ID**: Functionality to find an assignee by their unique ID.
  
- **Search Assignee by Name**: Searches for assignees based on their first and last names. Displays all assignees with matching names.
  
- **Search Assignee with No Task Assigned**: Finds and displays assignees who currently have no tasks assigned.
  
- **Shift Tasks of One Assignee to Another**: Transfers tasks from one assignee to another.
  
- **Delete Assignee**: Removes an assignee from the system if they have completed all their tasks.
  
- **Add Task**: Enables adding new tasks with descriptions, priority levels, and assigned assignee IDs.
  
- **Complete Task**: Marks tasks as completed and updates their status accordingly.
  
- **Print Task Queue**: Displays the list of tasks sorted by priority.
  
- **Find Highest Priority Task**: Retrieves and displays the task with the highest priority.
  
- **Find Task by Assignee**: Searches for tasks assigned to a specific assignee and displays them.
  
- **Count Total Tasks**: Provides a count of the total number of tasks in the system.
  
- **Update Task Priority**: Allows updating the priority level of a specific task.
  
- **Clear Completed Tasks**: Removes all completed tasks from the system.
  
- **Display All Completed Tasks**: Shows a list of all tasks that have been completed.
  
- **Search for Task by Priority Range**: Finds tasks within a specified priority range and displays them.

## Red-Black Tree Implementation

The Red-Black Tree is used to store task records, where each node represents a task in the system. Nodes are structured with fields including Task ID, Description, Priority Level, and Assignee ID.

### In-Order Traversal

The implementation includes an in-order traversal function for both the Task and Assignee trees. This function displays each node's data and its color (red or black) to maintain the tree's properties.

## Getting Started

To use this system, clone the repository and compile the code using a C++ compiler that supports C++11 or higher.

## Dependencies

This project relies on standard C++ libraries and does not require additional dependencies.

## Usage

1. Compile the code.
2. Execute the compiled program.
3. Use the provided menu options to interact with the Task Management System.

## Example

```cpp
// Example usage or code snippet demonstrating how to add an assignee and tasks
taskManagementSystem tm;
tm.addAssignee("John", "Doe", "123 Street, City", "1990-01-01");
tm.addTask(1, "Complete Project Proposal", 1, "A001");
// Use other methods as needed
