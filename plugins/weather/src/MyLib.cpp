#include "MyLib.h"
#include "CDDialog.h"
#include <cstdio>

extern HINSTANCE g_hinstDLL;


Weather::Weather()
{
    Init();
}

Weather::~Weather()
{

}

void Weather::Init(void){
    m_data.name = "Weather";
    m_data.version = "1.0.0";
    m_data.typePlugin = TYPE_PLUGIN_BACKGROUND;
}

PluginData Weather::GetPluginData() {
    return m_data;
}

void Weather::MainPlugin(CDControlerService* controler) {
 //MessageBox( NULL, "mainPlugin", "Dragon", MB_ICONINFORMATION );
    m_controler = controler;

    CDMessage message;
    message.SetTitle("DUPA");
    m_controler->AddMessage(message);
}



