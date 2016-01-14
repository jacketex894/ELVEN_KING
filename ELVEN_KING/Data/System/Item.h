#pragma once
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Database.h"
#include "Global.h"
#include "Debug.h"
#include "Change.h"
using namespace std;

class Item
{
public:
	int iId;
	string sInstruction = "SELECT * From `Item` WHERE `id` = ";
	string sId;
	int iHp;             //HP回復
	int iMp;             //MP回復
	int iPowerup;        //力量上升 物理傷害
	int iAgileup;        //敏捷上升
	int iLuckyup;        //幸運上升 爆擊率
	int iDefenseup;      //防禦上升
	int iMagicup;        //魔力上升
	int iMagicPowerup;   //魔功上升 魔法傷害
	int iMagicDefenseup; //魔防上升

	int iTime;           //持續時間 

	bool bPoisonClaen;   //解除毒狀態

	int iCost;            //$

	Item(int);
	
	string getname()
	    {
		return sId;
	    }
	int get()
	    {
		return iHp;
		return iMp;
		return iPowerup;
		return iAgileup;
		return iLuckyup;
		return iDefenseup;
		return iMagicup;
		return iMagicPowerup;
		return iMagicDefenseup;
		return iTime;
		return bPoisonClaen;
		return iCost;
	    }


private:

};


//皆為從資料庫讀取並存到變數中
Item::Item(int iId)
{
char cId[20];                     //char  方便轉換形態; 
string sHp;                       //sHp   方便轉換形態      
string sMp;                       
string sCost;                      
string sPowerup;
string sAgileup;
string sLuckyup;
string sDefenseup;
string sMagicup;
string sMagicPowerup;
string sMagicDefenseup;
string sPoisonClaen;
	

sprintf_s(cId, "%d", iId);        //iId轉換成char
string sCin = sInstruction + cId;

database.sql(sCin);


sId = wStrToStr(database.message[1]);
iHp = wStrToInt(database.message[2]);
iMp = wStrToInt(database.message[3]);
iCost = wStrToInt(database.message[5]);
iPowerup = wStrToInt(database.message[6]);
iAgileup = wStrToInt(database.message[7]);
iLuckyup = wStrToInt(database.message[8]);
iDefenseup = wStrToInt(database.message[9]);
iMagicup = wStrToInt(database.message[10]);
iMagicDefenseup = wStrToInt(database.message[11]);
iTime = wStrToInt(database.message[12]);
bPoisonClaen = wStrToInt(database.message[13]);


}