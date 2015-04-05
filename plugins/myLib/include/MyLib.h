#ifndef MYLIB_H
#define MYLIB_H
#include <string>
#include "IPlugin.h"

enum CMD_MyLib { CMD_MYLIB_TEST };

class MyLib : public IPlugin
{
    public:
        MyLib();
        virtual ~MyLib();
        std::string GetName();
        std::string GetVersion();
        TypePlugin GetTypePlugin();



    protected:
    private:

};

#endif // MYLIB_H
