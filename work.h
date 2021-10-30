#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include "calculate.h"
using namespace std;

//unordered_map<string,int>grade_dif={{"一年级",1},{"二年级",1},{"三年级",2},{"四年级",2},{"五年级",3},{"六年级",3}};

class Interaction
{
    int difficulty;
    int questionNum;
    int errorNum=0;
    vector<pair<string, double>> question;

public:
    int getDifficulty();
    int getQuestionNum();
    void creatQuestion();
    void work();
};


class QuestionFactory
{
    int num;
    int dif;
public:
    QuestionFactory(int n,int d) : num(n),dif(d){};
    vector<pair<string, double>> creat();
};


class Question
{
protected:    
    int figureNum;
    bool bracket;
public:
    Question()
    {
        figureNum=4;
        srand((int)time(0));
        bracket=rand()%2;
    }
    virtual pair<string, double> getQuestion()=0;
    void setfigureNum(int n)
    {
        figureNum=n;
    }
};


class Easy:public Question
{
protected:
    char symbol[2]={'+','-'};
public:
    pair<string, double> getQuestion()override;

};


class Normal:public Question
{
protected:
    char symbol[4]={'+','-','*','/'};
public:
    pair<string, double> getQuestion()override;
};


class Hard:public Question
{
protected:
    char symbol[4]={'+','-','*','/'};
public:
    pair<string, double> getQuestion()override;

};







//Question 子类实现,这里代码重复太多，需要修改
pair<string, double> Easy::getQuestion()
{
    //生成数字集和符号集
    string ques = "";
    if (figureNum <= 2)
        bracket = 0;
    //无括号
    if (bracket)
    {
        for (int i = 0; i < figureNum - 1; ++i)
        {
            int _num = rand() % 101;
            char _symbol = symbol[(rand() % 2)];
            ques += to_string(_num) + _symbol;
        }
        ques += to_string(rand() % 101);
    }

    //有括号
    else
    {
        int bracketNum = rand() % (figureNum - 2);
        int rbracketNum = 0;
        for (int i = 0; i < figureNum - 1; ++i)
        {
            int _num = rand() % 101;
            char _symbol = symbol[(rand() % 2)];
            int isBracket;
            int cur = 0; //判断是否进入过循环
            do
            {
                isBracket = rand() % 2;
                if (isBracket && bracketNum)
                {
                    bracketNum--;
                    cur++;
                    rbracketNum++;
                    ques += '(';
                }
            } while (isBracket);
            ques += to_string(rand() % 101);
            if ((!cur) && rbracketNum)
            {
                ques += ')';
                rbracketNum--;
            }
            ques += _symbol;
        }
        ques+=to_string(rand() % 101);
        for (int i = 0; i < rbracketNum; i++)
        {
            ques += ")";
        }
    }
    //计算输出
    pair<string, double> result;
    result = make_pair(ques, calculate(ques));
    return result;
}

pair<string, double> Normal::getQuestion()
{
    //生成数字集和符号集
    string ques = "";
    if (figureNum <= 2)
        bracket = 0;
    //无括号
    if (bracket)
    {
        for (int i = 0; i < figureNum - 1; ++i)
        {
            int _num = rand() % 10001;
            char _symbol = symbol[(rand() % 4)];
            ques += to_string(_num) + _symbol;
        }
        ques += to_string(rand() % 10001);
    }

    //有括号
    else
    {
        int bracketNum = rand() % (figureNum - 2);
        int rbracketNum = 0;
        for (int i = 0; i < figureNum - 1; ++i)
        {
            int _num = rand() % 10001;
            char _symbol = symbol[(rand() % 4)];
            int isBracket;
            int cur = 0; //判断是否进入过循环
            do
            {
                isBracket = rand() % 2;
                if (isBracket && bracketNum)
                {
                    bracketNum--;
                    cur++;
                    rbracketNum++;
                    ques += '(';
                }
            } while (isBracket);
            ques += to_string(rand() % 10001);
            if ((!cur) && rbracketNum)
            {
                ques += ')';
                rbracketNum--;
            }
            ques += _symbol;
        }
        ques+=to_string(rand() % 10001);
        for (int i = 0; i < rbracketNum; i++)
        {
            ques += ")";
        }
    }
    //计算输出
    pair<string, double> result;
    result = make_pair(ques, calculate(ques));
        return result;
}

pair<string, double> Hard::getQuestion()
{
    //生成数字集和符号集
    string ques = "";
    if (figureNum <= 2)
        bracket = 0;
    //无括号
    if (bracket)
    {
        for (int i = 0; i < figureNum - 1; ++i)
        {
            double _num = rand() % 10001+(double)(rand()%100)/100;
            char _symbol = symbol[(rand() % 4)];
            ques += to_string(_num) + _symbol;
        }
        ques += to_string(rand() % 10001+(double)(rand()%100)/100);
    }

    //有括号
    else
    {
        int bracketNum = rand() % (figureNum - 2);
        int rbracketNum = 0;
        for (int i = 0; i < figureNum - 1; ++i)
        {
            int _num = rand() % 10001+(double)(rand()%100)/100;
            char _symbol = symbol[(rand() % 4)];
            int isBracket;
            int cur = 0; //判断是否进入过循环
            do
            {
                isBracket = rand() % 2;
                if (isBracket && bracketNum)
                {
                    bracketNum--;
                    cur++;
                    rbracketNum++;
                    ques += '(';
                }
            } while (isBracket);
            ques += to_string(rand() % 10001+(double)(rand()%100)/100);
            if ((!cur) && rbracketNum)
            {
                ques += ')';
                rbracketNum--;
            }
            ques += _symbol;
        }
        ques+=to_string(rand() % 10001+(double)(rand()%100)/100);
        for (int i = 0; i < rbracketNum; i++)
        {
            ques += ")";
        }
    }
    //计算输出
    pair<string, double> result;
    result = make_pair(ques, calculate(ques));
        return result;
}

//Interaction类实现
int Interaction::getDifficulty()
{
    cout << "请输入你的年级" << endl;
    //string grade;
    //cin >> grade;
    //difficulty = grade_dif[grade];
    cin>> difficulty;
    return difficulty;
}

int Interaction::getQuestionNum()
{
    cout << "请输入题目数" << endl;
    cin >> questionNum;
    return questionNum;
}

void Interaction::creatQuestion()
{
    QuestionFactory *factory = new QuestionFactory(questionNum, difficulty);
    question = factory->creat();
}

void Interaction::work()
{
    for (int i = 0; i < questionNum; i++)
    {
        cout << question[i].first << "?" << endl;
        double temp;
        cin >> temp;
        if (question[i].second != temp)
        {
            errorNum++;
        }
    }
    if (errorNum == 0)
        cout << "结束！全部正确，太棒了！" << endl;
    else
        cout << "结束！错了" << errorNum << "道题哦" << endl;
}

//QuestionFactory类实现
vector<pair<string, double>> QuestionFactory::creat()
{
    vector<pair<string, double>> temp;
    switch (dif)
    {
    case 1:
        for (int i = 0; i < num; i++)
        {
            Question *ques = new Easy;
            temp.push_back(ques->getQuestion());
        }
        break;
    case 2:
        for (int i = 0; i < num; i++)
        {
            Question *ques = new Normal;
            temp.push_back(ques->getQuestion());
        }
        break;
    case 3:
        for (int i = 0; i < num; i++)
        {
            Question *ques = new Hard;
            temp.push_back(ques->getQuestion());
        }
        break;
    default:
        cout << "题目难度出错" << endl;
        break;
    }
    return temp;
}