#pragma once

#ifndef KY_ENGINE_GAME_COLOR_H
#define KY_ENGINE_GAME_COLOR_H


namespace KY_engine {
	class Game_color {
	private:
		int color_code; 

	protected: 	// Game color need check is it in range of array of conso
		bool is_it_in_range(); 

	public: // constant 
		static constexpr auto GREEN = 10;
		static constexpr auto BLUE = 11;
		static constexpr auto RED = 12;
		static constexpr auto PUPER = 13;
		static constexpr auto YELLOW = 14;
		static constexpr auto WITE = 15;
		static constexpr auto INIT_WITE = (0x0004) | (0x0001) | (0x0002);

	public:
		//base color 
		Game_color(int color = Game_color::INIT_WITE);
		~Game_color(); 

		
		void set_color_code(int color = Game_color::INIT_WITE);
		int get_color_code() const; 

		Game_color& add(int add = 1); 
		Game_color& sub(int sub = 1); 
		Game_color& multiplication(int mul = 2);
		Game_color& divison(int div = 0);

		void clear(); 
	};

#define _KYF_color_ KY_engine::Game_color
}

#endif // !KY_ENGINE_GAME_COLOR_H

