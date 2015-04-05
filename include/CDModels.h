#ifndef CDMODELS_H
#define CDMODELS_H
#include "ManagerPlugins.h"

class CDModels
{
public:
    static CDModels& getInstance()
    {
        static CDModels instance;
        return instance;
    }

    void Init();

    protected:
    private:
        CDModels() {}
        CDModels(CDModels const&) {};
        void operator= (CDModels const&);
        virtual ~CDModels() {}
        CManagerPlugins menagerPlugins;
};

#endif // CDMODELS_H
