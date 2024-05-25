#include <iostream>
using namespace std;

class a{
    private:
    public:
        a()
        {
            cout << "A Constructor\n";
        }
        ~a()
        {
            cout << "A Distructor\n";
        }
};

class b{
    private:
    public:
        b()
        {
            cout << "B Constructor\n";
        }
        ~b()
        {
            cout << "B Distructor\n";
        }
};

class c{
    private:
    public:
        c()
        {
            cout << "C Constructor\n";
        }
        ~c()
        {
            cout << "C Distructor\n";
        }
};


class d{
    private:
        a aa;
        b bb;
        c cc;
    public:
	    d() : bb(b()), aa(a()), cc(c()){
		    cout<<"D Constructor\n";
	    }
	    ~d() {
		    cout<<"D Destructor\n";
	    }
};
int main(void)
{
    d();
    return 0;
}