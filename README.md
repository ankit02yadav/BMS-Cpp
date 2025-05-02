# 🍞 Bakery Management System in C++

A simple console-based Bakery Management System implemented in C++. This project supports basic operations for **Admins** and **Customers**, such as managing menu items, placing orders, and viewing order details.

## 📋 Features

### Admin:
- Login system (via `AdminFile.txt`)
- Add new bakery items to the menu
- Remove existing items
- Update item quantity or price
- View current menu
- View all customer orders

### Customer:
- View menu
- Purchase bakery items
- Generate and view order with unique Order ID
- Store order history with timestamp

## 📁 File Structure

- `AdminFile.txt`: Stores admin login credentials (username & password).
- `MenuFile.txt`: Stores the list of available bakery items.
- `CostumerFile.txt`: Stores customer orders with order details and timestamps.

## 🛠️ How to Run

### 1. Compile the program:

```bash
g++ -o bakery main.cpp
```
### 2. Run the executable:
```bash
./bakery
```
Make sure AdminFile.txt, MenuFile.txt, and CostumerFile.txt are in the same directory. These files will be created automatically if they don't exist.
## 📝 Admin Login Credentials
To use the admin features, add credentials manually to AdminFile.txt:
```bash
admin123 password123
```
(Each line should contain username password.)
## 🧪 Sample Test Flow
1. Run the program.
2. Select Admin Login to manage items or view orders.
3. Select Customer to place an order and view their order by ID.

## 📦 Requirements
* C++ compiler (GCC or equivalent)
* Basic I/O access (file read/write permissions)

## ⚠️ Known Issues
* No password hashing/encryption for admin login.
* Customer name or item names with spaces are not supported.
* Minimal input validation (e.g., numeric checks, invalid input handling).

## ✅ Future Improvements
* Support item names with spaces using getline() and quotes.
* Add password masking for admin login.
* Store structured data in JSON or CSV for easier parsing.
* GUI version using C++ with Qt or Python (Tkinter/PyQt).
  
## 📄 License
This project is open-source and free to use under the MIT License
