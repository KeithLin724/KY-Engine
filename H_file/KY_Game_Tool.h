#pragma once
#ifndef KY_GAME_TOOL_H
#define KY_GAME_TOOL_H

#include "Game_point.h"
#include "Game_Backgrand.h"
#include "Game_graph.h"
#include "Game_Text.h"
#include "Game_Event.h"

#define var auto // java style
#define String std::string // java style string

namespace KY_engine {
	class KY_Game_Tool {
	private:
		Game_Backgrand bg; 
		std::vector<Game_graph> graph_all; 
		std::vector<Game_Text> text_all; 


	public:
		KY_Game_Tool(); 
		~KY_Game_Tool(); 

		//Tool function

		//Backgrand 
		static Game_Backgrand Build_backgrand(std::string PATH);
		static Game_Backgrand Build_backgrand(Quick_backgrand_setup quick_backgrand_setup);

		//point
		static Game_point Build_point(int x , int y);
		static Game_point Build_point(long x, long y);
		static Game_point Build_point(double x, double y);

		//graph
		static Game_graph Build_graph(std::string path);

		//text 
		static Game_Text Build_text(std::string str ,double x =0, double y  = 0 , int color = Game_color::INIT_WITE);
		static Game_Text Build_text(std::string str, Game_point point, int color = Game_color::INIT_WITE);

		
		static Game_Text Build_text(Game_Text GText , Game_point point, int color = Game_color::INIT_WITE);
		static Game_Text Build_text(Game_Text GText, double x = 0, double y = 0, int color = Game_color::INIT_WITE);

		//color
		static Game_color Build_color(int color_text = Game_color::INIT_WITE);

		//Event 
		static Game_Event Build_event();

		static void Draw_Graph(std::vector<std::vector<char>> &in_graph); 

		void add(Game_Backgrand& bg);
		void add(Game_graph& graph); 
		void add(Game_Text& text); 

		void add(std::vector<Game_graph>& graph_arr); 
		void add(std::vector<Game_Text>& text_arr); 

		void Draw_init(); 


	};

//fast cmd
#define _KYbuild_ KY_engine::KY_Game_Tool
}


#endif // !KY_GAME_TOOL_H




