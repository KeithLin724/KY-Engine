// KYengine(easy).cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include "KY_Game_Tool.h"
//#include <memory>
using namespace std; 

#define END_POINT 100, 100

int main() {
    _KYbuild_ thing_tool; 

    auto text = thing_tool.Build_text("hello", 2, 1, _KYF_color_::BLUE);
    auto backgrand = thing_tool.Build_background(_KYF_QBS_());
    auto graph = thing_tool.Build_graph("Spider_ASCII_art.txt");
    var event = thing_tool.Build_event();

    var text2 = thing_tool.Build_text("very good", 25., 25.); 
    var graph2 = _KYbuild_::Build_graph("cartoon.txt"); 
    //auto point = _KYbuild_::Build_point(0, 50); 

    graph.set_point(0,50);
    graph.set_color(_KYF_color_::RED); 

    graph2.set_color(_KYF_color_::GREEN); 
    graph2.set_point(15, 80); 

    //text2 *= 3; 

    thing_tool.add(text); 
    thing_tool.add(text2); 
    thing_tool.add(graph); 
    thing_tool.add(graph2); 
    thing_tool.add(backgrand); 

    thing_tool.Draw_init(); 

    text2.eraser(); 

    while (event.get_event() != 'q') {
		//std::cout << event.to_HEX() << "\n";
        if (event.get_event_memory() == 'w') {
            graph2.up();
        }
        else if (event.get_event_memory() == 's') {
            graph2.down(); 
        }
        else if (event.get_event_memory() == 'a') {
            graph2.left();
        }
        else if (event.get_event_memory() == 'd') {
            graph2.right();
        }
        else if (event.get_event_memory() == 'e') {
            graph2.up_right();
        }
    }
    
    var G = graph.get_Graph(); 

    _KYbuild_::Draw_Graph(G); 

    _KYF_GW_ MOVE;
    MOVE.Window_gotoxy(END_POINT,_KYF_color_::INIT_WITE);


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