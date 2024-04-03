#include <iostream>
using namespace std;

#define Max_Specs 20
#define Max_Spots 5

string names[Max_Specs][Max_Spots];
int status[Max_Specs][Max_Spots];
int spots[Max_Specs];

int Menu_choose(void);
void Add_Newpatien(void);
void Shift_Right(int Spec);
void Shift_Left(int Spec);
void Print_All(void);
void Get_Patient(void);

int main(void)
{
    while(1)
    {
        int x = Menu_choose();
        if (x == 1)
        {
            Add_Newpatien();
        }
        else if (x == 2)
        {
            Print_All();
        }
        else if (x == 3)
        {
            Get_Patient();
        }
        else if (x == 4)
        {
            break;
        }
    }
    return 0;
}


int Menu_choose(void)
{
    int choice = -1;
    while (choice < 1 || choice >4)
    {   cout << "Enter your choice:\n";
        cout << "1) Add new patient\n";
        cout << "2) Print all patients\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit\n\n";
        cin >> choice;
        cout << "\n**************************************\n\n";
        if (choice < 1 || choice >4)
        {
            cout << "Wrong choice Try again\n";
            cout << "\n**************************************\n\n";
        }
    }
    return choice;
}

void Add_Newpatien(void)
{
    int spec = -1,stat = -1;
    string name;
    while (spec >= 20 || spec < 0  || stat < 0 || stat >1)
    {
        cout << "Enter specialization, name, status: ";
        cin >> spec >> name >> stat;
        if (spec >= 20 || spec < 0) 
        {
            cout << "Wrong spectialization Try again\n";
        }
        if (stat < 0 || stat >1) 
        {
            cout << "Wrong status Try again\n";
        }
    }
    if (spots[spec] >= 5)
    {
        cout << "Sorry we can't add more patients for this specialization";
    }
    else if (stat == 0)
    {
        names[spec][spots[spec]] = name;
        status[spec][spots[spec]] = 0;
        spots[spec]++;
    }
    else if (stat == 1)
    {
        Shift_Right(spec);
        names[spec][0] = name;
        status[spec][0] = 1;
        spots[spec]++;
    }
}

void Shift_Right(int Spec)
{
    for (int i = spots[Spec];i > 0; i--)
    {
        names[Spec][i] = names[Spec][i-1];
        status[Spec][i] = status[Spec][i-1];
    }
    names[Spec][0] = "";
    status[Spec][0] = 0;
}
void Shift_Left(int Spec)
{
    for (int i = 1;i < spots[Spec]; i++)
    {
        names[Spec][i-1] = names[Spec][i];
        status[Spec][i-1] = status[Spec][i];
    }
}
void Print_All(void)
{
    for (int i = 0; i < Max_Specs;i++)
    {
        if (spots[i] == 0)
        {
            continue;
        }
        cout << "\n**************************************\n";
        cout << "There are " << spots[i] << " in specialization "<< i << endl;
        for (int j = 0; j < spots[i];j++)
        {
            cout << names[i][j] << " ";
            if (status[i][j] == 0)
            {
                cout << "Regular\n";
            }
            else
            {
                cout << "Urgent\n";
            }
        }
    }
    cout << "\n\n**************************************\n";
}

void Get_Patient(void)
{
    int spec;
    cout << "Please Enter specialization: ";
    cin >> spec;
    if (spots[spec] == 0)
    {
        cout << "No Patient at specialization " << spec << " ,Have a rest, Dr\n";
    }
    else
    {
        cout << names[spec][0] <<" Please go with Doctor\n";
        Shift_Left(spec);
        spots[spec]--;
    }
}