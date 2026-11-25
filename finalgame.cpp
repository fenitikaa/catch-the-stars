//KelompokTrioSugeh
#include "ncurses.h"
#include <cstdlib>
#include <ctime>

int main() {
    initscr();
    clear();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    srand(time(0));

    // BAGIAN FENI 
    // Arena dan posisi wadah pemain
    WINDOW *arena = newwin(35, 80, 0, 0);
    int posisiKolom = 12;
    int posisiBaris = 33;
    int hitunganFrame = 0;

    // BAGIAN RANGGA
    // Lima bintang dengan posisi dan gerak jatuh acak
    int barisBintang[5], kolomBintang[5];

    for (int i = 0; i < 5; i++) {
        barisBintang[i] = rand() % 32;
        kolomBintang[i] = rand() % 40 + 25;
    }

    while (TRUE) {
        // BAGIAN FENI
        // Kontrol wadah pemain
        int tombol = getch();
        if (tombol == KEY_RIGHT && posisiKolom < 71) posisiKolom++;
        if (tombol == KEY_LEFT && posisiKolom > 1) posisiKolom--;

        // BAGIAN RANGGA
        // Gerak jatuh bintang dan reset posisi acak
        if (++hitunganFrame == 10) {
            hitunganFrame = 0;
            for (int i = 0; i < 5; i++) {
                if (++barisBintang[i] == 32) {
                    barisBintang[i] = rand() % 10;
                    kolomBintang[i] = rand() % 40 + 25;
                }
            }
        }

        werase(arena);
        box(arena, 0, 0);
        mvwprintw(arena, 1, 25, "CATCH THE STARS");

        // BAGIAN RANGGA
        // Menampilkan bintang
        for (int i = 0; i < 5; i++)
            mvwprintw(arena, barisBintang[i], kolomBintang[i], "*");

        // BAGIAN FENI
        // Menampilkan wadah pemain
        mvwprintw(arena, posisiBaris, posisiKolom, "[======]");
        wrefresh(arena);
        napms(20);
    }
}
