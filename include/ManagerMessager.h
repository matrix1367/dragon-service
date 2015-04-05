#ifndef CDMANAGERMESSAGER_H
#define CDMANAGERMESSAGER_H
#include <queue>
#include "Message.h"

class CDManagerMessager
{
    public:
        static CDManagerMessager& getInstance()
        {
            static CDManagerMessager instance;
            return instance;
        }
        void Add(const CDMessage& message);
        bool Get(CDMessage * message);
    protected:
    private:
        CDManagerMessager(CDManagerMessager const&) {}
        void operator= (CDManagerMessager const&);
        CDManagerMessager() {}
        virtual ~CDManagerMessager() {}

        std::queue<CDMessage> queueMessage;
};

#endif // CDMANAGERMESSAGER_H
