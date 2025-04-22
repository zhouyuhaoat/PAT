/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 13:57:59
 *	modified:	2023-04-14 19:15:20
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1697151678120173568 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1172 Panda and PP Milk
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1697151678120173568
*/

// @pintia code=start
#include <iostream>
#include <queue>

using namespace std;

struct pan { // panda
    int id, w; // index, weight
    pan(int id, int w) : id(id), w(w) { // constructor
    }
    friend bool operator<(pan a, pan b) { // overload < operator for min-heap
        if (a.w != b.w) {
            return a.w > b.w;
        } else {
            return a.id > b.id;
        }
    }
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> w(n + 2);
    priority_queue<pan> p;
    for (int i = 0; i < n; i++) {
        cin >> w[i + 1];
        p.emplace(i + 1, w[i + 1]);
    }
    vector<int> m(n + 2); // milk
    while (!p.empty()) {
        pan t = p.top(); // the lightest panda
        p.pop();
        int id = t.id;
        if (m[id - 1] == 0 && m[id + 1] == 0) { // no both sides
            m[id] = 200; // basic
        } else if (m[id - 1] != 0 && m[id + 1] == 0) { // only left side
            m[id] = m[id - 1]; // inherit
            if (w[id] > w[id - 1]) { // heavier
                m[id] += 100;
            }
        } else if (m[id + 1] != 0 && m[id - 1] == 0) { // only right side
            m[id] = m[id + 1];
            if (w[id] > w[id + 1]) {
                m[id] += 100;
            }
        } else { // both sides
            // since weight first, index second in priority queue
            // => w[id - 1] <= w[id], w[id] > w[id + 1]
            if (w[id] > w[id - 1]) { // heavier than both sides
                m[id] = max(m[id - 1], m[id + 1]) + 100;
            } else if (w[id] == w[id - 1]) { // equal to left side, heavier than right side
                m[id] = max(m[id - 1], m[id + 1] + 100);
                if (m[id] > m[id - 1]) { // same weight, but not same milk
                    for (int j = id - 1; j >= 0; j--) { // backward
                        if (w[j] == w[id]) { // update milk since same weight
                            m[j] = m[id];
                        } else { // until the first different weight
                            break;
                        }
                    }
                }
            }
        }
    }
    int sum = 0;
    for (int it : m) {
        sum += it;
    }
    cout << sum << "\n";

    return 0;
}
// @pintia code=end
