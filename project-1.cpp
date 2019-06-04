#include<iostream>
#include<cstdlib>
#include<ctime>
#include <stdlib.h>
using namespace std;

void itoa (int n,char s[]);
class Player
{
        private:
                int card;
                int nNumber;//发了多少张牌
                int nDollar;//有多少钱
                int nGamble;//赌注
                int nWin;//赢的局数
                int nLose;//输的局数
                int nDraw;//平局数

        public:
                Player();//构造函数初始化
                void Win();//赢了
                void Lose();//输了
                void draw();//平局
                int setGamble(int);//设置赌注
                int getGamble(); // 获取赌注
                int getMoney();//返回钱数
                void display();//打印必要信息
                char getCard();//返回当前牌
                void drawCard(); // 抽牌
};

Player::Player()
{
        nNumber = 0;
        nDollar = 100;
        card = 0;
        nGamble = 0;
        nWin = 0;
        nLose = 0;
        nDraw = 0;

}


char processCard(int card){
        if (card <= 10)return card;
        switch (card)
        {
        case 11:
                return 'J';
        case 12:
                return 'Q';
        case 13:
                return 'K';
        default:
                char tmp[1];
                itoa(card, tmp);
                return tmp[0];
        }
}


int Player::getMoney()//
{
        return nDollar;
}


void Player::display()
{
        cout<<"您一共玩了"<<nWin+nLose+nDraw<<"局,"<<"赢了"<<nWin<<"局,"<<"输了"<<nLose<<"局，"<<"平局"<<nDraw<<"局"<<endl;
        cout<<"您的赌资共计有：$"<<nDollar<<".\n";

}

int Player::setGamble(int gamble)//设赌注
{
        if(nDollar - gamble<0)
        return -1;
        if(gamble<0)
        {
                if(nDollar - 20 <0)
                        return -1;
                nGamble = 20;
        }
        else
                nGamble =gamble;
        nDollar -= nGamble;
        return 0;
}

int Player::getGamble(){
        return nGamble;
}


void Player::Win()//赢了计算赌资
{
        nDollar = nDollar +2*nGamble;
        nWin++;
        cout<<"赌本：$"<<nDollar<<" 赢了"<<nWin<<"次"<<"输了"<<nLose<<"次 "<<"平局"<<nDraw<<"次"<<endl;
        cout <<endl<<endl;
}

void Player::Lose()//输了计算赌资
{
        nLose ++;
        cout<<"赌本：$"<<nDollar<<" 赢了"<<nWin<<"次"<<"输了"<<nLose<<"次 "<<"平局 "<<nDraw<<"次 "<<endl;
        cout<<endl<<endl;
}

void Player::draw()//平局
{
        nDraw++;
        nDollar+=nGamble;
        cout<<"赌本：$"<<nDollar<<" 赢了"<<nWin<<"次"<<"输了"<<nLose<<"次 "<<"平局 "<<nDraw<<"次 "<<endl;
        cout<<endl<<endl;
}

void Player::drawCard()
{
        card = rand()%13+1;
}

char Player::getCard(){
        return processCard(card);
}



void playTurn(Player &cpu, Player &user){
        cpu.drawCard();
        user.drawCard();
        cout << "电脑抽到的牌：" << cpu.getCard() << endl;
        cout << "你抽到的牌：" << user.getCard() << endl;
        if(cpu.getCard() > user.getCard()){
                cpu.Win();
                user.Lose();
                cout << "很遗憾你输了！损失：" << user.getGamble() << endl;
        }
        else{if(cpu.getCard() == user.getCard()){
                user.draw();
                cpu.draw();
                cout << "平局！赌注将会返还给你！" << endl;
        }else{
                user.Win();
                cpu.Lose();
                cout << "恭喜你赢了！赚取：" << user.getGamble()  << endl;
        }}
}


int main()
{
        srand((unsigned )time(NULL));//初始化随机数种子
        Player cpu,user;
        int blLogic;
        int nMoney;
        char chChoice;
        cout<<"是否开始游戏（Y/N）?";
        cin >>chChoice;
        while(chChoice == 'Y'||chChoice =='y')
        {
                do
                {
                        cout<<"您现在有余额：$"<<user.getMoney();
                        cout<<"\n请下注：";
                        cin>>nMoney;
                        blLogic = user.setGamble(nMoney);
                        if(blLogic)
                                cout<<"您的余额，请重新下注！\n";

                }
                while(blLogic);
                playTurn(cpu,user);
                cout<<"是否继续游戏（Y/N）?\n";
                cin>>chChoice;
        }
        user.display();
        cout<<"欢迎再次使用本程序\n\n\n";
        return 0;

}