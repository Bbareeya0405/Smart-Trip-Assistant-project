#ifndef BOX_H
#define BOX_H

#include <windows.h>

#define BTN_PLACE  101
#define BTN_PLAN   102
#define BTN_EXIT   103

extern HBRUSH hBackground;
extern HBRUSH hButtonBrush;
extern HBRUSH hEditBrush;

extern HFONT  hTitleFont;
extern HFONT  hGameFont;

extern HWND hTitle, hBtn1, hBtn2, hBtn3, hEdit;
extern bool editFocused;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg,
                            WPARAM wParam, LPARAM lParam);

#endif