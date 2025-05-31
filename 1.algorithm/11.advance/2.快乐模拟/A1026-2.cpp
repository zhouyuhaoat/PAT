/*
 *	author:		zhouyuhao
 *	created:	2025-05-31 08:51:27
 *	modified:	2025-05-31 10:12:40
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
#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

struct Person {
    int arrivalTime, playTime, startTime, waitTime;
    Person(int arrivalTime = 0, int playTime = 0)
        : arrivalTime(arrivalTime), playTime(playTime), startTime(0), waitTime(0) {
    }
    bool operator<(const Person& other) const {
        return arrivalTime > other.arrivalTime;
    }
};

struct Table {
    int id, endTime;
    Table(int id, int endTime) : id(id), endTime(endTime) {
    }
    bool operator<(const Table& other) const {
        return endTime != other.endTime ? endTime > other.endTime : id > other.id;
    }
};

vector<int> cnt; // count of people at each table
vector<Person> allPersons; // all people who played

void assign(priority_queue<Person>& persons, priority_queue<Table>& tables) {
    // assign a (vip/normal) table to a (vip/normal) person
    Person person = persons.top();
    Table table = tables.top();
    persons.pop(), tables.pop();
    person.startTime = table.endTime, person.waitTime = (table.endTime - person.arrivalTime + 30) / 60;
    cnt[table.id]++;
    tables.emplace(table.id, table.endTime + person.playTime);
    allPersons.emplace_back(person);
}

void update(priority_queue<Table>& tables, int arrivalTime) {
    // update the end time of (vip/normal) tables
    while (tables.top().endTime < arrivalTime) {
        Table table = tables.top();
        tables.pop();
        table.endTime = arrivalTime;
        tables.emplace(table);
    }
}

void print(int time) {
    cout << setfill('0') << setw(2) << time / 60 / 60 << ":";
    cout << setfill('0') << setw(2) << time / 60 % 60 << ":";
    cout << setfill('0') << setw(2) << time % 60 << " ";
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    priority_queue<Person> vipPersons, normalPersons;
    vipPersons.emplace(INT_MAX), normalPersons.emplace(INT_MAX); // dummy person
    for (int i = 0; i < n; i++) {
        int hh, mm, ss, playTime, vip;
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &playTime, &vip);
        int arrivalTime = hh * 3600 + mm * 60 + ss;
        playTime = min(playTime, 120) * 60;
        vip ? vipPersons.emplace(arrivalTime, playTime) : normalPersons.emplace(arrivalTime, playTime);
    }

    int k, m;
    cin >> k >> m;
    cnt.resize(k + 1);
    vector<bool> vipTableID(m + 1);
    for (int i = 0; i < m; i++) {
        int id;
        cin >> id;
        vipTableID[id] = true;
    }

    priority_queue<Table> vipTables, normalTables;
    vipTables.emplace(-1, INT_MAX), normalTables.emplace(-1, INT_MAX); // dummy table
    int open = 8 * 3600, closed = 21 * 3600;
    for (int i = 1; i <= k; i++) {
        vipTableID[i] ? vipTables.emplace(i, open) : normalTables.emplace(i, open);
    }

    while (vipPersons.size() > 1 || normalPersons.size() > 1) {
        Person vipPerson = vipPersons.top(), normalPerson = normalPersons.top();
        int arrivalTime = min(vipPerson.arrivalTime, normalPerson.arrivalTime);

        update(vipTables, arrivalTime), update(normalTables, arrivalTime); // allTables: idle -> busy

        Table vipTable = vipTables.top(), normalTable = normalTables.top();
        int endTime = min(vipTable.endTime, normalTable.endTime);
        if (endTime >= closed) break;

        if (vipPerson.arrivalTime <= endTime && vipTable.endTime == endTime) {
            // vip table -> vip person: vip person arrives, and vip table is free
            assign(vipPersons, vipTables);
        } else {
            /*
                !(vip table -> vip person)
                    1. normal table -> vip person: vip person arrives, and vip table is busy
                    2. (vip, normal) table -> normal person: only normal person arrivers
                tab1 < tab2
                    - <=> tab1.et > tab2.et || (tab1.et == tab2.et && tab1.id > tab2.id)
                    - => should assign tab2 first
            */
            assign(vipPerson.arrivalTime < normalPerson.arrivalTime ? vipPersons : normalPersons,
                   normalTable < vipTable ? vipTables : normalTables);
        }
    }

    sort(allPersons.begin(), allPersons.end(), [](Person a, Person b) {
        return a.startTime != b.startTime ? a.startTime < b.startTime : a.arrivalTime < b.arrivalTime;
    });

    for (auto [arrivalTime, ignore1, startTime, ignore2] : allPersons) {
        print(arrivalTime), print(startTime);
        cout << (startTime - arrivalTime + 30) / 60 << "\n";
    }

    for (int i = 1; i <= k; i++) {
        cout << cnt[i];
        i < k ? cout << ' ' : cout << "\n";
    }

    return 0;
}
// @pintia code=end
