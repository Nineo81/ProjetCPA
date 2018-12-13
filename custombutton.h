#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H
#include <QPushButton>

class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    CustomButton(int type, const QString &text);
    int getType();
private:
    int type;
signals:
    void customClicked(int type);
public slots:
    void reemitClicked();
};

#endif // CUSTOMBUTTON_H
