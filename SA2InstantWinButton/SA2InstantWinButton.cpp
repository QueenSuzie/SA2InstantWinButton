// SA2InstantWinButton.cpp : Defines the exported functions for the DLL application.
//

#include "pch.h"
#include "..\sa2-mod-loader\SA2ModLoader\include\SA2ModLoader.h"

extern "C"
{
	__declspec(dllexport) void OnFrame()
	{
		if (GameState == GameStates_Ingame && (ControllerPointers[0]->press & Buttons_X))
		{
			if (ControllerPointers[0]->press & Buttons_B)
				AwardWin(1);
			else
				AwardWin(0);
		}
	}

	__declspec(dllexport) ModInfo SA2ModInfo { ModLoaderVer };
}