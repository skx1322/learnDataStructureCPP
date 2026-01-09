#include <iostream>
using namespace std;

int binary_search(int arr[], int target, int size);

int main(){
    const int max_size = 7;
    int data[max_size] = {1, 2, 3, 4, 5, 6, 7};

    cout<<binary_search(data, 7, max_size)<<endl;

    return 0;
}

int binary_search(int arr[], int target, int size){
    int start = 0;
    int last = size - 1;
    while (start < last)
    {
        int center = start + (last + start) / 2;
        if (arr[center] == target)
        {
            return center;
        }
        else if (arr[center] < target){
            start++;
        } else {
            last--;
        }
    }
    return -1;
};