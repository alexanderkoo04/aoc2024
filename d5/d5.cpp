#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

void solve1() {
    string input;
    ll sol = 0;
    unordered_map<int, vector<int>> graph;
    while (getline(cin, input)) {
        if (input.empty()) break;
        int first = stoi(input.substr(0, 2));
        int second = stoi(input.substr(3, 2));
        graph[second].push_back(first);
    }

    string input2;

    while (getline(cin, input2)) {
        unordered_set<int> visited2;
        unordered_set<int> current2;
        deque<int> q2;
        stringstream ss2(input2);
        int num2;
        char comma2;
        while (ss2 >> num2) {
            q2.push_back(num2);
            current2.insert(num2);
            ss2 >> comma2;
        }

        bool good2 = true;

        for (int i = 0; i < q2.size(); i++) {
            int node2 = q2[i];
            for (auto neighbor : graph[node2]) {
                if (current2.find(neighbor) != current2.end() && visited2.find(neighbor) == visited2.end()) {
                    good2 = false;
                    break;
                }
            }
            if (!good2) break;
            visited2.insert(node2);
        }

        if (good2) {
            cout << "+" << q2[q2.size() / 2] << endl;
            sol += q2[q2.size() / 2];
        }

    }
    cout << sol << endl;
}

void solve2() {
    vector<unordered_set<int>> new_graph;
    string input;
    ll sol = 0;
    unordered_map<int, vector<int>> graph;
    while (getline(cin, input)) {
        if (input.empty()) break;
        int first = stoi(input.substr(0, 2));
        int second = stoi(input.substr(3, 2));
        graph[second].push_back(first);
    }

    string input2;
    while (getline(cin, input2)) {
        unordered_set<int> visited2;
        unordered_set<int> current2;
        deque<int> q2;
        stringstream ss2(input2);
        int num2;
        char comma2;
        while (ss2 >> num2) {
            q2.push_back(num2);
            current2.insert(num2);
            ss2 >> comma2;
        }

        bool good2 = true;

        for (int i = 0; i < q2.size(); i++) {
            int node2 = q2[i];
            for (auto neighbor : graph[node2]) {
                if (current2.find(neighbor) != current2.end() && visited2.find(neighbor) == visited2.end()) {
                    good2 = false;
                    break;
                }
            }
            if (!good2) break;
            visited2.insert(node2);
        }

        if (!good2) {
            new_graph.push_back(current2);
        }

    }

    for (auto nodes : new_graph) {
        unordered_map<int, int> in_degree;

        for (const auto& node : nodes) {
            in_degree[node] = 0;
        }

        for (const auto& [node, neighbors] : graph) {
            if (nodes.find(node) != nodes.end()) {
                for (const auto& neighbor : neighbors) {
                    if (nodes.find(neighbor) != nodes.end()) {
                        in_degree[neighbor]++;
                    }
                }
            }
        }

        queue<int> q;
        for (const auto& [node, degree] : in_degree) {
            if (degree == 0) {
                q.push(node);
            }
        }

        vector<int> sorted;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            sorted.push_back(current);
            if (graph.find(current) != graph.end()) {
                for (const auto& neighbor : graph[current]) {
                    if (nodes.find(neighbor) != nodes.end()) {
                        in_degree[neighbor]--;
                        if (in_degree[neighbor] == 0) {
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        if (sorted.size() != nodes.size()) continue;
        sol += sorted[sorted.size() / 2];
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
    solve2();
}