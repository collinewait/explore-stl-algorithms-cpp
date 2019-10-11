#include <vector>
#include <deque>
#include <numeric>
#include <string>

using std::vector;
using std::deque;
using std::string;

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

    return 0;
}