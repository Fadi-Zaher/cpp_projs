#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

int main() {
    // 0 Scissor
    // 1 Paper
    // 2 Rock
    map<int,string> myMap = {{0,"Scissor"}, {1,"Paper"}, {2,"Rock"}};
    
    cout << "Welcome to Rock Paper Scissor game:\n";
    cout << "You can pick one of the following options:\n";
    cout << "1. Scissor\n2. Rock\n3. Paper\n";
    cout << "The winner is the first to reach 3 points.\n" << endl;

    int result_pc = 0, result_user = 0;
    while (result_pc < 3 && result_user < 3) {
        int inp, x;
        cout << "Type your choice (1 for Scissor, 2 for Rock, 3 for Paper): ";
        cin >> inp;
        if (inp < 1 || inp > 3) {
            cout << "Invalid input! Please choose again.\n";
            continue;
        }
        inp--; // Convert to zero-based index for array access

        x = rand() % 3;

        if (inp == x) {
            cout << "DRAW!\n";
        } else {
            if ((inp == 0 && x == 2) || (inp == 1 && x == 0) || (inp == 2 && x == 1)) {
                cout << "You won! You picked " << myMap[inp] << " and PC picked " << myMap[x] << endl;
                result_user++;
            } else {
                cout << "You lost! You picked " << myMap[inp] << " and PC picked " << myMap[x] << endl;
                result_pc++;
            }
        }
    }

    if (result_user > result_pc) {
        cout << "Congratulations! You won with " << result_user << " points against PC's " << result_pc << " points." << endl;
    } else {
        cout << "Sorry! You lost with " << result_user << " points against PC's " << result_pc << " points." << endl;
    }

    return 0;
}
