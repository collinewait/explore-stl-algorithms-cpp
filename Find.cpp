#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    vector<int> v{ 4, 6, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4 };
    string s{ "Hello I am a sentence" };

    // find the first zero in the collection
    auto result = find(begin(v), end(v), 0);
    int weLookedFor = *result;
    cout << " find weLookedFor: " << weLookedFor << endl;

    // find the first 2 after 0
    result = find(result, end(v), 2);
    if (result != end(v))
    {
        weLookedFor = *result;
    }
    cout << "find weLookedFor: " << weLookedFor << endl;

    // find the first a
    auto letter = find(begin(s), end(s), 'a');
    char a = *letter;
    cout << "find a: " << a << endl;

    // find first odd value
    result = find_if(begin(v), end(v), [](auto elem) {return elem % 2 != 0;});
    weLookedFor = *result;
    cout << "find_if weLookedFor: " << weLookedFor << endl;

    // find first event value
    result = find_if_not(begin(v), end(v), [](auto elem) {return elem % 2 != 0;});
    weLookedFor = *result;
    cout << "find_if_not weLookedFor: " << weLookedFor << endl;

    vector<int> primes{ 1, 2, 3, 5, 7, 11, 13 };
    result = find_first_of(begin(v), end(v), begin(primes), end(primes));
    weLookedFor = *result;
    cout << "find_first_of weLookedFor: " << weLookedFor << endl;

    vector<int> sequence{ 2, 4 };
    result = search(begin(v), end(v), begin(sequence), end(sequence));
    weLookedFor = *result;
    cout << "search weLookedFor: " << weLookedFor << endl;
    result++; result++;
    int six = *result;

    string am = "am";
    letter = search(begin(s), end(s), begin(am), end(am));
    a = *letter;
    cout << "search a: " << a << endl;

    result = find_end(begin(v), end(v), begin(sequence), end(sequence));
    result++; result++;
    if (result != end(v))
    {
        weLookedFor = *result;
    }

    result = search_n(begin(v), end(v), 2, 4);
    result--;
    int two = *result;

    result = adjacent_find(begin(v), end(v));
    six = *result;
    result++;
    six = *result;

    return 0;
}