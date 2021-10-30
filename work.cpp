#include "work.h"
//Question 子类实现
pair<string, double> &Easy::getQuestion()
{
    //生成数字集和符号集
    
    string ques = "";
    for (int i = 0; i < figureNum - 1; ++i)
    {
        numVec.push_back(rand() % 101);
        symbolVec.push_back(symbol[rand() % 2]);
        ques += to_string(numVec[i]) + symbolVec[i];
    }
    numVec.push_back(rand() % 101);
    ques += numVec.back();

    //计算输出
}

//Interaction类实现
int Interaction::getDifficulty()
{
    cout << "请输入你的年级" << endl;
    string grade;
    cin >> grade;
    difficulty = grade_dif[grade];
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
vector<pair<string, double>> &QuestionFactory::creat()
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
            Question *ques = new Easy;
            temp.push_back(ques->getQuestion());
        }
        break;
    default:
        cout << "题目难度出错" << endl;
        break;
    }
}