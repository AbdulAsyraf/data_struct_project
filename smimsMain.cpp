#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "smims.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Info f;
    f.readExisting();
    for (int i = 0; i < 3; i++)     //loop for test
    {
        f.addEntry();
    }
    f.saveList();
    f.showList();
}