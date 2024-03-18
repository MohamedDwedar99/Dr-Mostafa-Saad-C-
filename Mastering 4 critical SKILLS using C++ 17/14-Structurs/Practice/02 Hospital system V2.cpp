#include <iostream>
using namespace std;

#define Max_Specs 20
#define Max_Spots 5

typedef struct Patient{
    string name;
    int status;
}Patient;

typedef struct Spectialization{
    Patient pat[Max_Spots];
    int len;
    Spectialization(void)
    {
        len = 0;
    }
    void add_end(Patient _pat)
    {
        pat[len] = _pat;
        len++;
    }
    void add_front(Patient _pat)
    {
        for (int i = len; i > 0; i--)
        {
            pat[i] = pat[i-1];
        }
        pat[0] = _pat;
        len++;
    }
    Patient Get_Patient(void)
    {
        Patient ret = pat[0];
        for (int i = 0; i < len-1; i++)
        {
            pat[i] = pat[i+1];
        }
        len--;
        return ret;
    }
    void Add_Patient(Patient _pat)
    {
        if (len >= 5)
        {
            cout << "Sorry we can't add more Patients for this specialization";
        }
        else if (_pat.status == 0)
        {
            add_end(_pat);
        }
        else if (_pat.status == 1)
        {
            add_front(_pat);
        }
    }
    void print(void)
    {
       for (int i = 0; i < len ; i++)
        {
            cout << pat[i].name << " ";
            if (pat[i].status == 0)
            {
                cout << "Regular\n";
            }
            else
            {
                cout << "Urgent\n";
            }
        }
    }
}Spectialization;

typedef struct Hospital{
    Spectialization spec[Max_Specs];
    void Print_all(void)
    {
        for (int i = 0; i < Max_Specs;i++)
        {
            if (spec[i].len == 0)
            {
                continue;
            }
            cout << "\n**************************************\n";
            cout << "There are " << spec[i].len << " in specialization "<< i << endl;
            spec[i].print();
        }
    }
    Hospital(void)
    {
        while(1)
        {
            int choice = -1;
            while (choice < 1 || choice >4)
            {   cout << "Enter your choice:\n";
                cout << "1) Add new Patient\n";
                cout << "2) Print all Patients\n";
                cout << "3) Get next Patient\n";
                cout << "4) Exit\n\n";
                cin >> choice;
                cout << "\n**************************************\n\n";
               if (choice < 1 || choice >4)
               {
                   cout << "Wrong choice Try again\n";
                   cout << "\n**************************************\n\n";
               }
            }
            if (choice == 1)
            {
                Patient _pat;
                int spectial;
                cout << "Enter specialization, name, status: ";
                cin >> spectial  >> _pat.name >> _pat.status;
                spec[spectial].Add_Patient(_pat);
            }
            else if (choice == 2)
            {
                Print_all();
            }
            else if (choice == 3)
            {
                int spectial;
                cout << "Enter specialization: ";
                cin >> spectial;
                Patient _pat = spec[spectial].Get_Patient();
                cout << _pat.name << " Please Go with Doctor\n";
            }
            else if (choice == 4)
            {
                break;
            }
        }
    }

}Hospital;



int main(void)
{
    Hospital();
    return 0;
}


