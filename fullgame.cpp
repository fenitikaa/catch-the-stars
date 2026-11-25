//Catch The Star (Full)
#include "ncurses/curses.h"
using namespace std;
int main() {
    initscr();
<<<<<<< HEAD
    clear(); S
//hhhhh
=======
    clear();
    keypad(stdscr, TRUE);
    
>>>>>>> b4bf77c3f0b07113d1d8651c2e02e3bd658c88a9
    WINDOW *arena = newwin(35, 80, 0, 0);

    int tombol;
    int posisiKolom = 12;
    int posisiBaris = 33;

    box(arena, 0, 0);
    mvwprintw(arena, 1, 5, "CATCH THE STARS");
    mvwprintw(arena, posisiBaris, posisiKolom, "[======]");
    wrefresh(arena);
    
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
        werase(arena);
        box(arena, 0, 0);
        mvwprintw(arena, 1, 25, "CATCH THE STARS");
        mvwprintw(arena, posisiBaris, posisiKolom, "[======]");
        wrefresh(arena);
    } while (TRUE);
    
    endwin();
    return 0;
}
