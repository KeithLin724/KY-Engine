#include "Game_contro.h"

namespace KY_engine {
	Game_contro::Game_contro(int up, int down, int left, int right) {
		this->UP = up; 
		this->DOWN = down; 
		this->LEFT = left; 
		this->RIGHT = right; 
	}

	Game_contro::~Game_contro() {
		this->UP = 0;
		this->DOWN = 0;
		this->LEFT = 0;
		this->RIGHT = 0;
	}

}