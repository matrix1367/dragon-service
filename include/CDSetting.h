#ifndef CDSETTING_H
#define CDSETTING_H
#include <string>

struct CDSettingData {
    public:
        bool m_automaticCallMainDlL;
        bool m_automaticShowMainForm;
    public:
        CDSettingData(bool automaticCallMainDlL, bool automaticShowMainForm) :
                        m_automaticCallMainDlL(automaticCallMainDlL),
                        m_automaticShowMainForm(automaticShowMainForm)
        {

        }
        CDSettingData() : m_automaticCallMainDlL(true), m_automaticShowMainForm(true)
        {

        }
};

class CDSetting
{
public:

    std::string pathPlugin;
    std::string fileNameExe;
    std::string pathExe;

    bool automaticCallMainDlL;
    bool automaticShowMainForm;

    static CDSetting& getInstance()
    {
        static CDSetting instance;
        return instance;
    }

    void Init();
    void Save();
    void Load();

protected:
private:
    CDSetting();
    CDSetting(CDSetting const &);
    void operator=(CDSetting const &);
    virtual ~CDSetting();
};

#endif // CDSETTING_H
