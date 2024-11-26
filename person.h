#pragma once

#include "deck.h"

class Person
{
public:
	Person(); // 絶対必要なコンストラクタ
	~Person(); // 一応作ったデストラクタ

public:
	int pullCard(); // カードを引くやつ
	void inputCard(Deck* deck); // カードを配列に入れるやつ
	void pullCardScore(); // カードの数字をスコアに変換するやつ
	bool judgeBurst(); // バーストか否かを判定するやつ
	void showCard(bool firstDealer); // 引いたカードを表示するやつ
	//void inputSumScore(); // 合計スコアを変数に入れるやつ
	//bool changeAce(); // Aの11を1に変換するやつ
	int getScore() const; // スコアを渡すやつ
	//void setSumCard(); // 引いたカードの枚数をセットするやつ
	//int getCardNum(int i) const; // カードの番号を渡す

private:
	static const int MAX_PULL = 13; // 13枚以上引いたらバーストするはず...?
	int cardNum[MAX_PULL]; // カード番号を入れるやつ
	int cardScore[MAX_PULL]; // カードのスコアを入れるやつ
	int sumScore; // スコアの合計を入れるやつ
	int sumCard; // 引いたカードの枚数

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