#pragma once

#ifndef KY_ENGINE_GAME_TEXT_H
#define KY_ENGINE_GAME_TEXT_H

#include <string>
#include "Game_point.h"
#include "Graph_Window.h"
#include "Game_color.h"
#include "Game_contro.h"

namespace KY_engine {
	class Game_text : protected Graph_Window  , public Game_contro{

	private:
		std::string text;
		Game_point point;
		int length;
		
		int text_color; 

	protected: // for class set 
		void set_string(std::string text_in);
		std::string& out_null(int length);

	public:
		Game_text(); 
		~Game_text(); 
		Game_text(std::string Text, int color = Game_color::INIT_WITE); 
		Game_text(std::string Text, Game_point point , int color = Game_color::INIT_WITE);
		Game_text(std::string Text, double x, double y , int color = Game_color::INIT_WITE);

		// set 
		void set_Text(std::string Text);
		void set_point(Game_point point);
		void set_point(double x, double y);
		void set_color(int color); 

		// get 
		std::string get_Text() const; 
		int get_length() const; 

		int get_color() const; 
		
		// function 
		void write();
		void eraser(); 

		Game_text add(std::string text, bool only_display = true);
		Game_text add(Game_text text, bool only_display = true);
		Game_text copy_time(int n , bool only_display = true);

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
		
		// operator 
		
		Game_text operator+ (Game_text& text);
		Game_text operator+ (std::string& text);

		Game_text operator* (int n);
		Game_text operator* (double n);

		Game_text& operator+= (Game_text& text);
		Game_text& operator+= (std::string& text);

		Game_text& operator*= (int n);
		Game_text& operator*= (double n);

		friend std::ostream& operator<<(std::ostream& output, const Game_text& D);

		// string to Game_text 
		Game_text& operator << (std::string text);
		Game_text& operator << (Game_point game_point);

		// Game_text to string 
		Game_text& operator= (std::string& str);
		Game_text& operator= (const char * str);

		friend std::string& operator >> (Game_text& text, std::string &str);
		friend Game_text& operator >> (std::string& str, Game_text& text);

	};

//fast cmd
#define _KYF_text_ KY_engine::Game_text
}

#endif // !KY_ENGINE_GAME_TEXT_H