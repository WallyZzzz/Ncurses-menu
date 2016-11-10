#include "cwidgetstatus.h"

CWidgetStatus::CWidgetStatus() : m_myStatus(false)
{

}

void CWidgetStatus::initWidget(void)
{

}

void CWidgetStatus::leftAction(void)
{
    m_myStatus = (m_myStatus == true)?false:true;
}

void CWidgetStatus::rightAction(void)
{
    m_myStatus = (m_myStatus == true)?false:true;
}

QString CWidgetStatus::getText(void)
{
    if(m_myStatus)
        return "TRUE ";
    else
        return "FALSE";
}
