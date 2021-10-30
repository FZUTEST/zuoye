#include"work.h"
int main()
{
    srand((int)time(0));
    Interaction *inter=new Interaction;
    inter->getDifficulty();
    inter->getQuestionNum();
    inter->creatQuestion();
    inter->work();
}