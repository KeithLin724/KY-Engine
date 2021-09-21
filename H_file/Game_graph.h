#pragma once

#ifndef KY_ENGINE_GAME_GRAPH_H
#define KY_ENGINE_GAME_GRAPH_H

#include <vector>
#include <string>
#include "Game_color.h"
#include "Game_point.h"
#include "Graph_Window.h"

namespace KY_engine {

	class Game_graph : protected Graph_Window , protected Game_color {

	private:
		Game_point graph_point , right_point; // game point 
		std::vector<std::string> Graph; // Graph 
		int _W, _H; 

		Game_color color; 
	protected:
		void set_point_both(Game_point point); 
		void set_point_both(double x, double y);

	public:
		Game_graph(); 
		~Game_graph();

		Game_graph(std::string FILE_PATH , int color_code = Game_color::INIT_WITE);
		Game_graph(std::string FILE_PATH, Game_point & point , int color_code = Game_color::INIT_WITE);

		// set 
		void set_a_graph_from_file(std::string PATH); 
		void set_to_sqrt(); 
		void set_color(int color_code); 


		void set_point(Game_point &game_point);
		void set_point(int x , int y);
		void set_point(double x, double y); 

		//get
		Game_color& get_color(); 

		Game_point& get_graph_point();

		std::vector<std::vector<char>> get_Graph();

		// fun 
		void graph_draw();
		void graph_clean();
		void clear();

		
	};

//fast cmd
#define _KYFgraph_ KY_engine::Game_graph
}

#endif //!KY_ENGINE_GAME_GRAPH_H