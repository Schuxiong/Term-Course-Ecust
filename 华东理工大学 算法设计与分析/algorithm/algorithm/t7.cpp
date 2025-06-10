//#include <iostream>
//
//using namespace std;
//
//int calculateTime(int currentFloor, int nextFloor) {
//    int time = 0;
//
//    if (nextFloor > currentFloor) {
//        time += (nextFloor - currentFloor) * 6;
//    }
//    else {
//        time += (currentFloor - nextFloor) * 4;
//    }
//
//    // Add 5 seconds for stopping at the floor
//    time += 5;
//
//    return time;
//}
//
//int main() {
//    int N;
//
//    while (cin >> N && N != 0) {
//        int total_time = 0;
//        int current_floor = 0;
//
//        for (int i = 0; i < N; ++i) {
//            int next_floor;
//            cin >> next_floor;
//
//            total_time += calculateTime(current_floor, next_floor);
//            current_floor = next_floor;
//        }
//
//        cout << total_time << endl;
//    }
//
//    return 0;
//}
