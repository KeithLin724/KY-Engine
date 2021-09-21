#include "Game_Text.h"
#include <iostream>
#include <iomanip>

namespace KY_engine {

	Game_Text::Game_Text() {
		this->text = std::string();
		this->length = 0; 
		this->point = Game_point();
	}
	Game_Text::~Game_Text() {

	}

	// set both length 
	void Game_Text::set_string(std::string text_in) {
		this->text = text_in;
		this->length = text_in.length();
	}

	// constructor 
	Game_Text::Game_Text(std::string Text , int color) {
		this->set_string(Text); 
		this->point = Game_point();
		this->text_color = color;
	}
	Game_Text::Game_Text(std::string Text, Game_point point , int color) {
		this->set_string(Text);
		this->point = point;
		this->text_color = color;
	}

	Game_Text::Game_Text(std::string Text, double x, double y , int color) {
		this->set_string(Text);
		this->point = Game_point(x, y); 
		this->text_color = color;
	}

	// set function 
	void Game_Text::set_Text(std::string Text) {
		this->set_string(Text); 
	}
	void Game_Text::set_Point(Game_point point) {
		this->point = point; 
	}

	void Game_Text::set_Point(double x, double y) {
		this->point = Game_point(x, y);
	}

	void Game_Text::set_color(int color){
		this->text_color = color;
	}

	// get function 

	std::string Game_Text::get_Text() {
		return this->text; 
	}
	int Game_Text::get_length() {
		return this->length; 
	}

	int Game_Text::get_color() {
		return this->text_color;
	}

	Game_Text Game_Text::add(std::string text, bool only_display) {
		if (only_display) {
			return Game_Text(this->text + text , this->point);
		}
		else {
			this->text += text; 
			this->set_string(this->text);// reset length 
			return *this; 
		}
	}

	Game_Text Game_Text::add(Game_Text text, bool only_display) {
		if (only_display) {
			return Game_Text(this->text + text.text, this->point);
		}
		else {
			this->set_string(this->text + text.text);// reset length 
			return *this;
		}
	}

	Game_Text Game_Text::copy_time(int n, bool only_display) {
		std::string copy(this->text);
		if (only_display) {
			for (auto i = 1; i < n; i++ ) {
				copy += this->text; 
			}
			return Game_Text(copy, this->point);
		}
		else {
			for (auto i = 0; i < n; i++) {
				this->text += copy; 
			}
			this->set_string(this->text); 
			return *this; 
		}
	}

	// function 
	void Game_Text::write() { // main write 
		this->gotoxy(this->point);
		this->Window_gotoxy(this->point, this->text_color); 
		std::cout << std::setw(this->length) << this->text; 
		
	}

	void Game_Text::clear() {
		this->text.clear(); 
		this->length = 0; 
		this->point.clear(); 
		this->text_color = Game_color::INIT_WITE; 
	}

	// operator
	Game_Text Game_Text::operator+ (Game_Text& text) {
		return Game_Text(this->text + text.text, this->point);

	}
	Game_Text Game_Text::operator+ (std::string& text) {
		return Game_Text(this->text + text, this->point);
	}

	Game_Text Game_Text::operator* (int n) {

		std::string* copy = new std::string(this->text); 
		for (auto i = 1; i < n; i++) {
			*copy += this->text;
		}
		return Game_Text(*copy, this->point);

	}
	Game_Text Game_Text::operator* (double n) {

		std::string* copy = new std::string(this->text);
		for (auto i = 1; i < n; i++) {
			*copy += this->text;
		}
		return Game_Text(*copy, this->point);
	}

	Game_Text& Game_Text::operator+= (Game_Text& text) {
		this->set_string(this->text + text.text);
		return *this; 
	}
	Game_Text& Game_Text::operator+= (std::string& text) {
		this->set_string(this->text + text);
		return *this;
	}

	Game_Text& Game_Text::operator*= (int n) {
		std::string* copy = new std::string(this->text); 
		for (auto i = 0; i < n; i++) {
			this->text += *copy;
		}
		this->set_string(this->text);
		delete copy;
		return *this;

	}
	Game_Text& Game_Text::operator*= (double n) {
		std::string* copy = new std::string(this->text);
		for (auto i = 0; i < n; i++) {
			this->text += *copy;
		}
		this->set_string(this->text);
		delete copy;
		return *this;
	}

	
	Game_Text& Game_Text::operator = (std::string& str) {
		this->set_string(str); 
		return *this; 
	}

	Game_Text& Game_Text::operator = (const char* str) {
		this->set_string(str);
		return *this;
	}

	// string to Game_text 
	Game_Text& Game_Text::operator << (std::string text) {
		this->set_string(text); 
		return *this; 
	}

	// set point use operator 

	Game_Text& Game_Text::operator << (Game_point game_point) {
		this->point = game_point; 
		return *this; 
	}

	std::ostream& operator << (std::ostream& output, const Game_Text& D) {
		output << "text " << D.text << " point : " << D.point; 
		return output; 
	}
	
	// Game_text to string 
	std::string& operator >> (Game_Text& text, std::string &str) {
		str = std::move(text.text);
		text.clear(); 
		return str; 
	}
	Game_Text& operator >> (std::string& str, Game_Text& text){
		text.set_Text(std::move(str));
		str.clear();
		return text;
	}

}