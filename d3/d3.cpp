#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

void solve1() {
    string input;
    string starter = "mul(";
    long long sol = 0;
    while (getline(cin, input)) {
        for (int i = 0; i <= input.size() - 7; i++) {
            if (input[i] == 'm' && input.substr(i, 4) == starter) {
                int x, y;
                int j = i + 4;
                if (!isdigit(input[j])) continue;
                while (isdigit(input[j])) {
                    j++;
                }
                x = stoi(input.substr(i + 4, j - (i + 4)));
                if (input[j] != ',') continue;
                int com = j;
                j++;
                if (!isdigit(input[j])) continue;
                while (isdigit(input[j])) {
                    j++;
                }
                y = stoi(input.substr(com + 1, j - (com + 1)));
                if (input[j] != ')') continue;
                sol += (x * y);
                // cout << x << " * " << y << endl;
            }
        }
    }
    cout << sol << endl;
}

void solve2() {
    string input;
    string starter = "mul(";
    string doo = "do()";
    string dont = "don't()";
    bool on = true;
    long long sol = 0;
    while (getline(cin, input)) {
        for (int i = 0; i <= input.size() - 7; i++) {
            if (input[i] == 'd') {
                if (input.substr(i, 4) == doo) on = true;
                else if (input.substr(i, 7) == dont) on = false;
            }
            else if (on && input[i] == 'm' && input.substr(i, 4) == starter) {
                int x, y;
                int j = i + 4;
                if (!isdigit(input[j])) continue;
                while (isdigit(input[j])) {
                    j++;
                }
                x = stoi(input.substr(i + 4, j - (i + 4)));
                if (input[j] != ',') continue;
                int com = j;
                j++;
                if (!isdigit(input[j])) continue;
                while (isdigit(input[j])) {
                    j++;
                }
                y = stoi(input.substr(com + 1, j - (com + 1)));
                if (input[j] != ')') continue;
                sol += (x * y);
                // cout << x << " * " << y << endl;
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