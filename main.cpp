#include <iostream>
#include <string>

using namespace std;

string lineOne, lineTwo, lineThree;

bool correct_line(string line) {
    int count=0;
    if (line.length()==3) {
        for (int i = 0; i<line.length(); i++){
            if (line[i]=='X' || line[i]=='O' || line[i]=='.') {
                count++;
            }
        }
        if (count==3) return true;
        else return false;
    }
    else {
        return false;
    }
}

bool horizontal_check(string line) {
    if (line[0]==line[1] && line[1]==line[2]) {
        return true;
    }
    else return false;
}

int column;
bool vertical_check(string one, string two, string three) {
    for (int j=0; j<3; j++) {
        if (one[j]==two[j] && one[j]==three[j]) {
            column=j;
            return true;
        }
        else return false;
    }
}

bool diagonal_check(string one, string two, string three) {
    if ((one[0]==two[1] && one[0]==three[2]) || (one[2]==two[1] && one[2]==three[0])) {
        return true;
    }
    else return false;
}

int main() {
    cout << "Enter the tic-tac-toe game field in the format of three lines (X O . characters are allowed): " << endl;
    cin >> lineOne >> lineTwo >> lineThree;
    cout<<correct_line(lineOne)<<endl;
    cout<<correct_line(lineTwo)<<endl;
    cout<<correct_line(lineThree)<<endl;

    if (correct_line(lineOne) != 1 && correct_line(lineTwo) != 1 && correct_line(lineThree) != 1) {
        cout << "Incorrect!";
    } else {
        int xCount = 0, oCount = 0;
        for (int i = 0; i < 3; i++) {
            if (lineOne[i] == 'X' || lineTwo[i] == 'X' || lineThree[i] == 'X') {
                xCount++;
            }
            if (lineOne[i] == 'O' || lineTwo[i] == 'O' || lineThree[i] == 'O') {
                oCount++;
            }
        }
        if (oCount > xCount) {
            cout << "Incorrect!";
        } else {
            if (horizontal_check(lineOne) == 0 && horizontal_check(lineTwo) == 0 && horizontal_check(lineThree) == 0 &&
                vertical_check(lineOne, lineTwo, lineThree) == 0 && diagonal_check(lineOne, lineTwo, lineThree) == 0) {
                cout << "Nobody";
            } else {
                if ((horizontal_check(lineOne) == 1 && lineOne[0] == 'X') ||
                    (horizontal_check(lineTwo) == 1 && lineTwo[0] == 'X')
                    || (horizontal_check(lineThree) == 1 && lineThree[0] == 'X') ||
                    (vertical_check(lineOne, lineTwo, lineThree) == 1
                     && lineOne[column] == 'X') || (diagonal_check(lineOne, lineTwo, lineThree) == 1) &&
                                                   (lineOne[0] == 'X' || lineOne[2] == 'X')) {
                    cout << "Petya won";
                } else {
                    if (xCount < oCount) {
                        cout << "Vanya won";
                    } else cout << "Incorrect!";
                }
            }
        }
    }
}