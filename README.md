# C-Language-Lab-Task-10

Question 1: Personal Expense Diary
A student wants to keep a record of daily expenses to manage their monthly budget. Write a
program that allows the student to enter the description and amount of a few expenses and save
them in a text file named expenses.txt. Each expense should be stored on a separate line. After
saving all entries, the program should read the file and display all recorded expenses along with
their amounts so the student can review the saved data.
Requirements:
 Create a text file named expenses.txt.
 Input the expense description and amount for multiple expenses.
 Write all expense records into the file, with each record on a separate line.
 Read the saved records from the file and display them on the screen.
 Close the file properly after each operation.


Question 2: Lost and Found Record Manager
A college maintains a record of items reported lost or found on campus. Each record contains an
item name, the location where it was found or lost, and the student's contact ID. Write a program
that allows staff to add new records to a text file named lostfound.txt without removing
previously saved records. The program should also display all saved records and allow staff to
search for records by item name. If the searched item exists, display its complete record;
otherwise, display a message indicating that no matching record was found.
Requirements:
 Store the item name, location and contact ID in the text file.
 Allow the user to add multiple new records without overwriting existing records.
 Display all records currently saved in the file.
 Search for an item by its name and display its complete record if found.
 Display an appropriate message if the searched item does not exist.
 Handle file-opening errors and close the file properly.


Question 3: Library Book Record System
A small library wants to maintain its book records digitally. Each book has a unique book ID,
title, author name and number of available copies. Write a program that manages these records
using a binary file named books.dat. The program should allow the librarian to add new book
records, display all stored books, search for a book using its ID, update the available copies of a
selected book, and delete a book record when the book is no longer part of the library. The
program must maintain the existing records while adding, updating or deleting books, and
changes should be reflected in the binary file.

Requirements:
 Define a structure Book containing book ID, title, author name and available copies.
 Create and store book records in a binary file named books.dat.
 Add multiple book records without overwriting existing records.
 Display all book records stored in the file.
 Search for a book using its unique ID and display its details if found.
 Update the available copies of a book using its ID.
 Delete a book record using its ID while preserving all other records.
 Display an appropriate message when the searched, updated or deleted book ID does not
exist.
 Ensure that all file operations are handled properly and files are closed after use.
