#include <windows.h>
#include "box.h"

HBRUSH hBackground;
HBRUSH hButtonBrush;
HBRUSH hEditBrush;

HFONT  hTitleFont;
HFONT  hGameFont;

HWND hTitle, hBtn1, hBtn2, hBtn3, hEdit;
bool editFocused = false;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg,
                            WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        // ================= CREATE =================
        case WM_CREATE:
        {
            // ===== Colors =====
            hBackground  = CreateSolidBrush(RGB(45,60,110));
            hButtonBrush = CreateSolidBrush(RGB(70,140,255));
            hEditBrush   = CreateSolidBrush(RGB(35,45,90));

            // ===== Title =====
            hTitle = CreateWindow(
                "STATIC",
                "SMART TRIP ASSISTANT",
                WS_VISIBLE | WS_CHILD | SS_CENTER,
                0,0,0,0,
                hwnd,NULL,NULL,NULL
            );

            hTitleFont = CreateFont(
                42,0,0,0,
                FW_BOLD,
                FALSE,FALSE,FALSE,
                DEFAULT_CHARSET,
                OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,
                CLEARTYPE_QUALITY,
                VARIABLE_PITCH,
                "Segoe UI"
            );

            // ===== Minecraft Style Font =====
            hGameFont = CreateFont(
                20,0,0,0,
                FW_NORMAL,
                FALSE,FALSE,FALSE,
                DEFAULT_CHARSET,
                OUT_DEFAULT_PRECIS,
                CLIP_DEFAULT_PRECIS,
                NONANTIALIASED_QUALITY, // pixel คม
                FIXED_PITCH,
                "Consolas" // หรือ "Press Start 2P"
            );

            SendMessage(hTitle, WM_SETFONT,
                        (WPARAM)hTitleFont, TRUE);

            // ===== Buttons =====
            hBtn1 = CreateWindow("BUTTON","Select Places",
                WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
                0,0,0,0,
                hwnd,(HMENU)BTN_PLACE,NULL,NULL);

            hBtn2 = CreateWindow("BUTTON","Restaurant Plan",
                WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
                0,0,0,0,
                hwnd,(HMENU)BTN_PLAN,NULL,NULL);

            hBtn3 = CreateWindow("BUTTON","Exit",
                WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
                0,0,0,0,
                hwnd,(HMENU)BTN_EXIT,NULL,NULL);

            // ===== Edit Box =====
            hEdit = CreateWindow("STATIC","",
                WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL,
                0,0,200,30,
                hwnd,NULL,NULL,NULL);

            // remove border default
            LONG style = GetWindowLong(hEdit, GWL_STYLE);
            style &= ~WS_BORDER;
            SetWindowLong(hEdit, GWL_STYLE, style);
            SetWindowPos(hEdit,NULL,0,0,0,0,
                SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);

            // ===== Apply game font =====
            SendMessage(hBtn1, WM_SETFONT,(WPARAM)hGameFont,TRUE);
            SendMessage(hBtn2, WM_SETFONT,(WPARAM)hGameFont,TRUE);
            SendMessage(hBtn3, WM_SETFONT,(WPARAM)hGameFont,TRUE);
            SendMessage(hEdit, WM_SETFONT,(WPARAM)hGameFont,TRUE);
        }
        break;

        // ================= LAYOUT =================
        case WM_SIZE:
        {
            int w = LOWORD(lParam);
            int h = HIWORD(lParam);

            int btnW = 260;
            int btnH = 50;
            int centerX = (w - btnW)/2;

            MoveWindow(hTitle, w/2 - 300, 40, 600,60, TRUE);

            // textbox ใหญ่ขึ้น
            MoveWindow(hEdit,
                w/2 - 140, h/2 - 150,
                280,40, TRUE);

            MoveWindow(hBtn1, centerX, h/2 - 40,
                btnW,btnH, TRUE);

            MoveWindow(hBtn2, centerX, h/2 + 30,
                btnW,btnH, TRUE);

            MoveWindow(hBtn3, centerX, h/2 + 100,
                btnW,btnH, TRUE);
        }
        break;

        // ===== Background =====
        case WM_ERASEBKGND:
        {
            RECT rect;
            GetClientRect(hwnd,&rect);
            FillRect((HDC)wParam,&rect,hBackground);
            return 1;
        }

        // ===== Edit color =====
        case WM_CTLCOLOREDIT:
        {
            HDC hdc = (HDC)wParam;
            SetTextColor(hdc, RGB(255,255,255));
            SetBkColor(hdc, RGB(35,45,90));
            return (LRESULT)hEditBrush;
        }

        case WM_CTLCOLORSTATIC:
        {
            HDC hdc = (HDC)wParam;
            SetTextColor(hdc, RGB(255,255,255));
            SetBkMode(hdc, TRANSPARENT);
            return (LRESULT)hBackground;
        }

        // ===== Focus detect =====
        case WM_COMMAND:
        {
            if(LOWORD(wParam)==BTN_EXIT)
                DestroyWindow(hwnd);

            if(HIWORD(wParam)==EN_SETFOCUS)
            {
                editFocused = true;
                InvalidateRect(hwnd,NULL,FALSE);
            }
            else if(HIWORD(wParam)==EN_KILLFOCUS)
            {
                editFocused = false;
                InvalidateRect(hwnd,NULL,FALSE);
            }
        }
        break;

        // ===== Glow + Rounded border =====
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd,&ps);

            RECT r;
            GetWindowRect(hEdit,&r);

            // ⭐ แปลง Screen → Client (ห้ามใช้ MapWindowPoints)
            POINT p1 = { r.left, r.top };
            POINT p2 = { r.right, r.bottom };

            ScreenToClient(hwnd,&p1);
            ScreenToClient(hwnd,&p2);

            r.left   = p1.x;
            r.top    = p1.y;
            r.right  = p2.x;
            r.bottom = p2.y;

            HGDIOBJ oldBrush = SelectObject(hdc,
                                GetStockObject(NULL_BRUSH));


            EndPaint(hwnd,&ps);
        }       
        break;

        case WM_DRAWITEM:
        {
            LPDRAWITEMSTRUCT dis = (LPDRAWITEMSTRUCT)lParam;

            bool pressed = (dis->itemState & ODS_SELECTED);

            if(dis->CtlType == ODT_BUTTON)
            {
                HDC hdc = dis->hDC;
                RECT r = dis->rcItem;

        // สีพื้นปุ่ม
                HBRUSH brush = CreateSolidBrush(RGB(70,140,255));
                FillRect(hdc,&r,brush);

        // ขอบ
                HPEN pen = CreatePen(PS_SOLID,2,RGB(0,200,255));
                SelectObject(hdc,pen);
                SelectObject(hdc,GetStockObject(NULL_BRUSH));
                RoundRect(hdc,r.left,r.top,r.right,r.bottom,10,10);

                // ตัวหนังสือ
                SetTextColor(hdc,RGB(255,255,255));
                SetBkMode(hdc,TRANSPARENT);
                SelectObject(hdc,hGameFont);

                char text[100];
                GetWindowText(dis->hwndItem,text,100);

                DrawText(hdc,text,-1,&r,
                    DT_CENTER | DT_VCENTER | DT_SINGLELINE);

                DeleteObject(brush);
                DeleteObject(pen);
                return TRUE;
            }       
        }
        break;

        case WM_DESTROY:
            PostQuitMessage(0);
        break;
    }

    return DefWindowProc(hwnd,msg,wParam,lParam);
}