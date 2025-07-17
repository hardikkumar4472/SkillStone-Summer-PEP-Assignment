#include<bits/stdc++.h>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int, int>> cars;
    for (int i = 0; i < n; ++i) {
        cars.push_back({position[i], speed[i]});
    }
    sort(cars.begin(), cars.end());
    stack<double> st;
    for (int i = n - 1; i >= 0; --i) {
        double time = (double)(target - cars[i].first) / cars[i].second;
        if (st.empty() || time > st.top()) {
            st.push(time);
        }
    }
    return st.size();
}

int main() {
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    int result = carFleet(target, position, speed);
    cout<<result;
    return 0;
}