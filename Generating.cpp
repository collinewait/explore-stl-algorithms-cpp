#include <vector>
#include <iostream>
#include <numeric>
#include "Resource.h"

using std::cout;
using std::endl;

using std::vector;

int main()
{
    vector<int> source { 3, 6, 1, 0, -2, 5 };
    vector<int> v2(source.size());

    copy(begin(source), end(source), begin(v2));

    auto v3 = source;
    auto position = find(begin(source), end(source), 1);
    vector<int> v4(source.size());
    copy(begin(source), position, begin(v4));

    vector<int> v5(source.size());
    copy_if(begin(source), end(source), begin(v5),
        [](int elem){ return elem % 2 == 0; });
    
    copy_n(begin(v5), 3, begin(v2));
    copy(begin(source), position+1, position+1); // safe because there is no overlaps. overlaps occur if the third element is between the first two params.
    copy_backward(begin(v3), end(v3), end(source));

    // copy(begin(source), end(source) - 1, begin(source) + 1); // not guaranteed to work. preffer copy_backward below
    copy_backward(begin(source), end(source) - 1, end(source));

    auto newend = remove(begin(source), end(source), 3);
    int s = source.size();
    cout << "s " << s << endl;
    int logicalsize = newend - begin(source);
    cout << "logicalsize " << logicalsize << endl;
    source.erase(newend, end(source));
    
    source = v3;
    source.erase(remove(begin(source), end(source), 3), end(source)); // can be done in one pass.

    vector<Resource> vr(2);
    vr[0].setValue(8);
    vr[1].setValue(9);

    auto renewend2 = remove_if(begin(vr), end(vr),
        [](const Resource& r){ return r.getValue() == 8; });
    vr.erase(renewend2, end(vr));
    cout << "Vr logicalsize " << vr.size() << endl;

    vector<int> v6(10);
    fill(begin(v6), end(v6), 1);
    fill_n(begin(v6), 6, 2);
    iota(begin(v6), end(v6), 1);

    int index = 10;
    generate(begin(v6), end(v6), [&index](){ return --index; });
    source = v6;
    index = 1;
    generate_n(begin(v6), 7, [&index](){ return (index *=2); });

    replace(begin(v6), end(v6), 2, 7);
    replace_if(begin(v6), end(v6), [](int elem) { return elem < 16; }, 7);

    return 0;
}