
#ifndef KY_GAME_HPP
#define KY_GAME_HPP

#include "KY_Game_Tool.h"

#define GAME_PAIR_INT int, int

namespace KY_engine {
	class KY_Game : protected Graph_Window { // total Game_tool inside
	private:
		Game_Backgrand game_backgrand;
		std::pair<GAME_PAIR_INT> HW; // frist is height , second is width 
		Game_point right_point, left_point, end_point; 

	protected:
		const int fix_end_point_index = 10; 
		void set_all_point(double x , double y);
		void set_all_point(Game_point game_point);

	public:
		// can use path , hw Game_backgrand or quit to set up the backgrand 
		KY_Game();
		KY_Game(std::string FILE_PATH); 
		KY_Game(Game_Backgrand game_Backgrand);
		KY_Game(Quick_backgrand_setup QB_Set_up);

		//void add(); it is add thing like Game_text , Game_Graph ... for Game _init to draw 

		~KY_Game();
		void init();
		void start();
		void end(); 

	};
	// constructor
	KY_Game::KY_Game() {
		
	}

	KY_Game::KY_Game(std::string FILE_PATH) {
		this->game_backgrand.set_Backgrand_use_file(FILE_PATH);
	}
	KY_Game::KY_Game(Game_Backgrand game_Backgrand) {
		this->game_backgrand = game_Backgrand;
	}
	KY_Game::KY_Game(Quick_backgrand_setup QB_Set_up) {
		this->game_backgrand.set_Backgrand(QB_Set_up);
	}


	KY_Game::~KY_Game() {

	}
	//protected function 
	void KY_Game::set_all_point(double x, double y) {
		this->right_point.set_point(x,y); 
		this->left_point.set_point(this->HW.first + x, this->HW.second + y);
		this->end_point.set_point(0, (int)(this->left_point.get_y() + this->fix_end_point_index));

	}
	void KY_Game::set_all_point(Game_point game_point) {
		this->right_point.set_point(game_point); 
		this->left_point.set_point(this->HW.first + game_point.get_x(), this->HW.second + game_point.get_y());
		this->end_point.set_point(0, (int)(this->left_point.get_y() + this->fix_end_point_index));

	}

	//public function 
	void KY_Game::init() {

	}

	void KY_Game::start() {

	}
	void KY_Game::end() {

	}
	// friend finction 

}
#endif // !KY_GAME_HPP