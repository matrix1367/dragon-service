#ifndef CDPLUGIN_H_INCLUDED
#define CDPLUGIN_H_INCLUDED

#include <string>

#include <process.h>
#include "IPLugin.h"
#include "ControlerService.h"

typedef void (__stdcall *f_DeleteObj)(IPlugin * obj);

struct CDPlugin
{
public:
    CDPlugin(std::string path,
             HINSTANCE hGetProcIDDLL,
             IPlugin* pluginOBJ) : m_path(path), m_hGetProcIDDLL(hGetProcIDDLL), m_pluginOBJ(pluginOBJ)
    {
        //printf("Create plugin path: [%s], name: [%s], version: [%s], istance: [%d], plugin: [%p]\n", path.c_str(), name.c_str(), version.c_str(), hGetProcIDDLL, pluginOBJ);
    }
    ~CDPlugin()
    {
        //UnLoad();
    }



    inline std::string GetPath()
    {
        return m_path;
    }

    std::string GetName()
    {
        return  m_pluginOBJ->GetPluginData().name;
    }

    std::string GetVersion()
    {
        return m_pluginOBJ->GetPluginData().version;
    }

    inline TypePlugin GetTypePlugin()
    {
        return m_pluginOBJ->GetPluginData().typePlugin;
    }

    inline std::string GetTypePluginStr()
    {
        switch(m_pluginOBJ->GetPluginData().typePlugin)
        {
            case TYPE_PLUGIN_GUI:
            {
                return "GUI";
            }
            case TYPE_PLUGIN_BACKGROUND:
            {
                return "BACKGROUND";
            }
        }
        return "NULL";
    }

    inline HINSTANCE GetHinstance()
    {
        return m_hGetProcIDDLL;
    }

    bool UnLoad()
    {
        if (!m_hGetProcIDDLL)
        {
            return false;
        }

        f_DeleteObj DeleteObj = (f_DeleteObj)GetProcAddress(m_hGetProcIDDLL, "DeleteObj");
        if (!DeleteObj)
        {
            return false;
        }

        DeleteObj(m_pluginOBJ);
        //nie koniecznie true....
        return true;
    }

    void MainPlugin() {
        m_pluginOBJ->MainPlugin(&CDControlerService::getInstance());
    }






private:
    std::string m_path;
    HINSTANCE m_hGetProcIDDLL;
    IPlugin* m_pluginOBJ;



};

#endif // CDPLUGIN_H_INCLUDED
