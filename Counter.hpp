/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** Counter
*/

#include <QtCore/QObject>

class Counter : public QObject {
    Q_OBJECT

public:
    Counter()
    {
        m_value = 0;
    }

    int value() const
    {
        return m_value;
    }

public slots:
    void setValue(int value);

signals:
    void valueChanged(int newValue);

private:
    int m_value;
};
