#pragma once
#ifndef DEF_INFO_H
#define DEF_INFO_H

#include "Objec.h"

void info_initialize();

int GetWidth();
int GetHeight();

void Collision(Objec* obj1, Objec* obj2);

#endif // !DEF_INFO_H
