#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// files
#define USERS_FILE "users.txt"
#define USERS_Count_FILE "users_count.txt"
#define QUESTIONS_FILE "questions.txt"
#define TEMP_FILE      "temp.txt"

//Question define
#define AQ       0
struct Users{
    pair<int,pair<string,int>> user;
    int id;
    int SUM;
    Users()
    {
        ifstream fin(USERS_Count_FILE);
        if (fin.fail())
        {
            cout << "Fail to open file";
        }
        string line;
        if (getline(fin,line))
        {
            istringstream iss(line);
            iss >> SUM;
        }
        else
        {
            ofstream fout(USERS_Count_FILE);
            if (fout.fail())
            {
                cout << "Fail to open file";
            }
            fout << 0;
            fout.close();
        }
        fin.close();
    }
    int Add_New(void)
    {
        while(true)
        {
            ifstream fout(USERS_FILE);
            if (fout.fail())
            {
                cout << "Can't open the file\n";
                return 1;
            }
            fout.seekg(0,ios::beg);
            string Line;
            int id;
            int pass;
            bool flag = true;
            string name = "";
            cout << "Enter user name & password: ";
            cin >> user.second.first;
            cin >> user.second.second;
            id = 0;
            while (getline(fout,Line))
            {
                istringstream iss(Line);
                iss >> id >> name >>pass;
                if (name == user.second.first)
                {
                    cout << "User is Exist Try again\n";
                    fout.close();
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                SUM++;
                id++;
                fout.close();
                ofstream fin(USERS_FILE,ios::app);
                if (fin.fail())
                {
                    cout << "Can't open the file\n";
                    return 1;
                }
                fin << id << " "<< user.second.first << " " << 
                user.second.second << endl; 
                cout << "User Registeried Successfully\n";
                fin.close();
                ofstream fout_2(USERS_Count_FILE);
                if (fout_2.fail())
                {
                    cout << "Fail to open file";
                }
                fout_2 << SUM;
                fout_2.close();
                break;
            }
        }
    }
    int Print_All(void)
    {
        int id;
        string name;
        bool flag = false;
        string line;
        ifstream fout(USERS_FILE);
        if (fout.fail())
        {
            cout << "Can't open the file\n";
            return 1;
        }
        cout << "Users List:\n";
        while(getline(fout,line))
        {
            flag = true;
            istringstream iss(line);
            iss >> id >> name;
            cout << "\tUser ID: " <<id<< " User Name: "<< name << endl;
        }
        if(!flag)
        {
            cout << "\tNo Users Found";
        }
        return 0;
    }
    int Login(void)
    {
        int pass;
        string name;
        bool name_flag = false;
        bool pass_flag = false;
        cout << "Enter user name & password: ";
        cin >> user.second.first >> user.second.second;
        string line;
        ifstream fout(USERS_FILE);
        if (fout.fail())
        {
            cout << "Can't open the file\n";
            return 1;
        }
        while(getline(fout,line))
        {
            istringstream iss(line);
            iss >> id >> name >> pass;
            if (name == user.second.first)
            {
                name_flag = true;
                break;
            }
        }
        if (name_flag == false)
        {
            cout << "Name not registeried\n";
            return 0;
        }
        int count = 3;
        while (count--)
        {
            if (pass == user.second.second)
            {
                cout << "Welcome : " << user.second.first<<endl;
                pass_flag = true;
                break;
            }
            if (count)
            {   cout << "Password wrong try Again " << count << " Trials remains!!\n";
                cout << "Enter Your password: ";
                cin >> user.second.second;
            }
        }
        if (!pass_flag)
           return 1;
        else
           return 0;
    }
};
struct Question{
    int id;
    int parent;
    int from;
    int to;
    string que;
    string ans;
    int max_id;
    ifstream OPEN_FILE_READ(string FILE_NAME)
    {
        ifstream fin(FILE_NAME);
        if (fin.fail())
        {
            cout << "Can't open the file\n";
        }
        return fin;
    }
    ofstream OPEN_FILE_WRITE(string FILE_NAME)
    {
        ofstream fout(FILE_NAME);
        if (fout.fail())
        {
            cout << "Can't open the file\n";
        }
        return fout;
    }
    ofstream OPEN_FILE_APPEND(string FILE_NAME)
    {
        ofstream fout(FILE_NAME,ios::app);
        if (fout.fail())
        {
            cout << "Can't open the file\n";
        }
        return fout;
    }
    Question()
    {
        ifstream fin = OPEN_FILE_READ(QUESTIONS_FILE);
        string line;
        if (getline(fin,line))
        {
            istringstream iss(line);
            iss >> max_id;
            fin.close();
        }
        else
        {
            fin.close();
            ofstream fout = OPEN_FILE_WRITE(QUESTIONS_FILE);
            fout << 100 << "\n";
            fout.close();
        }
    }
    void ASK_Question(int user_id)
    {
        int thread;
        int to;
        string question;
        cout << "Enter User id or -1 to cancel: ";
        cin >> to;
        if (to == -1)
            return;
        if (to > Users().SUM)
        {
            cout << "USER NOT EXIST";
            return;
        }
        cout << "For thread question: Enter Question id or for new question -1: ";
        cin >> thread;
        int anom = 1;
        if (thread != -1)
        {
            cout << "For Anonymous Choose press 0: ";
            cin >> anom;
        }
        cout << "Enter question text: ";
        cin.ignore(256, '\n');
        getline(cin,question);
        int max;
        string line;
        ofstream fout = OPEN_FILE_WRITE(TEMP_FILE);
        ifstream fin  = OPEN_FILE_READ(QUESTIONS_FILE);
        getline(fin,line);
        istringstream iss(line);
        iss >> max;
        id = max;
        max++;
        fout << max << endl;
        if (thread == -1)
        {
            while(getline(fin,line))
            {
                fout << line << endl;
            }
            fin.close();
            fout.close();
            ofstream fout_2 = OPEN_FILE_WRITE(QUESTIONS_FILE);
            ifstream fin_2  = OPEN_FILE_READ(TEMP_FILE);
            while(getline(fin_2,line))
            {
                fout_2 << line << endl;
            }
            fout_2 << id << " " <<0 << " "<<user_id <<" " <<to << " "<< question << '~'<< "NOTANS" << '~';   
            fout_2.close();
            fin_2.close();
        }    
        else
        {
            int flag = true;
            // go until reach question
            while(getline(fin,line))
            {
                int current;
                istringstream iss(line);
                iss >> current >> parent;
                fout << line << endl;
                if (thread == current)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << "Question ID not found\n";
                return;
            }
            // go through all threads
            while(getline(fin,line))
            {
                int current;
                istringstream iss(line);
                iss >> current >> parent;
                if (thread == parent)
                {
                    fout << line << endl;
                }
                else
                {
                    break;
                }
            }
            // add thread to file
            if (anom == 0)
                fout << id << " " << thread << " "<<0 <<" " <<to << " "<< question << '~'<< "NOTANS" << '~' << endl;
            else
                fout << id << " " << thread << " "<<user_id <<" " <<to << " "<< question << '~'<< "NOTANS" << '~' << endl;
            // // add LINE to file
            fout << line << endl;
            // go until END question
            while(getline(fin,line))
            {
                fout << line << endl;
            }
            // copy from temp to question
            ofstream fout_2 = OPEN_FILE_WRITE(QUESTIONS_FILE);
            ifstream fin_2  = OPEN_FILE_READ(TEMP_FILE);
            while(getline(fin_2,line))
            {
                fout_2 << line << endl;
            }
            fout_2.close();
            fin_2.close();
        }
    }
    void DEL_Question(int user_id)
    {
        cout << "Enter Question ID or -1 to Cancel: ";
        cin >> id;
        ifstream fin  = OPEN_FILE_READ(QUESTIONS_FILE);
        ofstream fout = OPEN_FILE_WRITE(TEMP_FILE);
        string line;
        bool found = false;
        while (getline(fin,line))
        {
            istringstream iss(line);
            int Current_ID;
            int Current_Parent;
            iss >> Current_ID >> Current_Parent >> from;
            if (Current_ID == id && Current_Parent == 0 && from == user_id)
            {
                found = true;
                continue;
            }
            if (found && Current_Parent == id)
            {
                continue;
            }
            fout << line << endl;
        }
        fin.close();
        fout.close();
        ifstream fin_2  = OPEN_FILE_READ(TEMP_FILE);
        ofstream fout_2 = OPEN_FILE_WRITE(QUESTIONS_FILE);
        while(getline(fin_2,line))
        {
            fout_2 << line << endl;
        }
        fin_2.close();
        fout_2.close();
    }
    void ANS_Question(int user_id)
    {
        cout << "USER: " << user_id<<endl; 
        cout << "Enter Question ID or -1 to Cancel: ";
        cin >> id;
        ifstream fin  = OPEN_FILE_READ(QUESTIONS_FILE);
        ofstream fout = OPEN_FILE_WRITE(TEMP_FILE);
        string line;
        getline(fin,line);
        fout << line <<endl;
        while (getline(fin,line))
        {
            istringstream iss(line);
            int Current_ID;
            int to;
            iss >> Current_ID >> parent >> from >> to;
            if (Current_ID == id && to == user_id )
            {
                getline(iss,que,'~');
                getline(iss,ans,'~');
                if (ans != "NOTANS")
                {
                    cout << "Warning answer will be modified\n";
                }
                cout << "Enter Answer: ";
                cin.ignore();
                getline(cin,ans);
                cout << Current_ID;
                cout << parent;
                cout << from;
                cout << to;
                cout << que;
                fout << Current_ID << " " << parent << " " << from << " " << to  << que <<'~'<< ans<<'~'<<endl;
            }
            else
            {
                fout << line << endl;
            }
        }
        ifstream fin_2  = OPEN_FILE_READ(TEMP_FILE);
        ofstream fout_2 = OPEN_FILE_WRITE(QUESTIONS_FILE);
        while(getline(fin_2,line))
        {
            fout_2 << line << endl;
        }
        fin_2.close();
        fout_2.close();
    }
    void Feed_ALL(void)
    {
        ifstream fin = OPEN_FILE_READ(QUESTIONS_FILE);
        string line;
        getline(fin,line);
        while(getline(fin,line))
        {
            istringstream iss(line);
            iss >> id >> parent >> from >> to;
            getline(iss,que,'~');
            getline(iss,ans,'~');
            if (parent == 0)
            {
                cout << "Question ID (";
            }
            else
            {
                cout << "Thread Parent Question ID (";
            }
            cout << id << ") from ";
            if (from == 0)
            {
                cout << "!AQ ";
            }
            else
            {
                cout << "From user ID (" << from<< ") ";
            }
            cout << "To user ID (" << to << ") \tQuestion: " <<que <<endl;
            if (ans != "NOTANS")
                cout <<"\tAnswer: " << ans<<endl;
        }
    }
    void Print_From_ME(int user_id)
    {
        ifstream fin = OPEN_FILE_READ(QUESTIONS_FILE);
        string line;
        getline(fin,line);
        while(getline(fin,line))
        {
            istringstream iss(line);
            iss >> id >> parent >> from >> to;
            getline(iss,que,'~');
            getline(iss,ans,'~');
            if (user_id != from)
                continue;
            if (parent == 0)
            {
                cout << "Question ID (";
            }
            else
            {
                cout << "Thread Parent Question ID (";
            }
            cout << id << ") from ";
            if (from == 0)
            {
                cout << "!AQ ";
            }
            else
            {
                cout << "From user ID (" << from<< ") ";
            }
            cout << "To user ID (" << to << ") \tQuestion: " <<que <<endl;
            if (ans != "NOTANS")
                cout <<"\tAnswer: " << ans<<endl;
        }     
    }
    void Print_TO_ME(int user_id)
    {
        ifstream fin = OPEN_FILE_READ(QUESTIONS_FILE);
        string line;
        getline(fin,line);
        while(getline(fin,line))
        {
            istringstream iss(line);
            iss >> id >> parent >> from >> to;
            getline(iss,que,'~');
            getline(iss,ans,'~');
            if (user_id != to)
                continue;
            if (parent == 0)
            {
                cout << "Question ID (";
            }
            else
            {
                cout << "Thread Parent Question ID (";
            }
            cout << id << ") from ";
            if (from == 0)
            {
                cout << "!AQ ";
            }
            else
            {
                cout << "From user ID (" << from<< ") ";
            }
            cout << "To user ID (" << to << ") \tQuestion: " <<que <<endl;
            if (ans != "NOTANS")
                cout <<"\tAnswer: " << ans<<endl;
        }     
    }
    
};



struct Ask_system{
    Users user;
    Question ques;
    Ask_system(){
        int flag = 1;
        while (flag)
        {
            int x = login_menu();
            if (x == 1)
            {
               flag = user.Login();
            }
            else if (x == 2)
            {
               user.Add_New();
            }
        }
        while (true)
        {
            int x = show_menu();
            if (flag == 0)
            {
                if (x == 1)
                    ques.Print_TO_ME(user.id);
                else if (x == 2)
                    ques.Print_From_ME(user.id);
                else if (x == 3)
                    ques.ANS_Question(user.id);
                else if (x == 4)
                    ques.DEL_Question(user.id);
                else if (x == 5)
                    ques.ASK_Question(user.id);
                else if (x == 6)
                    user.Print_All();
                else if (x == 7)
                    ques.Feed_ALL();
                else if (x == 8)
                    break;
            }
        }
            
    }
    int login_menu(void){
        int choice = -1;
        cout << "Menu:\n";
        cout << "\t1: Login\n";
        cout << "\t2: Sign Up\n";
        while (true)
        {
            cout << "Enter number in range 1 - 2: ";
            cin >> choice;
            if (choice >= 1 && choice <= 2)
                break;
            cout << "Wrong choice...Try Again\n";
        }
    }
    int show_menu(void)
    {
        int choice = -1;
        cout << "Menu:\n";
        cout << "\t1: Print Question To Me\n";
        cout << "\t2: Print Question From Me\n";
        cout << "\t3: Answer Question\n";
        cout << "\t4: Delete Question\n";
        cout << "\t5: Ask Question\n";
        cout << "\t6: List System Users\n";
        cout << "\t7: Feed\n";
        cout << "\t8: Logout\n";
        while (true)
        {
            cout << "Enter number in range 1 - 8: ";
            cin >> choice;
            if (choice >= 1 && choice <= 8)
                break;
            cout << "Wrong choice...Try Again\n";
        }
        return choice;
    }
};



int main(void)
{
    Ask_system();
    return 0;
}