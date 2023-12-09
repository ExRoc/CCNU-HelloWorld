#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& pipe1, vector<int>& pipe2) {
    return pipe1[2] < pipe2[2];
}
int Find(vector<int>v,int i) {
	return v[i] == i ? i : v[i] = Find(v,v[i]);
}
void Union(vector<int>&v,int i, int j) {
    int pi = Find(v, i);
    int pj = Find(v, j);
    v[pi] = v[pj];
}

int main()
{
    int n, m, a, b, c, answer = 0;
    cin >> n >> m;
    vector<int> parent(n + 1, 0);  //take 0 as source of all
    vector<int>base_cost(n);
    vector<vector<int>>pipe_cost(m, vector<int>(3));
    for (int i = 0; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < n; i++) { //add node 0
        cin >> base_cost[i];
        pipe_cost.push_back(vector<int>({ 0,i + 1,base_cost[i] }));
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        pipe_cost.push_back(vector<int>({ a,b,c}));
    }
    sort(pipe_cost.begin(), pipe_cost.end(), cmp);
    for (auto& pipe : pipe_cost) {
        if (Find(parent, pipe[0]) == Find(parent, pipe[1]))
            continue;
        answer += pipe[2];
        Union(parent, pipe[0], pipe[1]);
    }
    cout << answer;
}