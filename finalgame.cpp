//Kelompok TrioSugeh
#include "ncurses.h"
#include <cstdlib>
#include <ctime>

int main() {
    initscr();
    clear();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    srand(time(0));
    start_color();
    use_default_colors();

    init_pair(1, COLOR_MAGENTA, -1); //untuk judul
    init_pair(2, COLOR_CYAN, -1); //untuk wadah
    init_pair(3, COLOR_YELLOW, -1); //untuk bintang

    // ============= BAGIAN ARDI ==========
    // tampilan awal game
    nodelay(stdscr, FALSE);
    mvprintw(5, 32, "CATCH THE STARS!");
    mvprintw(7, 21, "Klik tombol apa saja untuk memulai...");
    refresh();
    getch();
    clear();
    nodelay(stdscr, TRUE);

    // ==================== BAGIAN FENI ====================
    // Arena dan posisi wadah pemain
    WINDOW *arena = newwin(35, 80, 0, 0);
    int posisiKolom = 12;
    int posisiBaris = 33;
    int hitunganFrame = 0;

    // ==================== BAGIAN RANGGA ====================
    // Lima bintang dengan posisi dan gerak jatuh acak
    int barisBintang[5], kolomBintang[5];

    for (int i = 0; i < 5; i++) {
        barisBintang[i] = rand() % 32;
        kolomBintang[i] = rand() % 40 + 25;
    }
    // ================= BAGIAN ARDI =================
    // timer dan score
    int score = 0;
    int timer = 30;
    time_t start = time(0);

    do {
        // Menghitung waktu permainan
        timer = 30 - (time(0) - start);

        if (timer <= 0) {
            break;
        }
        // ==================== BAGIAN FENI ====================
        // Kontrol wadah pemain
        int tombol = getch();
        if (tombol == KEY_RIGHT && posisiKolom < 71) {
            posisiKolom++; 
        } else if (tombol == KEY_LEFT && posisiKolom > 1) {
            posisiKolom--; 
        }

        // ==================== BAGIAN RANGGA ====================
        // Gerak jatuh bintang dan reset posisi acak
        if (++hitunganFrame == 15) {
            hitunganFrame = 0;
            for (int i = 0; i < 5; i++) {
                if (++barisBintang[i] >= posisiBaris &&
                    kolomBintang[i] >= posisiKolom &&
                    kolomBintang[i] <= posisiKolom + 7) {
                    score++;
                    barisBintang[i] = rand() % 10;
                    kolomBintang[i] = rand() % 40 + 25;
                    }
                else if (barisBintang[i] >= 34) {
                    barisBintang[i] = rand() % 10;
                    kolomBintang[i] = rand() % 40 + 25;
                }
            }
        }

        werase(arena);
        box(arena, 0, 0);
        wattron(arena, COLOR_PAIR(1));
        mvwprintw(arena, 1, 32, "CATCH THE STARS");
        wattroff(arena, COLOR_PAIR(1));
        
        // ============== BAGIAN ARDI =============
        // tampilan timer and score 
        mvwprintw(arena, 2, 2, "Score: %d", score);
        mvwprintw(arena, 2, 15, "Time: %d", timer);

        // ==================== BAGIAN RANGGA ====================
        // Menampilkan bintang
        for (int i = 0; i < 5; i++) {
            wattron(arena, COLOR_PAIR(3));
            mvwprintw(arena, barisBintang[i], kolomBintang[i], "*");
            wattroff(arena, COLOR_PAIR(3));
        }
        
        // ==================== BAGIAN FENI ====================
        // Menampilkan wadah pemain
        wattron(arena, COLOR_PAIR(2));
        mvwprintw(arena, posisiBaris, posisiKolom, "[======]");
        wattroff(arena, COLOR_PAIR(2));
        wrefresh(arena);
        napms(20);
    } while (TRUE);

    // ============= BAGIAN ARDI ================
    // tampilan akhir
    clear();
    mvprintw(5, 5, "GAME OVER!");
    mvprintw(7, 5, "Final Score: %d", score);
    refresh();
    nodelay(stdscr, FALSE);
    getch();

    endwin();
    return 0;
}
