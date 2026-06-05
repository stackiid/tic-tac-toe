#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Board holds either '1'-'9' (available spots) or 'X'/'O' (played moves)
char board[3][3];
string player1, player2;

// Refill board with position numbers for a fresh round
void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = num++;
}

void showBoard() {
    system("cls");
    cout << "\n  +------  TIC-TAC-TOE  ------+\n";
    cout << "    " << player1 << " [X]   vs   " << player2 << " [O]\n\n";

    for (int i = 0; i < 3; i++) {
        cout << "      ";
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        if (i < 2) cout << "\n      ---|---|---";
        cout << "\n";
    }
    cout << "\n";
}

// Check all rows, columns, and both diagonals for a winner
bool hasWon() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

// Plays one full round. Returns 1 = player1 wins, 2 = player2 wins, 0 = draw
int playRound() {
    int turn = 0;

    while (turn < 9) {
        showBoard();

        bool   isP1    = (turn % 2 == 0);
        string curName = isP1 ? player1 : player2;
        char   curMark = isP1 ? 'X' : 'O';

        cout << "  " << curName << " [" << curMark << "]  >>  Choose a position (1-9): ";

        int pos;
        if (!(cin >> pos)) {
            // user typed something that isn't a number
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Numbers only. Press Enter to try again...";
            cin.get();
            continue;
        }

        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;

        if (pos < 1 || pos > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "  That spot is already taken or out of range. Press Enter...";
            cin.ignore();
            cin.get();
            continue;
        }

        board[row][col] = curMark;
        turn++;

        if (hasWon()) {
            showBoard();
            cout << "  *** " << curName << " wins this round! ***\n";
            return isP1 ? 1 : 2;
        }
    }

    showBoard();
    cout << "  It's a draw — well played both!\n";
    return 0;
}

int main() {
    system("cls");

    cout << "\n  ======  TIC-TAC-TOE  ======\n\n";
    cout << "  Player 1 name: ";
    getline(cin, player1);
    cout << "  Player 2 name: ";
    getline(cin, player2);

    cout << "\n  " << player1 << " will play as [X]\n";
    cout << "  " << player2 << " will play as [O]\n";
    cout << "\n  Press Enter to start...";
    cin.get();

    int p1Wins = 0, p2Wins = 0, draws = 0;
    char again  = 'y';

    while (again == 'y' || again == 'Y') {
        resetBoard();
        int result = playRound();

        if      (result == 1) p1Wins++;
        else if (result == 2) p2Wins++;
        else                  draws++;

        cout << "\n  -------- Scoreboard --------\n";
        cout << "  " << player1 << "  :  " << p1Wins << " win(s)\n";
        cout << "  " << player2 << "  :  " << p2Wins << " win(s)\n";
        cout << "  Draws         :  " << draws    << "\n";
        cout << "  ----------------------------\n\n";

        cout << "  Play another round? (y/n): ";
        cin >> again;
        cin.ignore();
    }

    cout << "\n  Game over! Final result:\n";
    cout << "  " << player1 << "  :  " << p1Wins << " win(s)\n";
    cout << "  " << player2 << "  :  " << p2Wins << " win(s)\n";
    cout << "  Draws  :  " << draws << "\n\n";

    return 0;
}
