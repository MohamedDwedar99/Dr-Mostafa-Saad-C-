#include <iostream>
using namespace std;


void calc(double &n1,double &n2);
int add(double n1,double n2);
int sub(double n1,double n2);
int mul(double n1,double n2);
int div(double n1,double n2);
int menu(void);
int main(void)
{
    int op_sum = 0;
    double n1,n2;
    int op_choice;
    calc(n1,n2);
    while (1)
    {
        op_choice = menu();
        if (op_choice == 1)
        {
           op_sum+= add(n1,n2); 
        }
        else if (op_choice == 2)
        {
            op_sum+= sub(n1,n2); 
        }
        else if (op_choice == 3)
        {
            op_sum+= mul(n1,n2); 
        }
        else if (op_choice == 4)
        {
            op_sum+= div(n1,n2); 
        }
        else
        {
            break;
        }
    }
    cout << "Num of Operations = "<< op_sum;
    return 0;
}

void calc(double &n1,double &n2)
{
    bool flag = true;
    while (flag)
    {
        cout << "Choose 2 nums from 1 to 5"<< endl;
        cin >> n1 >> n2;
        if (n1 > 5 || n1 < 1 || n2 > 5 || n2 < 1)
        {
            std::cout << "Invalid Choice" << std::endl;
            continue;
        }
        flag = false;   
    }

}

int add(double n1,double n2)
{
    std::cout << "n1 + n2 = " <<n1+n2 << std::endl;
    return 1;
}
int sub(double n1,double n2)
{
    std::cout << "n1 + n2 = " <<n1-n2 << std::endl;
    return 1;
}
int mul(double n1,double n2){
    std::cout << "n1 + n2 = " <<n1*n2 << std::endl;
    return 1;
}
int div(double n1,double n2){
    if (n2 == 0)
    {
        std::cout << "Invlaid operation" << std::endl;
        return 0;
    }
    else
    {
        std::cout << "n1 + n2 = " <<n1/n2 << std::endl;
        return 1;
    }
}

int menu(void)
{
    int chos;
    bool flag = true;
    while (flag)
    {
        cout << "press 1 to add"<< endl;
        cout << "press 2 to subtract"<< endl;
        cout << "press 3 to multiply"<< endl;
        cout << "press 4 to divide"<< endl;
        cout << "press 5 to End"<< endl;
        cin >> chos;
        if (chos > 5 || chos < 1)
        {
            std::cout << "Invlaid input" << std::endl;
        }
        else
        {
            flag = false;
        }
    }
    return chos;
}