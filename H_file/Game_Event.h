#pragma once

#ifndef KY_ENGINE_GAME_EVENT_H
#define KY_ENGINE_GAME_EVENT_H

#include <string>

namespace KY_engine {
	class Game_Event {
	private:
		char event_memory; 
	public:
		Game_Event();
		~Game_Event();

		//get 
		char get_event() ;
		char get_event_memory() const; 

		// to string or HEX number function 
		std::string to_HEX(); 
		std::string to_string();

		//Quit get Game event function 
		static std::string Fast_Get_Event(); 
	};

//fast cmd
#define _KYGame_Event_ KY_engine::Game_Event
#define _KYF_event_ KY_engine::Game_Event::Fast_Get_Event()

}


#endif // !KY_ENGINE_GAME_EVENT_H
