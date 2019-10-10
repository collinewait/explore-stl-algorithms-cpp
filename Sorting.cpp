#include <vector>
#include "Employee.h"
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

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
    
    return 0;
}