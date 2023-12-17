#include "StdAfx.h"
#include <windows.h>
#include<stdlib.h>
#include <iostream>   
#include<string.h>
using namespace std; 
/*
1 HANDLE���������ľ����
2 HINSTANCE��Ӧ�ó���ʵ�������MSDN�������HINSTANCE�Ľ�����"handle to an instance" ����˵��һ��instance�ľ��
3 HWND�Ǵ��ڶ�������
	����HWND�Ľ����ǡ�Handle to a window.������window�Ľ�����"In a graphical 
	Windows-based application, a window is a rectangular area of the screen where 
	the application displays output and receives input from the user. Therefore, 
	one of the first tasks of a graphical Windows-based application is to create a 
	window. " ����˵����Ļ�ϵ�һ������

CWnd��MFC�еĴ����ࡣ
	CWnd��MFC��һ�����ˣ����д��壬����������ͼ����ʾ���඼�Ǵ��������ģ����Լ��Ǵ�
	CCmdTarget�������ģ����������Խ�����Ϣ��CCmdTarget��İְֿɾ���CObject�ˡ�
	msdn����Handle�Ľ�����"Handle to an object." ,��ֱ�Ƿϻ����Լ���ô�����Լ��ء�
	 
ID--HANDLE--HWND����֮��Ļ���ת��
	id->���-----------hWnd = ::GetDlgItem(hParentWnd,id);
	id->ָ��-----------CWnd::GetDlgItem();
	���->id-----------id = GetWindowLong(hWnd,GWL_ID);
	���->ָ��--------CWnd *pWnd=CWnd::FromHandle(hWnd);
	ָ��->ID----------id = GetWindowLong(pWnd->GetSafeHwnd,GWL_ID);
	GetDlgCtrlID();
	ָ��->���--------hWnd=cWnd.GetSafeHandle() or mywnd->m_hWnd;
 


Ӧ�ó����һЩHANDLE 
	// �õ����ھ��
	HWND parenthwnd = ::FindWindowEx(NULL, parenthwnd, "#32770", NULL);
	// �õ��˴��ڵ����߳�ID
	DWORD dwThreadId = ::GetWindowThreadProcessId(parenthwnd, 0);
	// �õ���ǰ���̵ľ��
	HANDLE hApp = GetModuleHandle(NULL);
*/
//�Ի���
//int WINAPI WinMain(
//    HINSTANCE hInstance,
//    HINSTANCE hPrevInstance,
//    LPSTR lpCmdLine,
//    int nCmdShow
//)
//{
//    // ����API ����MessageBox
//    int nSelect = MessageBox(NULL, TEXT("��ã���ӭ����C������������"), TEXT("Welcome"), MB_OKCANCEL);
//    if(nSelect == IDOK){
//        MessageBox(NULL, TEXT("�����ˡ�ȷ������ť"), TEXT("��ʾ"), MB_OK);
//    }else{
//        MessageBox(NULL, TEXT("�����ˡ�ȡ������ť"), TEXT("��ʾ"), MB_OK);
//    }
//    return 0;
//}

 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(  HINSTANCE hInstance,  HINSTANCE hPrevInstance, PSTR szCmdLine,   int iCmdShow
){
    static TCHAR szClassName[] = TEXT("HelloWin");  //��������
    HWND     hwnd;  //���ھ��
    MSG      msg ;  //��Ϣ
    WNDCLASS wndclass;  //������
    /**********�ڢٲ���ע�ᴰ����**********/
    //Ϊ������ĸ����ֶθ�ֵ
    wndclass.style = CS_HREDRAW | CS_VREDRAW;  //���ڷ��
    wndclass.lpfnWndProc  = WndProc;  //���ڹ���
    wndclass.cbClsExtra   = 0;  //��ʱ����Ҫ���
    wndclass.cbWndExtra   = 0;  //��ʱ����Ҫ���
    wndclass.hInstance    = hInstance;  //��ǰ���ھ��
    wndclass.hIcon        = LoadIcon (NULL, IDI_APPLICATION);  //����ͼ��
    wndclass.hCursor      = LoadCursor (NULL, IDC_ARROW);  //�����ʽ
    wndclass.hbrBackground= (HBRUSH) GetStockObject (WHITE_BRUSH);  //���ڱ�����ˢ
    wndclass.lpszMenuName = NULL ;  //���ڲ˵�
    wndclass.lpszClassName= szClassName;  //��������
    //ע�ᴰ��
    RegisterClass(&wndclass);
    /*****�ڢڲ�����������(���ô�����ʾ����)*****/
    hwnd = CreateWindow(
        szClassName,  //�����������
        TEXT("Welcome"),  //���ڱ��⣨�����ڱ�������
        WS_OVERLAPPEDWINDOW,  //���ڷ��
        CW_USEDEFAULT,  //��ʼ��ʱx���λ��
        CW_USEDEFAULT,  //��ʼ��ʱy���λ��
        500,  //���ڿ��
        300,  //���ڸ߶�
        NULL,  //�����ھ��
        NULL,  //���ڲ˵����
        hInstance,  //��ǰ���ڵľ��
        NULL  //��ʹ�ø�ֵ
    );
    //��ʾ����
    ShowWindow (hwnd, iCmdShow);
    //���£����ƣ�����
    UpdateWindow (hwnd);
    /**********�ڢ۲�����Ϣѭ��**********/
    while( GetMessage(&msg, NULL, 0, 0) ){
        TranslateMessage(&msg);  //������Ϣ
        DispatchMessage (&msg);  //������Ϣ
    }
	//msg.wParam=0;
    return msg.wParam;
}

/**********�ڢܲ������ڹ���**********/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
    HDC         hdc;  //�豸�������
    PAINTSTRUCT ps;
    RECT        rect;

	//if ( message != 0 )
	//{
	//	if( message == WM_PAINT) 
	//	{
	//		unsigned int m = message;
	//		wchar_t chr[255];
	//		_itow_s( m, chr, 10, 10);
	//		hdc = BeginPaint (hwnd, &ps) ;
	//		GetClientRect (hwnd, &rect) ;
	//		DrawText(  hdc,  chr, -1, &rect,  DT_SINGLELINE | DT_CENTER | DT_VCENTER );
	//		
	//	}//���£����ƣ�����
	//		UpdateWindow (hwnd);
	//}

    switch (message){
        //���ڻ�����Ϣ
        case WM_PAINT:
            hdc = BeginPaint (hwnd, &ps) ;
            GetClientRect (hwnd, &rect) ;
     //       DrawText(  hdc,  TEXT("Hellow Device. Draw"), -1, &rect,  DT_SINGLELINE | DT_CENTER | DT_VCENTER );
			int i,r,g,b;
				i=1,r=1;g=1;b=1;
	/*	 do  
		 {*/
			SetPixel(hdc, i,1, RGB(r,g,b));
			SetPixel(hdc, i,2, RGB(r,g,b));
			SetPixel(hdc, i,3, RGB(r,g,b));
			SetPixel(hdc, i,4, RGB(r,g,b));

			SetPixel(hdc, i,5, RGB(r,g,b));
			SetPixel(hdc, i,6, RGB(r,g,b));
			SetPixel(hdc, i,7, RGB(r,g,b));
			SetPixel(hdc, i,8, RGB(r,g,b));

			SetPixel(hdc, 20,1, RGB(100,100,100));
			SetPixel(hdc, 20,2, RGB(100,100,100));
			SetPixel(hdc, 20,3, RGB(100,100,100));
			SetPixel(hdc, 20,4, RGB(100,100,100));
			SetPixel(hdc, 20,5, RGB(100,100,100));
			SetPixel(hdc, 20,6, RGB(100,100,100));
			SetPixel(hdc, 20,7, RGB(100,100,100));
			SetPixel(hdc, 20,8, RGB(100,100,100));

			SetPixel(hdc, 30,1, RGB(80,90,11));
			SetPixel(hdc, 30,2, RGB(80,90,11));
			SetPixel(hdc, 30,3, RGB(80,90,11));
			SetPixel(hdc, 30,4, RGB(80,90,11));
			SetPixel(hdc, 30,5, RGB(80,90,11));
			SetPixel(hdc, 30,6, RGB(80,90,11));
			SetPixel(hdc, 30,7, RGB(80,90,11));
			SetPixel(hdc, 30,8, RGB(80,90,11));
									 
			SetPixel(hdc, 40,1, RGB(10,22,33));
			SetPixel(hdc, 40,2, RGB(10,22,33));
			SetPixel(hdc, 40,3, RGB(10,22,33));
			SetPixel(hdc, 40,4, RGB(10,22,33));
			SetPixel(hdc, 40,5, RGB(10,22,33));
			SetPixel(hdc, 40,6, RGB(10,22,33));
			SetPixel(hdc, 40,7, RGB(10,22,33));
			SetPixel(hdc, 40,8, RGB(10,22,33));

			//SetPixel(hdc, 11,10, RGB(5,5,50));
			//SetPixel(hdc, 10,11, RGB(255,0,0));
			//SetPixel(hdc, 11,11, RGB(5,50,50));

		//	wstring wst;
			 
			r++;g++;b++;
			i++;
		 //}
		 //while(i<rect.right);
   //         EndPaint (hwnd, &ps);
            return 0 ;
        //����������Ϣ
        case WM_DESTROY:
            PostQuitMessage(0) ;
            return 0 ;
    }
    return DefWindowProc(hwnd, message, wParam, lParam) ;
}