#ifndef MYLIB_H
#define MYLIB_H
#include <string>
#include "IPlugin.h"

class Weather : public IPlugin
{
    public:
        Weather();
        virtual ~Weather();
        void Init();
        void MainPlugin() ;
        PluginData GetPluginData();
    protected:
    private:

};

#endif // MYLIB_H
