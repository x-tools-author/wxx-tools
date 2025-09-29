/***************************************************************************************************
 * Copyright 2025-2025 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xxTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#include "mainwindow.h"

MainWindow::MainWindow()
    : CFrame()
{
    SetView(m_view);
}

MainWindow::~MainWindow() {}

HWND MainWindow::Create(HWND parent)

{
    return CFrame::Create(parent);
}

BOOL MainWindow::OnCommand(WPARAM wparam, LPARAM lparam)
{
    return CFrame::OnCommand(wparam, lparam);
}

int MainWindow::OnCreate(CREATESTRUCT& cs)
{
    // OnCreate controls the way the frame is created.
    // Overriding CFrame::OnCreate is optional.

    // A menu is added if the IDW_MAIN menu resource is defined.
    // Frames have all options enabled by default.
    // Use the following functions to disable options.

    // UseIndicatorStatus(FALSE);   // Don't show keyboard indicators in the StatusBar
    // UseMenuStatus(FALSE);        // Don't show menu descriptions in the StatusBar
    // UseReBar(FALSE);             // Don't use a ReBar
    // UseStatusBar(FALSE);         // Don't use a StatusBar
    // UseThemes(FALSE);            // Don't use themes
    // UseToolBar(FALSE);           // Don't use a ToolBar

    // call the base class function
    return CFrame::OnCreate(cs);
}

void MainWindow::OnInitialUpdate()
{
    // OnInitialUpdate is called after the frame and view window have been created.
    // Overriding CFrame::OnInitialUpdate is optional.

    // Call the base class function
    CFrame::OnInitialUpdate();

    // Put any additional initialisation here.
}

LRESULT MainWindow::OnNotify(WPARAM wparam, LPARAM lparam)
{
    return CFrame::OnNotify(wparam, lparam);
}

void MainWindow::SetupToolBar()
{
    // SetupToolBar is called by CFrame::OnCreate to add buttons to the ToolBar.
    // Overriding CFrame::SetupToolBar is optional.

    // Call the base class function to add the standard buttons.
    CFrame::SetupToolBar();

    // Add any additional buttons here.
}

LRESULT MainWindow::WndProc(UINT msg, WPARAM wparam, LPARAM lparam)
{
    return CFrame::WndProc(msg, wparam, lparam);
}