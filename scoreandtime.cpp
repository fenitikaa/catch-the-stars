//bagian ardi 
#include <ncurses/curses.h>
#include <ctime>
int main() {
    initscr();
    noecho();

    int score = 0;
    int timer = 15;
    time_t start = time(0);

    while (timer > 0) {
        timer = 15 - (time(0) - start);
        clear();

        mvprintw(2, 5, "CATCH THE STARS!");
        mvprintw(4, 5, "Score: %d", score);
        mvprintw(5, 5, "Time: %d", timer);
        refresh();
        napms(200);
    }
        clear();
        mvprintw(5, 7, "GAME OVER!");
        mvprintw(8, 7, "Final Score: %d", score);
        refresh();
        napms(5000);
        endwin();
        return 0;
    }
