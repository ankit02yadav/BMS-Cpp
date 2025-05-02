#include <bits/stdc++.h>
using namespace std;
string CurrentTime;
int Id = 800;
const string adminfile = "AdminFile.txt";
const string menufile = "MenuFile.txt";
const string costumerfile = "CostumerFile.txt";
int CheckFile(string filename);
string Time();
int IDGenerator();
// Admin
int AdminLogin();
int AdminMenu();
int AddItems();
int ViewMenu();
int ViewCostumer();
int RemoveItem();
int UpdateItem();
// Costumer
int CostumerMenu();
int BuyItems();
int ViewOrder(int n);

int main()
{
    while (1)
    {
        int choice;
        cout << "Bakery Management System \n";
        cout << "1. Admin Login \n";
        cout << "2. Costumer \n";
        cout << "3. Exit\n";
        cout << "Enter Your Choice : ";
        if (cin >> choice)
        {
            if (choice == 1)
            {
                cout << "Admin Login \n";
                AdminLogin();
            }
            else if (choice == 2)
            {
                cout << "costumer menu\n";
                CostumerMenu();
            }
            else if (choice == 3)
            {
                cout << "Exiting...\n";
                break;
            }
            else
            {
                cout << "Invalid choice. Please enter 1-3.\n";
                break;
            }
        }
        else
        {
            cout << "Invalid input. Please enter a number.\n";
            break;
        }
    }
}
int CheckFile(string filename)
{
    ofstream file(filename, ios::app); // ios:app = open file in append mode
    if (!file)
    {
        return 1;
    }
    file.close();
    return 0;
}
int AdminLogin()
{
    CheckFile(adminfile);
    char Login = 0;
    ifstream read_file(adminfile);
    string username;
    string password;
    cout << "Enter Username : ";
    cin >> username;
    cout << "Enter Password : ";
    cin >> password;
    string line;
    while (getline(read_file, line))
    {
        // cout << line << endl;
        string file_username, file_password;
        istringstream ank(line);
        ank >> file_username >> file_password;
        if (file_username == username)
        {
            cout << "Login Succesfull\n";
            Login = 1;
            AdminMenu();
        }
    }
    if (Login = 0)
    {
        cout << "Login Fail";
        return 0;
    }
}
int AdminMenu()
{
    while (1)
    {
        int choice;
        cout << "Admin Menu\n";
        cout << "1. Add Items\n";
        cout << "2. Remove Item\n";
        cout << "3. Update Item\n";
        cout << "4. View Menu \n";
        cout << "5. View All Costumers\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice : ";
        if (cin >> choice)
        {
            switch (choice)
            {
            case 1:
                AddItems();
                break;
            case 2:
                RemoveItem();
                break;
            case 3:
                UpdateItem();
                break;
            case 4:
                ViewMenu();
                break;
            case 5:
                ViewCostumer();
                break;
            default:
                break;
            }
        }
        else
        {
            cout << "Invalid input\n";
            break;
        }
    }
}
int AddItems()
{
    char ItemName[20];
    int ItemQuantity, ItemPrice;
    int count;
    ofstream file(menufile, ios::app);
    CheckFile(menufile);
    cout << "How many Items You Want to add : ";
    if (cin >> count)
    {
        while (count > 0)
        {
            cout << "ItemName : ";
            cin >> ItemName;
            cout << "ItemQuantity : ";
            cin >> ItemQuantity;
            cout << "ItemPrice : ";
            cin >> ItemPrice;
            file << ItemName << " " << ItemQuantity << " " << ItemPrice << endl;
            count--;
        }
    }
    else
    {
        cout << "Invalid Input\n";
    }
    file.close();
    return 0;
}
int ViewMenu()
{
    CheckFile(menufile);
    ifstream file(menufile);
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
    return 0;
}
int ViewCostumer()
{
    CheckFile(costumerfile);
    ifstream file(costumerfile);
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
    return 0;
}
int RemoveItem()
{
    CheckFile(menufile);
    char RemovingItemName[20];
    cout << "Enter Item Name : ";
    cin >> RemovingItemName;
    int found = 0;
    ofstream temp_file("temp.txt"); // write for append we use ios:app
    ifstream file(menufile);        // read
    string line;
    while (getline(file, line))
    {
        string file_itemname, file_itemquantity, file_itemprice;
        istringstream ank(line);
        ank >> file_itemname >> file_itemquantity >> file_itemprice;
        if (file_itemname == RemovingItemName)
        {
            found = 1;
            continue;
        }
        else
        {
            temp_file << line << endl;
        }
    };
    if (found == 1)
    {
        file.close();
        temp_file.close();
        cout << "Item Removed \n";
        remove("MenuFile.txt");
        rename("temp.txt", "MenuFile.txt");
        return 0;
    }
    else
    {
        file.close();
        temp_file.close();
        cout << "Item Not Found \n";
        remove("temp.txt");
    }
}
int UpdateItem()
{
    CheckFile(menufile);
    char UpdateItemName[20];
    cout << "Enter Item Name : ";
    cin >> UpdateItemName;
    int found = 0;
    ofstream temp_file("temp.txt"); // write for append we use ios:app
    ifstream file(menufile);        // read
    string line;
    while (getline(file, line))
    {
        string file_itemname, file_itemquantity, file_itemprice;
        istringstream ank(line);
        ank >> file_itemname >> file_itemquantity >> file_itemprice;
        if (file_itemname == UpdateItemName)
        {
            found = 1;
            int new_quantity;
            int new_price;
            cout << "Enter New Quantity : ";
            cin >> new_quantity;
            cout << "Enter Item Price : ";
            cin >> new_price;

            temp_file << file_itemname << " " << new_quantity << " " << new_price << endl;
        }
        else
        {
            temp_file << line << endl;
        }
    };
    if (found == 1)
    {
        file.close();
        temp_file.close();
        cout << "Item Removed \n";
        remove("MenuFile.txt");
        rename("temp.txt", "MenuFile.txt");
        return 0;
    }
    else
    {
        file.close();
        temp_file.close();
        cout << "Item Not Found \n";
        remove("temp.txt");
    }
}
// Admin Menu Completed
int CostumerMenu()
{
    while (1)
    {
        int choice;
        cout << "1. Buy Items \n";
        cout << "2. View Your Order \n";
        cout << "3. Exit\n";
        cout << "Enter Your Choice : ";
        if (cin >> choice)
        {
            switch (choice)
            {
            case 1:
                BuyItems();
                break;
            case 2:
                int orderId;
                cout << "Enter Your Id : ";
                cin >> orderId;
                ViewOrder(orderId);
                break;

            default:
                break;
            }
        }
        else
        {
            cout << " Invalid Input \n";
            break;
        }
    }
    return 0;
}
string Time()
{
    time_t now = time(nullptr);
    CurrentTime = ctime(&now);
    return CurrentTime;
}
int BuyItems()
{
    string CostumerName;
    int NoOfItems;
    int TotalPrice = 0;
    CheckFile(costumerfile);
    CheckFile(menufile);
    cout << "Enter Your Name : ";
    cin >> CostumerName;
    Time();
    cout << "How many Items You Want To Buy : ";
    cin >> NoOfItems;
    IDGenerator();
    ofstream file(costumerfile, ios::app);
    ifstream menu_readfile(menufile);
    file << Id << " " << CostumerName << " " << CurrentTime;
    while (NoOfItems > 0)
    {
        char ItemName[20];
        int ItemQuantity;
        cout << "Enter Item Name : ";
        cin >> ItemName;

        menu_readfile.clear();            // clear EOF flag
        menu_readfile.seekg(0, ios::beg); // move pointer to beginning

        string line;
        while (getline(menu_readfile, line))
        {
            string FileItemName, FileItemQuantity, FileItemPrice;
            istringstream ank(line);
            ank >> FileItemName >> FileItemQuantity >> FileItemPrice;
            if (ItemName == FileItemName)
            {
                cout << "Enter Quantity : ";
                cin >> ItemQuantity;
                file << ItemName << " " << ItemQuantity << " " << FileItemPrice << endl;
                int INTFileItemPrice = stoi(FileItemPrice);
                TotalPrice = TotalPrice + (ItemQuantity * INTFileItemPrice);
            }
        }
        NoOfItems--;
    }
    file << "TotalPrice " << TotalPrice << endl;
    cout << "Your Order ID is : " << Id;
    ViewOrder(Id);
    return 0;
}
int IDGenerator()
{
    ifstream file(costumerfile);
    string line;
    while (getline(file, line))
    {
        string first, second, third;
        istringstream ankit(line);
        ankit >> first >> second >> third;
        try
        {
            int id = stoi(first);
            if (id > Id)
            {
                Id = id + 1;
            }
        }
        catch (invalid_argument &)
        {
            continue;
        }
    }
    return 0;
}
int ViewOrder(int n)
{
    ifstream file(costumerfile);
    string line;
    int id;
    while (getline(file, line))
    {
        string first, second, third;
        istringstream ankit(line);
        ankit >> first >> second >> third;
        try
        {
            id = stoi(first);
            if (id == n)
            {
                cout << line << endl;
            }
        }
        catch (invalid_argument &)
        {
            if (id == n)
            {
                cout << line << endl;
            }
        }
    }
    file.close();
    return 0;
}
