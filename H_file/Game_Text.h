#pragma once

#ifndef KY_ENGINE_GAME_TEXT_H
#define KY_ENGINE_GAME_TEXT_H

#include <string>
#include "Game_point.h"
#include "Graph_Window.h"
#include "Game_color.h"

namespace KY_engine {
	class Game_Text : protected Graph_Window {

	private:
		std::string text;
		Game_point point;
		int length;
		
		int text_color; 

	protected: // for class set 
		void set_string(std::string text_in);


	public:
		Game_Text(); 
		~Game_Text(); 
		Game_Text(std::string Text , int color = Game_color::INIT_WITE); 
		Game_Text(std::string Text, Game_point point , int color = Game_color::INIT_WITE);
		Game_Text(std::string Text, double x, double y , int color = Game_color::INIT_WITE);

		// set 
		void set_Text(std::string Text);
		void set_Point(Game_point point);
		void set_Point(double x, double y);
		void set_color(int color); 

		// get 
		std::string get_Text(); 
		int get_length(); 

		int get_color(); 
		
		// function 
		void write();

		Game_Text add(std::string text, bool only_display = true);
		Game_Text add(Game_Text text, bool only_display = true);
		Game_Text copy_time(int n , bool only_display = true);

		void clear(); 
		
		// operator 
		
		Game_Text operator+ (Game_Text& text);
		Game_Text operator+ (std::string& text);

		Game_Text operator* (int n);
		Game_Text operator* (double n);

		Game_Text& operator+= (Game_Text& text);
		Game_Text& operator+= (std::string& text);

		Game_Text& operator*= (int n);
		Game_Text& operator*= (double n);

		friend std::ostream& operator<<(std::ostream& output, const Game_Text& D);

		// string to Game_text 
		Game_Text& operator << (std::string text);
		Game_Text& operator << (Game_point game_point);

		// Game_text to string 
		Game_Text& operator= (std::string& str);
		Game_Text& operator= (const char * str);

		friend std::string& operator >> (Game_Text& text, std::string &str);
		friend Game_Text& operator >> (std::string& str, Game_Text& text);

	};

//fast cmd
#define _KYF_text_ KY_engine::Game_Text
}

#endif // !KY_ENGINE_GAME_TEXT_H