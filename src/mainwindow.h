/***************************************************************************************************
 * Copyright 2025-2025 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xxTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#pragma once

#include <wxx_appcore.h>
#include <wxx_frame.h>

class MainWindow : public CFrame
{
public:
    MainWindow();
    virtual ~MainWindow();
    HWND Create(HWND parent = 0) override;

protected:
    BOOL OnCommand(WPARAM wparam, LPARAM lparam) override;
    int OnCreate(CREATESTRUCT& cs) override;
    void OnInitialUpdate() override;
    LRESULT OnNotify(WPARAM wparam, LPARAM lparam) override;
    void SetupToolBar() override;
    LRESULT WndProc(UINT msg, WPARAM wparam, LPARAM lparam) override;

private:
    CWnd m_view;
};
