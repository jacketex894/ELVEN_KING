#pragma once
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
#include "Base.h"
#pragma comment(lib, "WINMM.LIB")

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