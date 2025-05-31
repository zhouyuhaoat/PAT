/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 21:59:05
 *	modified:	2023-04-12 23:42:02
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805491530579968 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1017 Queueing at Bank
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805491530579968
*/

// @pintia code=start
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

struct Customer {
    int arrivalTime, processTime;
};

int convert(int hh, int mm, int ss) {
    return hh * 60 * 60 + mm * 60 + ss;
}

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k; // customers, windows
    vector<Customer> customers;
    int open = convert(8, 0, 0), closed = convert(17, 0, 0);
    for (int i = 0; i < n; i++) {
        int hh, mm, ss, processTime;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &processTime);
        processTime = min(processTime, 60); // max processing time
        if (convert(hh, mm, ss) > closed) continue; // shutter
        customers.emplace_back(Customer{convert(hh, mm, ss), processTime * 60});
    }
    sort(customers.begin(), customers.end(), [](Customer a, Customer b) {
        return a.arrivalTime < b.arrivalTime;
    });
    int waitTime = 0;
    priority_queue<int, vector<int>, greater<int>> windows; // end time of windows
    for (auto [arrivalTime, processTime] : customers) {
        if ((int)windows.size() < k) { // idle window, just allocate directly
            if (arrivalTime < open) { // before open
                waitTime += open - arrivalTime;
                arrivalTime = open;
            }
            windows.emplace(arrivalTime + processTime);
        } else { // all windows are used, find the earliest one
            if (arrivalTime < windows.top()) { // busy
                waitTime += windows.top() - arrivalTime;
                windows.emplace(windows.top() + processTime);
            } else { // idle
                windows.emplace(arrivalTime + processTime);
            }
            windows.pop();
        }
    }
    cout << fixed << setprecision(1) << (double)waitTime / customers.size() / 60 << "\n";

    return 0;
}
// @pintia code=end
