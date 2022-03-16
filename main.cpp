#include <iostream>
#include <cstring>

#include "board.h"
#include "game_object/player.h"

using namespace std;

void printLines(int columns) {
    for (int i = 0; i < columns; i++) {
        cout << "+----";
    }
    cout << "+" << endl;
}

int main() {
    setlocale(LC_ALL, "rus");

    Board board(7, 7);
    GameObject *player = new Player("Oleg");
    board.getCellAt(0, 0)->setObject(player);

    printLines(board.getCols());
    for (int i = 0; i < board.getRows(); ++i) {
        for (int j = 0; j < board.getCols(); ++j) {
            char *symbol = board.getCellAt(i, j)->getSymbol();
            cout << "| " << symbol;
            if (strlen(symbol) == 1) {
                cout << "  ";
            } else {
                cout << " ";
            }
        }
        cout << "|" << endl;
        printLines(board.getCols());
    }

    return 0;
}
