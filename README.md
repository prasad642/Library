# 📚 Library Management System in C

## 🔍 Overview

This is a simple Library Management System implemented in C.
It allows users to store book records in a binary file and retrieve them using Book ID.

---

## ⚙️ Features

* Add multiple books
* Store data using **binary file handling**
* Search book by ID
* Display book details
* Dynamic memory allocation using `malloc`

---

## 🧠 Concepts Used

* Structures (`struct`)
* Pointers
* Dynamic Memory Allocation
* File Handling (`fwrite`, `fread`)
* String handling

---

## ▶️ How to Run

### Compile:

```bash
gcc main.c -o library
```

### Run:

```bash
./library
```

---

## 📌 Sample Output

Enter number of books: 2
Enter details of book 1:
Enter Book Title: C Programming
Enter Author Name: Dennis Ritchie
Enter Birth Year Of Author: 1941
Assigned Book ID: 1
Enter cost: 500

Enter Book ID you're looking for: 1

book name: C Programming
written by Dennis Ritchie born in 1941
ID: 1
Cost: 500.00

---

## 🚧 Future Improvements

* Update/Delete books
* Better UI
* Sorting and filtering
* Error handling improvements

---

## 👨‍💻 Author

Prasad
