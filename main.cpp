#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"
#include "CDModels.h"
#include "ControlerService.h"
#include "CDLog.h"

#define ID_TRAY1   601
#define CMSG_TRAY1 0x8001

HINSTANCE hInst;

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
        //trayicon
        char sTipTmp[] = {"Dragon - service"};
        LPSTR sTip = sTipTmp;
        NOTIFYICONDATA nid;
        nid.cbSize = sizeof( NOTIFYICONDATA );
        nid.hWnd = hwndDlg;
        nid.uID = ID_TRAY1;
        nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
        nid.uCallbackMessage = CMSG_TRAY1;
        nid.hIcon = LoadIcon( NULL, IDI_APPLICATION );
        lstrcpy( nid.szTip, sTip );
        BOOL r;
        r = Shell_NotifyIcon( NIM_ADD, & nid );
        if( !r ) MessageBox( hwndDlg, "Shell_NotifyIcon is false...", "Error...", MB_ICONEXCLAMATION );
        break;
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
            case IDM_CLOSE: {
                CDLog::Write( __FUNCTION__ , __LINE__, Info, "IDM_CLOSE" );
                EndDialog(hwndDlg, 0);
                break;
            }
        }
    }
    return TRUE;

    case CMSG_TRAY1:
    {
        if( wParam == ID_TRAY1 )
        if( lParam == WM_LBUTTONDOWN )
        {
            CDLog::Write( __FUNCTION__ , __LINE__, Info, "CMSG_TRAY1" );
            POINT point;
            GetCursorPos(&point);
            HMENU hMenu = LoadMenu(NULL, MAKEINTRESOURCE(IDR_POPUPMENU));
            TrackPopupMenu( GetSubMenu( hMenu, 0 ), 0, point.x, point.y, 0, hwndDlg, NULL );
        }

        break;
    }
    return TRUE;

    case WM_DESTROY:
    {
        NOTIFYICONDATA nid;
        nid.cbSize = sizeof( NOTIFYICONDATA );
        nid.hWnd = hwndDlg;
        nid.uID = ID_TRAY1;
        nid.uFlags = 0;

        Shell_NotifyIcon( NIM_DELETE, & nid );

        PostQuitMessage( 0 );
    }
    return TRUE;
    }
    return FALSE;
}



int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    CDControlerService::getInstance().Init();
    CDModels::getInstance().Init();

    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
