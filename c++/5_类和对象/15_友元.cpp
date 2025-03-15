#include <iostream>
#include <string>
using namespace std;

class Building;
class Player
{
public:
    Building *b;
    Player();
    void goToPlay();
};

class Building
{

    // *全局函数做友元：让全局函数goodGay可以访问Building中的私有成员
    friend void goodGay(Building *building);
    // *类做友元：让类可以访问Building中的私有成员
    friend class Visitor;
    // *成员函数做友元：让类的成员函数可以访问Building中的私有成员
    friend void Player::goToPlay();

public:
    Building()
    {
        m_sittingRoom = "客厅";
        m_bedRoom = "卧室";
    }

public:
    string m_sittingRoom;

private:
    string m_bedRoom;
};

// 全局函数
void goodGay(Building *building)
{
    cout << "好基友全局函数 正在访问：" << building->m_sittingRoom << endl;
    cout << "好基友全局函数 正在访问：" << building->m_bedRoom << endl; // 默认不可访问私有变量
}

// 类
class Visitor
{
public:
    Building *b;
    Visitor()
    {
        b = new Building;
    }

    void goToVisit()
    {
        cout << "参观者类正在访问：" << b->m_sittingRoom << endl;
        cout << "参观者类正在访问：" << b->m_bedRoom << endl; // 默认不可访问私有变量
    }
};

// 在类外实现成员函数
Player::Player()
{
    b = new Building;
};

void Player::goToPlay()
{
    cout << "游玩者类正在访问：" << b->m_sittingRoom << endl;
    cout << "游玩者类正在访问：" << b->m_bedRoom << endl; // 默认不可访问私有变量
};

int main()
{
    Building b;
    goodGay(&b);

    Visitor v;
    v.goToVisit();

    Player p;
    p.goToPlay();
}