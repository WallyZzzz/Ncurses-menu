#include "cwidgetnumber.h"

CWidgetNumber::CWidgetNumber() : m_intNumber(46)
{

}

void CWidgetNumber::initWidget(void)
{

}

void CWidgetNumber::leftAction(void)
{
    if(!--m_intNumber)
        ++m_intNumber;
}

void CWidgetNumber::rightAction(void)
{
    if(++m_intNumber > 100)
        --m_intNumber;
}

QString CWidgetNumber::getText(void)
{
    QString result = QString::number(m_intNumber);
    return result;
}

