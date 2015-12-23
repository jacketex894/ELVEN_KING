#pragma once
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")

#define AUDIO_BGM_ADDRESS	"../CRPG/Data/Audio/BGM/"
#define AUDIO_SE_ADDRESS	"../CRPG/Data/Audio/SE/"

using namespace std;

class Audio {
	public:
		Audio();
		void setBGM(string);
		void setSE(string);
	private:
		bool playing;
		//BGM
		const string BGMFolder = AUDIO_BGM_ADDRESS;
		LPCWSTR BGMName;
		void playBGM();
		void stopBGM();
		//SE
		const string SEFolder = AUDIO_SE_ADDRESS;
		LPCWSTR SEName;
		void playSE();
		void stopSE();
};

Audio::Audio() { 
	playing = false;
}

void Audio::setBGM(string address) {
	wchar_t fileName[256];
	address = this->BGMFolder + address;
	wsprintfW(fileName, L"%hs",address.c_str());
	BGMName = fileName;
	playBGM();
}

void Audio::playBGM() {
	PlaySound(this->BGMName, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_ALIAS);
	this->playing = true;
}

void Audio::stopBGM() {
	PlaySound(NULL, NULL, SND_ASYNC);
	this->playing = false;
}
