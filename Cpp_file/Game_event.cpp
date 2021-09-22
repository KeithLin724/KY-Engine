#include "Game_event.h"
#include <conio.h>
namespace KY_engine {
	Game_Event::Game_Event() {
		this->event_memory = NULL; 
	}
	Game_Event::~Game_Event(){

	}

	char Game_Event::get_event(){
		auto e = _getch();
		this->event_memory = e; 
		return e;
	}
	char Game_Event::get_event_memory() const {
		return this->event_memory;
	}
	std::string Game_Event::to_HEX() {
		char arr[200] = {}; 
		sprintf_s(arr, "%02X", this->event_memory); 
		return std::string(arr);
	}
	std::string Game_Event::to_string() {
		return std::to_string(this->event_memory);
	}
	std::string Game_Event::Fast_Get_Event() {
		char arr[200] = {} , e; 
		e = _getch(); 
		sprintf_s(arr, "%02X", e); 
		return std::string(arr);
	}
}