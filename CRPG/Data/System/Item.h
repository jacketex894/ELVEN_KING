#pragma once
#include <iostream>
using namespace std;

class Item
{
public:
//�ڪ��Q�k�O�D�������private�A�A�bpublic�g�Ө��
//�������⪺�ƭȨ�o�Ө�ƥ[��Private���ܼƪ��ƭȫ�^��
//��L���A�h�O��bool�P�_
//private���ܼƤ��ᦳ�w��q�Ψ�L�ƭȤ���A�]��

private:
	int HpSmall;        //�p�qHP�^�_
	int HpMiddle;       //���qHP�^�_
	int HpLarge;        //�j�qHP�^�_
	int MpSmall;        //�p�qMP�^�_
	int MpMiddle;       //���qMP�^�_
	int MpLarge;        //�j�qMP�^�_
	int Powerup;        //�u�ɶ��O�q�W��
	int Agileup;        //�u�ɶ��ӱ��W��
	bool PoisonClaen;   //�Ѱ��r���A
	bool LoveClean;     //�Ѱ��y�b���A
	bool WeakClean;     //�Ѱ���z���A
	bool confusionclean;//�Ѱ��V�ê��A
	bool AllClean;      //�Ѱ��Ҧ��t�����A


};
