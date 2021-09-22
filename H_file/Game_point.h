#pragma once


#ifndef KY_ENGINE_GAME_POINT_H
#define KY_ENGINE_GAME_POINT_H

#include <iostream>
#define GAME_PAIR_DOUBLE double, double 

namespace KY_engine {

	class Game_point {

	private:
		double X, Y; 

	public:
		Game_point(double x = 0, double y = 0);
		Game_point(int x, int y);
		~Game_point(); 

		// get 
		double get_x(); 
		double get_y(); 
		std::pair<GAME_PAIR_DOUBLE> get_point_to_pair();

		// set 
		Game_point& set_x(int x);
		Game_point& set_x(double x);

		Game_point& set_y(int y);
		Game_point& set_y(double y);

		Game_point& set_point(int x , int y);
		Game_point& set_point(double x, double y);
		Game_point& set_point(Game_point game_point);

		// function
		Game_point& swap_xy(); 

		Game_point& add_x(int number = 1);
		Game_point& add_x(double number = 1);

		Game_point& add_y(int number = 1);
		Game_point& add_y(double number = 1);

		Game_point& sub_x(int number = 1);
		Game_point& sub_x(double number = 1);

		Game_point& sub_y(int number = 1);
		Game_point& sub_y(double number = 1);

		void clear(); 

		// operator 
		friend std::ostream& operator<<(std::ostream& output, const Game_point& D);
		friend std::istream& operator>>(std::istream& input, Game_point& D);

		bool operator != (Game_point com);
		bool operator == (Game_point com);

		// friend function 
		friend double Game_Point_Length(Game_point &point1 , Game_point& point2);

	};
//fast cmd
#define _KYF_point_ KY_engine::Game_point 

#define _KYF_NULL_point_ KY_engine::Game_point {NULL,NULL}
}

#endif // !KY_ENGINE_GAME_POINT_H