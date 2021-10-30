#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define random(a,b) (rand()%(b-a)+a)


int random1()//生成[0，100]随机整数
{
    srand((int)time(0));
    int num = random(0, 100);
    return num;
}

int random2()//生成[0，10000]随机整数
{
    int b;
    srand((int)time(0));  // 产生随机种子
    b=(rand() % (10000-0+1))+ 0; 
    system("pause");
    return b;

}

float random3()//生成[0，10000]随机小数
{
    
}

void test_a(int num)//第一等级
{

    //调用random1()生成[0，100]随机整数
}

void test_b(int num)//第二等级
{
    
    //调用random2()生成[0，10000]随机整数
}

void test_c(int num)//第三等级
{
    
    //调用random3()生成[0，10000]随机小数 float
}

int main()
{
    int grade;
    
    cout <<  "enter grade" << endl;//输入一到六
    cin>>grade;
    int num=0;
    cout <<  "enter num" << endl;
    cin>>num;
    //cout <<  random1() << endl;
    switch(grade)
    {
        case 1 :
        case 2 :  test_a(num); break;
        case 3 :
        case 4 :  test_b(num); break;
        case 5 :
        case 6 :  test_c(num); break;
    }

    
}