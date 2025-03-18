#include <iostream>
// محمدامین اسدی

int fibo_recur(int n)
{
    int fibo_number;
    if (n <= 1)
    {
        fibo_number = n;
    }
    else
    {
        fibo_number = fibo_recur(n - 2) + fibo_recur(n - 1);
    };
    return fibo_number;
}

int main()
{
    std::cout << "Enter number of fibo series wanted: " << std::endl;
    int n;
    std::cin >> n;
    std::cout << "Fibo series ==> ";
    for (int i = 1; i < n; i++)
    {
        int fibo = fibo_recur(i);
        std::cout << fibo << ", ";
    }
    int fibo = fibo_recur(n);
    std::cout << fibo << std::endl;
    return 0;
}
