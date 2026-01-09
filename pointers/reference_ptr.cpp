#include <iostream>
using namespace std;

/*
1000 = qwe;
1001 = rty;
1002, *ptr_qwe = &qwe // 1000 so it ref 5
1003, *ptr_qwe = &rty //  1001 so it ref 8

Address | Value
1000    | 5
1001    | 8
1003    | 1000 // if point, it'll be 5
1004    | 1001 // if we point, it'll be back 8
1005    |

let's say int *ptr_qwe = &qwe;
*ptr_qwe value will be 1001 in this instance

*/

void swap(int &a, int &b)
{ // we passed in 0x1001 and 0x1001, now the 0x1000 location is treated same as qwe and 0x1001 as rty, this is what they meant by references
    int temp = b;
    a = b;
    b = temp;
};

int main()
{
    int qwe = 5, rty = 8; // 1000 with 5, 1001 with 8
    cout << "Original Value: ";
    cout << qwe << " " << rty << endl; 

    int &ref1 = qwe; // ref, 1000
    int &ref2 = rty; // ref, 1001

    int *ptr_qwe = &qwe; // pointer, 1000 
    int *ptr_rty = &rty; // pointer, 1001 

    cout << "Memory Location Value: ";
    cout << &qwe << " " << &rty << endl;

    cout << "Pointer Location Value: "; // expect 1
    cout << ptr_qwe << " " << ptr_rty << endl; // now I have the memory address of qwe and rty

    cout << "References Value Location Value: ";
    cout << *ptr_qwe << " " << *ptr_rty << endl; // now I point toward to the reference of qwe and rty

    ref1++;
    ref2++;

    cout << "Original Value: ";
    cout << qwe << " " << rty << endl;

    // assume qwe location is 0x1000 and assume rty is 0x1001
    swap(qwe, rty); // now we pass in 0x1000 and 0x1001 into this swap.

    return 0;
}
