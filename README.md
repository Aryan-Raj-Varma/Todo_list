# Todo_list
To-Do List App (C++)

Description:
------------
This is a simple command-line To-Do List application written in C++. 
Users can add tasks, view them, mark tasks as done, and delete tasks.
The tasks persist between runs by saving to a file.

Features:
---------
- Add new tasks
- View all tasks
- Mark a task as completed
- Delete a task
- Save and load tasks from a text file (tasks.txt)

Files:
------
- todo_list_app.cpp  : Main source file
- tasks.txt          : Stores tasks (created after first run)
- Makefile           : For building the project
- README.txt         : This help file

How to Compile:
---------------
Use the provided Makefile:
$ make

Or compile manually:
$ g++ -o todo_app todo_list_app.cpp

Run the program:
$ ./todo_app

Author:
-------
Created for interview preparation. Demonstrates OOP, file handling, and basic data structures in C++.
