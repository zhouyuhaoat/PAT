/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 16:45:24
 *	modified:	2023-04-12 17:08:43
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
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int maxn = 1e5 + 1, sqr = sqrt(maxn); // block size
stack<int> st;
vector<int> b(sqr), ht(maxn);
// count of elements in block, count of element

void emplace(int v) {
    st.emplace(v);
    b[v / sqr]++, ht[v]++;
}

void pop() {
    int v = st.top();
    st.pop();
    b[v / sqr]--, ht[v]--;
    cout << v << "\n";
}

void peekmedian(int k) {
    int cnt = 0, id = 0;
    while (cnt + b[id] < k) { // find the block
        cnt += b[id++];
    }
    int median = id * sqr;
    while (cnt + ht[median] < k) { // find the element
        cnt += ht[median++];
    }
    cout << median << "\n";
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
            emplace(v);
        } else if (s.find("Pop") != string::npos) {
            if (st.empty()) {
                cout << "Invalid\n";
            } else {
                pop();
            }
        } else {
            if (st.empty()) {
                cout << "Invalid\n";
            } else {
                int k = (st.size() + 1) / 2; // median
                peekmedian(k);
            }
        }
    }

    return 0;
}
// @pintia code=end