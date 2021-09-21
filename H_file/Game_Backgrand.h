#pragma once

#ifndef GAME_BACKGRAND_H
#define GAME_BACKGRAND_H

#include <vector>
#include <string>
#include "Graph_Window.h"
#include "Game_point.h"
#include "Game_color.h"

namespace KY_engine {

	struct Quick_backgrand_setup {
		char angle, line, V_graph;
		int _W, _H, color; 

		struct GRID {
			bool Grid_mode; 
			int _W, _H; 
			GRID(bool Grid_mode = false, int Grid_W = 2, int Grid_H = 2);
		}Grid;

		Quick_backgrand_setup(int _W = 10, int _H = 10,
			bool Grid_mode = false, char angle = '+', char line = '-', char V_graph = '|', 
			int Grid_W = 2, int Grid_H = 2 , int color = Game_color::INIT_WITE);

	};

	// Game_Color V  , Game_Event V , (maybe)Game_error 
	class Game_Backgrand : protected Graph_Window  {

	private:
		std::vector <std::pair <Game_point, char>> Graph_backgrand;
		//Graph_Window graph_drawer; 
		int _W, _H, color;
		// quit graph is use init base graph
		// user can use the backgrand from txt file 
	/*protected:
		void set_data_Both(int _W, int _H);
		void set_data_Both(std::vector <std::pair <Game_point, char>> Graph_backgrand);*/

	public:
		// constructor 
		Game_Backgrand(); 
		Game_Backgrand(Quick_backgrand_setup quit_set_up); // use Quick_backgrand_setup 
		Game_Backgrand(std::string FILE_PATH , int color = Game_color::INIT_WITE); // file 
		~Game_Backgrand(); 

		// set 
		void set_Backgrand(Quick_backgrand_setup quit_set_up);
		void set_Backgrand_use_file(std::string FILE_PATH);
		
		void set_color(int color); 
		// get 
		std::vector<Game_point> get_Game_Backgrand_point_map(); 
		std::vector<std::vector<char>> get_Game_Backgrand(); 
		int get_High(); 
		int get_Wide(); 
		int get_color(); 

		// function 
		void draw();
		void clear(); 


	};
//fast define 
#define _KYF_bg_ KY_engine::Game_Backgrand
#define _KYF_QBS_ KY_engine::Quick_backgrand_setup

}

#endif // !GAME_BACKGRAND_H