#include <iostream>

using namespace std;

//Fill the TicTacToe matrix and check immediately if there is an obvious win
int fill_ttt(char ttt[3][3], char* winner, int instantWin) {
    int j;
    for (int i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            cin >> ttt[i][j];

            //Check if there is a row win at position j
            if (j == 2) {
                if ((ttt[i][j] == ttt[i][j - 1]) && (ttt[i][j] == ttt[i][j - 2])) {
                    instantWin = 1;
                    *winner = ttt[i][j];
                    break;
                }
            }

        }

        //Check if there is a column win
        if (i == 2) {
            if ((ttt[i][0] == ttt[i - 1][0]) && (ttt[i][0] == ttt[i - 2][0])) {
                instantWin = 1;
                *winner = ttt[i][0];
                break;
            }
            else if ((ttt[i][1] == ttt[i - 1][1]) && (ttt[i][1] == ttt[i - 2][1])) {
                instantWin = 1;
                *winner = ttt[i][1];
                break;
            }
            else if ((ttt[i][2] == ttt[i - 1][2]) && (ttt[i][2] == ttt[i - 2][2])) {
                instantWin = 1;
                *winner = ttt[i][2];
                break;
            }
        }

    }

    return instantWin;
}

int ttt_checker(char ttt[3][3], char* winner, int win) {
    //Check the last 2 possibilities in a diagonal win
    if (ttt[0][0] == ttt[1][1] && ttt[0][0] == ttt[2][2]) {
        win = 1;
        *winner = ttt[0][0];
    }
    if (ttt[0][2] == ttt[1][1] && ttt[0][2] == ttt[2][0]) {
        win = 1;
        *winner = ttt[0][2];
    }

    return win;
}

int main()
{
    char ttt[3][3], winner = '?';
    int instantWin = 0, win = 0;

    instantWin = fill_ttt(ttt, &winner, instantWin);

    if (instantWin == 1 && (winner == 'x' || winner == 'o')) { //Make sure to not consider blank spaces as a winner
        cout << "The winner is " << winner << endl;
    }
    else {
        win = ttt_checker(ttt, &winner, win);
        if (win == 1 && (winner == 'x' || winner == 'o')) { //Make sure to not consider blank spaces as a winner
            cout << "The winner is " << winner << endl;
        }
        else {
            cout << "It's a tie " << endl;
        }
    }

    return 0;

}