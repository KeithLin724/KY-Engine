#pragma once

#ifndef KY_ENGINE_GRAPH_WINDOW_H
#define KY_ENGINE_GRAPH_WINDOW_H

#include <Windows.h>
#include "Game_point.h"

namespace KY_engine {

    class Graph_Window {
    private:
        COORD scrn;
        HANDLE hOuput;
    protected:
        void gotoCenter(int W, int H);

    public:
        Graph_Window();

        void Textcolor(int color);

        void gotoxy(int xpos, int ypos);
        void gotoxy(Game_point& game_point);

        void Window_gotoxy(int xpos, int ypos, int color);
        void Window_gotoxy(Game_point& game_point, int color);


    };
}
#endif //!KY_ENGINE_GRAPH_WINDOW_H