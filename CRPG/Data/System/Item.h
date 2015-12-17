#pragma once
#include <iostream>
#include "Global.h"
using namespace std;

class Item
{
public:
    Item(int);
//我的想法是道具類放到private，再在public寫個函數
//提取角色的數值到這個函數加減Private內變數的數值後回傳
//其他狀態則是用bool判斷
//private的變數之後有定血量或其他數值之後再設值

private:
    int id;
    wchar_t *name;
	int hp;             //HP回復
	int mp;
    int time;           //持續時間
	
    int Powerup;        //力量上升
	int Agileup;        //敏捷上升

	bool PoisonClaen;   //解除毒狀態
	bool LoveClean;     //解除魅惑狀態
	bool WeakClean;     //解除虛弱狀態
	bool confusionclean;//解除混亂狀態
};

Item::Item(int id)
{
    this->id = id;
    database.sql("SELECT * FROM `Item` WHERE `id` = " + id);
    this->name = database.message[1];
}