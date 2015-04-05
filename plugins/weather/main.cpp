/*
* APPID (API key)d5141e09f65620429bf2ac06cd2a5a2c
*/


#include "main.h"

HINSTANCE g_hinstDLL;

Weather * DLL_EXPORT CreateObj()
{
    return new Weather;
}

void DLL_EXPORT DeleteObj(Weather * obj)
{
    delete obj;
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    g_hinstDLL = hinstDLL;
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
