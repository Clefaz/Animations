#include "stdafx.h"

#define SCRSIZEX 1000
#define SCRSIZEY 800
#define TITLE "EDIT NAME IN GAME.H"

typedef struct PersonnageDef {
	sfSprite** Timeline;
	float Tempstotalanimation;
}PersonnageDef;

//------------------------------------------Structures
typedef struct UTILS {
	//Engine
	sfRenderWindow* window;
	sfEvent event;

	//deltaclock
	sfClock* deltaclock;
	float deltatime;
}strUtils;

typedef struct INGAME {
	PersonnageDef Zelda;
	PersonnageDef Nirad;
}strIngame;

//------------------------------------------Prototypes de fonctions
void InitUtils(strUtils* _Utils);
void InitIngame(strIngame* _Ingame);

void Control(strUtils* _Utils, strIngame* _Ingame);

void Update(strUtils* _Utils, strIngame* _Ingame);

void Display(strUtils* _Utils, strIngame* _Ingame);
