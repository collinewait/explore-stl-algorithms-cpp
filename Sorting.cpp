#include <vector>
#include "Employee.h"
#include <iostream>
#include <random>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::random_device;
using std::mt19937;

int main()
{
    vector<int> v{ 4, 1, 0, 1, -2, 3, 7, -6, 2, 0, 0, -9, 9 };
    auto v2 = v;
    sort(begin(v2), end(v2));
    sort(begin(v2), end(v2),
        [](int elem1, int elem2){return elem1 > elem2;});
    sort(begin(v2), end(v2),
        [](int elem1, int elem2){return abs(elem1) > abs(elem2);});

    vector<Employee> staff{
        { "Colline", "Wait", 1000 },
        { "some", "name", 2000 },
        { "other", "someamen", 1000 },
        { "mary", "hope", 2000 },
        { "bucky", "pucky", 2000 }
    };

    // sort(begin(staff), end(stuff)); // - only works if operator < is defined for Employee

    sort(begin(staff), end(staff),
        [](Employee e1, Employee e2){ return e1.getSalary() < e2.getSalary(); });
    sort(begin(staff), end(staff),
        [](Employee e1, Employee e2){ return e1.getSortingName() < e2.getSortingName(); });

    stable_sort(begin(staff), end(staff),
        [](Employee e1, Employee e2){ return e1.getSalary() < e2.getSalary(); });

    auto sorted = is_sorted(begin(v2), end(v2));
    cout << "sorted? " << sorted << endl;
    sorted = is_sorted(begin(v2), end(v2), [](int elem1, int elem2){ return abs(elem1) > abs(elem2); });
    cout << "sorted? " << sorted << endl;

    int high = *(max_element(begin(v), end(v)));
    cout << "max_element: " << high << endl;
    int low = *(min_element(begin(v), end(v)));
    cout << "min_element: " << low << endl;

    sort(begin(v), end(v));
    low = *begin(v);
    cout << "low after sorting: " << low << endl;
    high = *(end(v) -1);
    cout << "high after sorting: " << high << endl;

    int positive = *upper_bound(begin(v), end(v), 0);
    cout << "positive: " << positive << endl;

    sort(begin(staff), end(staff),
        [](Employee e1, Employee e2){ return e1.getSortingName() < e2.getSortingName(); });

    auto p = lower_bound(begin(staff), end(staff), "mary, hope",
        [](Employee e1, string n){ return e1.getSortingName() < n; });
    int sal  = p->getSalary();
    cout << "sal: " << sal << endl;

    random_device ramdomDevice;
    mt19937 generator(ramdomDevice());
    shuffle(begin(v), end(v), generator);
    cout << "after shuffle: " << v[0] << endl;

    partial_sort(begin(v2), find(begin(v2), end(v2), 4), end(v2));
    int breakpoint = *is_sorted_until(begin(v2), end(v2));

    vector<int> v3(3);
    partial_sort_copy(begin(v), end(v), begin(v3), end(v3));

    v2 = { 1, 5, 4, 2, 9, 7, 3, 8, 2 };
    int i = *(begin(v2) + 4);
    cout << "i: " << i << endl;
    nth_element(begin(v2), begin(v2)+4, end(v2));
    i = *(begin(v2) + 4);
    cout << "i again: " << i << endl;
    
    return 0;
}