#include <iostream>

#define LOG(x) std::cout << x << std::endl

class Player
{
public:
    // 公有变量，意味着可以在任何地方访问
    static int x, y;
    int speed;

    Player(int x, int y)
    {

    }

    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }

    static void s_print()
    {
        LOG(x);
        LOG(y);
    }

};

class Good : public Player{
public:
    using Player::Player;
};

void sum_f(Good player)
{
    static int sum = 0;
    sum ++;
    LOG(player.y);
}

class Log
{
    private:
        // 这是一个约定，m_表示私有元素，就像python里面会用_表示私有
        int m_LogLevel;
    public:
        void SetLevel(int level)
        {
            m_LogLevel = level;      
        }

        void warn(const char *)
        {

        }
};

int Player::x;
int Player::y;  

int main()
{       
    // 默认一个类中所有变量都是对外不可见的
    Player player(1, 2);
    Log log;
    Player::x = 5;
    Player::y = 10;

    Good g(3, 4);
    for(int i = 0; i < 3; i++)
    {
        sum_f(g);
    }
    player.s_print();
}