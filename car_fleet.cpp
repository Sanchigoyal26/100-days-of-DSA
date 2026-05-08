#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {

    int n = position.size();

    // Store {position, time_to_reach}
    vector<pair<int, double>> cars;

    for(int i = 0; i < n; i++) {
        double time = (double)(target - position[i]) / speed[i];
        cars.push_back({position[i], time});
    }

    // Sort by position in descending order
    sort(cars.begin(), cars.end(), greater<pair<int, double>>());

    int fleets = 0;
    double prevTime = 0;

    // Traverse cars from nearest to target
    for(auto car : cars) {

        double currTime = car.second;

        // New fleet formed
        if(currTime > prevTime) {
            fleets++;
            prevTime = currTime;
        }
    }

    return fleets;
}

int main() {

    int target = 12;

    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    cout << "Number of Car Fleets: "
         << carFleet(target, position, speed);

    return 0;
}