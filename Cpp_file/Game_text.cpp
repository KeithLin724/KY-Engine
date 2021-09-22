#include "Game_text.h"
#include <iostream>
#include <iomanip>

namespace KY_engine {

	Game_text::Game_text() {
		this->text = std::string();
		this->length = 0; 
		this->point = Game_point();
	}
	Game_text::~Game_text() {

	}

	// set both length 
	void Game_text::set_string(std::string text_in) {
		this->text = text_in;
		this->length = text_in.length();
	}

	std::string& Game_text::out_null(int length) {
		std::string no(" ");
		for (int i = 1; i < length; i ++ ) {
			no += " "; 
		}
		return no; 
	}

	// constructor 
	Game_text::Game_text(std::string Text , int color)
		:Game_contro() {
		this->set_string(Text); 
		this->point = Game_point();
		this->text_color = color;
	}
	Game_text::Game_text(std::string Text, Game_point point , int color)
		:Game_contro() {
		this->set_string(Text);
		this->point = point;
		this->text_color = color;
	}

	Game_text::Game_text(std::string Text, double x, double y , int color) 
		:Game_contro() {
		this->set_string(Text);
		this->point = Game_point(x, y); 
		this->text_color = color;
	}

	// set function 
	void Game_text::set_Text(std::string Text) {
		this->set_string(Text); 
	}
	void Game_text::set_point(Game_point point) {
		this->point = point; 
	}

	void Game_text::set_point(double x, double y) {
		this->point = Game_point(x, y);
	}

	void Game_text::set_color(int color){
		this->text_color = color;
	}

	// get function 

	std::string Game_text::get_Text() {
		return this->text; 
	}
	int Game_text::get_length() {
		return this->length; 
	}

	int Game_text::get_color() {
		return this->text_color;
	}

	Game_text Game_text::add(std::string text, bool only_display) {
		if (only_display) {
			return Game_text(this->text + text , this->point);
		}
		else {
			this->text += text; 
			this->set_string(this->text);// reset length 
			return *this; 
		}
	}

	Game_text Game_text::add(Game_text text, bool only_display) {
		if (only_display) {
			return Game_text(this->text + text.text, this->point);
		}
		else {
			this->set_string(this->text + text.text);// reset length 
			return *this;
		}
	}

	Game_text Game_text::copy_time(int n, bool only_display) {
		std::string copy(this->text);
		if (only_display) {
			for (auto i = 1; i < n; i++ ) {
				copy += this->text; 
			}
			return Game_text(copy, this->point);
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
	void Game_text::write() { // main write 
		//this->gotoxy(this->point);
		this->Window_gotoxy(this->point, this->text_color); 
		std::cout << std::setw(this->length) << this->text; 
		
	}

	void Game_text::eraser() {
		this->Window_gotoxy(this->point, 0);
		std::cout << std::setw(this->length) << this->out_null(this->length);
	}

	void Game_text::clear() {
		this->text.clear(); 
		this->length = 0; 
		this->point.clear(); 
		this->text_color = Game_color::INIT_WITE; 
	}

	void Game_text::set_all_step(int up, int down, int left, int right) {
		this->UP = up;
		this->DOWN = down;
		this->RIGHT = right;
		this->LEFT = left;
	}

	void Game_text::set_up(int up) {
		this->UP = up;
	}

	void Game_text::set_down(int down) {
		this->DOWN = down;
	}

	void Game_text::set_left(int left) {
		this->LEFT = left;
	}

	void Game_text::set_right(int right) {
		this->RIGHT = right;
	}

	int Game_text::get_up() {
		return this->UP;
	}

	int Game_text::get_down() {
		return this->DOWN;
	}

	int Game_text::get_left() {
		return this->LEFT;
	}

	int Game_text::get_right() {
		return this->RIGHT;
	}

	void Game_text::up() {
		this->eraser(); 
		this->point.sub_y(this->UP);
		this->write(); 
	}

	void Game_text::down() {
		this->eraser();
		this->point.add_y(this->DOWN); 
		this->write();
	}

	void Game_text::left() {
		this->eraser();
		this->point.sub_x(this->LEFT); 
		this->write();
	}

	void Game_text::right() {
		this->eraser();
		this->point.add_x(this->RIGHT); 
		this->write();
	}

	void Game_text::up_left() {
		this->eraser();
		this->point.sub_y(this->UP).sub_x(this->LEFT); 
		this->write();
	}

	void Game_text::up_right() {
		this->eraser();
		this->point.sub_y(this->UP).add_x(this->RIGHT); 
		this->write();
	}

	void Game_text::down_left() {
		this->eraser();
		this->point.add_y(this->DOWN).sub_x(this->LEFT); 
		this->write();
	}

	void Game_text::down_right() {
		this->eraser();
		this->point.add_y(this->DOWN).add_x(this->RIGHT); 
		this->write();
	}

	// operator
	Game_text Game_text::operator+ (Game_text& text) {
		return Game_text(this->text + text.text, this->point);

	}
	Game_text Game_text::operator+ (std::string& text) {
		return Game_text(this->text + text, this->point);
	}

	Game_text Game_text::operator* (int n) {

		std::string* copy = new std::string(this->text); 
		for (auto i = 1; i < n; i++) {
			*copy += this->text;
		}
		return Game_text(*copy, this->point);

	}
	Game_text Game_text::operator* (double n) {

		std::string* copy = new std::string(this->text);
		for (auto i = 1; i < n; i++) {
			*copy += this->text;
		}
		return Game_text(*copy, this->point);
	}

	Game_text& Game_text::operator+= (Game_text& text) {
		this->set_string(this->text + text.text);
		return *this; 
	}
	Game_text& Game_text::operator+= (std::string& text) {
		this->set_string(this->text + text);
		return *this;
	}

	Game_text& Game_text::operator*= (int n) {
		std::string* copy = new std::string(this->text); 
		for (auto i = 0; i < n; i++) {
			this->text += *copy;
		}
		this->set_string(this->text);
		delete copy;
		return *this;

	}
	Game_text& Game_text::operator*= (double n) {
		std::string* copy = new std::string(this->text);
		for (auto i = 0; i < n; i++) {
			this->text += *copy;
		}
		this->set_string(this->text);
		delete copy;
		return *this;
	}

	
	Game_text& Game_text::operator = (std::string& str) {
		this->set_string(str); 
		return *this; 
	}

	Game_text& Game_text::operator = (const char* str) {
		this->set_string(str);
		return *this;
	}

	// string to Game_text 
	Game_text& Game_text::operator << (std::string text) {
		this->set_string(text); 
		return *this; 
	}

	// set point use operator 

	Game_text& Game_text::operator << (Game_point game_point) {
		this->point = game_point; 
		return *this; 
	}

	std::ostream& operator << (std::ostream& output, const Game_text& D) {
		output << "text " << D.text << " point : " << D.point; 
		return output; 
	}
	
	// Game_text to string 
	std::string& operator >> (Game_text& text, std::string &str) {
		str = std::move(text.text);
		text.clear(); 
		return str; 
	}
	Game_text& operator >> (std::string& str, Game_text& text){
		text.set_Text(std::move(str));
		str.clear();
		return text;
	}

}