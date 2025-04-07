/*
 *	author:		zhouyuhao
 *	created:	2025-04-07 08:51:27
 *	modified:	2025-04-07 10:12:40
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=994805472333250560 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1026 Table Tennis
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805472333250560
*/

// @pintia code=start
// https://www.acwing.com/solution/content/145313/
#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

struct per { // person
    int at, pt, st, wt; // arrival time, play time, start time, wait time
    per(int at = 0, int pt = 0) : at(at), pt(pt), st(0), wt(0) {
    }
    bool operator<(const per& p) const {
        return at > p.at;
    }
};

struct tab { // table
    int id, et; // end time
    tab(int id, int et) : id(id), et(et) {
    }
    bool operator<(const tab& t) const {
        return et != t.et ? et > t.et : id > t.id;
    }
};

vector<int> cnt; // count of people at each table
vector<per> pers; // all people who played

void assign(priority_queue<per>& ps, priority_queue<tab>& ts) {
    // assign a (VIP/normal) person to a (VIP/normal) table
    per p = ps.top();
    tab t = ts.top();
    ps.pop(), ts.pop();
    p.st = t.et, p.wt = (t.et - p.at + 30) / 60;
    cnt[t.id]++;
    pers.emplace_back(p);
    ts.emplace(t.id, t.et + p.pt);
}

void update(priority_queue<tab>& ts, int at) {
    // update the end time of (VIP/normal) tables
    while (ts.top().et < at) {
        tab t = ts.top();
        ts.pop();
        t.et = at;
        ts.emplace(t);
    }
}

void print(int t) {
    cout << setfill('0') << setw(2) << t / 60 / 60 << ":";
    cout << setfill('0') << setw(2) << t / 60 % 60 << ":";
    cout << setfill('0') << setw(2) << t % 60 << " ";
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;

    priority_queue<per> vps, nps; // persons: VIP, normal
    vps.emplace(INT_MAX), nps.emplace(INT_MAX); // dummy person
    for (int i = 0; i < n; i++) {
        int h, m, s, pt, f;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &pt, &f);
        int at = h * 3600 + m * 60 + s;
        pt = min(pt, 120) * 60;
        f ? vps.emplace(at, pt) : nps.emplace(at, pt);
    }

    int k, m;
    cin >> k >> m;
    cnt.resize(k + 1);
    vector<bool> vtf(m + 1); // VIP table flag
    for (int i = 0; i < m; i++) {
        int id;
        cin >> id;
        vtf[id] = true;
    }

    priority_queue<tab> vts, nts; // tables: VIP, normal
    vts.emplace(-1, INT_MAX), nts.emplace(-1, INT_MAX); // dummy table
    for (int i = 1; i <= k; i++) {
        vtf[i] ? vts.emplace(i, 8 * 3600) : nts.emplace(i, 8 * 3600); // open up
    }

    while (vps.size() > 1 || nps.size() > 1) {
        per vp = vps.top(), np = nps.top();
        int at = min(vp.at, np.at);

        // idle -> busy
        update(vts, at), update(nts, at);

        tab vt = vts.top(), nt = nts.top();
        int et = min(vt.et, nt.et);
        if (et >= 21 * 3600) break; // shut down

        if (vp.at <= et && vt.et == et) { // VIP person arrives, and VIP table is free
            assign(vps, vts);
        } else {
            // 1. VIP person arrives, and VIP table is busy
            // 2. normal person arrivers, no VIP person arrives, and VIP table is free
            assign(vp.at < np.at ? vps : nps, nt < vt ? vts : nts);
            // tab1 < tab2 <=> tab1.et > tab2.et || (tab1.et == tab2.et && tab1.id > tab2.id)
            // => should assign tab2 first
        }
    }

    sort(pers.begin(), pers.end(), [](per a, per b) -> bool {
        return a.st != b.st ? a.st < b.st : a.at < b.at;
    });
    for (auto p : pers) {
        print(p.at), print(p.st);
        cout << p.wt << endl;
    }
    for (int i = 1; i <= k; i++) {
        cout << cnt[i];
        i < k ? cout << ' ' : cout << "\n";
    }

    return 0;
}
// @pintia code=end