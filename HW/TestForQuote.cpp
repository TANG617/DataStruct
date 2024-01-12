#include "include_test.h"
using namespace std;

// Function prototype. The parameter is a reference variable.
void doubleNum(int &SrefVar);

int main()
{
    int value = 4;
    cout << "In main, value is " << value << endl;
    cout << "Now calling doubleNum..." << endl;
    doubleNum(value);
    cout << "Now back in main, value is "<< value << endl;
    return 0;
}
