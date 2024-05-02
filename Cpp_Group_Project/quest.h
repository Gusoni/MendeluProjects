#ifndef QUEST_H
#define QUEST_H

#include <QObject>
#include "gameobject.h"
#include <QVariant>
#include <QString>
class Quest : public GameObject
{
    Q_OBJECT
public:
    explicit Quest(GameObject *parent = nullptr, QString desc = "");
    QString getDescription();
    int getExpReward();
    void setDescription(QString desc);
    void setExpReward(int exp);

signals:
private:
    QString m_description;
    int m_exp_reward;

};

#endif // QUEST_H
