/**************************************************************************
 *
 * Copyright (c) 2013 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: bicoloring.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 04-28-2016 22:47:06
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <memory>

using namespace std;

class Graph {
public:
    Graph() = default;
    Graph(int n, int l): num_vectices_(n), num_edges_(l) {
        graph_.resize(num_vectices_);
        for (int i = 0; i < num_edges_; ++i) {
            int p1, p2;
            cin >> p1 >> p2;
            graph_[p1].push_back(p2);
        }
    }
    ~Graph() = default;

    bool Bicoloring() {
        unordered_set<int> black, red;
        queue<int> vertices;
        vertices.push(0);
        black.insert(0);

        while (!vertices.empty()) {
            auto i = vertices.front();
            vertices.pop();

            unordered_set<int> * check_list(&black);
            unordered_set<int> * appended_list(&red);
            if (red.count(i)) {
                check_list = &red;
                appended_list = &black;
            }

            for (auto j : graph_[i]) {
                if (!check_list->count(j)) {
                    if (!appended_list->count(j)) {
                        appended_list->insert(j);
                        vertices.push(j);
                    }
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }

    void PrintGraph() {
        for (int i = 0; i < num_vectices_; ++i) {
            cout << i << ": ";
            for (auto j : graph_[i]) {
                cout << j;
            }
            cout << endl;
        }
    }

private:
    vector<vector<int>> graph_;
    int num_vectices_ = 0;
    int num_edges_ = 0;
};

int main() {
    int n, l;
    cin >> n;
    while (n != 0) {
        cin >> l;
        Graph g(n, l);
        cout << (g.Bicoloring() ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
        cin >> n;
    }

    return 0;
}
