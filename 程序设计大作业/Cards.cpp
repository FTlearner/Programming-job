#include "Cards.h"
Cards::Cards(const string n) 
{
	Node* s = new Node;
	head = s;
	head->next = nullptr;
	head->name = n;
	insertCard();
	insertCard();
	insertCard();
	insertCard();
}

void Cards::insertCard()
{
	Node* x = new Node;
	x->name = getRandName();
	x->next = head->next;
	head->next = x;
}

void Cards::useCard()
{
	string s;
	cout << endl << "输入你想使用的卡牌：";
	cin >> s;
	(this->*test[findNumber(s)])();//测试卡包的调用情况
	deleteCard(s);
}

void Cards::deleteCard(string name)//待优化，如果输入一个错误的名字，那么应该重新输入
{
	for (Node* i = head; i != nullptr; i = i->next)
	{
		if (i->next->name == name)
		{
			Node* x = i->next;
			i->next = i->next->next;//删除操作
			delete x;
			return;	//防止多张同名卡牌同时被使用
		}
	}
}

void Cards::showCard()
{
	cout << "你现在拥有的手牌：";
	for (Node* i = head->next; i != nullptr; i = i->next)
	{
		cout << i->name << " ";
	}
	cout << endl;
}
