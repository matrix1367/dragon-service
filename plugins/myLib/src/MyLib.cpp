#include "MyLib.h"
#include "CDDialog.h"
#include <cstdio>

extern HINSTANCE g_hinstDLL;
BOOL CALLBACK ToolDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);


MyLib::MyLib()
{
    m_name = "myLib";
    m_version = "1.0";
    m_typePlugin = TYPE_PLUGIN_GUI;
    //unikalny id

}

MyLib::~MyLib()
{

}

std::string MyLib::GetName()
{
    return m_name;
}

std::string MyLib::GetVersion()
{
    return m_version;
}

TypePlugin MyLib::GetTypePlugin()
{
    return m_typePlugin;
}








BOOL CALLBACK ToolDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch(Message)
    {
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case IDC_PRZYC1:
                    MessageBox(hwnd, "Hi!", "This is a message",
                        MB_OK | MB_ICONEXCLAMATION);
                break;
                case IDC_PRZYC2:
                    MessageBox(hwnd, "Bye!", "This is also a message",
                        MB_OK | MB_ICONEXCLAMATION);
                break;
            }
        break;
        case WM_CLOSE :
            {
                 ShowWindow(hwnd, SW_HIDE);
            }
//        case WM_DESTROY:
//            {
//                DestroyWindow(m_ma);
//                PostQuitMessage(0);
//                break;
//            }


        default:
            return FALSE;
    }
    return TRUE;
}
