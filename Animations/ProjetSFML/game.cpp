#include "stdafx.h"

void ChargementSprites(PersonnageDef* Player, char* Directory) {
	//Chargement du fichier
	char tempchar[50];
	sprintf(tempchar,"%s/def.txt", Directory);
	printf("%s: ", tempchar);

	FILE* ptrfile = 0;
	ptrfile = fopen(tempchar, "r+");
	if (ptrfile == NULL)
		return printf("error loading file\n\n");
	printf("loading success\n\n");

	bool stop = false;
	while (stop == false) {
		//Chargement des mots clés
		fscanf(ptrfile, "%s", &tempchar);

		//Conditions des mots clés
		if (!strcmp(tempchar, "SPRITES"))
		{
			//allocation en fonction du nombre de sprites
			int nbsprites;
			fscanf(ptrfile, "%d", &nbsprites);
			Player->Timeline = malloc(nbsprites*sizeof(sfSprite*));

			//Importation des sprites
			for (int i = 0; i < nbsprites; i++)
			{
				fscanf(ptrfile, "%s", &tempchar);
				Player->Timeline[i] = LoadSprite(tempchar, 0);
			}
		}
		else
			stop = true;
	}
	fclose(ptrfile);
}

//------------------------------------------Initialisation
void InitUtils(strUtils* _Utils)
{
	//Window
	sfVideoMode mode = { SCRSIZEX, SCRSIZEY, 32 };
	_Utils->window = sfRenderWindow_create(mode, TITLE, sfResize | sfClose, NULL);

	//Deltaclock   
	_Utils->deltaclock = sfClock_create();
}
void InitIngame(strIngame* _Ingame)
{
	ChargementSprites(&_Ingame->Zelda, "Assets/Zelda");
	ChargementSprites(&_Ingame->Nirad, "Assets/Nirad");
}

//------------------------------------------Update
void Control(strUtils* _Utils, strIngame* _Ingame)
{
	if (_Utils->event.type == sfEvtClosed)
		sfRenderWindow_close(_Utils->window);
}

void Update(strUtils* _Utils, strIngame* _Ingame)
{

}

//------------------------------------------Affichage
void Display(strUtils* _Utils, strIngame* _Ingame)
{
	sfRenderWindow_clear(_Utils->window, sfBlack);

	for (int i = 0; i < 20; i++)
	{
		if (i % 2)
			BlitSprite(_Ingame->Zelda.Timeline[i], (sfVector2f) { 50 * (i - 1), 0 }, 0, _Utils->window);
		else
			BlitSprite(_Ingame->Zelda.Timeline[i], (sfVector2f) { 50 * i, 100 }, 0, _Utils->window);
	}

	sfRenderWindow_display(_Utils->window);
}