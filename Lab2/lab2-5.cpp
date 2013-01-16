#include <iostream>
#include <string>
using namespace std;
void f();
void g();
int x = 11;
int main() {
    int x = 22;
    {
        int x = 33;
        cout << "In block inside main(): x = " << x << endl;
    }
    cout << "In main(): x = " << x << endl;
    cout << "In main(): ::x = " << ::x << endl;
    f();
    g();
    return 0;
}

void f()
{
    int x = 44;
    cout << "In f(): x = " << x << endl;
}

void g()
{
    cout << "In g(): x = " << x << endl;
}
