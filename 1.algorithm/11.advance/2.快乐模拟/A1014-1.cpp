/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 23:42:25
 *	modified:	2023-04-13 08:50:22
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805498207911936 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1014 Waiting in Line
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805498207911936
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

struct Customer {
    int windowID, endTime;
    Customer(int windowID, int endTime) : windowID(windowID), endTime(endTime) {
    }
    friend bool operator<(Customer a, Customer b) {
        if (a.endTime != b.endTime) {
            return a.endTime > b.endTime;
        } else {
            return a.windowID > b.windowID;
        }
    }
};

int main(int argc, char const *argv[]) {

    int n, m, k, q;
    cin >> n >> m >> k >> q; // windows, capacity, customers, queries
    vector<queue<int>> windows(n + 1); // end time of windows
    priority_queue<Customer> customers; // to be served
    vector<int> processTime(k + 1), endTime(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> processTime[i];
        if (i <= m * n) { // first m customers of n windows
            int windowID = (i - 1) % n + 1;
            endTime[i] = (windows[windowID].empty() ? 0 : windows[windowID].back()) + processTime[i];
            windows[windowID].emplace(endTime[i]);
            if (i <= n) { // serving the first customer of each window
                customers.emplace(windowID, windows[windowID].front());
            }
        }
    }
    for (int i = m * n + 1; i <= k; i++) { // remaining customers
        auto [windowID, _] = customers.top(); // served
        customers.pop();
        endTime[i] = windows[windowID].back() + processTime[i];
        windows[windowID].pop(); // leave the window
        windows[windowID].emplace(endTime[i]); // enter the window
        customers.emplace(windowID, windows[windowID].front()); // serving the next customer of each window
    }
    while (q--) {
        int id;
        cin >> id;
        if (endTime[id] - processTime[id] >= 540) {
            cout << "Sorry\n";
        } else {
            cout << setfill('0') << setw(2) << 8 + endTime[id] / 60 << ":";
            cout << setfill('0') << setw(2) << endTime[id] % 60 << "\n";
        }
    }

    return 0;
}
// @pintia code=end
