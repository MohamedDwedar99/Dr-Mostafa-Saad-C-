#include <iostream>
using namespace std;


int main(void)
{
    string name[1000];
    int salary[1000] = {0};
    int age[1000] = {0};
    char gender[1000];
    while (1)
    {
        int choice = 0;
        int curser = 0;
        cout << "Enter your choice" <<endl;
        cout << "1) Add new employee" <<endl;
        cout << "2) Print all employee" <<endl;
        cout << "3) Delete by age" <<endl;
        cout << "4) Update salary by name\n" <<endl ;
        cin >> choice;
        if (choice == 1)
        {
            while (age[curser] != 0)
            {
                curser++;
            }
            cout << "Enter Name: ";
            cin >> name[curser];
            cout << "Enter age: ";
            cin >> age[curser];
            cout << "Enter salary: ";
            cin >> salary[curser];
            cout << "Enter gender: ";
            cin >> gender[curser];
        }
        else if (choice == 2)
        {
            int Empty_flag = true;
            for (curser = 0; curser < 1000;curser++)
            {
                if (age[curser] != 0)
                {
                    cout << name[curser]<<" ";
                    cout << age[curser]<<" ";
                    cout << salary[curser]<<" ";
                    cout << gender[curser]<<endl;
                    Empty_flag = false;
                }
            }
            curser = 0;
            if (Empty_flag)
            {
                cout <<"Empty List"<<endl;
            }
        }
        else if (choice == 3)
        {
            bool D_flag = false;
            int age_s;
            cout << "Enter Age: ";
            cin >> age_s;
            for (curser = 0; curser < 1000;curser++)
            {
                if (age[curser] == age_s)
                {
                    age[curser]=0;
                    D_flag = true;
                    break;
                }
            }
            if (D_flag == true)
            {
                cout << "Removed Successfully"<< endl;
            }
            else
            {
                cout << "Not Fount!!"<< endl;
            }
        }
        else if (choice == 4)
        {
            bool N_flag = false;
            string name_s;
            cout << "Enter Name: ";
            cin >> name_s;
            int salary_s;
            cout << "Enter Salary: ";
            cin >> salary_s;
            for (curser = 0; curser < 1000;curser++)
            {
                if (name[curser] == name_s)
                {
                    salary[curser] = salary_s;
                    N_flag = true;
                    break;
                }
            }
            if (N_flag == true)
            {
                cout << "Updated Successfully"<< endl;
            }
            else
            {
                cout << "Not Fount!!"<< endl;
            }
        }
        else
        {
            std::cout << "--Wrong choice Try again--" << std::endl;
        }
    }
    return 0;
}