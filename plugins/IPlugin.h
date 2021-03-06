#ifndef IPLUGIN_H_INCLUDED
#define IPLUGIN_H_INCLUDED

#include <string>
#include <windows.h>
#include "ControlerService.h"


enum TypePlugin { TYPE_PLUGIN_GUI , TYPE_PLUGIN_BACKGROUND };

typedef struct TPluginData {
public:
    std::string name;
    std::string version;
    TypePlugin typePlugin;
} PluginData;


class IPlugin {
public:

    virtual PluginData GetPluginData() = 0;
    virtual void MainPlugin(CDControlerService* controler) = 0;

protected:
    PluginData m_data;
    CDControlerService* m_controler;
private:


};

#endif // IPLUGIN_H_INCLUDED
