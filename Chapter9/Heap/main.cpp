// Heap
// Demonstrates dynamically allocating memory
#include <iostream>
using namespace std;
int *intOnHeap(); // returns an int on the heap
void leak1();     // creates a memory leak
void leak2();     // creates a different memory leak
int main()
{
    int *ptrHeap = new int;
    *ptrHeap = 10;
    cout << "*ptrHeap: [" << *ptrHeap << "]" << endl;
    int *ptrHeap2 = intOnHeap();
    cout << "*ptrHeap2: [" << *ptrHeap2 << "]" << endl;
    cout << "Freeing memory pointed to by ptrHeap." << endl;
    delete ptrHeap;
    cout << "Freeing memory pointed to by ptrHeap2." << endl;
    // Fix dangling pointers
    ptrHeap = 0;
    ptrHeap2 = 0;
    return 0;
}
int *intOnHeap()
{
    int *ptrTemp = new int(20);
    return ptrTemp;
}
void leak1()
{
    int *memoryDrip1 = new int(30);
}
void leak2()
{
    int *memoryDrip2 = new int(50);
    memoryDrip2 = new int(100);
    delete memoryDrip2;
}
