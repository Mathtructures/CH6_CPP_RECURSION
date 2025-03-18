#include <iostream>

using namespace std;

bool is_mirror(string str)
{
    int length = str.length();
    if (length > 1)
    {
        char first = str[0];
        char last = str[length - 1];
        if (first != last)
        {
            return false;
        }
        str.erase(length - 1, 1);
        str.erase(0, 1);
        return is_mirror(str);
    }
    else
    {
        return true;
    }
    return true;
}

main()
{
    string str;
    cin >> str;
    cout << is_mirror(str);
}