/***************************************************************************************************
 * Copyright 2025-2025 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xxTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#include "application.h"
#include "mainwindow.h"

#if WXXT_LOG_TO_CONSOLE
int main(int argc, char* argv[])
{
    Application app;

    MainWindow mw;
    mw.Create(0);

    return app.Run();
}
#else
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application app;

    Trace(_T("WinMain: Start of WinMain\n"));

    MainWindow mw;
    mw.Create(0);

    return app.Run();
}
#endif