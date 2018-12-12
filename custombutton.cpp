#include "custombutton.h"

CustomButton::CustomButton(int type, const QString &text) : type(type)
{
    setText(text);
    QObject::connect(this,SIGNAL(clicked()),this,SLOT(reemitClicked()));
}

int CustomButton::getType()
{
    return type;
}

void CustomButton::reemitClicked()
{
    emit customClicked(type);
}
