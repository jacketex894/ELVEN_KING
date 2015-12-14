#pragma once
#include <iostream>
using namespace std;

class Item
{
public:
//我的想法是道具類放到private，再在public寫個函數
//提取角色的數值到這個函數加減Private內變數的數值後回傳
//其他狀態則是用bool判斷
//private的變數之後有定血量或其他數值之後再設值

private:
	int HpSmall;        //小量HP回復
	int HpMiddle;       //中量HP回復
	int HpLarge;        //大量HP回復
	int MpSmall;        //小量MP回復
	int MpMiddle;       //中量MP回復
	int MpLarge;        //大量MP回復
	int Powerup;        //短時間力量上升
	int Agileup;        //短時間敏捷上升
	bool PoisonClaen;   //解除毒狀態
	bool LoveClean;     //解除魅惑狀態
	bool WeakClean;     //解除虛弱狀態
	bool confusionclean;//解除混亂狀態
	bool AllClean;      //解除所有負面狀態


};
