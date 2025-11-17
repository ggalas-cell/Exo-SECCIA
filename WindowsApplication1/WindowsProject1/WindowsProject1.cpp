// WindowsProject1.cpp : Définit le point d'entrée de l'application.
//
#include <map>
#include <iostream>
#include "framework.h"
#include "WindowsProject1.h"

#define MAX_LOADSTRING 100

// Variables globales :
HINSTANCE hInst;                                // instance actuelle
WCHAR szTitle[MAX_LOADSTRING];                  // Texte de la barre de titre
WCHAR szWindowClass[MAX_LOADSTRING];            // nom de la classe de fenêtre principale

// Déclarations anticipées des fonctions incluses dans ce module de code :
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
std::map<int, HWND>ctrls;
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Placez le code ici.

    // Initialise les chaînes globales
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Effectue l'initialisation de l'application :
    if (!InitInstance (hInstance, nCmdShow))
    {
        hInst = hInstance;
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

    // Boucle de messages principale :
    while (GetMessage(&msg, nullptr, 0, 0))
    {   
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}



//
//  FONCTION : MyRegisterClass()
//
//  OBJECTIF : Inscrit la classe de fenêtre.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = L"yes";                                   //nom de clsse
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FONCTION : InitInstance(HINSTANCE, int)
//
//   OBJECTIF : enregistre le handle d'instance et crée une fenêtre principale
//
//   COMMENTAIRES :
//
//        Dans cette fonction, nous enregistrons le handle de l'instance dans une variable globale, puis
//        nous créons et affichons la fenêtre principale du programme.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Stocke le handle d'instance dans la variable globale
  
   
   HWND hWnd = CreateWindowW(L"yes", L"Test", WS_OVERLAPPEDWINDOW,         //szTitle = titre de fenetre
       CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   
   
   //HWND button = CreateWindowW(L"Button", L"Enter", WS_VISIBLE|WS_CHILD,       
   //    300, 300, 100, 80, hWnd, nullptr, hInstance, nullptr);
   //HWND text = CreateWindowW(L"Edit", L"SELECTIONNER UNE ENTRER", WS_VISIBLE | WS_CHILD|BS_DEFPUSHBUTTON,   //creation button visible pour showwindow et updatewindow et child pour dire que c'est l'enfant de la fenetre
   //    100, 0, 100, 80, hWnd, (HMENU)100, hInstance, nullptr);
   //ctrls.insert(std::make_pair(100, button));
   //HWND hwndButton = CreateWindow(
   //    L"BUTTON",  // Predefined class; Unicode assumed 
   //    L"OK",      // Button text 
   //    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
   //    10,         // x position 
   //    10,         // y position 
   //    100,        // Button width
   //    100,        // Button height
   //    m_hwnd,     // Parent window
   //    NULL,       // No menu.
   //    (HINSTANCE)GetWindowLongPtr(m_hwnd, GWLP_HINSTANCE),
   //    NULL);      // Pointer not needed.

   //BM_GETSTATE(0, 0);
   
   /*if (button_handle != NULL)
   {
       button_state = SendMessage(button_handle,
           BM_GETSTATE,
           0, 0);*/
   //if (!button)return FALSE;

   if (!hWnd)
   {
      return FALSE;
   }
   //if()

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FONCTION : WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  OBJECTIF : Traite les messages pour la fenêtre principale.
//
//  WM_COMMAND  - traite le menu de l'application
//  WM_PAINT    - Dessine la fenêtre principale
//  WM_DESTROY  - génère un message d'arrêt et retourne

   
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Analyse les sélections de menu :
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            //tagBITMAPINFO();
            FILE* file;
            errno_t error = fopen_s(&file, "C:\\Users\\ggalas\\Documents\\GitHub\\Exo-SECCIA\\wolf 1.bmp", "rb");;
            if (!file)break;
            
            BYTE* buf = new BYTE[50000000];	// (source)	//lecture du file -> buffer 
            size_t size = fread(buf, 1, 50000000, file);		//idem
            fclose(file);
            
            BITMAPFILEHEADER head = {};	//destination
            BITMAPINFOHEADER bih = {};
            
            memcpy(&head, buf, sizeof(BITMAPFILEHEADER));
            memcpy(&bih, buf + sizeof(BITMAPFILEHEADER), sizeof(BITMAPINFOHEADER));

            fread(&head, sizeof(head), 1, file);
            fread(&bih, sizeof(bih), 1, file);
            

            if (head.bfType != 0x4D42)
            {
                std::cout << "Ce n'est pas un fichier BMP.\n";
                return -1;
            }
            fseek(file, head.bfOffBits, SEEK_SET);  
            unsigned char* pixels = (unsigned char*)malloc(bih.biSizeImage);
            fclose(file);
            for (int i = 0; i < bih.biSizeImage; i += 3) 
            {
                unsigned char b = pixels[i];                    //modif pixels
                unsigned char g = pixels[i + 1];
                unsigned char r = pixels[i + 2];

                pixels[i] = 255 - b;
                pixels[i + 1] = 255 - g;
                pixels[i + 2] = 255 - r;
            }
            FILE* f2 = fopen("output.bmp", "wb");

            // Écriture des en-têtes
            fwrite(&head, sizeof(head), 1, f2);
            fwrite(&bih, sizeof(bih), 1, f2);

            // Écriture des pixels
            fwrite(pixels, 1, bih.biSizeImage, f2);

            fclose(f2);
            free(pixels);


            int bitwidth = bih.biWidth;
            int bitheight = bih.biHeight;
            
            BYTE* src = buf + head.bfOffBits;
            BITMAPINFO bi = {};
            bi.bmiHeader = bih;
            PAINTSTRUCT ps;
            HWND hd ;
            HDC hdc = BeginPaint(hWnd, &ps); 
            HDC hdcmem = CreateCompatibleDC(hdc);
            HBITMAP bm = CreateDIBitmap(hdc, &bih, CBM_INIT, src, &bi, DIB_RGB_COLORS);
            SelectObject(hdcmem, bm); //mettre dans hdcmem
            //SetScrollRange(,)         a faire 
           //for (int i = 0; i < 250; i++)
           //{
           //    for (int k = 0; k < 250; k++)
           //    {
           //        SetPixel(hdc, i, k, RGB(i, k, i));
           //    }
           //}
            
            //SetPixel(hdc,50,50)  WM_TIMER
            //Rectangle(hdc, 550, 1000, 50, 100); //(x,y,x,y)
            //Rectangle(hdc, 350, 100, 550, 300);
            //LineTo(hdc,100,500);
            BitBlt(hdc, 50, 50, bih.biWidth,bih.biHeight,hdcmem,0,0,SRCCOPY);       //afficher img avec coordonner haut gauche bas droit
            int SetScrollInfo();    
            DeleteDC(hdcmem);
            DeleteObject(bm);
            delete[] buf;
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Gestionnaire de messages pour la boîte de dialogue À propos de.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {

            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    case 100 :
        
        break;
    }
    return (INT_PTR)FALSE;
}
