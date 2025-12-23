#include <iostream>
using namespace std;

const int array_size = 10;

int find_highest(int *nums, int nums_size)
{
    int highest = nums[0];
    for (int i = 1; i < nums_size; i++)
    {
        if (nums[i] > highest)
        {
            highest = nums[i];
        }
    }
    return highest;
};

void count_sort(int *nums, int nums_size, int expo)
{
    int output[nums_size];
    int count[10] = {0};

    for (int i = 0; i < nums_size; i++)
    {
        count[(nums[i] / expo) % 10]++;
    };

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    };

    for (int i = nums_size - 1; i >= 0; i--)
    {
        int dim_index = (nums[i] / expo) % 10;
        output[count[dim_index] - 1] = nums[i];
        count[dim_index]--;
    };

    for (int i = 0; i < nums_size; i++)
    {
        nums[i] = output[i];
    };
}

void radix_sort(int *nums, int nums_size)
{
    int current_highest = find_highest(nums, nums_size);
    cout << current_exception << endl;
    for (int expo = 0; current_highest / expo > 0; expo *= 10)
    {
        cout << expo << endl;

        count_sort(nums, nums_size, expo);
    }
};

void display_array(int *numbers)
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