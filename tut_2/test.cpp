bool findLeapYear(int year){
    if (year % 4 != 0)
    {
        return false;
    };
    if (year % 100 !=0 )
    {
        return true;
    };
    if (year % 400 != 0)
    {
        return false;
    };
    return true;
}

int main()
{
    cout<<findLeapYear(2024)<<endl;
    return 0;
}
