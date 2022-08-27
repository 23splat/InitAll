// Psuedocode [External]

void init_all()
{
	game_data* gdata = new game_data;

	gdata->WindowName = "Counter Strike Global Offensive";
	gdata->hwnd = FindWindowA(NULL, gdata->WindowName);

	if (gdata->hwnd)
	{
		GetWindowThreadProcessId(gdata->hwnd, &gdata->procId);
		gdata->ModuleBaseAddress = GetModuleBaseAddress((TCHAR*)"client.dll", gdata->procId);

		gdata->hProcessAccess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, gdata->procId);

		if (gdata->ModuleBaseAddress)
			gdata->localPlayer = rpm<DWORD>(gdata->ModuleBaseAddress + local_player_offset, gdata->hProcessAccess);

		if (gdata->localPlayer)
			gdata->EntityList = rpm<DWORD>(gdata->ModuleBaseAddress + entity_list_offset, gdata->hProcessAccess);

		gdata->health = rpm<DWORD>(gdata->ModuleBaseAddress + gdata->localPlayer, gdata->hProcessAccess);

		gdata->Colour = GetStdHandle(STD_OUTPUT_HANDLE);
	}
}
