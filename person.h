#pragma once

#include "deck.h"

class Person
{
public:
	Person(); // ��ΕK�v�ȃR���X�g���N�^
	~Person(); // �ꉞ������f�X�g���N�^

public:
	int PullCard(); // �J�[�h���������
	void InputCard(Deck* deck); // �J�[�h��z��ɓ������
	void PullCardScore(); // �J�[�h�̐������X�R�A�ɕϊ�������
	bool JudgeBurst(); // �o�[�X�g���ۂ��𔻒肷����
	//void inputSumScore(); // ���v�X�R�A��ϐ��ɓ������
	//bool changeAce(); // A��11��1�ɕϊ�������
	int GetScore() const; // �X�R�A��n�����
	//void setSumCard(); // �������J�[�h�̖������Z�b�g������
	//int getCardNum(int i) const; // �J�[�h�̔ԍ���n��

	virtual void ShowCard() = 0; // �������J�[�h��\��������

private:
	static const int MAX_PULL = 13; // 13���ȏ��������o�[�X�g����͂�...?
	int cardScore[MAX_PULL]; // �J�[�h�̃X�R�A��������
	int sumScore; // �X�R�A�̍��v��������

protected:
	int cardNum[MAX_PULL]; // �J�[�h�ԍ���������
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