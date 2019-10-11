#include <vector>
#include <iostream>
#include <string>
#include <numeric>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

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

    int total = 0;
    for (int i : a)
    {
        total +=1;
    } 
    cout << "total: " << total << endl;

    total = accumulate(begin(a), end(a), 0);
    cout << "total: " << total << endl;
    total = accumulate(begin(a), end(a), 0,
        [](int total, int i){if (i%2) return total + i; return total;});
    cout << "total: " << total << endl;
    total = accumulate(begin(a), end(a), 1,
        [](int total, int i){return total * i;});
    cout << "total: " << total << endl;

    vector<string> words{ "one", "two", "three" };
    auto allwords = accumulate(begin(words), end(words), string{});
    cout << "allwords: " << allwords << endl;
    int length = allwords.size();
    cout << "length: " << length << endl;
    allwords = accumulate(begin(words), end(words), string{"words:"}, [](const string& total, string& s){ return total + " " + s; });
    cout << "allwords: " << allwords << endl;
    length = allwords.size();
    cout << "length: " << length << endl;

    string s = accumulate(begin(a), end(a), string{"The numbers are:"},
        [](const string& total, int i){return total + " " + to_string(i);});
    cout << "s: " << s << endl;

    b = a;
    for (auto it = begin(b); it != end(b); it++)
    {
        *it = 0;
    }

    for (auto& i : b)
    {
        i = 1;
    }

    for_each(begin(b), end(b), [](int& elem){ elem = 2; });

    b = a;
    auto firstthree = find(begin(b), end(b), 3);
    for_each(firstthree, end(b), [](int& elem){ elem = 0; });

    return 0;
}