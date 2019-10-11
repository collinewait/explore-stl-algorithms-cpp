#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> a{ 1, 2, 3, 4, 5 };
    vector<int> b{ 1, 2, 0, 4 };

    bool same = a.size()==b.size();
    for(size_t i = 0; i < a.size() && same; i++)
    {
        if (a[i] != b[i])
        {
            same = false;
        }
    }
    cout << "same: " << same << endl;

    same = equal(begin(a), end(a), begin(b), end(b)); // better than the for loop
    cout << "same: " << same << endl;

    auto firstchange = mismatch(begin(a), end(a), begin(b));
    int avalue = *(firstchange.first);
    cout << "avalue: " << avalue << endl;
    int bvalue = *(firstchange.second);
    cout << "bvalue: " << bvalue << endl;

    auto distance = firstchange.first - begin(a); // getting how long the collection stayed the same
    cout << "distance: " << distance << endl;

    return 0;
}