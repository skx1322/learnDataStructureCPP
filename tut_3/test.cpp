#include <iostream>
using namespace std;


bool leapYearCheck(int year)
{
    if (year % 4 != 0)
    {
        return false;
    };
    if (year % 100 != 0)
    {
        return true;
    };
    if (year % 400 != 0)
    {
        return false;
    };

    return true;
};

int dayFinder(int month, int year)
{
    if (month == 1 || month == 3 || month = 5 || month == 7 || month == 10 || month == 12)
    {
        return 31;
    };
    if (month == 4 || month == 6 || month = 7 || month == 8 || month == 9 || month == 11)
    {
        return 30;
    };
    if (month == 2)
    {
        if (leapYearCheck(year))
        {
            return 29;
        }
        return 28;
    }
    
    throw new range_error("Month can't be less than 1 or more than 12");
};


int main()
{
    cout <<dayFinder(2, 2024) << endl;

    return 0;
}
