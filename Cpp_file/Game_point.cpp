#include "Game_point.h"
#include <tgmath.h>
namespace KY_engine {
	Game_point::Game_point(int x , int y) {
		this->X = x; 
		this->Y = y; 
	}

	Game_point::Game_point(double x , double y) {
		this->X = x;
		this->Y = y;
	}
	Game_point::~Game_point() {
		
	}

	double Game_point::get_x() {
		return this->X;
	}
	double Game_point::get_y() {
		return this->Y; 
	}

	std::pair<GAME_PAIR_DOUBLE> Game_point::get_point_to_pair() {
		return std::pair<GAME_PAIR_DOUBLE>(this->X, this->Y);
	}

	Game_point& Game_point::set_x(int x) {
		this->X = x; 
		return *this;
	}
	Game_point& Game_point::set_x(double x) {
		this->X = x; 
		return *this;
	}

	Game_point& Game_point::set_y(int y) {
		this->Y = y; 
		return *this;
	}
	Game_point& Game_point::set_y(double y) {
		this->Y = y;
		return *this;
	}

	Game_point& Game_point::set_point(int x, int y) {
		this->X = x; 
		this->Y = y; 
		return *this;
	}
	Game_point& Game_point::set_point(double x, double y) {
		this->X = x;
		this->Y = y;
		return *this;
	}

	Game_point& Game_point::set_point(Game_point game_point) {
		*this = game_point;
		return *this;
	}

	Game_point& Game_point::swap_xy() {
		std::swap(this->X, this->Y); 
		return *this; 
	}

	Game_point& Game_point::add_x(int number) {
		this->X += number; 
		return *this; 
	}
	Game_point& Game_point::add_x(double number) {
		this->X += number;
		return *this;
	}

	Game_point& Game_point::add_y(int number) {
		this->Y += number;
		return *this;
	}
	Game_point& Game_point::add_y(double number) {
		this->Y += number;
		return *this;
	}

	Game_point& Game_point::sub_x(int number) {
		this->X -= number;
		return *this;
	}
	Game_point& Game_point::sub_x(double number) {
		this->X -= number;
		return *this;
	}

	Game_point& Game_point::sub_y(int number) {
		this->Y -= number;
		return *this;
	}
	Game_point& Game_point::sub_y(double number) {
		this->Y -= number;
		return *this;
	}

	void Game_point::clear() {
		this->X = 0; 
		this->Y = 0; 
	}

	std::ostream& operator<<(std::ostream& output, const Game_point& D) {
		output << D.X << ", " << D.Y; 
		return output; 

	}

	std::istream& operator>>(std::istream& input, Game_point& D) {
		input >> D.X >>D.Y;
		return input;
	}

	bool Game_point::operator != (Game_point com) {
		return ((this->X == com.X && this->Y == Y) ? false : true);
	}
	bool Game_point::operator == (Game_point com) {
		return ((this->X == com.X && this->Y == Y) ? true : false);
	}


	// friend function 

	double Game_Point_Length(Game_point& point1, Game_point& point2) {
		return std::sqrt(std::pow(point1.X - point2.X, 2) + std::pow(point1.Y - point2.Y, 2));
	}
}
