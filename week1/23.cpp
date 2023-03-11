#include <vector>
#include <stack>
using namespace std;
void solve(int N, int order[]) {
    vector<int> loc(N+1,0);
    stack<int> places;
    for (int i = N; i >= 1; i--) {
        places.push(i);
    }
    stack<int> first_station;
    stack<int> second_station;
    for (int i = 0; i < N; i++) {
        if (loc[order[i]] == 0) {
            while (places.top() != order[i]) {
                loc[places.top()] = 1;
                int temp = places.top();
                first_station.push(temp);
                places.pop();
                push_train();
            }
            places.pop();
            loc[order[i]] = 3;
            push_train();
            move_station_1_to_2();
            pop_train();
        } else if (loc[order[i]] == 1) {
            while (first_station.top() != order[i]) {
                loc[first_station.top()] = 2;
                int temp = first_station.top();
                second_station.push(temp);
                first_station.pop();
                move_station_1_to_2();
            }
            first_station.pop();
            loc[order[i]] = 3;
            move_station_1_to_2();
            pop_train();
        } else if (loc[order[i]] == 2) {
            while (second_station.top() != order[i]) {
                loc[second_station.top()] = 1;
                int temp = second_station.top();
                first_station.push(temp);
                second_station.pop();
                move_station_2_to_1();
            }
            second_station.pop();
            loc[order[i]] = 3;
            pop_train();
        }
    }
}