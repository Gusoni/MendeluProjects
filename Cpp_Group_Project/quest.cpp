#include "quest.h"

Quest::Quest(GameObject *parent, QString desc)
    : GameObject{parent}, m_description{desc}
{

}

QString Quest::getDescription(){
    return m_description;
}

int Quest::getExpReward(){
return m_exp_reward;
}

void Quest::setDescription(QString desc){
m_description= desc;
}

void Quest::setExpReward(int exp){
m_exp_reward = exp;
}
