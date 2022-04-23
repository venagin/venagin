#include "triangle.hpp"
#define WINDOW_POS_X 0
#define WINDOW_POS_Y 0
#define WINDOW_SIZE_X 512
#define WINDOW_SIZE_Y 512
#define WINDOW_CLASS_NAME "512"
HGLRC opengl;

void test_triangle()
{
    printf("%sWorld!%c","Hello ",'\n');
    WNDCLASS cls=
    {
        .style=CS_OWNDC | CS_VREDRAW | CS_HREDRAW,
        .lpfnWndProc=window_procedure,
        .cbClsExtra=0,
        .cbWndExtra=0,
        .hInstance=GetModuleHandle(NULL),
        .hIcon=0,
        .hCursor=0,
        .hbrBackground=0,
        .lpszMenuName="",
        .lpszClassName=WINDOW_CLASS_NAME 
        
    };
    //cls.hbrBackground=cls.hCursor=cls.hIcon=NULL; 
    RegisterClass(&cls);

    HWND window=CreateWindow
    (
        WINDOW_CLASS_NAME,
        "Hello World!",
        WS_OVERLAPPED|WS_CAPTION|WS_OVERLAPPEDWINDOW,
        WINDOW_POS_X,WINDOW_POS_Y,
        WINDOW_SIZE_X,WINDOW_SIZE_Y,
        NULL,
        NULL,
        cls.hInstance,
        NULL
    );
    ShowWindow(window,SW_SHOWDEFAULT);
    UpdateWindow(window);

    HDC device=GetWindowDC(window);
    PIXELFORMATDESCRIPTOR format_struct = 
    {
        .nSize = sizeof(PIXELFORMATDESCRIPTOR),
        .nVersion = 1,
        .dwFlags = PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL,
        .iPixelType = PFD_TYPE_RGBA,
        .cColorBits = 24,
        .cRedBits = 0, .cRedShift = 0,
        .cGreenBits = 0, .cGreenShift = 0,
        .cBlueBits = 0, .cBlueShift = 0,
        .cAlphaBits = 0, .cAlphaShift = 0,
        .cAccumBits = 0,
        .cAccumRedBits = 0, .cAccumGreenBits = 0, .cAccumBlueBits = 0, .cAccumAlphaBits = 0,
        .cDepthBits = 0, .cStencilBits = 0,
        .cAuxBuffers = 0,
        .iLayerType = PFD_MAIN_PLANE,
        .bReserved = 0,
        .dwLayerMask = 0, .dwVisibleMask = 0, .dwDamageMask = 0

    };

    int formatindex=ChoosePixelFormat(device,&format_struct);
    if (formatindex!=0){

        SetPixelFormat(device,formatindex,&format_struct);
        DescribePixelFormat(device,formatindex,format_struct.nSize,&format_struct);
        opengl=wglCreateContext(device);
        wglMakeCurrent(device,opengl);
        gladLoadGL();
        printf("openglversion=%s\n",glGetString(GL_VERSION));
        printf("shadingversion=%s\n",glGetString(GL_SHADING_LANGUAGE_VERSION));

        MSG message;
        glClearColor(0.0f,0.0f,0.0f,0.0f);
        while(GetMessage(&message,window,0,0)>0)
        {
        DispatchMessage(&message);//отсылает сообщение в window_procedure
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        glVertex2f(-1.0f,-1.0f);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex2f(-0.0f,+1.0f);
        glColor3f(0.0f,1.0f,0.0f);
        glVertex2f(+1.0f,-1.0f);
        glColor3f(0.0f,0.0f,1.f);
        
        glEnd();
        SwapBuffers(device);
        }
        
    }
    DestroyWindow(window);
    UnregisterClass(cls.lpszClassName,cls.hInstance);
}
//(В window_procedure)Первый аргумент это id нашего окна, второй аргумент это сообщение которое отослали, данные про сообщения
LRESULT window_procedure(HWND windowhandle,UINT messageid,WPARAM wparam,LPARAM lparam)
{
    switch(messageid)
    {
    case WM_DESTROY: // когда нажат красный крест
    printf("terso%c",'\n');
    PostQuitMessage(0); // отправить сообщение для выхода - GetMessage вернет 0
    break;
    case WM_SIZE:
        {
            if(opengl!=NULL)
            glViewport(0,0,LOWORD(lparam),HIWORD(lparam));
        }
    break;
    case WM_KEYDOWN:
    if(wparam==VK_ESCAPE){

    PostQuitMessage(0);
    }
    break;
    default:return DefWindowProc(windowhandle, messageid, wparam, lparam);
    }
}  