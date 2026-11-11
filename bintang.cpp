//bagian Rangga
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
int main() {
    initscr();
    noecho();
    srand(time(0));
    int baris[3] = {0, 5, 10};
    int kolom[3] = {rand() % 40 + 25, rand() % 40 + 25, rand() % 40 + 25};
    while (true) {
        clear();
        for (int i = 0; i < 3; i++) {
            baris[i]++;
            if (baris[i] == 20) {
                baris[i] = 0;
                kolom[i] = rand() % 40 + 25;
            }
            mvprintw(baris[i], kolom[i], "*");
        }
        refresh();
        napms(200);
    }
    endwin();
    return 0;
}
