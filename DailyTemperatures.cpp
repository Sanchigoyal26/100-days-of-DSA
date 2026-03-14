#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for(int i = 0; i < n; i++) {

        while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int idx = st.top();
            st.pop();
            ans[idx] = i - idx;
        }

        st.push(i);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> temps(n);

    for(int i = 0; i < n; i++)
        cin >> temps[i];

    vector<int> result = dailyTemperatures(temps);

    for(int x : result)
        cout << x << " ";

    return 0;
}