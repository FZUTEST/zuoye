#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
#define random(x) rand()%(x)


int random1()//生成[0，100]随机整数
{
    
    return random(100);
}

int random2()//生成[0，10000]随机整数
{

    return random(10000);
}

float random3()//生成[0，10000]随机小数
{


  	float num;   
	//srand((unsigned int)time(NULL));
    num=(float)rand()*10000/RAND_MAX;
    
    //printf("a=%f\n",a);
	return num;



}

void test_a(int num)//第一等级
{
    //调用random1()生成[0，100]随机整数
    int flag = 0;
    int randomSingle = 0;
    int _num = num;//用户输入要做的题目数
    int answer[_num];
    //srand((int)time(0));  // 产生随机种子
    char str1[4] = { '+','-','=','?'};//加减等于问号 字符串数组
    for (int j = 0; j < _num; j++)
    {
        int sum = 0;
        int num_random = random(10);//随机出每个算式的数字有多少个
        while(num_random==1)
        {
            num_random = random(10);
        }
        
        for (int i = 0; i <num_random ; i++)
        {
            int str1_random = rand() % 2;//随机生成0或1，为0生成加号，为1生成减号
            randomSingle = random1();
            cout << randomSingle << " ";
            if (str1_random == 0 && i != num_random - 1)
            {
                cout << str1[0]<<" ";//输出+号
            }
            if (str1_random == 0)
            {
                if (i == 0)
                {
                    sum = randomSingle;
                }
                else
                {
                    sum += randomSingle;
                }
            }
            if (str1_random == 1 && i != num_random - 1)
            {
                cout << str1[1] << " ";//输出-号
            }
            if (str1_random == 1)
            {
                if (i == 0)
                {
                    sum = randomSingle;
                }
                if (i != 0)
                {
                    sum -= randomSingle;
                }
            }
            if (i == num_random - 1)
            {
                cout << str1[2] <<" "<< str1[3] << endl;//输出=和?号
            }
        }
        cin >> answer[j];
        if (sum == answer[j])
        {
            flag++;
        }
        //cout<<sum<<endl;
    }
    if (flag == _num)
    {
        cout << "结束！全部正确，太棒了！" << endl;
    }
    else
    {
        cout << "结束！错了" << _num - flag << "题哦" << endl;
    }
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
    srand((int)time(NULL));  
    // for (int i = 0; i < 8; i++)
    // {
    //     cout<<random3()<<endl;
    // }
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
