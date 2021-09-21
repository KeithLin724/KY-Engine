#include "Game_graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <tgmath.h>

#define GAME_PAIR_INT int, int

namespace KY_engine {
	Game_graph::Game_graph() {
		this->_H = 0; 
		this->_W = 0; 
		this->graph_point.set_point(0, 0);
		this->right_point.set_point(this->_W, this->_H); 
	}

	Game_graph::~Game_graph() {

	}

	Game_graph::Game_graph(std::string FILE_PATH , int color_code) {
		this->set_a_graph_from_file(FILE_PATH);
		this->set_point_both(0, 0);

		this->color = color_code; 
	}

	Game_graph::Game_graph(std::string FILE_PATH, Game_point& point , int color_code) {
		this->set_a_graph_from_file(FILE_PATH);
		this->set_point_both(point);

		this->color = color_code; 
	}

	void Game_graph::set_a_graph_from_file(std::string FILE_PATH) { // make graph in 
		std::ifstream in_file(FILE_PATH);  
		std::string Line; 
		this->_W = 0; 

		if (in_file.is_open()) {
			while (!in_file.eof()) {
				std::getline(in_file, Line);
				this->Graph.push_back(Line);
				if (Line.length() > this->_W) {
					this->_W = Line.length(); // about max 
				}
			}
			in_file.close(); 
			this->_H = this->Graph.size(); // about line 
		}
		else {
			std::cout << "can't open or can't find the graph txt file \n"; 
		}
	}

	void Game_graph::set_to_sqrt() {
		int MAX = 0, D = 0; 

		for (auto &emle : this->Graph) {
			if ((int)emle.size() > MAX) {
				MAX = emle.size();
			} 
		}

		for (auto& emle : this->Graph) {
			if (emle.size() < MAX) {
				D = MAX - emle.size(); 
				emle.insert(emle.end(), D, ' '); 
			}
		}
		this->_W = MAX; 
		this->_H = this->Graph.size(); 
		

	}

	void Game_graph::set_color(int color_code) {
		this->color = *(new Game_color(color_code));
	}

	void Game_graph::graph_draw() {
		std::pair<GAME_PAIR_INT>* _xy = new std::pair<GAME_PAIR_INT>(this->graph_point.get_x(), this->graph_point.get_y());
		int* Color = new int(this->color.get_color_code()); 
		for (const auto &elme : this->Graph) {
			this->Window_gotoxy(_xy->first, _xy->second++, *Color); 
			std::cout << std::setw(elme.length()) << elme;
		}
		delete _xy , Color; 
	}

	void Game_graph::graph_clean() {
		std::pair<GAME_PAIR_INT>* _xy = new std::pair<GAME_PAIR_INT>(this->graph_point.get_x(), this->graph_point.get_y());
		std::string* Clean = new std::string(); 
		for (const auto& elme : this->Graph) {
			Clean->insert(Clean->begin(), elme.length(), ' '); 
			this->gotoxy(_xy->first, _xy->second++);
			std::cout << std::setw(Clean->length()) << *Clean;
			Clean->clear(); 
		}
		delete Clean, _xy; 
	}

	void Game_graph::clear() {
		this->Graph.clear(); 
		this->graph_point.clear(); 
		this->_H = 0;
		this->_W = 0;
	}

	// protecded 
	void Game_graph::set_point_both(Game_point point) { // set both point 
		this->graph_point.set_point(point);
		this->right_point.set_point(point.get_x() + this->_W, point.get_y() + this->_H);
	}

	void Game_graph::set_point_both(double x, double y) {
		this->graph_point.set_point(x, y);
		this->right_point.set_point(x + this->_W, y + this->_H);
	}

	void Game_graph::set_point(Game_point &game_point) {
		this->set_point_both(game_point);
	}

	void Game_graph::set_point(int x, int y) {
		this->set_point_both((double)x, (double)y);
	}

	void Game_graph::set_point(double x, double y) {
		this->set_point_both(x, y);
	}

	Game_color& Game_graph::get_color() {
		return this->color; 
	}

	Game_point& Game_graph::get_graph_point() {
		return this->graph_point; 
	}

	std::vector<std::vector<char>> Game_graph::get_Graph() {
		std::vector<std::vector<char>> graph; 
		for (auto &emle : this->Graph) {
			graph.push_back(std::vector<char>(emle.begin(), emle.end())); 
		}
		return graph; 

	}

}
