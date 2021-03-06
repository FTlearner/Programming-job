 #include "City.h"
City::City(const string s)
{
	troops = 1000;
	belong = s;
	if (s == "刘邦")
		distance = 1;
	else if (s == "项羽")
		distance = 3;
	else
		distance = 2;
}
void City::fight()
{
	cout << "选择你要出兵的城池" << endl;	//选择城池阶段
	City* c1 = &CardPackage::findCity();
	while (c1->belong != belong)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		c1 = &CardPackage::findCity();
	}
	cout << "选择军队目标的城池（选择己方城池可屯兵）" << endl;
	City* c2 = &CardPackage::findCity();//使用卡包中寻找城市的功能
	while (abs(c1->distance - c2->distance) > 1) //两座城池距离大于1，无法直接攻击
	{
		cout << "你的军队无法直接到达该城池，请重新选择" << endl;
		c2 = &CardPackage::findCity();
	}
	int c1Num = selectTroops();	//选择出兵数量阶段
	while (c1Num > c1->troops)
	{
		cout << "你的拥有的兵力为：" << c1->troops << "请重新选择" << endl;
		c1Num = selectTroops();
	}
	c1->troops -= c1Num;
	if (difference == 0) {//数据采集
		difference = c1Num;
	}
	if (c1->belong == c2->belong) // 战斗判定阶段
	{
		c2->troops += c1Num;//归属相同，屯兵
		cout << "你已选择屯兵，战斗回合结束" << endl;
		return;
	}

	if (c1Num > c2->troops)	//c1兵力占优
	{
		c2->belong = belong;//c2被占领
		c2->troops = c1Num - c2->troops;
	}
	else if (c1Num == c2->troops)//兵力相同
	{
		//被攻击的城池归属不改变
		c2->troops = 0;
	}
	else
	{
		c2->troops -= c1Num;
	}
}

void City::show()
{
	if (distance == 2)//如果展示中立城池
	{
		//设置字体颜色为绿色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
		cout << "中立城池归属：" << belong << " 兵力：" << troops << endl;
		//输出后恢复
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		return;
	}
	cout << belong << "城池剩余兵力：" << troops << endl << endl;
}

void City::adjustDistance()
{
	if (belong == "项羽")	//项羽的城池
	{
		if (distance == 3)	//距离未改变
			distance = 1;	//缩短两主城距离差值
		else 
			distance = 3;
	}
	else//刘邦的城池
	{
		if (distance == 1) // 未改变
			distance = 3;
		else
			distance = 1;
	}
}

void City::adjustTroops(double ratio)
{
	troops *= ratio;
}

string City::checkBelong()
{
	return belong;
}

int City::selectTroops()
{
	cout << "选择派出军队的数量" << endl;
	int num = 0;
	cin >> num;
	return num;
}

void City::win()
{
	//system("cls");
	cout << belong << "获得游戏胜利！" << endl;
	exit(0);
}

City& City::operator+=(const  City& temp)
{
	this->troops += temp.troops;
	return *this;
}
City& City::operator-=(const  City& temp)
{
	this->troops -= temp.troops;
	return *this;
}

double City::difference = 0;

void City::change_static(bool flag)
{
	if (flag) {
		troops = troops + difference*0.4;
	}
	else troops = troops / 2.0;
}

void City::changeBelong(string s)
{
	belong = s;
}

void City::changeTroops(double c)
{
	troops = c;
}