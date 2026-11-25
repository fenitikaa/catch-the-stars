
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    srand(time(0));

    WINDOW *arena = newwin(35, 80, 0, 0);

    // BAGIAN FENI: WADAH
    int tombol;
    int posisiKolom = 12;
    int posisiBaris = 33;

    // BAGIAN RANGGA: BINTANG
    int baris[3] = {6, 12, 18};
    int kolom[3] = {
        rand() % 40 + 25,
        rand() % 40 + 25,
        rand() % 40 + 25
    };

    // BAGIAN ARDI: SCORE DAN TIMER
    int score = 0;
    int timer = 30;
    time_t start = time(0);

    int waktuBintang = 0;

    keypad(arena, TRUE);
    nodelay(arena, TRUE);

    while (timer > 0) {

        // MEMBACA TOMBOL
        tombol = wgetch(arena);

        // MENGGERAKKAN WADAH
        if (tombol == KEY_RIGHT && posisiKolom < 71) {
            posisiKolom++;
        }
        else if (tombol == KEY_LEFT && posisiKolom > 1) {
            posisiKolom--;
        }
        else if (tombol == 27) {
            break;
        }

        // MENGATUR TIMER
        timer = 30 - (time(0) - start);

        // MENGATUR KECEPATAN BINTANG
        waktuBintang += 10;

        if (waktuBintang >= 200) {

            for (int i = 0; i < 3; i++) {

                baris[i]++;

                // MENDETEKSI BINTANG MENYENTUH WADAH
                if (baris[i] >= posisiBaris) {

                    if (kolom[i] >= posisiKolom &&
                        kolom[i] <= posisiKolom + 7) {

                        score++;
                    }

                    // BINTANG KEMBALI KE ATAS
                    baris[i] = 0;
                    kolom[i] = rand() % 40 + 25;
                }
            }

            waktuBintang = 0;
        }

        // MEMBERSIHKAN ARENA
        werase(arena);
        box(arena, 0, 0);

        // MENAMPILKAN JUDUL
        mvwprintw(arena, 1, 30, "CATCH THE STARS");

        // MENAMPILKAN SCORE DAN TIMER
        mvwprintw(arena, 2, 5, "Score: %d", score);
        mvwprintw(arena, 2, 20, "Time: %d", timer);

        // MENAMPILKAN BINTANG
        for (int i = 0; i < 3; i++) {
            mvwprintw(arena, baris[i], kolom[i], "*");
        }

        // MENAMPILKAN WADAH
        mvwprintw(arena, posisiBaris, posisiKolom, "[======]");

        wrefresh(arena);

        // JEDA PROGRAM
        napms(10);
    }

    // GAME OVER
    werase(arena);
    box(arena, 0, 0);

    mvwprintw(arena, 15, 30, "GAME OVER!");
    mvwprintw(arena, 17, 28, "Final Score: %d", score);

    wrefresh(arena);

    napms(5000);

    delwin(arena);
    endwin();

    return 0;
}
