#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

void ShowMessage(const char* message) {
    MessageBoxA(NULL, message, "Notification", MB_OK | MB_ICONINFORMATION);
}

int main() {
    ShowMessage("Press OK to execute the 'Hosts_Update.cmd' script.");

    char exePath[MAX_PATH];
    GetModuleFileNameA(NULL, exePath, MAX_PATH);

    string exeDir = string(exePath);
    exeDir = exeDir.substr(0, exeDir.find_last_of("\\/"));

    string cmdScriptPath = exeDir + "\\Hosts_Update.cmd";
    string commandLine = "cmd.exe /C start \"\" \"" + cmdScriptPath + "\"";

    PROCESS_INFORMATION processInfo;
    STARTUPINFO startupInfo;
    ZeroMemory(&processInfo, sizeof(processInfo));
    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);

    if (!CreateProcess(NULL, const_cast<char*>(commandLine.c_str()), NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &processInfo)) {
        ShowMessage("Failed to execute.");
        return 1;
    }

    WaitForSingleObject(processInfo.hProcess, INFINITE);
    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);

    ShowMessage("Press OK once done.");

    return 0;
}