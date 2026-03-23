#include "App.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    App *app = appCreate(argc, argv, "Chess");
    if (!app) {
        return 1;
    }

    char possition[8][8] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    srand((unsigned)time(NULL));
    int placed = 0;
    while (placed < 6) {
        int row = rand() % 8;
        int col = rand() % 8;
        if (possition[row][col] == ' ') {
            possition[row][col] = 'Q';
            placed++;
        }
    }
    tableFill(app->table, possition);

    appLoopStart(app);
    return 0;
}
