#include <iostream>
#include <conio.h>
#include <vector>
// محمدامین اسدی
using namespace std;

void print_array(vector<int>);
bool are_queens_friends(vector<int>);
vector<int> reroute_current_rows(vector<int>, int);
vector<int> set_peace_for_queens(int, vector<int>);
main()
{
    system("cls");
    int n = 20;
    int initial_row = 1;
    vector<int> queens_rows = {initial_row};
    queens_rows = set_peace_for_queens(n, queens_rows);
    cout << "Stable positioning is found successfully:\n\n";
    print_array(queens_rows);
    getch();
}
void print_array(vector<int> array)
{
    for (auto r : array)
    {
        cout << r << ' ';
    }
    cout << endl;
}
vector<int> set_peace_for_queens(int n, vector<int> queens_rows)
{
    int r = 1;
    while (queens_rows.size() < n)
    {
        queens_rows.push_back(r);
        if (!are_queens_friends(queens_rows))
        {
            queens_rows = reroute_current_rows(queens_rows, n);
        }
        system("cls");
    }
    return queens_rows;
}
vector<int> reroute_current_rows(vector<int> queens_rows, int n)
{
    if (queens_rows.at(queens_rows.size() - 1) < n)
        queens_rows.at(queens_rows.size() - 1) += 1;
    else
    {
        queens_rows.pop_back();
        queens_rows = reroute_current_rows(queens_rows, n);
    }
    // system("cls");
    print_array(queens_rows);
    if (are_queens_friends(queens_rows))
        return queens_rows;
    else
        return reroute_current_rows(queens_rows, n);
}

bool are_queens_friends(vector<int> queens_rows)
{
    int first_queen_row = queens_rows[0];
    if (queens_rows.size() > 1)
    {
        for (int i = 1; i < queens_rows.size(); i++)
        {
            int ith_queen = queens_rows[i];
            if (ith_queen == first_queen_row)
                return false;
            if ((ith_queen == first_queen_row + i || ith_queen == first_queen_row - i))
                return false;
        }
    }
    else
    {
        return true;
    }
    queens_rows.erase(queens_rows.begin());
    return are_queens_friends(queens_rows);
}
