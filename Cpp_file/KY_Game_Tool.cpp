#include "KY_Game_Tool.h"

namespace KY_engine {
	KY_Game_Tool::KY_Game_Tool() {

	}

	KY_Game_Tool::~KY_Game_Tool(){

	}

	Game_Backgrand KY_Game_Tool::Build_backgrand(std::string PATH) {
		return *(new Game_Backgrand(PATH)); 
	}

	Game_Backgrand KY_Game_Tool::Build_backgrand(Quick_backgrand_setup quick_backgrand_setup) {
		return *(new Game_Backgrand(quick_backgrand_setup)); 
	}

	Game_point KY_Game_Tool::Build_point(int x, int y) {
		return *(new Game_point(x, y)); 
	}

	Game_point KY_Game_Tool::Build_point(long x, long y) {
		return *(new Game_point((int)x, (int)y));
	}

	Game_point KY_Game_Tool::Build_point(double x, double y) {
		return *(new Game_point(x, y));
	}

	Game_graph KY_Game_Tool::Build_graph(std::string path) {
		return *(new Game_graph(path));
	}

	Game_Text KY_Game_Tool::Build_text(std::string str, double x, double y, int color) {
		return *(new Game_Text(str, x, y, color)); 
	}

	Game_Text KY_Game_Tool::Build_text(std::string str, Game_point point, int color) {
		return *(new Game_Text(str, point, color)); 
	}

	Game_Text KY_Game_Tool::Build_text(Game_Text GText, Game_point point, int color) {
		auto *thing = new Game_Text(GText); 
		thing->set_Point(point); 
		thing->set_color(color);
		return *thing; 
	}
	Game_Text KY_Game_Tool::Build_text(Game_Text GText, double x, double y, int color) {
		auto* thing = new Game_Text(GText);
		thing->set_Point(x, y);
		thing->set_color(color);
		return *thing;
	}
	
	Game_color KY_Game_Tool::Build_color(int color_text){

/*#if color_text >= 1 && color_text < 255
		return *(new Game_color(color_text));
#else
		return *(new Game_color(Game_color::INIT_WITE)); 
#endif // color_text >= 1 && color_text < 255*/


		return *(new Game_color((color_text >= 1 && color_text < 255) ? color_text : Game_color::INIT_WITE));
	}
	Game_Event KY_Game_Tool::Build_event() {
		return Game_Event();
	}
	void KY_Game_Tool::Draw_Graph(std::vector<std::vector<char>>& in_graph) {
		for (auto &elme : in_graph) {
			for (auto &each : elme) {
				std::cout << each;
			}
			std::cout << "\n"; 
		}
	}
	void KY_Game_Tool::add(Game_Backgrand& bg) {
		this->bg = bg; 
	}
	void KY_Game_Tool::add(Game_graph& graph) {
		this->graph_all.push_back(graph); 
	}
	void KY_Game_Tool::add(Game_Text& text) {
		this->text_all.push_back(text); 
	}
	void KY_Game_Tool::add(std::vector<Game_graph>& graph_arr){
		this->graph_all.insert(this->graph_all.end(), graph_arr.begin(), graph_arr.end()); 
	}

	void KY_Game_Tool::add(std::vector<Game_Text>& text_arr) {
		this->text_all.insert(this->text_all.end(), text_arr.begin(), text_arr.end()); 
	}
	void KY_Game_Tool::Draw_init() {
		this->bg.draw(); 
		for (var& elme :this->text_all) {
			elme.write(); 
		}
		for (var& elme : this->graph_all) {
			elme.graph_draw();
		}
	}
}


