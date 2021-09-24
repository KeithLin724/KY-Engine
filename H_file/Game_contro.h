#pragma once

#ifndef KY_ENGINE_GAME_CONTRO_H
#define KY_ENGINE_GAME_CONTRO_H

namespace KY_engine {

	class Game_contro {// abstract class 
	protected:
		int UP, DOWN, LEFT, RIGHT; 

	public:
		Game_contro(int up = 1, int down = 1, int left = 1, int right = 1) ;
		~Game_contro();

		//set 
		virtual void set_up(int up = 1) = 0; 
		virtual void set_down(int down = 1) = 0;
		virtual void set_left(int left = 1) = 0;
		virtual void set_right(int right = 1) = 0;

		virtual void set_all_step(int up, int down, int left, int right) = 0;
		//get
		virtual int get_up() = 0;
		virtual int get_down() = 0;
		virtual int get_left() = 0;
		virtual int get_right() = 0;

		//function
		virtual void up() = 0;
		virtual void down() = 0;
		virtual void left() = 0;
		virtual void right() = 0;

		virtual void up_left() = 0;
		virtual void up_right() = 0;
		virtual void down_left() = 0;
		virtual void down_right() = 0;


	};
//fast cmd
#define _KYF_Contro_ KY_engine::Game_contro
}

#endif // !KY_ENGINE_GAME_CONTRO_H





