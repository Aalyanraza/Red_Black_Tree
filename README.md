# Task Management System with Red-Black Tree Implementation

This project implements a Task Management System using Red-Black Trees for efficient task and assignee management. It maintains two separate Red-Black Trees—one for tasks and another for assignees—to organize and manage project-related information effectively.
![Red-black-Tree-banner-ezgif com-webp-to-jpg-converter](https://github.com/Aalyanraza/Red_Black_Tree/assets/114768774/2385b176-549d-433f-8729-03d8652bcd50)

## Task Management System Overview

### Red-Black Tree for Assignees

The Assignee Red-Black Tree stores information about team members:

- **Add Assignee**: Allows adding new assignees with details such as First Name, Last Name, Address, and Date of Birth. Assignee IDs are automatically generated based on the number of assignees added.
  
- **Search Assignee by ID**: Functionality to find an assignee by their unique ID.
  
- **Search Assignee by Name**: Searches for assignees based on their first and last names. Displays all assignees with matching names.
  
- **Search Assignee with No Task Assigned**: Finds and displays assignees who currently have no tasks assigned.
  
- **Shift Tasks of One Assignee to Another**: Transfers tasks from one assignee to another. Useful for redistributing workload.
  
- **Delete Assignee**: Removes an assignee from the system if they have completed all their tasks. Ensures no data inconsistency.

### Red-Black Tree for Tasks

The Task Red-Black Tree manages project tasks:

- **Add Task**: Enables adding new tasks with descriptions, priority levels, and assigned assignee IDs. Tasks are inserted into the tree based on their priority level.
  
- **Complete Task**: Marks tasks as completed and updates their status accordingly. This operation ensures that completed tasks can be managed separately or removed if required.
  
- **Print Task Queue**: Displays the list of tasks sorted by priority. Useful for visualizing task priorities and workload.
  
- **Find Highest Priority Task**: Retrieves and displays the task with the highest priority. Optimizes task management by focusing on critical tasks.
  
- **Find Task by Assignee**: Searches for tasks assigned to a specific assignee and displays them. Helps in tracking individual assignments.
  
- **Count Total Tasks**: Provides a count of the total number of tasks in the system. Useful for reporting and workload analysis.
  
- **Update Task Priority**: Allows updating the priority level of a specific task. Maintains flexibility in task management.
  
- **Clear Completed Tasks**: Removes all completed tasks from the system. Keeps the task list clean and manageable.
  
- **Display All Completed Tasks**: Shows a list of all tasks that have been completed. Useful for tracking progress and generating reports.
  
- **Search for Task by Priority Range**: Finds tasks within a specified priority range and displays them. Facilitates focused task management based on priority levels.

### In-Order Traversal

Both the Assignee and Task trees implement an in-order traversal method:

- In-order traversal displays each node's data and its color (red or black) to maintain the tree's balance and properties.
- This feature aids in debugging, understanding tree structure, and verifying the correctness of tree operations.

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
