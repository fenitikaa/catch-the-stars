#include "ncurses.h"
using namespace std;
int main() {
    initscr();
    clear();
    keypad(stdscr, TRUE);

    int tombol;
    int posisiKolom = 12;
    int posisiBaris = 33;
    
    do {
        tombol = getch();
        if (tombol == KEY_RIGHT) {
            posisiKolom++;
        } else if (tombol == KEY_LEFT) {
            posisiKolom--;
        } else if (tombol == KEY_UP) {
            posisiBaris--;
        } else if (tombol == KEY_DOWN) {
            posisiBaris++;
        }
        clear();
        mvprintw (posisiBaris, posisiKolom, "[======]");
        refresh;
    } while (TRUE);
    
    endwin();
    return 0;

}
