#pragma once

#ifndef KY_ENGINE_GAME_GRAPH_H
#define KY_ENGINE_GAME_GRAPH_H

#include <vector>
#include <string>
#include "Game_color.h"
#include "Game_point.h"
#include "Graph_Window.h"
#include "Game_contro.h"

namespace KY_engine {

	class Game_graph : protected Graph_Window , protected Game_color , public Game_contro  {

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
		Game_color get_color() const; 

		Game_point get_graph_point() const;

		std::vector<std::vector<char>>& get_Graph();

		// fun 
		void graph_draw();
		void graph_clean();
		void clear();

		//about contro
		void set_all_step(int up, int down, int left, int right);
		void set_up(int up = 1);
		void set_down(int down = 1);
		void set_left(int left = 1);
		void set_right(int right = 1);

		//get
		int get_up();
		int get_down();
		int get_left();
		int get_right();

		//function
		void up();
		void down();
		void left();
		void right();

		void up_left();
		void up_right();
		void down_left();
		void down_right();
	};

//fast cmd
#define _KYFgraph_ KY_engine::Game_graph
}

#endif //!KY_ENGINE_GAME_GRAPH_H