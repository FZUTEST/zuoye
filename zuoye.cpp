#include <iostream>
using namespace std;

int random1()//生成[0，100]随机整数
{

}

int random2()//生成[0，10000]随机整数
{

}

float random3()//生成[0，10000]随机小数
{
  	float num1,num2; 
 	float down=0.2,top=2.4;
 	float a;
 	srand((unsigned int)time(NULL));
    num1=(float)rand()/RAND_MAX;
    num2=(float)rand()*9999/RAND_MAX;
    a=num2+down+num1*(top-down);
    return a
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
    cout<<"请输入你的年级"<<endl;//输入一到六
    cin>>grade;
    int num=0;
    cout<<"请输入你想要的题数"<<endl;
    cin>>num;
    
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
