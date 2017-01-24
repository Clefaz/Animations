#include "stdafx.h"

//------------------------------------------
///Fonctions Utiles SFML
//------------------------------------------

void Rigidbody_Init(Rigidbody* _rigidbody) {
	_rigidbody->mass = 1.0f;
	_rigidbody->gravityscale = 1.0f;
	_rigidbody->force = (sfVector2f) { 0.0f, 0.0f };
	_rigidbody->acceleration = (sfVector2f) { 0.0f, 0.0f };
	_rigidbody->velocity = (sfVector2f) { 0.0f, 0.0f };
	_rigidbody->position = (sfVector2f) { 0.0f, 0.0f };
}

void Rigidbody_Update(Rigidbody* _rigidbody, float dT, sfVector2f _gravity)
{
	_rigidbody->acceleration.x = _rigidbody->force.x / _rigidbody->mass + _gravity.x * _rigidbody->gravityscale;
	_rigidbody->acceleration.y = _rigidbody->force.y / _rigidbody->mass + _gravity.y * _rigidbody->gravityscale;

	_rigidbody->position.x += _rigidbody->velocity.x * dT + _rigidbody->acceleration.x * dT * dT / 2.0;
	_rigidbody->position.y += _rigidbody->velocity.y * dT + _rigidbody->acceleration.y * dT * dT / 2.0;

	_rigidbody->velocity.x += _rigidbody->acceleration.x * dT;
	_rigidbody->velocity.y += _rigidbody->acceleration.y * dT;

	_rigidbody->force.x = 0;
	_rigidbody->force.y = 0;
}


sfSprite* LoadSprite(char* _sNom, int _isCentered)
{
	sfSprite* sprite;
	sfTexture* texture;

	texture = sfTexture_createFromFile(_sNom, NULL);
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);

	if (_isCentered != 0)
	{
		sfVector2u tempsize = sfTexture_getSize(texture);
		sfVector2f origin = { tempsize.x / 2 , tempsize.y / 2 };
		sfSprite_setOrigin(sprite, origin);
	}

	return sprite;
}

void BlitSprite(sfSprite* _sprite, sfVector2f _position, float _rotation, sfRenderWindow* _window)
{
	sfSprite_setPosition(_sprite, _position);
	sfSprite_setRotation(_sprite, _rotation);
	sfRenderWindow_drawSprite(_window, _sprite, NULL);
}

void DrawPixel(sfImage* _image, sfVector2f _point, sfColor _color)
{
	sfVector2u tempSize = sfImage_getSize(_image);
	if (_point.x >= 0 && _point.y >= 0 && _point.x < tempSize.x && _point.y < tempSize.y)
	{
		sfImage_setPixel(_image, _point.x, _point.y, _color);
	}
}

void DrawLine(sfImage* _image, sfVector2f _point1, sfVector2f _point2, sfColor _color)
{
	//http://tech-algorithm.com/articles/drawing-line-using-bresenham-algorithm/

	int dx = abs(_point2.x - _point1.x), sx = _point1.x<_point2.x ? 1 : -1;
	int dy = abs(_point2.y - _point1.y), sy = _point1.y<_point2.y ? 1 : -1;
	int err = (dx>dy ? dx : -dy) / 2, e2;

	while (1) {
		DrawPixel(_image, _point1, _color);
		if (_point1.x == _point2.x && _point1.y == _point2.y) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; _point1.x += sx; }
		if (e2 < dy) { err += dx; _point1.y += sy; }
	}
}
