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

const int N = 1e5 + 1, blockSize = sqrt(N);

stack<int> stk;
vector<int> blocks(blockSize), cnt(N); // count of elements in block, count of each element

void emplace(int val) {
    stk.emplace(val);
    blocks[val / blockSize]++, cnt[val]++;
}

void pop() {
    int val = stk.top();
    stk.pop();
    blocks[val / blockSize]--, cnt[val]--;
    cout << val << "\n";
}

void peekMedian(int k) {
    int count = 0, block = 0;
    while (count + blocks[block] < k) { // find the block
        count += blocks[block++];
    }
    int median = block * blockSize;
    while (count + cnt[median] < k) { // find the median
        count += cnt[median++];
    }
    cout << median << "\n";
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
                int k = (stk.size() + 1) / 2; // median
                peekMedian(k);
            }
        }
    }

    return 0;
}
// @pintia code=end
