// SA2InstantWinButton.cpp : Defines the exported functions for the DLL application.
//

#include "pch.h"
#include "..\sa2-mod-loader\SA2ModLoader\include\SA2ModLoader.h"

DataArray(int, PressedButtons, 0x3B0E354, 8);
extern "C"
{
	__declspec(dllexport) void OnFrame()
	{
		switch (GameMode)
		{
		case GameModes_Adventure_ActionStg:
		case GameModes_Adventure_Field:
		case GameModes_Adventure_Story:
		case GameModes_Mission:
		case GameModes_Trial:
			if (ControllerPointers[0]->PressedButtons & Buttons_X)
			{
				if (ControllerPointers[0]->PressedButtons & Buttons_B)
					SetOpponentRaceVictory();
				else
					SetTailsRaceVictory();
				LoadLevelResults();
			}
			break;
		}
	}

	__declspec(dllexport) ModInfo SADXModInfo { ModLoaderVer };
}