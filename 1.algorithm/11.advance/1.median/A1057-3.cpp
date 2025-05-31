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

#define lowbit(i) (i & -i)
/*
    BIT
    - lowbit(i): get the lowest set bit (rightmost 1) of i
        - with its power of 2
        - the value in binary representation
    - i & -i: bitwise AND of i and its two's complement
        - two's complement: negate the number and add 1
    - used in Binary Indexed Tree (Fenwick Tree) for efficient range queries
*/

using namespace std;

stack<int> stk;
vector<int> tree(1e5 + 1);

void add(int x, int val) {
    for (int i = x; i < (int)tree.size(); i += lowbit(i)) {
        tree[i] += val;
    }
}

int getSum(int x) { // [1, x]
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += tree[i];
    }
    return sum;
}

void peekMedian(int k) { // lower_bound for the k-th number
    int lo = 1, hi = tree.size();
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if (getSum(mi) >= k) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    cout << lo << "\n";
}

int main(int argc, char const *argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.find("Push") != string::npos) {
            int val;
            cin >> val;
            stk.emplace(val);
            add(val, 1);
        } else {
            if (stk.empty()) {
                cout << "Invalid\n";
            } else if (s.find("Pop") != string::npos) {
                cout << stk.top() << "\n";
                add(stk.top(), -1);
                stk.pop();
            } else {
                int k = (stk.size() + 1) / 2;
                peekMedian(k);
            }
        }
    }

    return 0;
}
// @pintia code=end
