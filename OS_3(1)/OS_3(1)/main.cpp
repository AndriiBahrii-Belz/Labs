#include <Windows.h>
#include <iostream>
#include <string>
#include <tchar.h>

#define ID_OK 1001
#define IDC_EDIT_DAY 1002
#define IDC_EDIT_MONTH 1003
#define IDT_TIMER 1 // ID таймера

// Global variables
HWND hStaticHour, hStaticMinute, hStaticSecond;
HWND hEditHour, hEditMinute, hEditSecond;
HWND hButtonStart, hButtonStop, hButtonReset, hButtonChangeDate;
HANDLE hThread;
DWORD dwThreadId;
bool isRunning = false;
int targetHours = 0, targetMinutes = 0, targetSeconds = 0;
int initialHours = 0, initialMinutes = 0, initialSeconds = 0;

// Function prototypes
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
DWORD WINAPI TimerThread(LPVOID lpParam);
void OpenChangeDateWindow(HWND hwndParent);
LRESULT CALLBACK ChangeDateWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Pointer to the change date window
HWND hwndChangeDate = NULL;

// Main function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Register window class
    const TCHAR* CLASS_NAME = TEXT("TimerApp");
    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create window
    HWND hwnd = CreateWindowEx(0, CLASS_NAME, TEXT("Таймер"), WS_OVERLAPPEDWINDOW | WS_THICKFRAME | WS_MAXIMIZEBOX | WS_MINIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, 500, 300, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        return 0;
    }

    // Static elements for displaying hours, minutes, and seconds
    hStaticHour = CreateWindowEx(0, TEXT("STATIC"), TEXT("Години"), WS_CHILD | WS_VISIBLE, 20, 20, 80, 20, hwnd, NULL, hInstance, NULL);
    hStaticMinute = CreateWindowEx(0, TEXT("STATIC"), TEXT("Хвилини"), WS_CHILD | WS_VISIBLE, 120, 20, 80, 20, hwnd, NULL, hInstance, NULL);
    hStaticSecond = CreateWindowEx(0, TEXT("STATIC"), TEXT("Секунди"), WS_CHILD | WS_VISIBLE, 220, 20, 80, 20, hwnd, NULL, hInstance, NULL);

    // Input fields for hours, minutes, and seconds
    hEditHour = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""), WS_CHILD | WS_VISIBLE | ES_NUMBER | WS_BORDER, 20, 40, 80, 25, hwnd, NULL, hInstance, NULL);
    hEditMinute = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""), WS_CHILD | WS_VISIBLE | ES_NUMBER | WS_BORDER, 120, 40, 80, 25, hwnd, NULL, hInstance, NULL);
    hEditSecond = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""), WS_CHILD | WS_VISIBLE | ES_NUMBER | WS_BORDER, 220, 40, 80, 25, hwnd, NULL, hInstance, NULL);

    // Timer control buttons
    hButtonStart = CreateWindowEx(0, TEXT("BUTTON"), TEXT("Start"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 20, 80, 80, 30, hwnd, NULL, hInstance, NULL);
    hButtonStop = CreateWindowEx(0, TEXT("BUTTON"), TEXT("Stop"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 120, 80, 80, 30, hwnd, NULL, hInstance, NULL);
    hButtonReset = CreateWindowEx(0, TEXT("BUTTON"), TEXT("Reset"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 220, 80, 80, 30, hwnd, NULL, hInstance, NULL);
    hButtonChangeDate = CreateWindowEx(0, TEXT("BUTTON"), TEXT("Зміна системної дати"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 320 + 10, 80 + 10, 150, 30, hwnd, NULL, GetModuleHandle(NULL), NULL);

    // Add borders to input fields
    SendMessage(hEditHour, EM_SETLIMITTEXT, 2, 0);
    SendMessage(hEditMinute, EM_SETLIMITTEXT, 2, 0);
    SendMessage(hEditSecond, EM_SETLIMITTEXT, 2, 0);

    // Show window
    ShowWindow(hwnd, nCmdShow);

    // Set timer to update time and date
    SetTimer(hwnd, IDT_TIMER, 1000, NULL); // Timer to update every second

    // Message loop
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

// Function for the change date window
void OpenChangeDateWindow(HWND hwndParent) {
    // If the window is already open, bring it to the front
    if (hwndChangeDate != NULL) {
        SetForegroundWindow(hwndChangeDate);
        return;
    }

    // Register window class for change date window
    const TCHAR* CHANGE_DATE_CLASS_NAME = TEXT("ChangeDateWindow");
    WNDCLASS wc = {};
    wc.lpfnWndProc = ChangeDateWindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = CHANGE_DATE_CLASS_NAME;
    RegisterClass(&wc);

    // Create change date window
    hwndChangeDate = CreateWindowEx(0, CHANGE_DATE_CLASS_NAME, TEXT("Зміна системної дати"), WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, hwndParent, NULL, GetModuleHandle(NULL), NULL);

    if (hwndChangeDate == NULL) {
        MessageBox(hwndParent, TEXT("Помилка при створенні вікна зміни системної дати."), TEXT("Помилка"), MB_OK | MB_ICONERROR);
        return;
    }

    // Create elements in the change date window (labels, text fields, buttons)

    // Labels for hours, minutes, and seconds
    CreateWindowEx(0, TEXT("STATIC"), TEXT("Година:"), WS_CHILD | WS_VISIBLE, 20, 20, 60, 20, hwndChangeDate, NULL, GetModuleHandle(NULL), NULL);
    CreateWindowEx(0, TEXT("STATIC"), TEXT("Хвилина:"), WS_CHILD | WS_VISIBLE, 20, 50, 60, 20, hwndChangeDate, NULL, GetModuleHandle(NULL), NULL);
    CreateWindowEx(0, TEXT("STATIC"), TEXT("Секунда:"), WS_CHILD | WS_VISIBLE, 20, 80, 60, 20, hwndChangeDate, NULL, GetModuleHandle(NULL), NULL);

    // Labels for day, month, and year
    CreateWindowEx(0, TEXT("STATIC"), TEXT("День:"), WS_CHILD | WS_VISIBLE, 20, 120, 60, 20, hwndChangeDate, NULL, GetModuleHandle(NULL), NULL);
    CreateWindowEx(0, TEXT("STATIC"), TEXT("Місяць:"), WS_CHILD | WS_VISIBLE, 20, 150, 60, 20, hwndChangeDate, NULL, GetModuleHandle(NULL), NULL);
    CreateWindowEx(0, TEXT("STATIC"), TEXT("Рік:"), WS_CHILD | WS_VISIBLE, 20, 180, 60, 20, hwndChangeDate, NULL, GetModuleHandle(NULL), NULL);

    // Text fields for entering hours, minutes, and seconds
    HWND hEditHour = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""), WS_CHILD | WS_VISIBLE | ES_NUMBER | WS_BORDER, 90, 20, 50, 25, hwndChangeDate, NULL, GetModuleHandle(NULL), NULL);
    HWND hEditMinute = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""), WS_CHILD | WS_VISIBLE | ES_NUMBER | WS_BORDER, 90, 50, 50, 25, hwndChangeDate, NULL, GetModuleHandle(NULL), NULL);
    HWND hEditSecond = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""), WS_CHILD | WS_VISIBLE | ES_NUMBER | WS_BORDER, 90, 80, 50, 25, hwndChangeDate, NULL, GetModuleHandle(NULL), NULL);

    // Comboboxes for day, month, and year
    HWND hComboDay = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("COMBOBOX"), TEXT(""), WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS, 90, 120, 50, 100, hwndChangeDate, NULL, GetModuleHandle(NULL), NULL);
    HWND hComboMonth = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("COMBOBOX"), TEXT(""), WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS, 90, 150, 100, 100, hwndChangeDate, NULL, GetModuleHandle(NULL), NULL);
    HWND hComboYear = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("COMBOBOX"), TEXT(""), WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS, 90, 180, 80, 100, hwndChangeDate, NULL, GetModuleHandle(NULL), NULL);

    // Fill comboboxes with values
    for (int i = 1; i <= 31; ++i) {
        TCHAR szDay[3];
        _stprintf_s(szDay, _T("%02d"), i);
        SendMessage(hComboDay, CB_ADDSTRING, 0, (LPARAM)szDay);
    }
    for (int i = 1; i <= 12; ++i) {
        TCHAR szMonth[3];
        _stprintf_s(szMonth, _T("%02d"), i);
        SendMessage(hComboMonth, CB_ADDSTRING, 0, (LPARAM)szMonth);
    }
    for (int i = 2022; i <= 2030; ++i) {
        TCHAR szYear[5];
        _stprintf_s(szYear, _T("%d"), i);
        SendMessage(hComboYear, CB_ADDSTRING, 0, (LPARAM)szYear);
    }

    // Set initial selection in comboboxes to current date
    SYSTEMTIME st;
    GetLocalTime(&st);
    SendMessage(hComboDay, CB_SETCURSEL, st.wDay - 1, 0);
    SendMessage(hComboMonth, CB_SETCURSEL, st.wMonth - 1, 0);
    for (int i = 0; i < SendMessage(hComboYear, CB_GETCOUNT, 0, 0); i++) {
        TCHAR szYear[5];
        SendMessage(hComboYear, CB_GETLBTEXT, i, (LPARAM)szYear);
        if (_ttoi(szYear) == st.wYear) {
            SendMessage(hComboYear, CB_SETCURSEL, i, 0);
            break;
        }
    }

    // Set handles to text fields and combo boxes as window properties
    SetProp(hwndChangeDate, TEXT("EditHour"), (HANDLE)hEditHour);
    SetProp(hwndChangeDate, TEXT("EditMinute"), (HANDLE)hEditMinute);
    SetProp(hwndChangeDate, TEXT("EditSecond"), (HANDLE)hEditSecond);
    SetProp(hwndChangeDate, TEXT("ComboDay"), (HANDLE)hComboDay);
    SetProp(hwndChangeDate, TEXT("ComboMonth"), (HANDLE)hComboMonth);
    SetProp(hwndChangeDate, TEXT("ComboYear"), (HANDLE)hComboYear);

    // OK button to confirm the change of system date
    CreateWindowEx(0, TEXT("BUTTON"), TEXT("OK"), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 20, 220, 80, 30, hwndChangeDate, (HMENU)ID_OK, GetModuleHandle(NULL), NULL);
}

// Message handler for the change date window
LRESULT CALLBACK ChangeDateWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case ID_OK:
            // Retrieve handles to text fields and combo boxes
            HWND hEditHour = (HWND)GetProp(hwnd, TEXT("EditHour"));
            HWND hEditMinute = (HWND)GetProp(hwnd, TEXT("EditMinute"));
            HWND hEditSecond = (HWND)GetProp(hwnd, TEXT("EditSecond"));
            HWND hComboDay = (HWND)GetProp(hwnd, TEXT("ComboDay"));
            HWND hComboMonth = (HWND)GetProp(hwnd, TEXT("ComboMonth"));
            HWND hComboYear = (HWND)GetProp(hwnd, TEXT("ComboYear"));

            // Get the entered values for hours, minutes, and seconds
            TCHAR szHour[4], szMinute[4], szSecond[4];
            GetWindowText(hEditHour, szHour, 4);
            GetWindowText(hEditMinute, szMinute, 4);
            GetWindowText(hEditSecond, szSecond, 4);

            int newHours = _ttoi(szHour);
            int newMinutes = _ttoi(szMinute);
            int newSeconds = _ttoi(szSecond);

            // Get selected day, month, and year
            int selectedDay = SendMessage(hComboDay, CB_GETCURSEL, 0, 0) + 1;
            int selectedMonth = SendMessage(hComboMonth, CB_GETCURSEL, 0, 0) + 1;
            TCHAR szYear[5];
            SendMessage(hComboYear, CB_GETLBTEXT, SendMessage(hComboYear, CB_GETCURSEL, 0, 0), (LPARAM)szYear);
            int selectedYear = _ttoi(szYear);

            // Validate input values
            if (newHours < 0 || newHours > 23 || newMinutes < 0 || newMinutes > 59 || newSeconds < 0 || newSeconds > 59 ||
                selectedDay < 1 || selectedDay > 31 || selectedMonth < 1 || selectedMonth > 12 || selectedYear < 2022 || selectedYear > 2030) {
                MessageBox(hwnd, TEXT("Невірні введені значення. Будь ласка, перевірте і введіть коректні значення."), TEXT("Помилка"), MB_OK | MB_ICONERROR);
                return 0;
            }

            // Get current system time
            SYSTEMTIME st;
            GetLocalTime(&st);

            // Update system time with the entered values
            st.wHour = newHours;
            st.wMinute = newMinutes;
            st.wSecond = newSeconds;
            st.wDay = selectedDay;
            st.wMonth = selectedMonth;
            st.wYear = selectedYear;

            // Set new system time
            BOOL bSuccess = SetLocalTime(&st);

            if (!bSuccess) {
                DWORD dwError = GetLastError();
                TCHAR szErrorMessage[256];
                FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, dwError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), szErrorMessage, 256, NULL);
                MessageBox(hwnd, szErrorMessage, TEXT("Помилка при встановленні системної дати."), MB_OK | MB_ICONERROR);
            }
            else {
                MessageBox(hwnd, TEXT("Системну дату успішно змінено."), TEXT("Успішно"), MB_OK | MB_ICONINFORMATION);
                // Close the change date window after successful change
                DestroyWindow(hwnd);
                hwndChangeDate = NULL; // Set the pointer to the change date window to NULL, as it no longer exists
            }
            break;
        }
        break;
    case WM_CLOSE:
        // Handle window close
        DestroyWindow(hwnd);
        hwndChangeDate = NULL;
        break;
    case WM_DESTROY:
        // Handle window destruction
        RemoveProp(hwnd, TEXT("EditHour"));
        RemoveProp(hwnd, TEXT("EditMinute"));
        RemoveProp(hwnd, TEXT("EditSecond"));
        RemoveProp(hwnd, TEXT("ComboDay"));
        RemoveProp(hwnd, TEXT("ComboMonth"));
        RemoveProp(hwnd, TEXT("ComboYear"));
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

// Message handler for the main window
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_COMMAND:
        if (lParam == (LPARAM)hButtonStart) {
            if (!isRunning) {
                isRunning = true;
                // Get the user-entered time
                TCHAR szHour[4], szMinute[4], szSecond[4];
                GetWindowText(hEditHour, szHour, 4);
                GetWindowText(hEditMinute, szMinute, 4);
                GetWindowText(hEditSecond, szSecond, 4);
                targetHours = _ttoi(szHour);
                targetMinutes = _ttoi(szMinute);
                targetSeconds = _ttoi(szSecond);
                // Save the initial time
                initialHours = targetHours;
                initialMinutes = targetMinutes;
                initialSeconds = targetSeconds;

                hThread = CreateThread(NULL, 0, TimerThread, NULL, 0, &dwThreadId);
            }
        }
        else if (lParam == (LPARAM)hButtonStop) {
            isRunning = false;
            // Send a message to the thread to terminate
            PostThreadMessage(dwThreadId, WM_QUIT, 0, 0);
        }
        else if (lParam == (LPARAM)hButtonReset) {
            // Reset to the initial time
            targetHours = initialHours;
            targetMinutes = initialMinutes;
            targetSeconds = initialSeconds;

            // Update input fields
            SetWindowText(hEditHour, std::to_wstring(targetHours).c_str());
            SetWindowText(hEditMinute, std::to_wstring(targetMinutes).c_str());
            SetWindowText(hEditSecond, std::to_wstring(targetSeconds).c_str());
        }
        else if (lParam == (LPARAM)hButtonChangeDate) {
            OpenChangeDateWindow(hwnd);
        }
        break;
    case WM_SIZE: {
        RECT rect;
        GetClientRect(hwnd, &rect); // Отримати розміри клієнтської області вікна

        int buttonWidth = 150; // Ширина кнопки
        int buttonHeight = 30; // Висота кнопки

        // Перемістити кнопку "Зміна системної дати" в нижній лівий кут вікна
        SetWindowPos(hButtonChangeDate, NULL, 325, rect.bottom - buttonHeight - 10, buttonWidth, buttonHeight, SWP_NOSIZE);
        break;
    }
    case WM_TIMER:
        switch (wParam) {
        case IDT_TIMER:
            // Invalidate window to trigger repaint
            InvalidateRect(hwnd, NULL, TRUE);
            break;
        }
        break;
    case WM_DESTROY:
        // Clean up and exit
        PostQuitMessage(0);
        break;
    case WM_PAINT:
    {
        // Paint the window
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        TCHAR szTime[9];
        TCHAR szDate[11];
        SYSTEMTIME st;

        GetLocalTime(&st);

        // Format strings for time and date
        _stprintf_s(szTime, _T("%02d:%02d:%02d"), st.wHour, st.wMinute, st.wSecond);
        _stprintf_s(szDate, _T("%02d/%02d/%d"), st.wDay, st.wMonth, st.wYear);

        // Display time and date in the window
        TextOut(hdc, 20, 180, szTime, lstrlen(szTime)); // Display time
        TextOut(hdc, 20, 210, szDate, lstrlen(szDate)); // Display date

        EndPaint(hwnd, &ps);
    }
    break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

DWORD WINAPI TimerThread(LPVOID lpParam) {
    // Timer thread function (unchanged)
    // This function updates the target time and the input fields every second
    while (isRunning) {
        Sleep(1000);
        if (targetSeconds > 0) {
            targetSeconds--;
        }
        else {
            if (targetMinutes > 0) {
                targetMinutes--;
                targetSeconds = 59;
            }
            else {
                if (targetHours > 0) {
                    targetHours--;
                    targetMinutes = 59;
                    targetSeconds = 59;
                }
                else {
                    isRunning = false;
                }
            }
        }

        // Update input fields
        SetWindowText(hEditHour, std::to_wstring(targetHours).c_str());
        SetWindowText(hEditMinute, std::to_wstring(targetMinutes).c_str());
        SetWindowText(hEditSecond, std::to_wstring(targetSeconds).c_str());
    }

    return 0;
}