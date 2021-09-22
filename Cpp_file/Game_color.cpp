#include "Game_color.h"
namespace KY_engine {

	Game_color::Game_color(int Color_code) {
		this->color_code = (Color_code >= 1 && Color_code < 255) ? Color_code : Game_color::INIT_WITE;
	}

	Game_color::~Game_color() {
		this->color_code = 0;
	}

	void Game_color::set_color_code(int color) {
		this->color_code = color; 
	}

	int Game_color::get_color_code() const {
		return this->color_code; 
	}

	Game_color& Game_color::add(int add) {
		this->color_code += add; 
		return *this; 
	}

	Game_color& Game_color::sub(int sub) {
		this->color_code -= sub; 
		return *this; 
	}

	Game_color& Game_color::multiplication(int mul){
		this->color_code *= mul;
		return *this;
	}

	Game_color& Game_color::divison(int div) {
		if (div == 0) {
			return *this; 
		}
		this->color_code /= div;
		return *this; 
	}

	void Game_color::clear() {
		this->color_code = Game_color::INIT_WITE; 
	}


	bool Game_color::is_it_in_range() {
		return ((this->color_code >= 1 && this->color_code < 255) ? true : false);
	}
}

