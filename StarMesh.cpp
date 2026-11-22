#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include "source/MainForm.h"
int WINAPI _tWinMain(HINSTANCE,HINSTANCE,LPTSTR,int) {
    try {
        Application->Initialize();Application->MainFormOnTaskBar=true;
        Application->CreateForm(__classid(TMainForm),&MainForm);
        MainForm->Show();ShowWindow(MainForm->Handle,SW_SHOWNORMAL);
        MainForm->start();
        MainForm->Show();ShowWindow(MainForm->Handle,SW_SHOWNORMAL);MainForm->BringToFront();
        Application->Run();
    } catch(Exception& e) {Application->ShowException(&e);return 1;}
    return 0;
}
