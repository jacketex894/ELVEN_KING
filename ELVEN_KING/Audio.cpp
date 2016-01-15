#include "Data\System\Audio.h"

Audio::Audio() {
	playing = false;
}

void Audio::setBGM(string address) {
	wchar_t fileName[256];
	address = this->BGMFolder + address;
	wsprintfW(fileName, L"%hs", address.c_str());
	BGMName = fileName;
	playBGM();
}

void Audio::playBGM() {
	PlaySound(this->BGMName, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	this->playing = true;
}

void Audio::stopBGM() {
	PlaySound(NULL, NULL, SND_ASYNC);
	this->playing = false;
}
