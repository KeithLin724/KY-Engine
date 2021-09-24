#pragma once
#ifndef KY_GAME_TOOL_H
#define KY_GAME_TOOL_H

#include "Game_point.h"
#include "Game_background.h"
#include "Game_graph.h"
#include "Game_text.h"
#include "Game_event.h"

#define var auto // java style
#define String std::string // java style string

namespace KY_engine {
	class KY_Game_Tool {
	private:
		Game_background bg; 
		std::vector<Game_graph> graph_all; 
		std::vector<Game_text> text_all; 

	public:
		KY_Game_Tool(); 
		~KY_Game_Tool(); 

		//Tool function

		//Backgrand 
		static Game_background& Build_background(std::string PATH);
		static Game_background& Build_background(Quick_background_setup quick_backgrand_setup);

		//point
		static Game_point& Build_point(int x , int y);
		static Game_point& Build_point(long x, long y);
		static Game_point& Build_point(double x, double y);

		//graph
		static Game_graph& Build_graph(std::string path);

		//text 
		static Game_text& Build_text(std::string str ,double x =0, double y  = 0 , int color = Game_color::INIT_WITE);
		static Game_text& Build_text(std::string str, Game_point point, int color = Game_color::INIT_WITE);
		
		static Game_text& Build_text(Game_text GText , Game_point point, int color = Game_color::INIT_WITE);
		static Game_text& Build_text(Game_text GText, double x = 0, double y = 0, int color = Game_color::INIT_WITE);

		//color
		static Game_color& Build_color(int color_text = Game_color::INIT_WITE);

		//event 
		static Game_Event& Build_event();

		static void Draw_Graph(std::vector<std::vector<char>>& in_graph);

		void add(Game_background& bg);
		void add(Game_graph& graph); 
		void add(Game_text& text); 

		void add(std::vector<Game_graph>& graph_arr); 
		void add(std::vector<Game_text>& text_arr); 

		void Draw_init(Game_point end_point = _KYF_NULL_point_);

	};

//fast cmd
#define _KYbuild_ KY_engine::KY_Game_Tool
}


#endif // !KY_GAME_TOOL_H




