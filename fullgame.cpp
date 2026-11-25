//Catch The Star
#include "ncurses/curses.h"
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    initscr();
    clear();
    keypad(stdscr, TRUE);

    WINDOW *arena = newwin(35, 80, 0, 0);
    
    keypad(arena, TRUE);
    nodelay(arena, TRUE);
    int tinggiArena, lebarArena;
    getmaxyx(arena, tinggiArena, lebarArena);
    
    int tombol;
    int posisiKolom = 12;
    int posisiBaris = 33;

    srand(time(0));
    int bintangBaris[3] = {2, 7, 12};
    int bintangKolom[3] = {
        rand() % (lebarArena - 2) + 1,
        rand() % (lebarArena - 2) + 1,
        rand() % (lebarArena - 2) + 1
    };
    
    box(arena, 0, 0);
    mvwprintw(arena, 1, 5, "CATCH THE STARS");
    mvwprintw(arena, posisiBaris, posisiKolom, "[======]");
    wrefresh(arena);
    
    do {
        tombol = wgetch(arena);
        if (tombol == KEY_RIGHT) {
            posisiKolom++;
        } else if (tombol == KEY_LEFT) {
            posisiKolom--;
        } 

        
        for (int i = 0; i < 3; i++) {
            bintangBaris[i]++;
            if (bintangBaris[i] >= tinggiArena - 1) {
                bintangBaris[i] = 2;
                bintangKolom[i] = rand() % (lebarArena - 2) + 1;
            }
        }

        werase(arena);
        box(arena, 0, 0);
        mvwprintw(arena, 1, 25, "CATCH THE STARS");
        mvwprintw(arena, posisiBaris, posisiKolom, "[======]");
        
        for (int i = 0; i < 3; i++) {
            mvwprintw(arena, bintangBaris[i], bintangKolom[i], "*");
        }
        wrefresh(arena);
        napms(200);
    } while (TRUE);
    
    endwin();
    return 0;
}
