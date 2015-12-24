#pragma once
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Database.h"
#include "Global.h"
#include "Debug.h"
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


	wstring ws(database.message[1]);   //寬字元轉換
	string sId(ws.begin(), ws.end());

	wstring ws(database.message[2]);   //寬字元轉換
	string sHp(ws.begin(), ws.end());
	iHp = atoi(sHp.c_str());          //string→int

	wstring ws(database.message[3]);   
	string sMp(ws.begin(), ws.end());
	iMp = atoi(sMp.c_str());          

	wstring ws(database.message[5]);   
	string sCost(ws.begin(), ws.end());
	iCost = atoi(sCost.c_str());       

	wstring ws(database.message[6]);   
	string sPowerup(ws.begin(), ws.end());
	iPowerup = atoi(sPowerup.c_str());      

	wstring ws(database.message[7]);  
	string sAgileup(ws.begin(), ws.end());
	iAgileup = atoi(sAgileup.c_str());       

	wstring ws(database.message[8]);   
	string sLuckyup(ws.begin(), ws.end());
	iLuckyup = atoi(sLuckyup.c_str());      

	wstring ws(database.message[9]);  
	string sDefenseup(ws.begin(), ws.end());
	iDefenseup = atoi(sDefenseup.c_str());      

	wstring ws(database.message[10]);   
	string sMagicup(ws.begin(), ws.end());
	iMagicup = atoi(sMagicup.c_str());      

	wstring ws(database.message[11]);   
	string sMagicPowerup(ws.begin(), ws.end());
	iMagicPowerup = atoi(sMagicPowerup.c_str());      

	wstring ws(database.message[12]);   
	string sMagicDefenseup(ws.begin(), ws.end());
	iMagicDefenseup = atoi(sMagicDefenseup.c_str());   

	wstring ws(database.message[13]);
	string sPoisonClaen(ws.begin(), ws.end());
	bPoisonClaen = atoi(sPoisonClaen.c_str());
}