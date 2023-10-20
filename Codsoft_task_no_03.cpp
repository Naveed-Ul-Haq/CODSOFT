#include <iostream>
#include <vector>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void  Board(const vector<vector<char>>& board) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            cout << board[row][col];
            if (col < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (row < 2) {
            cout << "---------" << endl;
        }
    }
    cout << endl;
}


bool Win(const vector<vector<char>>& board, char player) {

    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; 
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; 
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; 
    }
    return false;
}


bool Draw(const vector<vector<char>>& board) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == ' ') {
                return false; 
            }
        }
    }
    return true;
}

int main(int argc, char** argv)  {
    vector<vector<char>> board(3, vector<char>(3, ' ')); 
    char currentPlayer = 'X'; 
    bool gameIsOver = false; 

    cout<<" ***************** Tic_Tac_Toe Game ***************** "<<endl<<endl;

    while (!gameIsOver) { 
        Board(board);


        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

  
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue; 
        }

        board[row - 1][col - 1] = currentPlayer;

    
        if (Win(board, currentPlayer)) {
            Board(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
            gameIsOver = true;
        } else if (Draw(board)) {
           Board(board);
            cout << "It's a draw! Good game!" << endl;
            gameIsOver = true;
        }

      
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

	return 0;
}