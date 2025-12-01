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
    const int day_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month < 1 || month > 12)
    {
        throw new range_error("Month can't be less than 1 or more than 12");
    };

    if (month == 2)
    {
        if (leapYearCheck(year))
        {
            return 29;
        } else {
            return 28;
        };
    };
    
    return day_month[month-1];
};

int main()
{
    cout << dayFinder(3, 2024) << endl;

    return 0;
}
