#pragma once

#ifndef GAME_BACKGRAND_H
#define GAME_BACKGRAND_H

#include <vector>
#include <string>
#include "Graph_Window.h"
#include "Game_point.h"
#include "Game_color.h"

namespace KY_engine {

	struct Quick_background_setup {
		char angle, line, V_graph;
		int _W, _H, color; 

		struct GRID {
			bool Grid_mode; 
			int _W, _H; 
			GRID(bool Grid_mode = false, int Grid_W = 2, int Grid_H = 2);
		}Grid;

		Quick_background_setup(int _W = 10, int _H = 10,
			bool Grid_mode = false, char angle = '+', char line = '-', char V_graph = '|', 
			int Grid_W = 2, int Grid_H = 2 , int color = Game_color::INIT_WITE);

	};
	
	class Game_background : protected Graph_Window  {

	private:
		std::vector <std::pair <Game_point, char>> Graph_background;
		int _W, _H, color;
		// quit graph is use init base graph
		// user can use the background from txt file 

	public:
		// constructor 
		Game_background(); 
		Game_background(Quick_background_setup quit_set_up); // use Quick_backgrand_setup 
		Game_background(std::string FILE_PATH , int color = Game_color::INIT_WITE); // file 
		~Game_background(); 

		// set 
		void set_background(Quick_background_setup quit_set_up);
		void set_background_use_file(std::string FILE_PATH);
		
		void set_color(int color); 
		// get 
		std::vector<Game_point> get_Game_background_point_map(); 
		std::vector<std::vector<char>> get_Game_background(); 
		int get_high() const; 
		int get_wide() const;
		int get_color() const; 

		// function 
		void draw();
		void clear(); 


	};
//fast define 
#define _KYF_bg_ KY_engine::Game_background
#define _KYF_QBS_ KY_engine::Quick_background_setup

}

#endif // !GAME_BACKGRAND_H
