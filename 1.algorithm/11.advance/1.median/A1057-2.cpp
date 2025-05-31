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
#include <iostream>
#include <set>
#include <stack>

using namespace std;

stack<int> stk;
multiset<int> setMin, setMax;
/*
    multiset
        - asending order, allow duplicates
    setMin <= median < setMax
        1. setMin: contains the smaller half of the elements, including the median
        2. setMax: contains the larger half of the elements
        3. median: the largest element in setMin
    0 <= setMin.size() - setMax.size() <= 1
        - balance: ensure the size of setMin is at most one larger than setMax
*/

void balance() {
    if (setMin.size() > setMax.size() + 1) {
        setMax.insert(*setMin.rbegin());
        setMin.erase(--setMin.end());
    } else if (setMin.size() < setMax.size()) {
        setMin.insert(*setMax.begin());
        setMax.erase(setMax.begin());
    }
}

void emplace(int val) {
    stk.emplace(val);
    if (setMin.empty() || val <= *setMin.rbegin()) {
        setMin.insert(val);
    } else {
        setMax.insert(val);
    }
    balance();
}

void pop() {
    int val = stk.top();
    stk.pop();
    int median = *setMin.rbegin();
    if (val <= median) {
        setMin.erase(setMin.find(val));
    } else {
        setMax.erase(setMax.find(val));
    }
    cout << val << "\n";
    balance();
}

void peekMedian() {
    cout << *setMin.rbegin() << "\n";
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
            emplace(val);
        } else {
            if (stk.empty()) {
                cout << "Invalid\n";
            } else if (s.find("Pop") != string::npos) {
                pop();
            } else {
                peekMedian();
            }
        }
    }

    return 0;
}
// @pintia code=end
