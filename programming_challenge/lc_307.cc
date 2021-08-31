#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;



class NumArray {

private:
    template<typename T>
    struct SegTreeNode {
        T sum;
        size_t l, r;
    };

    vector<SegTreeNode<int>> seg_tree;

    vector<int> data;

    void build_segment_tree(size_t, size_t, size_t);

    size_t left(size_t i) { return 2*i+1;}
    size_t right(size_t i) { return 2*i+2;}

    SegTreeNode<int> merge(size_t l, size_t r) {
        SegTreeNode<int> p;
        p.sum = seg_tree[l].sum + seg_tree[r].sum;
        p.l = seg_tree[l].l;
        p.r = seg_tree[r].r;

        return p;
    }

    void seg_update(size_t l, size_t r, size_t t_index, int val) {
        auto t_l = seg_tree[t_index].l;
        auto t_r = seg_tree[t_index].r;
        if (t_l >= l && t_r <= r) {
            seg_tree[t_index].sum = val * (t_r - t_l+1);
            return;
        }

        auto m = t_l + ((t_r-t_l)>>1);
        if (l <= m)
            seg_update(l, r, left(t_index), val);
        if (r > m)
            seg_update(l, r, right(t_index), val);

        seg_tree[t_index] = merge(left(t_index), right(t_index));
    }

    int sum(size_t t_index, size_t l, size_t r) {
        auto t_l = seg_tree[t_index].l;
        auto t_r = seg_tree[t_index].r;

        if (t_l >= l && t_r <= r) {
            return seg_tree[t_index].sum;
        }

        auto m = t_l + ((t_r-t_l)>>1);
        auto s = 0;
        if (l <= m)
            s += sum(left(t_index), l, r);
        if (r > m)
            s += sum(right(t_index), l, r);

        return s;
    }

public:
    const vector<int>& get_data() {
        return data;
    }

    const vector<int>& operator*() {
        return data;
    }

    NumArray(vector<int>& nums) {
        data = std::move(nums);
        seg_tree.resize(4 * data.size());
        build_segment_tree(0, 0, data.size()-1);
    }

    void update(int index, int val) {
        data[index] = val;
        seg_update(index, index, 0, val);
    }

    int sumRange(int left, int right) {

        return sum(0, left, right);
    }
};

void NumArray::build_segment_tree(size_t t_index, size_t l, size_t r) {
    if (l == r) {
        seg_tree[t_index].sum = data[l];
        seg_tree[t_index].l = seg_tree[t_index].r = l;
        return;
    }

    auto m = l + ((r-l) >> 1);
    build_segment_tree(left(t_index), l, m);
    build_segment_tree(right(t_index), m+1, r);

    seg_tree[t_index] = merge(left(t_index), right(t_index));
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
    //vector<int> nums{1,2,3,4,5};
    vector<int> nums{5, 18, 13};
    NumArray* obj = new NumArray(nums);

    ostream_iterator<int> cout_iter(cout, " ");

    cout << obj->sumRange(0,2) << endl;

    obj->update(1, -1);
    copy((**obj).begin(), (**obj).end(), cout_iter);
    cout << endl;

    obj->update(2, 3);
    obj->update(0, 5);
    obj->update(0, -4);
    copy((**obj).begin(), (**obj).end(), cout_iter);
    cout << endl;

    cout << obj->sumRange(0,2) << endl;

    /*
    cout << obj->sumRange(1,3) << endl;
    cout << obj->sumRange(1,1) << endl;
    cout << obj->sumRange(0,1) << endl;
    cout << obj->sumRange(0,4) << endl;
    */

    return 0;
}
