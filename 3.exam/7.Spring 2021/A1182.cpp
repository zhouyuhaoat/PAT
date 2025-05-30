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

unordered_map<int, int> loc; // 1-based index

void upAdjust(vector<int>& heap, int lo, int hi) { // of max heap
    int i = hi, j = i / 2;
    while (j >= lo) {
        if (heap[i] > heap[j]) { // child > parent
            swap(heap[i], heap[j]);
            i = j, j = i / 2;
        } else {
            break;
        }
    }
}

bool judge(string s) { // judge the relationship by index in a max heap
    int a, b;
    if (s.find("root") != string::npos) {
        sscanf(s.c_str(), "%d is the root", &a);
        return loc[a] == 1; // root is the first node
    } else if (s.find("siblings") != string::npos) {
        sscanf(s.c_str(), "%d and %d are siblings", &a, &b);
        return loc[a] / 2 == loc[b] / 2;
    } else if (s.find("parent") != string::npos) {
        sscanf(s.c_str(), "%d is the parent of %d", &a, &b);
        return loc[a] == loc[b] / 2;
    } else if (s.find("left") != string::npos) {
        sscanf(s.c_str(), "%d is the left child of %d", &a, &b);
        return loc[a] == loc[b] * 2;
    } else if (s.find("right") != string::npos) {
        sscanf(s.c_str(), "%d is the right child of %d", &a, &b);
        return loc[a] == loc[b] * 2 + 1;
    }
    return false;
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<int> heap(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> heap[i];
        upAdjust(heap, 1, i);
    }
    // max heap is a (complete) binary tree
    for (int i = 1; i <= n; i++) {
        loc[heap[i]] = i;
    }
    getchar();
    while (m--) {
        string s;
        getline(cin, s);
        cout << judge(s);
    }
    cout << "\n";

    return 0;
}
