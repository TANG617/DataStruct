#include<iostream>
using namespace std;
class TestForPTR
{
private:
    
public:
    TestForPTR();
    ~TestForPTR();
    int a;
    int b;
};

TestForPTR::TestForPTR()
{

}

TestForPTR::~TestForPTR()
{
}


int main()
{
    TestForPTR anything;
    TestForPTR anything2;
    anything.a=10;
    anything.b=10;
    anything2.a=10;
    anything2.b=10;
    cout<<&anything.a<<endl<<&anything.b<<endl;
    cout<<&anything2.a<<endl<<&anything2.b;


}