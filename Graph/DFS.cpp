//DEPTH FIRST SEARCH OF THE GRAPH USING ARRAY OR SAY VECTOR IN CPP
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    vector<bool> visited(n, false);
    stack<int> st;
    vector<int> result;

    
    st.push(0);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            result.push_back(node);

            
            for (int i = n - 1; i >= 0; i--) {
                if (adj[node][i] == 1 && !visited[i]) {
                    st.push(i);
                }
            }
        }
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
