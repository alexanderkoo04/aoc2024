#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

void solve1() {
    string input;
    long long sol = 0;
    while (getline(cin, input)) {
        stringstream ss(input);
        int num;
        int prev;
        bool safe = true;
        bool first = true;
        bool second = false;
        bool greater = true;
        while (ss >> num) {
            if (first) {
                first = false;
                second = true;
                prev = num;
                continue;
            }
            else if (second) {
                second = false;
                if (prev < num && abs(prev - num) < 4) {
                    prev = num;
                }
                else if (prev > num && abs(prev - num) < 4) {
                    greater = false;
                    prev = num;
                }
                else {
                    safe = false;
                    break;
                }
            }
            else if (greater) {
                if (prev < num && abs(prev - num) < 4) {
                    prev = num;
                }
                else {
                    safe = false;
                    break;
                }
            }
            else if (!greater) {
                if (prev > num && abs(prev - num) < 4) {
                    prev = num;
                }
                else {
                    safe = false;
                    break;
                }
            }
        }
        if (safe) sol++;
    }
    cout << sol << endl;
}

bool safe(vector<ll>& v) {
    if (v.size() <= 2) return true;
    for (int i = 1; i < v.size() - 1; i++) {
        if (abs(v[i - 1] - v[i]) == 0 || abs(v[i - 1] - v[i]) > 3) return false;
        if (abs(v[i + 1] - v[i]) == 0 || abs(v[i + 1] - v[i]) > 3) return false;
        if ((v[i - 1] < v[i] && v[i] > v[i + 1]) || (v[i - 1] > v[i] && v[i] < v[i + 1])) return false;
    }
    return true;

    if (v.size() <= 2) return true;
    bool inc = true, dec = true;
    for (int i = 1; i < v.size(); i++) {
        ll diff = v[i] - v[i - 1];
        if (diff == 0 || abs(diff) > 3) return false;
        if (diff < 0) inc = false;
        if (diff > 0) dec = false;
    }
    return inc || dec;
}

void solve2() {
    string input;
    ll sol = 0;
    while (getline(cin, input)) {
        stringstream ss(input);
        ll num;
        vector<ll> v;
        while (ss >> num) {
            v.push_back(num);
        }
        if (safe(v)) {
            sol++;
            continue;
        }

        bool isSafe = false;
        for (int i = 0; i < v.size(); i++) {
            vector<ll> temp = v;
            temp.erase(temp.begin() + i);
            if (safe(temp)) {
                isSafe = true;
                break;
            }
        }
        if (isSafe) sol++;
    }
    cout << sol << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // auto t = 0;
    // std::cin >> t;
    // for (int i = 0; i < t; i++) {
    //     solve1();
    // }
    // solve1();
    solve2();
}