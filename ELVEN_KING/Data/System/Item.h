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
	int iHp;             //HP�^�_
	int iMp;             //MP�^�_
	int iPowerup;        //�O�q�W�� ���z�ˮ`
	int iAgileup;        //�ӱ��W��
	int iLuckyup;        //���B�W�� �z���v
	int iDefenseup;      //���m�W��
	int iMagicup;        //�]�O�W��
	int iMagicPowerup;   //�]�\�W�� �]�k�ˮ`
	int iMagicDefenseup; //�]���W��

	int iTime;           //����ɶ� 

	bool bPoisonClaen;   //�Ѱ��r���A

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


//�Ҭ��q��ƮwŪ���æs���ܼƤ�
Item::Item(int iId)
{
char cId[20];                     //char  ��K�ഫ�κA; 
string sHp;                       //sHp   ��K�ഫ�κA      
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
	

sprintf_s(cId, "%d", iId);        //iId�ഫ��char
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