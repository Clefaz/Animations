#include "stdafx.h"

//------------------------------------------
///Fonction mais avec les structuresz Ingame et Utils
///Pensez a editer le code de game.h et game.c
//------------------------------------------

int _tmain(int argc, _TCHAR* argv[])
{
	strUtils Utils;
	strIngame Ingame;

	InitUtils(&Utils);
	InitIngame(&Ingame);

	Utils.deltatime = 0;

	while (sfRenderWindow_isOpen(Utils.window))
	{
		while (sfRenderWindow_pollEvent(Utils.window, &Utils.event))
		{
			Control(&Utils, &Ingame);
		}

		Update(&Utils, &Ingame);

		Display(&Utils, &Ingame);
	}
	return 0;
}

