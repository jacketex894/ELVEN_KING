#include "Data\System\Stage.h"

Stage::Stage(string background, string bgm) {
	this->background = background;
	this->bgm = bgm;
}

void Stage::setMenu(string* options) {
	this->selection = new Selection(options,false);
}
