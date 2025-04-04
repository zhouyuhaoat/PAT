/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 16:47:29
 *	modified:	2023-04-12 20:55:31
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805342720868352 pid=994805417945710592 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1057 Stack
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805417945710592
*/

// @pintia code=start
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define lowbit(i) ((i) & -(i)) // get the last 1 bit of i

const int maxn = 1e5 + 1;
stack<int> st;
vector<int> t(maxn); // Binary Indexed Tree (BIT, Fenwick Tree)

void update(int x, int v) { // update the value of x by v
    for (int i = x; i < (int)t.size(); i += lowbit(i)) {
        t[i] += v;
    }
}

int getsum(int x) { // get the sum of [1, x]
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += t[i];
    }
    return sum;
}

void peekmedian(int k) {
    int lo = 1, hi = t.size(); // binary search for the k-th number
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if (getsum(mi) >= k) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    cout << lo << "\n";
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.find("Push") != string::npos) {
            int v;
            cin >> v;
            st.emplace(v);
            update(v, 1);
        } else if (s.find("Pop") != string::npos) {
            if (st.empty()) {
                cout << "Invalid\n";
            } else {
                cout << st.top() << "\n";
                update(st.top(), -1);
                st.pop();
            }
        } else {
            if (st.empty()) {
                cout << "Invalid\n";
            } else {
                int k = (st.size() + 1) / 2;
                peekmedian(k);
            }
        }
    }

    return 0;
}
// @pintia code=end