#include "KY_Game_Tool.h"

namespace KY_engine {
	KY_Game_Tool::KY_Game_Tool() {

	}

	KY_Game_Tool::~KY_Game_Tool(){

	}

	Game_background& KY_Game_Tool::Build_background(std::string PATH) {
		return *(new Game_background(PATH)); 
	}

	Game_background& KY_Game_Tool::Build_background(Quick_background_setup quick_backgrand_setup) {
		return *(new Game_background(quick_backgrand_setup)); 
	}

	Game_point& KY_Game_Tool::Build_point(int x, int y) {
		return *(new Game_point(x, y)); 
	}

	Game_point& KY_Game_Tool::Build_point(long x, long y) {
		return *(new Game_point((int)x, (int)y));
	}

	Game_point& KY_Game_Tool::Build_point(double x, double y) {
		return *(new Game_point(x, y));
	}

	Game_graph& KY_Game_Tool::Build_graph(std::string path) {
		return *(new Game_graph(path));
	}

	Game_text& KY_Game_Tool::Build_text(std::string str, double x, double y, int color) {
		return *(new Game_text(str, x, y, color)); 
	}

	Game_text& KY_Game_Tool::Build_text(std::string str, Game_point point, int color) {
		return *(new Game_text(str, point, color)); 
	}

	Game_text& KY_Game_Tool::Build_text(Game_text GText, Game_point point, int color) {
		return *(new Game_text(GText.get_Text(), point, color));
	}
	Game_text& KY_Game_Tool::Build_text(Game_text GText, double x, double y, int color) {
		return *(new Game_text(GText.get_Text(), x, y, color));
	}
	
	Game_color& KY_Game_Tool::Build_color(int color_text){
		return *(new Game_color((color_text >= 1 && color_text < 255) ? color_text : Game_color::INIT_WITE));
	}
	Game_Event& KY_Game_Tool::Build_event() {
		return *(new Game_Event());
	}

	void KY_Game_Tool::Draw_Graph(std::vector<std::vector<char>>& in_graph, _KYF_point_ point, int color ) {
		
		std::pair<GAME_PAIR_DOUBLE>* xy = 
			(point == _KYF_NULL_point_) ? new std::pair<GAME_PAIR_DOUBLE>(0,0) :
			new std::pair<GAME_PAIR_DOUBLE>(point.x(), point.y());
		
		_KYF_GW_* gw = new _KYF_GW_();
		for (auto& elme : in_graph) {
			xy->first = point.x(); 
			for (auto& each : elme) {
				gw->Window_gotoxy(xy->first, xy->second, color); 
				std::cout << each;
				xy->first++; 
			}
			xy->second++; 
			std::cout << "\n";
		}
		delete xy, gw; 
	}

	void KY_Game_Tool::add(Game_background& bg) {
		this->bg = bg; 
	}

	void KY_Game_Tool::add(Game_graph& graph) {
		this->graph_all.push_back(graph); 
	}

	void KY_Game_Tool::add(Game_text& text) {
		this->text_all.push_back(text); 
	}

	void KY_Game_Tool::add(std::vector<Game_graph>& graph_arr){
		this->graph_all.insert(this->graph_all.end(), graph_arr.begin(), graph_arr.end()); 
	}

	void KY_Game_Tool::add(std::vector<Game_text>& text_arr) {
		this->text_all.insert(this->text_all.end(), text_arr.begin(), text_arr.end());
	}

	void KY_Game_Tool::Draw_init(Game_point end_point) {
		this->bg.draw(); 
		for (var& elme :this->text_all) {
			elme.write(); 
		}
		for (var& elme : this->graph_all) {
			elme.graph_draw();
		}

		Graph_Window thing; 
		if (end_point == _KYF_NULL_point_) {
			end_point.set_point(this->graph_all.back().get_graph_point());
		}
		thing.Window_gotoxy(end_point, Game_color::INIT_WITE);
	}
	void KY_Game_Tool::Write_text(std::string text, _KYF_point_ point, int color) {
		Game_point* copy = (point == _KYF_NULL_point_) ? new Game_point(0, 0) : new Game_point(point);
		Graph_Window* gw = new Graph_Window();
		gw->Window_gotoxy(point, color); 
		std::cout << text; 
		delete copy, gw; 
	}
}


