#ifndef CMANAGERPLUGINS_H
#define CMANAGERPLUGINS_H
#include <string>
#include <list>
#include <vector>
#include "CDPlugin.h"

class CManagerPlugins
{
    public:
        CManagerPlugins();
        virtual ~CManagerPlugins();
        std::list<std::string> GetFiles(std::string path);
        int LoadPlugins();
        int LoadPlugin(std::string path);
        void UnLoadPlugins();
    protected:
    private:
        std::vector<CDPlugin > plugins;
};

#endif // CMANAGERPLUGINS_H
