#pragma once
#include <iostream>
#include <cstdio>
#include <cmath>
#include "Control.h"
#include "Global.h"

using namespace std;

class Character {
    private:
    //data
    int id;
    string name;
    int level;
    int hp;
    int mp;
    int exp;
    Control control;

    // A*(Level^2) + B*Level + C
    int maxHp(); int hpP  [3]; 
    int maxMp(); int mpP  [3];
    int atk();   int atkP [3];
    int def();   int defP [3];
    int satk();  int satkP[3];
    int sdef();  int sdefP[3];
    int spd();   int spdP [3];
    int nLExp(); int expP [3];
    void setData(int*, wstring);
    public:
    Character(int);
    void levelUp();
    void levelDown();
};

Character::Character(int id) {
    this->id = id;
    char* sql = new char [45];
    sprintf_s(sql,45,"SELECT * FROM `Character` WHERE `id` = %d", id);
    database.sql(sql);
    this->level = wcstol(database.message[2], NULL, 10);
    this->setData(this->hpP,   database.message [3]);
    this->setData(this->mpP,   database.message [4]);
    this->setData(this->atkP,  database.message [5]);
    this->setData(this->defP,  database.message [6]);
    this->setData(this->satkP, database.message [7]);
    this->setData(this->sdefP, database.message [8]);
    this->setData(this->spdP,  database.message [9]);
    this->setData(this->expP,  database.message[10]);
}

int Character::maxHp() { return this->hpP[0] * pow(this->level, 2) + this->hpP[1] * this->level + this->hpP[2]; }
int Character::maxMp() { return this->mpP[0] * pow(this->level, 2) + this->mpP[1] * this->level + this->mpP[2]; }

void Character::levelUp() {
    //setData(this->maxHp, database.sql());
}

void Character::levelDown() {

}

void Character::setData(int *data, wstring wsParameter) {
    string sParameter;
    string temp;
    int n = 0,index = 0;
    //init
    for (char wc: wsParameter) sParameter += wc;
    for (n = 0; n < 3; n++) data[n] = 0;
    sParameter += ',';
    n = 0;
    //run data
    for (char  c : sParameter){
        if(c == ','){
            for (char tc : temp) data[index] += (tc - 48) * pow(10,(--n)--);
            temp = "";
            index++;
        }else{
            temp += c;
            n++;
        }
    }
}