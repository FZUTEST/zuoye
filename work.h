#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
using namespace std;

unordered_map<string,int>grade_dif={{"一年级",1},{"二年级",1},{"三年级",2},{"四年级",2},{"五年级",3},{"六年级",3}};

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
    vector<pair<string, double>> &creat();
};


class Question
{
protected:    
    int figureNum;
    vector<char>symbolVec;
    bool bracket;
public:
    Question()
    {
        figureNum=4;
        srand((int)time(0));
        bracket=rand()%2;
    }
    virtual pair<string, double> &getQuestion();
    void setfigureNum(int n)
    {
        figureNum=n;
    }
};


class Easy:public Question
{
protected:
    char symbol[2]={'+','-'};
    vector<int>numVec;
public:
    pair<string, double> &getQuestion()override;

};


class Normal:public Question
{
protected:
    char symbol[4]={'+','-','*','/'};
    vector<int>numVec;
public:
    pair<string, double> &getQuestion()override;
};


class Hard:public Question
{
protected:
    char symbol[4]={'+','-','*','/'};
    vector<double>numVec;
public:
    pair<string, double> &getQuestion()override;

};


double calculate(string str)
{

}




