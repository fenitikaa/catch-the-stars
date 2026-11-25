//Catch The Star (Full)
#include "ncurses/curses.h"
using namespace std;
int main() {
    initscr();
    clear(); S

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
        if (tombol == KEY_RIGHT && posisiKolom < 71) {
            posisiKolom++;
        } else if (tombol == KEY_LEFT && posisiKolom > 1) {
            posisiKolom--;
        } else if (tombol == KEY_UP && posisiBaris > 1) {
            posisiBaris--;
        } else if (tombol == KEY_DOWN && posisiBaris < 33) {
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
