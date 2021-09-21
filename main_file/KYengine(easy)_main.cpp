// KYengine(easy).cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include "Game_Backgrand.h"
#include "Game_graph.h"
#include "Game_Text.h"
#include "KY_Game_Tool.h"
using namespace std; 

#define END_POINT 100, 100

int main() {
    _KYbuild_ thing_tool; 

    auto text = thing_tool.Build_text("hello", 2., 1., _KYF_color_::BLUE); 
    auto backgrand = thing_tool.Build_backgrand(_KYF_QBS_());
    auto graph = thing_tool.Build_graph("Spider_ASCII_art.txt");
    auto event = thing_tool.Build_event();
    //auto point = _KYbuild_::Build_point(0, 50); 

    graph.set_point(0,50);
    graph.set_color(_KYF_color_::RED); 

    thing_tool.add(text); 
    thing_tool.add(graph); 
    thing_tool.add(backgrand); 

    thing_tool.Draw_init(); 
    /*backgrand.draw();
    text.write();

    graph.graph_draw();*/
    //graph.graph_clean();

    //auto get = graph.get_Graph(); 

    while (event.get_event() != 'q') {
		std::cout << event.to_HEX() << "\n";
    }
    /*std::cout << "\n";
    for (auto &elme : get) {
        for (auto &el : elme) {
            std::cout << el; 
        }
        std::cout << "\n";
    }*/

    KY_engine::Graph_Window MOVE;
    MOVE.gotoxy(END_POINT);


    return 0; 
}


/*int main() {
    KY_engine::Game_Text out_text("hello", 2., 1., KY_engine::Game_color::BLUE);

     KY_engine::Quick_backgrand_setup quit_set_up;
     KY_engine::Game_Backgrand game_backgrand(quit_set_up);

     KY_engine::Game_graph spider_man("Spider_ASCII_art.txt");



     spider_man.set_point(0, 50);

     game_backgrand.draw();
     out_text.write();

     spider_man.graph_draw();

     KY_engine::Graph_Window MOVE;
     MOVE.gotoxy(END_POINT);

    
    return 0;
}*/