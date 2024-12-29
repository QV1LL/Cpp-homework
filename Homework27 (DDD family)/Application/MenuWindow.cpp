#include "MenuWindow.h"
#include <Windows.h>

using namespace Project;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MenuWindow());

    return 0;
}