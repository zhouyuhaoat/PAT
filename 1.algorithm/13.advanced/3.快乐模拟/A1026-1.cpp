/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 08:51:27
 *	modified:	2023-04-14 10:12:40
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805342720868352 pid=994805472333250560 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1026 Table Tennis
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805472333250560
*/

// @pintia code=start
#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct per { // person
    int at, pt, st; // arrival time, play time, start time
    bool isvip; // VIP
};

int trans(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}
int be = trans(8, 0, 0), en = trans(21, 0, 0);

struct tab { // table
    int cnt, et = be; // count of people, end time
    bool isvip; // VIP table
};

void print(int t) {
    cout << setfill('0') << setw(2) << t / 60 / 60 << ":";
    cout << setfill('0') << setw(2) << t / 60 % 60 << ":";
    cout << setfill('0') << setw(2) << t % 60 << " ";
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<per> p(n);
    for (int i = 0; i < n; i++) {
        int h, m, s, pt, f;
        // getchar() to consume ':'
        cin >> h, getchar();
        cin >> m, getchar();
        cin >> s >> pt >> f;
        p[i].at = trans(h, m, s);
        if (pt > 120) pt = 120; // at most 2 hours
        p[i].pt = pt * 60;
        if (f) p[i].isvip = true;
    }

    sort(p.begin(), p.end(), [](per a, per b) -> bool {
        return a.at < b.at;
    });

    int k, m;
    cin >> k >> m;
    vector<tab> t(k + 1);
    vector<int> tv(m); // VIP table index
    for (int i = 0; i < m; i++) {
        cin >> tv[i];
        t[tv[i]].isvip = true;
    }

    vector<bool> vis(n);
    int ip = 0; // index of person
    while (ip < n) {
        if (vis[ip]) {
            ip++;
            continue;
        }
        if (p[ip].isvip) {
            int it = -1; // index of table
            for (int i = 0; i < m; i++) { // try to find a VIP table
                if (p[ip].at >= t[tv[i]].et) {
                    it = i;
                    break;
                }
            }
            if (it != -1) { // find a VIP table
                p[ip].st = p[ip].at; // play immediately
                t[tv[it]].et = p[ip].st + p[ip].pt;
                if (p[ip].st < en) t[tv[it]].cnt++;
                vis[ip] = true;
                ip++;
                continue;
            }
        }
        // 1. not a VIP person
        // 2. a VIP person, but no VIP table available
        int it = -1;
        for (int i = 1; i <= k; i++) { // try to find a normal table
            if (p[ip].at >= t[i].et) {
                it = i;
                break;
            }
        }
        if (it != -1) { // find a normal table and play immediately
            p[ip].st = p[ip].at;
            t[it].et = p[ip].st + p[ip].pt;
            if (p[ip].st < en) t[it].cnt++;
            vis[ip] = true;
            ip++;
            continue;
        }
        // no table available
        int minit = -1, minet = INT_MAX; // find the table with the earliest end time
        for (int i = 1; i <= k; i++) {
            if (minet > t[i].et) {
                minet = t[i].et;
                minit = i;
            }
        }
        if (!p[ip].isvip) {
            if (!t[minit].isvip) { // allow to play immediately
                p[ip].st = t[minit].et;
                t[minit].et += p[ip].pt;
                if (p[ip].st < en) t[minit].cnt++;
                vis[ip] = true;
                ip++;
            } else { // privilege: try to find a VIP person in the queue
                int tip = ip;
                for (int i = tip; i < n; i++) {
                    if (!vis[i]) {
                        if (p[i].at <= t[minit].et) {
                            if (p[i].isvip) {
                                ip = i;
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                }
                // current person or a VIP person
                p[ip].st = t[minit].et;
                t[minit].et += p[ip].pt;
                if (p[ip].st < en) t[minit].cnt++;
                vis[ip] = true;
                ip = tip; // reset
            }
        } else {
            for (int i = 0; i < m; i++) { // try to find a VIP table with the same end time
                if (minet == t[tv[i]].et) {
                    minit = tv[i];
                    break;
                }
            }
            p[ip].st = t[minit].et;
            t[minit].et += p[ip].pt;
            if (p[ip].st < en) t[minit].cnt++;
            vis[ip] = true;
            ip++;
        }
    }

    sort(p.begin(), p.end(), [](per a, per b) -> bool {
        return a.st < b.st;
    });

    for (auto it : p) {
        if (it.st >= en) continue;
        print(it.at), print(it.st);
        cout << (it.st - it.at + 30) / 60 << "\n";
    }

    for (int i = 1; i <= k; i++) {
        cout << t[i].cnt;
        i < k ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end