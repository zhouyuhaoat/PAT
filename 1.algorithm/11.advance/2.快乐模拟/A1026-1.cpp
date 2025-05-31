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

struct Person {
    int arrivalTime, playTime, startTime;
    bool vip;
};

int convert(int hh, int mm, int ss) {
    return hh * 60 * 60 + mm * 60 + ss;
}
int open = convert(8, 0, 0), closed = convert(21, 0, 0);

struct Table {
    int cnt, endTime = open; // count of people
    bool vip;
};

void print(int time) {
    cout << setfill('0') << setw(2) << time / 60 / 60 << ":";
    cout << setfill('0') << setw(2) << time / 60 % 60 << ":";
    cout << setfill('0') << setw(2) << time % 60 << " ";
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<Person> persons(n);
    for (int i = 0; i < n; i++) {
        int hh, mm, ss, playTime, vip;
        cin >> hh, getchar(); // getchar() to consume ':'
        cin >> mm, getchar();
        cin >> ss >> playTime >> vip;
        persons[i].arrivalTime = convert(hh, mm, ss);
        persons[i].playTime = min(playTime, 120) * 60; // at most 2 hours
        if (vip) persons[i].vip = true;
    }

    sort(persons.begin(), persons.end(), [](Person a, Person b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int k, m;
    cin >> k >> m;
    vector<Table> tables(k + 1);
    vector<int> vipTableID(m); // VIP table index
    for (int i = 0; i < m; i++) {
        cin >> vipTableID[i];
        tables[vipTableID[i]].vip = true;
    }

    vector<bool> vis(n);
    int person = 0; // index of person
    while (person < n) {
        if (vis[person]) {
            person++;
            continue;
        }
        if (persons[person].vip) {
            int table = -1; // index of table
            for (int i = 0; i < m; i++) { // try to find a VIP table
                if (persons[person].arrivalTime >= tables[vipTableID[i]].endTime) {
                    table = i;
                    break;
                }
            }
            if (table != -1) { // find a VIP table
                persons[person].startTime = persons[person].arrivalTime; // play immediately
                tables[vipTableID[table]].endTime = persons[person].startTime + persons[person].playTime;
                if (persons[person].startTime < closed) tables[vipTableID[table]].cnt++;
                vis[person] = true, person++;
                continue;
            }
        }
        // 1. not a VIP person
        // 2. a VIP person, but no VIP table available
        int table = -1;
        for (int i = 1; i <= k; i++) { // try to find a normal table
            if (persons[person].arrivalTime >= tables[i].endTime) {
                table = i;
                break;
            }
        }
        if (table != -1) { // find a normal table and play immediately
            persons[person].startTime = persons[person].arrivalTime;
            tables[table].endTime = persons[person].startTime + persons[person].playTime;
            if (persons[person].startTime < closed) tables[table].cnt++;
            vis[person] = true, person++;
            continue;
        }
        // no table available
        int minTable = -1, minEndTime = INT_MAX; // find the table with the earliest end time
        for (int i = 1; i <= k; i++) {
            if (minEndTime > tables[i].endTime) {
                minEndTime = tables[i].endTime;
                minTable = i;
            }
        }
        if (!persons[person].vip) {
            if (!tables[minTable].vip) { // allow to play immediately
                persons[person].startTime = tables[minTable].endTime;
                tables[minTable].endTime += persons[person].playTime;
                if (persons[person].startTime < closed) tables[minTable].cnt++;
                vis[person] = true, person++;
            } else { // privilege: try to find a VIP person in the queue
                int temp = person;
                for (int i = temp; i < n; i++) {
                    if (!vis[i]) {
                        if (persons[i].arrivalTime <= tables[minTable].endTime) {
                            if (persons[i].vip) {
                                person = i;
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                }
                // current person or a VIP person
                persons[person].startTime = tables[minTable].endTime;
                tables[minTable].endTime += persons[person].playTime;
                if (persons[person].startTime < closed) tables[minTable].cnt++;
                vis[person] = true, person = temp; // reset
            }
        } else {
            for (int i = 0; i < m; i++) { // try to find a VIP table with the same end time
                if (minEndTime == tables[vipTableID[i]].endTime) {
                    minTable = vipTableID[i];
                    break;
                }
            }
            persons[person].startTime = tables[minTable].endTime;
            tables[minTable].endTime += persons[person].playTime;
            if (persons[person].startTime < closed) tables[minTable].cnt++;
            vis[person] = true, person++;
        }
    }

    sort(persons.begin(), persons.end(), [](Person a, Person b) {
        return a.startTime < b.startTime;
    });

    for (auto [arrivalTime, ignore1, startTime, ignore2] : persons) {
        if (startTime >= closed) continue;
        print(arrivalTime), print(startTime);
        cout << (startTime - arrivalTime + 30) / 60 << "\n";
    }

    for (int i = 1; i <= k; i++) {
        cout << tables[i].cnt;
        i < k ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
