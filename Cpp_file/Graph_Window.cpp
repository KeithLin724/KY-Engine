#include "Graph_Window.h"
namespace KY_engine {

    Graph_Window::Graph_Window() {
        this->scrn = {};
        this->hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    void Graph_Window::Textcolor(int color) {
        SetConsoleTextAttribute(this->hOuput, color);
        return;
    }

    void Graph_Window::gotoxy(int xpos, int ypos) {
        this->scrn.X = xpos; this->scrn.Y = ypos;
        SetConsoleCursorPosition(this->hOuput, this->scrn);
        return;
    }

    void Graph_Window::Window_gotoxy(int xpos, int ypos, int color) {
        this->scrn.X = xpos; this->scrn.Y = ypos;
        SetConsoleCursorPosition(this->hOuput, this->scrn);
        SetConsoleTextAttribute(this->hOuput, color);
        return;
    }

    void Graph_Window::gotoxy(Game_point& game_point) {
        this->scrn.X = game_point.get_x(); this->scrn.Y = game_point.get_y();
        SetConsoleCursorPosition(this->hOuput, this->scrn);
        return;
    }

    void Graph_Window::Window_gotoxy(Game_point& game_point, int color) {
        this->scrn.X = game_point.get_x(); this->scrn.Y = game_point.get_y();
        SetConsoleCursorPosition(this->hOuput, this->scrn);
        SetConsoleTextAttribute(this->hOuput, color);
        return;
    }

    void Graph_Window::gotoCenter(int W, int H) {
        this->gotoxy(W / 2, H / 2);
        return;
    }
}