#pragma once
#include <iostream>
#include "Database.h"
#include "Global.h"
#include "Debug.h"
#include "Change.h"
using namespace std;

class Armor
{
public:
	int iId;
	string sInstruction = "SELECT * From `Armor` WHERE `id` = ";
	string sId;
	int iHp;
	int iMp;
	int iAtk;
	int iDef;
	int iSatk;
	int iSdef;
	int iSpd;
	int iCost;

	Armor(int);

	string getname()
	    {
		return sId;
	    }
	int get()
	    {
		return iHp;
		return iMp;
		return iAtk;
		return iDef;
		return iSatk;
		return iSdef;
		return iSpd;
		return iCost;
	    }



private:

};
Armor::Armor(int iId)
{
string iHp;
string iMp;
string iAtk;
string iDef;
string iSatk;
string iSdef;
string iSpd;
string iCost;
char cId[20];

sprintf_s(cId, "%d", iId);
string sCin = sInstruction + cId;

database.sql(sCin);

sId = wStrToStr(database.message[1]);
iHp = wStrToInt(database.message[2]);
iMp = wStrToInt(database.message[3]);
iAtk = wStrToInt(database.message[4]);
iDef = wStrToInt(database.message[5]);
iSatk = wStrToInt(database.message[6]);
iSdef = wStrToInt(database.message[7]);
iSpd = wStrToInt(database.message[8]);
iCost = wStrToInt(database.message[9]);


}