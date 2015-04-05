#include "ManagerMessager.h"

void CDManagerMessager::Add(const CDMessage& message)
{
    queueMessage.push(message);
}

bool CDManagerMessager::Get(CDMessage * message)
{
    if (queueMessage.size() > 0){
        message = &queueMessage.front();
        queueMessage.pop();
        return true;
    }
    return false;
}
