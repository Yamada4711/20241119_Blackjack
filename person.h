#pragma once

#include "deck.h"

class Person
{
public:
	Person(); // ��ΕK�v�ȃR���X�g���N�^
	~Person(); // �ꉞ������f�X�g���N�^

public:
	int pullCard(); // �J�[�h���������
	void inputCard(Deck& deck, int* sumTurn); // �J�[�h��z��ɓ������
	void pullCardScore(); // �J�[�h�̐������X�R�A�ɕϊ�������
	bool judgeBurst(); // �o�[�X�g���ۂ��𔻒肷����
	void showCard(bool firstDealer); // �������J�[�h��\��������
	//void inputSumScore(); // ���v�X�R�A��ϐ��ɓ������
	//bool changeAce(); // A��11��1�ɕϊ�������
	int getScore() const; // �X�R�A��n�����
	//void setSumCard(); // �������J�[�h�̖������Z�b�g������
	//int getCardNum(int i) const; // �J�[�h�̔ԍ���n��

private:
	static const int MAX_PULL = 13; // 13���ȏ��������o�[�X�g����͂�...?
	int cardNum[MAX_PULL]; // �J�[�h�ԍ���������
	int cardScore[MAX_PULL]; // �J�[�h�̃X�R�A��������
	int sumScore; // �X�R�A�̍��v��������
	int sumCard; // �������J�[�h�̖���

protected:
	enum Turn
	{
		FIRST = 2,
		SECOND = 1
	};

	enum State
	{
		PLAY = 1,
		QUIT = 2
	};

	int pullNum = FIRST;
};
//#ifndef 2024_07_27_1938_Blackjack_Class_H_
//#define 2024_07_27_1938_Blackjack_Class_H_
//
//
//#endif // !2024_07_27_1938_Blackjack_Class_H_