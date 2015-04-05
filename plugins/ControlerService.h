#ifndef CONTROLERSERVICE_H_INCLUDED
#define CONTROLERSERVICE_H_INCLUDED
#include "ManagerMessager.h"

class CDControlerService {
public:
    static CDControlerService& getInstance()
    {
        static CDControlerService instance;
        return instance;
    }

    void Init(void) {
    }

    void AddMessage(CDMessage& message) {
        managerMessage->Add(message);
    }

private:
    //std::string m_dupa;

    CDControlerService(CDControlerService const&) {};
    void operator= (CDControlerService const&);
    CDControlerService() {
        managerMessage = &CDManagerMessager::getInstance();
    }
    virtual ~CDControlerService() {}

    CDManagerMessager *managerMessage;
};

#endif // CONTROLERSERVICE_H_INCLUDED
