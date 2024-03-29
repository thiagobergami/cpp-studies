#include <iostream>

using namespace std;

int *intOnHeap();
void leak1();
void leak2();

int main()
{
    int *pHeap = new int;
    *pHeap = 10;
    cout << "*pHeap: " << *pHeap << "\n\n";

    int *pHeap2 = intOnHeap();
    cout << "*pHeap2: " << *pHeap2 << "\n\n";

    cout << "Freeing memory pointed to by pHeap. \n\n";
    delete pHeap;

    cout << "Freeing memory pointed to by pHeap2. \n\n";
    // Unlike storage for local variables on the stack, memory that you've allocated on the heap must be explicitly freed.
    delete pHeap2;
    // get rid of dangling pointers
    pHeap = 0;
    pHeap2 = 0;

    return 0;
}

void leak1()
{   
    //In this section, whe a leaking the memory, since there is no way to access this data before executed.
    int *drip1 = new int(30);
}
void leak2()
{   
    //The leak here is caused by the new value of drip2. when assigned by 100, the memory allocated to 50 is lost.
    int *drip2 = new int(50);
    drip2 = new int(100);
    delete drip2;
}
int *intOnHeap()
{
    int *pTemp = new int(20);
    return pTemp;
}