#ifndef WINDOW_HPP
#define WINDOW_HPP
#undef UNICODE
#include "windows.h"
#include "stdio.h"
#include "../lib/glad/glad.h"

LRESULT window_procedure(HWND windowshandle,UINT messageid,WPARAM wparam,LPARAM lparam);

void test_window();

#endif