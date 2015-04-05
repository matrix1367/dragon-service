#include "ManagerPlugins.h"
#include <Windows.h>
#include "IPlugin.h"
#include "CDPlugin.h"
#include "CDSetting.h"
#include "CDLog.h"

typedef IPlugin * (__stdcall *f_CreateObj)();

CManagerPlugins::CManagerPlugins()
{
    //ctor
}

CManagerPlugins::~CManagerPlugins()
{
    //dtor
}

std::list<std::string> CManagerPlugins::GetFiles(std::string path)
{
    CDLog::Write( __FUNCTION__ , __LINE__, Info, "GetFiles:path: " + std::string(path) );
    WIN32_FIND_DATA ffd;
    HANDLE hFind;
    hFind = FindFirstFile((path+ "*.dll").c_str(), &ffd);
    std::list<std::string> files;
    if (INVALID_HANDLE_VALUE != hFind)
    {
        do
        {
            if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {

            }
            else
            {
                files.push_back(path+  ffd.cFileName);
                CDLog::Write( __FUNCTION__ , __LINE__, Info, "add filename" + std::string(path+ffd.cFileName) );
            }
        }
        while(FindNextFile(hFind, &ffd) != 0);
        FindClose(hFind);
    }
    return files;
}

int CManagerPlugins::LoadPlugin(std::string path)
{
    HINSTANCE hGetProcIDDLL = NULL;
    hGetProcIDDLL = LoadLibrary(path.c_str());

    if (!hGetProcIDDLL)
    {
       // controls.ShowMeesage("[LoadPlugin] Could not load the dynamic library")    ;
        return EXIT_FAILURE;
    }

    f_CreateObj CreateObj = NULL;
    CreateObj = (f_CreateObj)GetProcAddress(hGetProcIDDLL, "CreateObj");
    if (!CreateObj)
    {
       // controls.ShowMeesage("could not locate the function CreateObj");
        return EXIT_FAILURE;
    }
    IPlugin * iplugin = NULL;
    iplugin = CreateObj();

    if (iplugin != NULL)
    {
        CDPlugin plugin(path, hGetProcIDDLL, iplugin);
        CDLog::Write( __FUNCTION__ , __LINE__, Info, "Plugin Name:" + plugin.GetName() );
        plugins.push_back(plugin);
        return EXIT_SUCCESS;
    }
    else
    {
        //controls.ShowMeesage("iplugin is null.");
        return EXIT_FAILURE;
    }
}

int CManagerPlugins::LoadPlugins()
{
    std::list<std::string> files =  GetFiles(CDSetting::getInstance().pathExe);
    for(std::list<std::string>::iterator it_files = files.begin(); it_files!= files.end(); it_files++)
    {
        LoadPlugin(*it_files);
    }
    return files.size();
}

void CManagerPlugins::UnLoadPlugins()
{
    for(std::vector<CDPlugin>::size_type i = 0 ; i != plugins.size(); i++)
    {
        if(!plugins[i].UnLoad())
        {
            CDLog::Write( __FUNCTION__ , __LINE__, Info, "[UnLoadPlugins] Could not unload the dynamic library." );
            //controls.ShowMeesage("[UnLoadPlugins] Could not unload the dynamic library.");
            return;
        }
    }
}

void CManagerPlugins::MainPlugin(void) {
    for(std::vector<CDPlugin>::size_type i = 0 ; i != plugins.size(); i++)
    {
        plugins[i].MainPlugin();
        CDLog::Write( __FUNCTION__ , __LINE__, Info, "[MainPlugin] Run." );
    }
}
