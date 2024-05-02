#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <QObject>

class GameObject: public QObject{
    Q_OBJECT
    Q_PROPERTY(QString type READ getType CONSTANT)
public:
    explicit GameObject(QObject *parent = nullptr){};
    virtual QString getType() const {return m_type;};
    int m_tile_position;

private:
    QString m_type;
};

#endif // GAMEOBJECT_H

