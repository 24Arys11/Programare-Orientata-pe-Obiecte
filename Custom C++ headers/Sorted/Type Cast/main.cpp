#include <iostream>
#include "type_cast.h"

using namespace std;
using namespace dtk;

int main()
{
    cout << "strToInt(\"5\") = " << strToInt("5") << endl;
    cout << "strToDouble(\"5.3\") = " << strToDouble("5.3") << endl;
    cout << "intToString(5) = " << intToString(5) << endl;
    cout << "doubleToString(5.3) = " << doubleToString(5.3) << endl;

    return 0;
}
