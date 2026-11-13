//bagian feni
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
        mvprintw (2, 12, "==============================");
        mvprintw (3, 12, "| Welcome to Catch the Star  |");
        mvprintw (4, 12, "==============================");
        mvprintw (5, 12, "create by feni, ardi, & rangga");
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
