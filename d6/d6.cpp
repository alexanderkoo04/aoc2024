#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

void solve1() {
    long long sol = 0;
    vector<vector<char>> map;
    string line;
    while (getline(cin, line)) {
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        map.push_back(row);
    }

    int x, y;
    bool found = false;

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == '^') {
                x = i;
                y = j;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));
    int state = 0; // 0 - up, 1 - right, 2 - down, 3 - left
    while (true) {
        if (x < 0 || x >= map.size() || y < 0 || y >= map[0].size()) {
            break;
        }
        if (!visited[x][y]) {
            visited[x][y] = true;
            sol++;
        }
        if (state == 0) {
            if (x - 1 >= 0 && map[x - 1][y] == '#') state = (state + 1) % 4;
            else {
                x--;
            }
        }
        else if (state == 1) {
            if (y + 1 < map[0].size() && map[x][y + 1] == '#') state = (state + 1) % 4;
            else {
                y++;
            }
        }
        else if (state == 2) {
            if (x + 1 < map.size() && map[x + 1][y] == '#') state = (state + 1) % 4;
            else {
                x++;
            }
        }
        else if (state == 3) {
            if (y - 1 >= 0 && map[x][y - 1] == '#') state = (state + 1) % 4;
            else {
                y--;
            }
        }
    }
    cout << sol << endl;
}

struct State {
    int x, y, dir;
    bool operator<(const State &other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return dir < other.dir;
    }
    bool operator==(const State &other) const {
        return x == other.x && y == other.y && dir == other.dir;
    }
};

void solve2() {
    ll sol = 0;
    vector<vector<char>> map;
    string line;
    while (getline(cin, line)) {
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        map.push_back(row);
    }

    int startX = -1, startY = -1, startDir = -1;
    bool found = false;

    for (int i = 0; i < (int)map.size(); i++) {
        for (int j = 0; j < (int)map[i].size(); j++) {
            if (map[i][j] == '^') { startX = i; startY = j; startDir = 0; found = true; break; }
        }
        if (found) break;
    }

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++) {
            if ((i == startX && j == startY) || map[i][j] == '#') continue;
            set<State> visited;
            map[i][j] = '#';
            State guard{startX, startY, startDir};
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};

            while (true) {
                if (guard.x < 0 || guard.x >= map.size() || guard.y < 0 || guard.y >= map[0].size()) {
                    break;
                }
                if (visited.find(guard) != visited.end()) {
                    sol++;
                    break;
                }
                visited.insert(guard);

                int nx = guard.x + dx[guard.dir];
                int ny = guard.y + dy[guard.dir];
                bool forwardBlocked = false;
                if (nx < 0 || nx >= map.size() || ny < 0 || ny >= map[0].size()) {
                    break;
                }
                if (map[nx][ny] == '#') {
                    forwardBlocked = true;
                }
                if (forwardBlocked) guard.dir = (guard.dir + 1) % 4;
                else {
                    guard.x = nx;
                    guard.y = ny;
                }
            }
            map[i][j] = '.';
        }
    }
    cout << sol << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // auto t = 0;
    // std::cin >> t;
    // for (int i = 0; i < t; i++) {
    //     solve();
    // }
    // solve1();
    solve2();
}