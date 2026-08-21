#include <windows.h>

static FARPROC xinput1_4_ordinal(WORD ordinal) {
  static HMODULE module;
  if (!module)
    module = LoadLibraryW(L"XINPUT1_4.dll");
  return module ? GetProcAddress(module, (LPCSTR)(ULONG_PTR)ordinal) : NULL;
}

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
  (void)instance;
  (void)reason;
  (void)reserved;
  return TRUE;
}

void WINAPI XInputEnable(BOOL enable) {
  (void)enable;
}

DWORD WINAPI XInputGetBatteryInformation(DWORD user_index, BYTE device_type, void *battery_information) {
  (void)user_index;
  (void)device_type;
  (void)battery_information;
  return ERROR_NOT_SUPPORTED;
}

DWORD WINAPI XInputGetKeystroke(DWORD user_index, DWORD reserved, void *keystroke) {
  (void)user_index;
  (void)reserved;
  (void)keystroke;
  return ERROR_NOT_SUPPORTED;
}

DWORD WINAPI XInputGetStateEx(DWORD user_index, void *state) {
  typedef DWORD(WINAPI *Function)(DWORD, void *);
  Function function = (Function)xinput1_4_ordinal(100);
  return function ? function(user_index, state) : ERROR_NOT_SUPPORTED;
}

DWORD WINAPI XInputWaitForGuideButton(DWORD user_index, DWORD flags, void *reserved) {
  typedef DWORD(WINAPI *Function)(DWORD, DWORD, void *);
  Function function = (Function)xinput1_4_ordinal(101);
  return function ? function(user_index, flags, reserved) : ERROR_NOT_SUPPORTED;
}

DWORD WINAPI XInputCancelGuideButtonWait(DWORD user_index) {
  typedef DWORD(WINAPI *Function)(DWORD);
  Function function = (Function)xinput1_4_ordinal(102);
  return function ? function(user_index) : ERROR_NOT_SUPPORTED;
}

DWORD WINAPI XInputPowerOffController(DWORD user_index) {
  typedef DWORD(WINAPI *Function)(DWORD);
  Function function = (Function)xinput1_4_ordinal(103);
  return function ? function(user_index) : ERROR_NOT_SUPPORTED;
}
