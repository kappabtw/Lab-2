#include "zeroevent.h"
#include "arr.cpp"

zeroevent::zeroevent(string ename):event(ename, 0)
{   
    num++;
    arr2 = new string[num];
    for (int i = 0; i < (num - 1); i++)
    {
        arr2[i] = arr[i];
    }
    arr2[num - 1] = name;
    delete[] arr;
    arr = arr2;
}