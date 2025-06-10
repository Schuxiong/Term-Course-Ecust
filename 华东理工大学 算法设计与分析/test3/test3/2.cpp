//#include <iostream>
//#include <string>
//
//using namespace std;
//
//bool canTransform(string spells[]) {
//    for (int i = 0; spells[i] != "0"; ++i) {
//        if (spells[i][0] == 'b' && spells[i][spells[i].length() - 1] == 'g') {
//            return true;
//        }
//    }
//    return false;
//}
//
//int main() {
//    while (true) {
//        string spells[100];
//        int idx = 0;
//
//        while (true) {
//            cin >> spells[idx];
//            if (spells[idx] == "0") {
//                break;
//            }
//            idx++;
//        }
//
//        if (spells[0] == "0") {
//            break;
//        }
//
//        if (canTransform(spells)) {
//            cout << "Yes." << endl;
//        }
//        else {
//            cout << "No." << endl;
//        }
//    }
//
//    return 0;
//}
