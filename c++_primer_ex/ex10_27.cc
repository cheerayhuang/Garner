#include <iostream> 
#include <algorithm> 
#include <vector>
#include <iterator>
#include <list>
#include <forward_list>
#include <deque>

using namespace std; 

int main() {
    vector<int> v{1, 1, 2, 2, 3, 3, 4, 4};
    list <int> lst;
    
    unique_copy(v.begin(), v.end(), back_inserter(lst));

    for_each(lst.begin(), lst.end(), [](int i) {cout << i << " ";});

    cout << endl;

    v.assign({1, 2, 3, 4, 5, 6, 7, 8, 9});

    forward_list<int> fwd_lst;
    copy(v.begin(), v.end(), front_inserter(fwd_lst));
    for_each(fwd_lst.begin(), fwd_lst.end(), [](int &i) {cout << i << " ";});

    deque<int> d; 
    copy(v.begin(), v.end(), inserter(d, d.end()));
    for_each(d.begin(), d.end(), [](int i ) { cout << i << " "; });

    return 0;
}

