#include "skip-list.hpp"

#include <iostream>
#include <cassert>

using namespace std;
using namespace MMaze;

void unit_test() {
    cout << "Running SkipList module unit test..." << endl;

    SkipList sl1;
    assert(sl1.length() == 0);
    assert(!sl1.find(5));
    sl1.add(5);
    sl1.add({2, 3, 6});
    assert(sl1.find(5));
    assert(sl1.find({2, 3}));
    sl1.remove({2, 6});
    assert(!sl1.find({2, 6}));
    sl1.remove(7);
    assert(!sl1.find(7));
    assert(sl1.length() == 2);

    SkipList sl2 = sl1;
    sl2.add({0, -7, 11, -50, 105, 21});
    sl2.remove({3, 5});
    assert(sl2.find({0, -7, 11}));
    assert(!sl2.find({3, 5}));
    assert(sl2.length() == 6);

    cout << "SkipList sl1 : " << sl1 << " on " << sl1.max_levels() << " level" << ((sl1.max_levels() > 1) ? "s": "") << ", " << sl1.length() << " elements" << endl;
    sl1.show_details();
    cout << endl;

    cout << "SkipList sl2 : " << sl2 << " on " << sl2.max_levels() << " level" << ((sl2.max_levels() > 1) ? "s": "") << ", " << sl2.length() << " elements" << endl;
    sl2.show_details();
    cout << endl;

    SkipList sl3({-5, -4, 5, 1, 0});
    sl3.find({-4, 0, -5, 5, 1});
    SkipList sl4(sl3);
    assert(sl4.find({-4, 0, -5, 5, 1}));
    sl4.clear();
    assert(sl4.length() == 0);
    for (int i = 0; i < 1000; i++) {
        sl4.add(i);
        assert(sl4.length() == (i + 1));
    }
    for (int i = 0; i < 1000; i++) {
        sl4.remove(i);
        assert(sl4.length() == ((1000 - i) - 1));
    }
    sl4.clear();

    cout << "SkipList sl3 : " << sl3 << " on " << sl3.max_levels() << " level" << ((sl3.max_levels() > 1) ? "s": "") << ", " << sl3.length() << " elements" << endl;
    sl3.show_details();
    cout << endl;

    sl3.remove_head();
    
    cout << "SkipList sl3 : " << sl3 << " on " << sl3.max_levels() << " level" << ((sl3.max_levels() > 1) ? "s": "") << ", " << sl3.length() << " elements" << endl;
    sl3.show_details();
    cout << endl;

    cout << "SkipList sl4 : " << sl4 << " on " << sl4.max_levels() << " level" << ((sl4.max_levels() > 1) ? "s": "") << ", " << sl4.length() << " elements" << endl;
    sl4.show_details();
    cout << endl;
}

int main() {

    unit_test();

    return 0;
}