#pragma once

#include "stdafx.h"

typedef struct Rigidbody {
	float mass;
	float gravityscale;
	sfVector2f force;
	sfVector2f acceleration;
	sfVector2f velocity;
	sfVector2f position;
}Rigidbody;

void Rigidbody_Init(Rigidbody* _rigidbody);
void Rigidbody_Update(Rigidbody* _rigidbody, float dT, sfVector2f _gravity);

sfSprite* LoadSprite(char* _sNom, int _isCentered);
void BlitSprite(sfSprite* _sprite, sfVector2f _position, float _rotation, sfRenderWindow* _window);
void DrawPixel(sfImage* _image, sfVector2f _point, sfColor _color);
void DrawLine(sfImage* _image, sfVector2f _point1, sfVector2f _point2, sfColor _color);