//KelompokTrioSugeh
#include "ncurses.h"
using namespace std;
int main() {
    initscr();
    clear();
    keypad(stdscr, TRUE);

    WINDOW *arena = newwin(35, 80, 0, 0);

    int tombol;
    int posisiKolom = 12;
    int posisiBaris = 33;

    box(arena, 0, 0);
    mvwprintw(arena, 1, 30, "CATCH THE STARS");
    mvwprintw(arena, posisiBaris, posisiKolom, "[======]");
    wrefresh(arena);
    
    do {
        tombol = getch();
        if (tombol == KEY_RIGHT) {
            posisiKolom++;
        } else if (tombol == KEY_LEFT) {
            posisiKolom--;
        }

        werase(arena);
        box(arena, 0, 0);
        mvwprintw(arena, 1, 25, "CATCH THE STARS");
        mvwprintw(arena, posisiBaris, posisiKolom, "[======]");
        wrefresh(arena);

    } while (TRUE);
    
    endwin();
    return 0;

}
