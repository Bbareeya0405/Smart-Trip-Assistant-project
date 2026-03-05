#include <windows.h>
#include "box.h"

// ================= MAIN =================
int WINAPI WinMain(HINSTANCE hInst,
                   HINSTANCE,
                   LPSTR,
                   int nCmdShow)
{
    const char CLASS_NAME[]="SmartTripGUI";

    WNDCLASS wc={};
    wc.lpfnWndProc=WindowProc;
    wc.hInstance=hInst;
    wc.lpszClassName=CLASS_NAME;
    wc.hbrBackground=NULL;

    RegisterClass(&wc);

    HWND hwnd=CreateWindowEx(
        0,CLASS_NAME,
        "SMART TRIP ASSISTANT",
        WS_OVERLAPPEDWINDOW,
        300,150,650,500,
        NULL,NULL,hInst,NULL
    );

    ShowWindow(hwnd,nCmdShow);

    MSG msg={};
    while(GetMessage(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
