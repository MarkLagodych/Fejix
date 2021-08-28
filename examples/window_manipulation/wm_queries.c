#include <fejix.h>

int main(int argc, char *argv[])
{
    if (fj_init()) exit(1);

    fj_window *win = fj_wm_queryNewWindow();

    // Set window title
    fj_wm_queryStr(win, 1, FJ_WM_QUERY_WINDOW_TITLE, "Hello, world!");

    // Set window size
    int w = 800;
    int h = 600;
    fj_wm_queryInt2(win, 1, FJ_WM_QUERY_WINDOW_SIZE, &w, &h);

    // Minimize window
    int flag = FJ_WM_FLAG_MINIMIZED;
    int value = 1; // true
    fj_wm_queryInt2(win, 1, FJ_WM_QUERY_WINDOW_FLAG, &flag, &value);

    // Get cursor position
    int x, y;
    fj_wm_queryInt2(win, 0, FJ_WM_QUERY_CURSOR_POS, &x, &y);

    fj_loop();

    // Same as fj_delWindow
    fj_wm_queryDelWindow(win);

    fj_quit();
}
