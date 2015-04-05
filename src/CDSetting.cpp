#include "CDSetting.h"
#include "CDUntils.h"
#include "CDSerialize.h"

#include <windows.h>

CDSetting::CDSetting()
{
    pathPlugin = "./bin/Debug/";
    Load();
    Init();
}

CDSetting::~CDSetting()
{
    //dtor
}

void CDSetting::Init()
{
    TCHAR szFileName[MAX_PATH];
    GetModuleFileName( NULL, szFileName, MAX_PATH );
    fileNameExe = szFileName;
    pathExe = szFileName;
    CDDragon::CDUntils::PathRemoveFileSpec(pathExe);

}

void CDSetting::Save()
{
    CDSettingData settingData(automaticCallMainDlL, automaticShowMainForm);
    CDSerialize<CDSettingData> serialzer("dragon_setting.dat");
    serialzer.Write(settingData);
}

void CDSetting::Load()
{
    CDSettingData settingData;
    CDSerialize<CDSettingData> serialzer("dragon_setting.dat");
    serialzer.Read(settingData);
    automaticCallMainDlL  = settingData.m_automaticCallMainDlL;
    automaticShowMainForm = settingData.m_automaticShowMainForm;
}


