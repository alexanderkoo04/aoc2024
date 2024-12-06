#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

const vector<pair<int, int>> directions = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
    {1, 1},
    {-1, -1},
    {1, -1},
    {-1, 1}
};

void solve1() {
    long long sol = 0;
    string word = "XMAS";
    string input;
    vector<vector<char>> grid;
    while (getline(cin, input)) {
        vector<char> row;
        for (auto c : input) {
            row.push_back(c);
        }
        grid.push_back(row);
    }

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 'X') {
                // sol += search(grid, i, j, 0, word);

                for (auto& dir : directions) {
                    int ni = i, nj = j;
                    bool found = true;

                    for (int k = 1; k < word.size(); k++) {
                        ni += dir.first;
                        nj += dir.second;

                        if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size()) {
                            found = false;
                            break;
                        }

                        if (grid[ni][nj] != word[k]) {
                            found = false;
                            break;
                        }
                    }
                    
                    if (found) {
                        sol++;
                    }
                }
            }
        }
    }
    cout << sol << endl;
}

void solve2() {
    long long sol = 0;
    string input;
    vector<vector<char>> grid;
    while (getline(cin, input)) {
        vector<char> row;
        for (auto c : input) {
            row.push_back(c);
        }
        grid.push_back(row);
    }
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 'A') {
                if (i - 1 >= 0 && i + 1 < grid.size() && j - 1 >= 0 && j + 1 < grid[i].size()) {
                    char nw = grid[i - 1][j - 1];
                    char ne = grid[i - 1][j + 1];
                    char sw = grid[i + 1][j - 1];
                    char se = grid[i + 1][j + 1];

                    bool combo1 = (nw == 'M' && se == 'S') && (ne == 'M' && sw == 'S');
                    bool combo2 = (nw == 'M' && se == 'S') && (ne == 'S' && sw == 'M');
                    bool combo3 = (nw == 'S' && se == 'M') && (ne == 'M' && sw == 'S');
                    bool combo4 = (nw == 'S' && se == 'M') && (ne == 'S' && sw == 'M');
                    if (combo1 || combo2 || combo3 || combo4) {
                        sol++;
                    }
                }
            }
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