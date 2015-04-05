#include "Message.h"

CDMessage::CDMessage()
{
    //ctor
}

CDMessage::~CDMessage()
{
    //dtor
}

void CDMessage::SetTitle(std::string title){
    m_title = title;
}

std::string CDMessage::GetTitle(){
    return m_title;
}
