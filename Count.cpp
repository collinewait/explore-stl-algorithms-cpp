#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v{2, 7, 1, 6, 2, -2, 4, 0};

    // count how many entries have the target value (2)
    int twos = 0;
    int const target = 2;
    for(size_t i = 0; i < v.size(); i++)
    {
        if (v[i] == target)
        {
            twos++;
        }
    }
    cout << twos << endl;

    twos = count(v.begin(), v.end(), target); // better than for loop
    cout << twos << endl;
    twos = count(v.begin(), v.end(), target); // the safes choice and a good habit
    cout << twos << endl;

    return 0;
}
