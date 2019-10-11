#include <iostream>
#include <vector>
#include <numeric>

using std::cout;
using std::endl;
using std::vector;
using std::swap;

int main()
{
    int a{ 4 }, b{ 5 };
    swap(a, b);

    vector<int> evens{ 2, 4, 6, 8, 10 };
    vector<int> odds{ 1, 3, 5, 7, 9 };

    auto v1 = evens;
    swap(v1[0], v1[1]);
    cout << "after swap: " << v1[0] << " " << v1[1] << endl;
    iter_swap(begin(v1), begin(v1)+1);
    cout << "after swap: " << v1[0] << " " << v1[1] << endl;

    auto v2 = odds;
    swap(v1[0], v2[0]);
    iter_swap(begin(v1), find(begin(v2), end(v2), 5));

    v1 = evens;
    v2 = odds;

    swap_ranges(begin(v1), find(begin(v1), end(v1), 6), begin(v2));

    vector<int> tasks(6);
    iota(begin(tasks), end(tasks), 1);
    auto two = find(begin(tasks), end(tasks), 2);
    auto four = find(begin(tasks), end(tasks), 4);
    rotate(two, four, four+1);

}