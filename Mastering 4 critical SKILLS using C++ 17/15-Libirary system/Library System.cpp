#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_BOOKS  100
#define MAX_USERS  100
struct book;
struct user;
struct sys;

bool name_comp(book &a,book &b);
bool id_comp(book &a,book &b);

typedef struct book{
    string name;
    int quantity;
    int id;
    int borrowed;
    string borrow_name[10];
    book(void){
        quantity = 0;
        borrowed = 0;
        id = -1;
    }
    void Borrow_Book(string name)
    {
        if (borrowed >= quantity)
        {
            cout << "No enough book\n";
            return;
        }
        borrow_name[borrowed] = name;
        borrowed++;
    }
    void Retrun_Book(string name)
    {
        int location;
        for (int i = 0; i < borrowed; i++)
        {
            if (name == borrow_name[i])
            {
                location = i;
                break;
            }
        }
        for (int i = location; i < borrowed-1; i++)
        {
            borrow_name[i] = borrow_name[i+1];
        }
        borrowed--;
    }

}book_st;
typedef struct user{
    string name;
    int id;
    int borrowed_Num;
    string borrowed_name[10];
    user(void){
        id = -1;
        borrowed_Num = 0;
    }
    void Borrow_Book(string Book_Name)
    {
        borrowed_name[borrowed_Num] = Book_Name;
        borrowed_Num++;
    }
    void Return_Book(string Book_Name)
    {
        int location;
        for (int i = 0; i < borrowed_Num; i++)
        {
            if (Book_Name == borrowed_name[i])
            {
                location = i;
                break;
            }
        }
        for (int i = location; i < borrowed_Num-1; i++)
        {
            borrowed_name[i] = borrowed_name[i+1];
        }
        borrowed_Num--;
    }
}user_st;


typedef struct sys{
    user_st user[MAX_USERS];
    book_st book[MAX_BOOKS];
    int user_num;
    int book_num;
    sys(void)
    {
        user_num = 0;
        book_num = 0;
    }
    void Add_Book(void)
    {
        if (book_num >= MAX_BOOKS)
        {
            cout << "Max number of books\n\n";
            return;
        }
        cout << "Enter Book Name, ID, Quantity: ";
        cin >> book[book_num].name >> book[book_num].id >> book[book_num].quantity;
        book_num++;
    }
    void Add_User(void)
    {
        if (user_num >= MAX_USERS)
        {
            cout << "Max number of users\n\n";
            return;
        }
        cout << "Enter User Name, ID: ";
        cin >> user[user_num].name >> user[user_num].id;
        user_num++;
    }
    void Print_Users(void)
    {
        for (int i = 0; i < user_num; i++)
        {
            cout << user[i].name << " Borrowed ";
            for (int j = 0; j < user[i].borrowed_Num; j++)
            {
                cout << user[i].borrowed_name[i];
            }
            cout << "\n";
        }
    }
    void Search_Book(void)
    {
        string name;
        cin>> name;
        int count = 0;
        for (int i = 0; i < book_num; i++)
        {
            bool flag = true;
            for (int j = 0; j < name.size(); j++)
            {
                if (name[j] != book[i].name[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << book[i].name << ", ";
                count++;
            }
        }
        if (count == 0)
        {
            cout << "Nothing.";
        }
        cout << endl;
    }
    void List_By_Name(void)
    {
        sort(book,book+book_num,name_comp);
        for (int i = 0; i < book_num; i++)
        {
            cout << book[i].name <<" ";
        }
        cout << endl;
    }
    void List_By_ID(void)
    {
        sort(book,book+book_num,id_comp);
        for (int i = 0; i < book_num; i++)
        {
            cout << book[i].name <<" ";
        }
        cout << endl;
    }
    void User_Borrow_Book(void)
    {

    }
    void User_Return_Book(void)
    {
        
    }
    void Print_Who_Borrowed_Book_By_Name(void)
    {
        
    }
    void Menu(void)
    {
        while(true)
        {
            int choice;
            while (true)
            {
                cout <<"Liberary Menu;\n";
                cout <<"1) add_book\n";
                cout <<"2) search_book_by_prefix\n";
                cout <<"3) print_who_borrowed_book_by_name\n";
                cout <<"4) print_Library_by_id\n";
                cout <<"5) print_Library_by_name\n";
                cout <<"6) add_user\n";
                cout <<"7) user_borrow_book\n";
                cout <<"8) user_return_book\n";
                cout <<"9) print_users\n";
                cout <<"10) Exit\n\n";
                cout << "Enter your menu choice [1 - 10]: ";
                cin >> choice;
                if (choice < 1 || choice > 10)
                {
                    cout <<"Not correct choice, try again\n\n";
                }else
                {
                    cout << "\n";
                    break;
                }
            }

        }
    }
}sys_st;



int main(void)
{

    return 0;
}


bool name_comp(book &a,book &b)
{
    if (a.name < b.name)
        return true;
    return false;
}

bool id_comp(book &a,book &b)
{
    if (a.id < b.id)
        return true;
    return false;
}



// cout <<"3) print_who_borrowed_book_by_name\n"; 
// cout <<"7) user_borrow_book\n"; for user book
// cout <<"8) user_return_book\n"; for user book
