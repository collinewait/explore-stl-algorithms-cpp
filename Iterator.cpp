#include <vector>
#include <deque>
#include <numeric>
#include <string>
#include <iostream>
#include <array>

using std::vector;
using std::deque;
using std::string;
using std::cout;
using std::endl;
using std::array;

int main()
{
    vector<int> v1(10);
    fill(begin(v1), end(v1), 1);
    fill_n(begin(v1), 6, 2);
    iota(begin(v1), end(v1), 1);

    vector<int> v2;
    fill_n(back_inserter(v2), 6, 2);
    generate_n(back_inserter(v2), 10, [n = 0]()mutable{ return n++; });

    deque<int> q3;
    fill_n(front_inserter(q3), 6, 2);
    generate_n(front_inserter(q3), 10, [n = 0]()mutable{ return n++; });

    // fill_n(front_inserter(v2), 6, 2); // front_inserter doesn't work with vectors

    v2.clear();
    transform(begin(v1), end(v1), back_inserter(v2),
        [](int elem){ return elem * 2; });

    vector<int> v3{ 3, 6, 1, 0, -2, 5 };
    vector<int> v5;
    copy_if(begin(v3), end(v3), back_inserter(v5),
        [](int elem){ return elem % 2 == 0; });

    v3[3] = -2;
    vector<int> v6;
    unique_copy(begin(v3), end(v3), back_inserter(v6));

    string sentence = "Hello world";
    string reverse;
    reverse_copy(begin(sentence), end(sentence), back_inserter(reverse));

    v2.clear();
    copy(rbegin(v1), rend(v1), back_inserter(v2));

    v1[5] = 2;
    auto two = find(begin(v1), end(v1), 2);
    auto distance = two - begin(v1);
    two++;

    auto rtwo = find(rbegin(v1), rend(v1), 2);
    distance = rtwo - rbegin(v1);
    rtwo++;

    auto three = find(begin(v1), end(v1), 3);
    bool firsthalf = (three - begin(v1) < end(v1) - three);
    cout << "firsthalf: " << firsthalf << endl;

    auto nine = find(begin(v1), end(v1), 9);
    firsthalf = (nine - begin(v1) < end(v1) - nine);
    cout << "firsthalf: " << firsthalf << endl;

    array<const int, 5> ca = { 3, 1, 6, 0, 2 };
    auto it = begin(ca);
    it++;
    // *it = 7;
    int i = *it;

    // vector<const int> vc; //compilation error
    it = std::find(begin(ca), end(ca), 1);
    it++;
    // *it = 7;
    // it = cbegin(ca);

    auto it2 = begin(v2);
    it2++;
    *it2 = 7;

    auto cit = cbegin(v2);
    cit++;
    // *cit = 7;

    return 0;
}