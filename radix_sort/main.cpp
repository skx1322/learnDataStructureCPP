#include <iostream>
using namespace std;

const int array_size = 10;

int find_highest(int *nums, int nums_size)
{
    int highest = nums[0]; // {2804, 2723, 3369, 4425, 1920, 4423, 4291, 1649, 6877, 4536}
    for (int i = 1; i < nums_size; i++) 
    {
        if (nums[i] > highest) // 1st cycle, [1], is 2723 > 2804?, nope, next until 6877 is the highest
        {
            highest = nums[i]; // 
        }
    }
    return highest;
};

void count_sort(int *nums, int nums_size, int expo)
{
    int output[nums_size]; // placeholder output
    int i, count[10] = {0}; 

    for (i = 0; i < nums_size; i++) // 9 < 10
    {
        count[(nums[i] / expo) % 10]++; // 1st cycle, find 1st decimal, for example if 2804, we will divide it by 1 then module by 10 which remain 4 then 2nd cycle 2723 remainder will be 3 when expo = 1
        cout<<(nums[i] / expo) % 10<<endl;
        // 5, 4, 10, 6, 1, 3, 2, 10, 8
    };                                             

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1]; // set i as 0, 1st cycle, count[1] += count[0]
    };

    for (i = nums_size - 1; i >= 0; i--)
    {
        output[count[(nums[i] / expo ) % 10] - 1] = nums[i]; // rearrange output based from the remainder with the num
        count[(nums[i] / expo) % 10]--; //
    };

    for (i = 0; i < nums_size; i++)
    {
        nums[i] = output[i]; // resort back to original array
    };
}

void radix_sort(int *nums, int nums_size)
{
    int current_highest = find_highest(nums, nums_size); // return highest size of the nums array, this is to limit the expo to stop the bottom loop if the expo is bigger than the highest number for exampple our limit is 6877 and if expo is 10000, we will stop
    for (int expo = 1; current_highest / expo > 0; expo *= 10) // for expo, 1st cycle, 1 then 10, then 100, 1000, stop when the loop is at decimal
    {
        count_sort(nums, nums_size, expo);
    }
};

void display_array(int numbers[])
{
    for (int i = 0; i < array_size; i++)
    {
        cout << numbers[i] << ", ";
    };
    cout << endl;
}

int main()
{
    int sample_data[array_size] = {2804, 2723, 3369, 4425, 1920, 4423, 4291, 1649, 6877, 4536};

    radix_sort(sample_data, array_size); 

    display_array(sample_data);

    return 0;
}