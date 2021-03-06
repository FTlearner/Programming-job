#pragma once
#ifndef _City_h_
#define _City_h_
#include <iostream>
#include <cstring>
#include <Windows.h>
#include "CardPackage.h"
using namespace std;
class City
{	
public:
	City(const string s);
	City(const double temp) :troops(temp) {};//卡牌内临时数据
	double army() { return troops; }//访问兵力
	City& operator+=(const  City&);//兵力的变动
	City& operator-=(const  City&);
	void show();		//输出还有多少兵力
	void fight();		//战斗阶段
	void adjustTroops(double);//留一个对外接口用于改变私有数据的兵力
	void changeTroops(double);//改变兵力
	void adjustDistance();//调整两座主城之间的攻击距离
	void win();		//输出胜利的函数
	int selectTroops(); //选择出击的军队数量
	string checkBelong();	  //接口，查看城池的归属
	void changeBelong(string);//改变城池的归属
	static double difference;//回合卡牌作用的差值
	void change_static(bool);//卡牌改变的静态变量来改变兵力
private:
	int distance;		//攻击距离。刘邦是1，项羽是3，中立城池恒为2，可当作中立城池的特殊标志
	double troops;		//兵力
	string belong;		//归属
};
#endif
