#pragma once
#include <iostream>
#include "Global.h"
using namespace std;

class Item
{
public:
    Item(int);
//�ڪ��Q�k�O�D�������private�A�A�bpublic�g�Ө��
//�������⪺�ƭȨ�o�Ө�ƥ[��Private���ܼƪ��ƭȫ�^��
//��L���A�h�O��bool�P�_
//private���ܼƤ��ᦳ�w��q�Ψ�L�ƭȤ���A�]��

private:
    int id;
    wchar_t *name;
	int hp;             //HP�^�_
	int mp;
    int time;           //����ɶ�
	
    int Powerup;        //�O�q�W��
	int Agileup;        //�ӱ��W��

	bool PoisonClaen;   //�Ѱ��r���A
	bool LoveClean;     //�Ѱ��y�b���A
	bool WeakClean;     //�Ѱ���z���A
	bool confusionclean;//�Ѱ��V�ê��A
};

Item::Item(int id)
{
    this->id = id;
    database.sql("SELECT * FROM `Item` WHERE `id` = " + id);
    this->name = database.message[1];
}