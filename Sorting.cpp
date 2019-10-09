#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v{ 4, 1, 0, 1, -2, 3, 7, -6, 2, 0, 0, -9, 9 };
    auto v2 = v;
    sort(begin(v2), end(v2));
    sort(begin(v2), end(v2),
        [](int elem1, int elem2){return elem1 > elem2;});
    sort(begin(v2), end(v2),
        [](int elem1, int elem2){return abs(elem1) > abs(elem2);});

    return 0;
}