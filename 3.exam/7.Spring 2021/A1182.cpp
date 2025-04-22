/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 17:53:15
 *	modified:	2023-04-13 18:14:44
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1182 Structure of Max-Heap
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> t;

void upAdjust(int lo, int hi) { // up adjust, or heapify for max-heap [lo, hi]
    int i = hi, j = i / 2;
    while (j >= lo) {
        if (t[i] > t[j]) { // child > parent
            swap(t[i], t[j]);
            i = j, j = i / 2; // move up
        } else {
            break;
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    t.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> t[i + 1];
        upAdjust(1, i + 1);
    }
    // max heap is a (complete) binary tree
    unordered_map<int, int> loc; // 1-based index
    for (int i = 0; i < n; i++) {
        loc[t[i + 1]] = i + 1;
    }
    getchar();
    for (int q = 0; q < m; q++) {
        string s;
        getline(cin, s);
        int a, b;
        bool flag = false; // judge the relationship by index in a max heap -> binary tree
        if (s.find("root") != string::npos) {
            sscanf(s.c_str(), "%d is the root", &a);
            flag = loc[a] == 1; // root is the first node
        } else if (s.find("siblings") != string::npos) {
            sscanf(s.c_str(), "%d and %d are siblings", &a, &b);
            flag = loc[a] / 2 == loc[b] / 2; // siblings have the same parent
        } else if (s.find("parent") != string::npos) {
            sscanf(s.c_str(), "%d is the parent of %d", &a, &b);
            flag = loc[a] == loc[b] / 2; // parent is half of child
        } else if (s.find("left") != string::npos) {
            sscanf(s.c_str(), "%d is the left child of %d", &a, &b);
            flag = loc[a] == loc[b] * 2; // left child is double of parent
        } else if (s.find("right") != string::npos) {
            sscanf(s.c_str(), "%d is the right child of %d", &a, &b);
            flag = loc[a] == loc[b] * 2 + 1; // right child is double of parent + 1
        }
        cout << flag;
    }
    cout << "\n";

    return 0;
}
