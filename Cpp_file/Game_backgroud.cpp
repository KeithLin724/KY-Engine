#include "Game_background.h"
#include <iostream>
#include <iomanip>
#include <fstream>

#define GAME_CHAR Game_point, char
namespace KY_engine {

	Quick_background_setup::GRID::GRID(bool Grid_mode, int Grid_W, int Grid_H) {
		this->Grid_mode = Grid_mode;
		this->_W = Grid_W;
		this->_H = Grid_H;
	}

	Quick_background_setup::Quick_background_setup(int _W, int _H,
		bool Grid_mode, char angle, char line , char V_graph 
		, int Grid_W , int Grid_H , int color) {
		this->angle = angle;
		this->line = line;
		this->V_graph = V_graph;
		this->_W = _W;
		this->_H = _H;

		this->Grid = GRID(Grid_mode, Grid_W, Grid_H);
		this->color = color; 
	}

	Game_background::Game_background() {
		this->_H = 0; 
		this->_W = 0; 
		this->color = Game_color::INIT_WITE; 
	}

	Game_background::Game_background(Quick_background_setup quit_set_up) {
		this->_H = 0;
		this->_W = 0;
		this->set_background(quit_set_up);
	}


	

	Game_background::Game_background(std::string FILE_PATH , int color) {
		this->set_background_use_file(FILE_PATH); 
		this->color = color;
	}
	Game_background::~Game_background() {

	}

	// set 
	void Game_background::set_background(Quick_background_setup quit_set_up) {
		this->_H = quit_set_up._H;
		this->_W = quit_set_up._W;
		this->color = quit_set_up.color; 

		if (quit_set_up.Grid.Grid_mode) {
			int number_W = quit_set_up._W / (quit_set_up.Grid._W - 1),
				number_H = quit_set_up._H / (quit_set_up.Grid._H - 1);

			for (int y = 0; y < this->_H; y++) {
				for (int x = 0; x < this->_W; x++) {

					if (y % number_H == 0) {
						x % number_W == 0 ? 
							this->Graph_background.emplace_back(Game_point(x, y), quit_set_up.angle) :
							this->Graph_background.emplace_back(Game_point(x, y), quit_set_up.line);
					}
					else {
						if (x % number_W == 0) {
							this->Graph_background.emplace_back(Game_point(x, y), quit_set_up.V_graph);
						}
					}
				}
			}
		}
		else {
			for (int y = 0; y < this->_H; y++) {
				for (int x = 0; x < this->_W; x++) {
					if (y % (this->_H - 1) == 0 ) {

						x % (this->_W - 1) == 0 ?
							this->Graph_background.emplace_back(Game_point(x, y) , quit_set_up.angle):
							this->Graph_background.emplace_back(Game_point(x, y), quit_set_up.line);
					}
					else {
						if (x % (this->_W - 1) == 0) {
							this->Graph_background.emplace_back(Game_point(x, y), quit_set_up.V_graph);
							
						}
					}
				}

			}
		}

	}
	void Game_background::set_background_use_file(std::string FILE_PATH) {
		std::ifstream in_file(FILE_PATH);
		std::pair<int, int> XY(0, 0);
		std::string in_line;
		this->_H = 0;
		this->_W = 0;

		if (in_file.is_open()) {
			while (!in_file.eof()) {
				XY.first = 0;
				std::getline(in_file, in_line);
				for (auto& emle : in_line) {
					if (emle != ' ') {
						this->Graph_background.emplace_back(Game_point(XY.first, XY.second), emle); 
					}
					XY.first++;
				}
				XY.second++;
				this->_W = (XY.first > this->_W) ? XY.first : this->_W;
			}
			this->_H = XY.second;

			in_file.close();
			XY = { 0,0 };
		}
		else {
			std::cout << "can't open or can't find the graph txt file \n";
		}
	}

	void Game_background::set_color(int color) {
		this->color = color; 
	}

	// get
	int Game_background::get_high() {
		return this->_H; 
	}
	int Game_background::get_wide() {
		return this->_W; 
	}

	int Game_background::get_color() {
		return this->color;
	}
	
	std::vector<Game_point> Game_background::get_Game_background_point_map() {
		std::vector<Game_point> point_arr; 
		for (const auto& elme : this->Graph_background) {
			point_arr.emplace_back(elme.first);
		}
		return point_arr; 
	}

	std::vector<std::vector<char>> Game_background::get_Game_background() {
		std::vector<std::vector <char>> RETURN; 
		std::vector<char> part; 
		int i = 0; // run Graph 
		for (int y = 0; y < this->_H; y++) {

			for (int x = 0; x < this->_W; x++) {
				if (this->Graph_background[i].first == Game_point(x, y)) {
					part.emplace_back(this->Graph_background[i].second); 
					i++;
				}
				else {
					part.emplace_back(' '); 
				}
			}
			RETURN.emplace_back(part); 
			part.clear();
		}

		return RETURN; 
	}

	// function 
	void Game_background::draw() {
		for (auto &emle : this->Graph_background) {
			this->Window_gotoxy(emle.first, this->color); 
			std::cout <<std::setw(1) <<emle.second;
		}
	}
	void Game_background::clear() {
		this->Graph_background.clear(); 
		this->_H = 0; 
		this->_W = 0;
	}

}
