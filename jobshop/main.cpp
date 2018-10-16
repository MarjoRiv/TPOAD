#include <iostream>
#include "instance.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Data D;
    lecture_instance(D);
    cout << D.get_m();
    return 0;
}
