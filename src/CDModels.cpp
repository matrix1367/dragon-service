#include "CDModels.h"
#include "CDSetting.h"

void CDModels::Init()
{
    menagerPlugins.LoadPlugins();
    if(CDSetting::getInstance().automaticCallMainDlL)
    {
        //menagerPlugins.Main();
    }

}
