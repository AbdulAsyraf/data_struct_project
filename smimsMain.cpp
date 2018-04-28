#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "smims.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Info f;
    for (int i = 0; i < 1; i++)     //loop for test
    {
        f.addEntry();
    }
    f.showList();
    f.saveList();
}