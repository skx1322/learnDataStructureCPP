#include <iostream>
using namespace std;

const int array_size = 10;

//Swap Function, Argument integer one and integer two
void swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

// Bubble sorting function here
void bubble_sort(int *numbers)
{
    bool is_swapped;
    for (int i = 0; i < array_size; i++)
    {
        is_swapped = false;
        for (int j = 0; j < array_size - i - 1; j++) // minus i and 1 because we are checking two array at once
        {
            if (numbers[j] > numbers[j + 1]) // if current array is larger than an array ahead then they swap
            {
                swap(numbers[j], numbers[j + 1]);
                is_swapped = true;
            }
        }
        if (!is_swapped)
        {
            break;
        }
        
    }
}

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
    int sample_number[array_size] = {6, 42, 65, 34, 12, 8, 41, 7, 42, 24};

    bubble_sort(sample_number);

    display_array(sample_number);
    return 0;
}