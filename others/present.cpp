#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num_present = 2;
    string present[num_present] = {"strawberries with white chocolate", "knife and stone"};

    for (int i = 0; i < num_present; i++)
    {
        cout << "you give me " << present[i] << endl;
    }

    return 0;
}