#ifndef SE_DEBUGOUTPUT_H
#define SE_DEBUGOUTPUT_H

#include <QWidget>
#include <QTextEdit>

class SE_DebugOutput : public QWidget
{
    Q_OBJECT
public:
    explicit SE_DebugOutput(QWidget *parent = nullptr);

signals:

};

#endif // SE_DEBUGOUTPUT_H
