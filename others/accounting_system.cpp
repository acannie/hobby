#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> num;
    int made = 0;
    vector<int> done;

    while (1)
    {
        while (1)
        {
            int new_num;
            cout << "Input num. --> ";
            cin >> new_num;

            if (isdigit(new_num) || new_num < 1 || find(done.begin(), done.end(), new_num) != done.end())
            {
                cout << "Error! Input integer again." << endl;
            }
            else
            {
                num.push_back(new_num);
                done.push_back(new_num);
                break;
            }
        }

        sort(num.begin(), num.end());

        while (*(num.begin()) == made + 1)
        {
            num.erase(num.begin());
            made++;
        }

        if (made > 0)
        {
            cout << "No." << made << " made no kata." << endl;
        }

        for (auto it = num.begin(); it != num.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl
             << endl;
    }

    return 0;
}