#pragma once
#include<utility>
#include<conio.h>
#include<time.h>
#include<vector>
#include "Object.h"
#include "Projectile.h"
#include "Equipment.h"
using namespace std;


class Player : public Object
{
private:
pair<int, int> lookAt;

int frontIdleHead[26][29] = { {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	0,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	0,	0,	0,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99},
							  {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99},
							  {99,	99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99,	99},
							  {99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99},
							  {99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99},
							  {0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0},
							  {0,	0,	6,	14,	6,	0,	0,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	0,	0,	0,	6,	14,	6,	0,	0},
							  {0,	0,	6,	14,	0,	15,	15,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	15,	15,	15,	0,	0,	0,	14,	6,	0,	0},
							  {0,	0,	6,	6,	0,	15,	15,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	15,	15,	15,	0,	0,	0,	6,	6,	0,	0},
							  {0,	0,	4,	6,	0,	0,	0,	0,	0,	0,	14,	14,	0,	0,	0,	0,	14,	14,	0,	0,	0,	0,	0,	0,	0,	6,	4,	0,	0},
							  {99,	0,	0,	6,	0,	0,	0,	0,	0,	0,	14,	0,	0,	0,	0,	0,	0,	14,	0,	0,	0,	0,	0,	0,	0,	6,	0,	0,	99},
							  {99,	0,	0,	6,	0,	0,	0,	0,	0,	0,	14,	0,	0,	0,	0,	0,	0,	14,	0,	0,	0,	0,	0,	0,	0,	6,	0,	0,	99},
							  {99,	0,	0,	4,	6,	0,	0,	0,	0,	6,	14,	0,	15,	15,	15,	15,	0,	14,	6,	0,	0,	0,	0,	0,	6,	4,	0,	0,	99},
							  {99,	99,	0,	0,	6,	8,	8,	8,	6,	14,	14,	0,	0,	0,	0,	0,	0,	14,	14,	6,	6,	8,	8,	8,	6,	0,	0,	99,	99},
							  {99,	99,	0,	0,	4,	8,	8,	8,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	8,	8,	8,	4,	0,	0,	99,	99},
							  {99,	99,	99,	0,	0,	3,	8,	8,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	8,	8,	3,	0,	0,	99,	99,	99},
							  {99,	99,	99,	99,	0,	0,	3,	8,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	8,	3,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	0,	0,	0,	3,	6,	14,	14,	14,	14,	14,	14,	14,	14,	6,	3,	3,	0,	0,	0,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	6,	6,	6,	6,	6,	6,	4,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}
};

int frontIdleBody[7][11][29] = {{ {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	6,	6,	6,	6,	6,	6,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	6,	6,	6,	6,	6,	6,	6,	6,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	6,	6,	6,	6,	6,	6,	6,	6,	14,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	0,	0,	6,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	0,	0,	6,	14,	0,	6,	14,	14,	14,	14,	14,	14,	6,	0,	14,	14,	6,	0,	0,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	0,	0,	6,	14,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	14,	14,	6,	0,	0,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	14,	14,	6,	0,	0,	6,	14,	14,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	14,	14,	14,	0,	0,	6,	14,	14,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	14,	14,	0,	0,	6,	14,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	99,	99,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}},

							  {{99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	4,	6,	6,	6,	6,	6,	6,	4,	0,	0,	0,	99,	99, 99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	0,	0,	6,	4,	6,	6,	6,	6,	6,	6,	6,	6,	4,	6,	0,	0,	99, 99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	0,	0,	6,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	6,	0,	0,  99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	0,	0,	6,	14,	0,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	6,	0,	0,  99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	0,	0,	6,	4,	0,	6,	14,	14,	14,	14,	14,	14,	6,	0,	14,	6,	0,	0,  99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	0,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	99, 99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	14,	6,	0,	0,	6,	14,	14,	0,	0,	0,	99,	99, 99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	4,	4,	4,	0,	0,	6,	14,	6,	0,	0,	99,	99,	99, 99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	4,	4,	0,	0,	0,	99,	99,	99, 99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99, 99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	99,	99,	99,	99,	99, 99,	99,	99,	99,	99,	99}},

{ {99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	6,	6,	6,	6,	6,	6,	4,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	0,	0,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	14,	0,	0,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	0,	0,	6,	6,	4,	4,	4,	6,	6,	6,	4,	6,	14,	14,	14,	0,	0,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	0,	0,	4,	6,	4,	6,	6,	6,	4,	6,	6,	4,	6,	6,	14,	14,	0,	0,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	0,	0,	4,	0,	6,	14,	14,	14,	4,	6,	6,	4,	6,	6,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	0,	0,	0,	0,	6,	14,	14,	14,	4,	6,	6,	6,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	0,	0,	0,	6,	14,	14,	14,	4,	0,	6,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	6,	6,	6,	0,	4,	6,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	4,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}},

{{99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	6,	6,	6,	6,	6,	6,	4,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	0,	0,	0,	6,	4,	6,	6,	6,	6,	6,	6,	6,	6,	14,	6,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	0,	0,	6,	6,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	6,	0,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	0,	0,	14,	14,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	14,	0,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	0,	0,	0,	0,	14,	0,	6,	6,	14,	14,	6,	6,	6,	6,	4,	14,	14,	0,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	6,	14,	14,	14,	14,	6,	6,	6,	0,	6,	6,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	14,	14,	14,	14,	4,	6,	4,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	14,	14,	6,	14,	0,	4,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	14,	14,	14,	4,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	14,	14,	14,	14,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}},

 {{99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	6,	6,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	6,	6,	6,	6,	6,	6,	6,	6,	6,	14,	6,	0,	0,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	0,	0,	6,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	6,	0,	0,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	0,	0,	14,	14,	0,	6,	14,	14,	14,	14,	14,	6,	6,	6,	14,	14,	14,	0,	0,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	0,	0,	0,	14,	0,	14,	14,	14,	14,	14,	14,	6,	6,	6,	4,	14,	14,	0,	0,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	14,	14,	6,	14,	4,	6,	6,	6,	6,	0,	6,	6,	0,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	14,	14,	14,	4,	0,	6,	4,	4,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	14,	14,	14,	14,	0,	4,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	14,	14,	14,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}},

 {{99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	4,	6,	6,	6,	6,	6,	6,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	0,	0,	6,	4,	6,	6,	6,	6,	6,	6,	6,	6,	4,	6,	0,	0,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	0,	0,	6,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	6,	0,	0,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	0,	0,	6,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	0,	14,	6,	0,	0,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	0,	0,	6,	14,	0,	6,	14,	14,	14,	14,	14,	14,	6,	0,	4,	6,	0,	0,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	14,	14,	6,	0,	0,	6,	14,	14,	6,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	6,	0,	0,	14,	14,	14,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	4,	4,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}},

 {{99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	6,	6,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	0,	0,	0,	0,	14,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	0,	0,	0,	14,	14,	14,	6,	4,	6,	6,	6,	4,	4,	4,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	0,	0,	0,	14,	14,	6,	6,	4,	6,	6,	4,	6,	6,	6,	4,	6,	4,	0,	0,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	0,	0,	0,	6,	6,	6,	6,	4,	6,	6,	4,	14,	14,	14,	6,	0,	4,	0,	0,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	6,	6,	6,	4,	14,	14,	14,	6,	0,	0,	0,	0,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	6,	0,	4,	14,	14,	14,	6,	0,	0,	0,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	4,	0,	6,	6,	6,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	4,	4,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99},
  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}}
};

int rightIdleHead[26][29] = { {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99, 99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99, 99},
							  {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99, 99},
							  {99,	99,	99,	99,	99,	0,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	0,	99,	99,	99,	99,	99, 99},
							  {99,	99,	99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99, 99},
							  {99,	99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99, 99},
							  {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99, 99},
							  {99,	99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99,	99, 99},
							  {99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99, 99},
							  {99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99, 99},
							  {0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	0,	0,	6,	14,	14,	14,	14,	14,	6,	0,	0, 99},
							  {0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	15,	15,	0,	0,	0,	14,	14,	14,	14,	14,	6,	0,	0, 99},
							  {0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	15,	15,	0,	0,	0,	14,	14,	14,	14,	14,	6,	0,	0, 99},
							  {0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	0,	0,	14,	14,	14,	6,	0,	0,	0,	0, 99},
							  {0,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	0,	0,	14,	14,	6,	0,	0,	0,	0,	0, 99},
							  {99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	0,	0,	6,	14,	14,	0,	15,	15,	15,	0,	0, 99},
							  {99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	0,	0,	6,	14,	14,	0,	15,	15,	15,	0,	0, 99},
							  {99,	0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	8,	8,	8,	8,	14,	14,	14,	0,	0,	0,	0,	0,	0, 99},
							  {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	8,	8,	8,	8,	14,	14,	14,	6,	6,	6,	0,	0,	99, 99},
							  {99,	99,	0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	8,	8,	8,	8,	14,	14,	14,	14,	6,	4,	0,	0,	99, 99},
							  {99,	99,	99,	0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	8,	8,	8,	8,	14,	14,	14,	6,	4,	0,	0,	99,	99, 99},
							  {99,	99,	99,	99,	0,	0,	4,	6,	6,	14,	14,	14,	14,	14,	14,	8,	8,	8,	8,	14,	14,	6,	4,	0,	0,	99,	99,	99, 99},
							  {99,	99,	99,	99,	99,	0,	0,	0,	4,	6,	14,	14,	14,	14,	14,	8,	8,	8,	3,	6,	4,	0,	0,	0,	99,	99,	99,	99, 99},
							  {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	6,	6,	6,	6,	3,	3,	3,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99, 99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99, 99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99, 99}
};

int backIdleHead[26][29] = { {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	6,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	0,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	0,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99},
							 {99,	99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99},
							 {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99},
							 {99,	99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99,	99},
							 {99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99},
							 {99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99},
							 {0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0},
							 {0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0},
							 {0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0},
							 {0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0},
							 {0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	4,	0,	0},
							 {99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99},
							 {99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99},
							 {99,	0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	4,	0,	0,	99},
							 {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99},
							 {99,	99,	0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	4,	0,	0,	99,	99},
							 {99,	99,	99,	0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	4,	0,	0,	99,	99,	99},
							 {99,	99,	99,	99,	0,	0,	4,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	4,	0,	0,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	0,	0,	0,	4,	6,	6,	14,	14,	14,	14,	14,	14,	14,	6,	6,	4,	0,	0,	0,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	6,	6,	6,	6,	6,	6,	6,	4,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}
};

int rightIdleBody[7][11][29] = {{ {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	6,	6,	6,	6,	6,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	6,	6,	6,	6,	6,	6,	6,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	14,	6,	6,	6,	6,	6,	6,	6,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	14,	14,	6,	6,	6,	6,	6,	6,	6,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	14,	0,	6,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	0,	6,	14,	14,	14,	14,	14,	14,	6,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	6,	14,	14,	14,	0,	4,	6,	6,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	6,	14,	14,	14,	0,	4,	6,	6,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	6,	6,	6,	0,	4,	6,	6,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}},

							  {{99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	4,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	6,	6,	6,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	6,	14,	14,	6,	6,	6,	6,	6,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	14,	14,	6,	6,	6,	6,	6,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	14,	0,	6,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	14,	0,	6,	14,	14,	14,	14,	6,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	6,	14,	14,	14,	14,	0,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	4,	6,	14,	14,	0,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	4,	6,	0,	4,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}},
	
{{99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	4,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	6,	4,	6,	6,	6,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	6,	6,	14,	14,	6,	6,	6,	6,	4,	4,	6,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	6,	14,	14,	14,	6,	6,	6,	4,	14,	14,	4,	4,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	14,	14,	0,	14,	14,	6,	4,	14,	14,	14,	14,	4,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	4,	0,	0,	6,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	4,	6,	6,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	4,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	4,	4,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}},

{{99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	4,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	6,	4,	6,	6,	6,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	0,	0,	6,	6,	6,	6,	14,	14,	6,	6,	6,	6,	6,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	0,	0,	6,	6,	6,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	14,	14,	0,	6,	6,	6,	14,	14,	14,	14,	4,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	4,	6,	6,	6,	6,	14,	14,	14,	6,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	0,	0,	0,	0,	4,	6,	6,	6,	0,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	4,	4,	4,	4,	0,	0,	4,	6,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	4,	4,	4,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	99,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99}},

{{99,	99,	99,	99,	99,	99,	0,	0,	0,	6,	4,	4,	4,	6,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	0,	0,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	0,	0,	6,	6,	14,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	0,	0,	0,	14,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	6,	6,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	6,	6,	6,	14,	14,	14,	14,	14,	0,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	0,	0,	0,	4,	6,	6,	14,	14,	14,	0,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	4,	4,	4,	0,	0,	4,	4,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99}},

{{99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	6,	6,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	14,	6,	6,	6,	6,	6,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	14,	14,	6,	6,	6,	6,	6,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	14,	0,	6,	6,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	0,	6,	6,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	6,	6,	6,	14,	14,	14,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	0,	0,	6,	6,	6,	14,	14,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	4,	0,	0,	6,	6,	6,	6,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	99,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99}},

{{99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	4,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	0,	0,	0,	6,	4,	6,	6,	6,	6,	6,	6,	6,	6,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	0,	0,	6,	6,	6,	14,	14,	6,	6,	6,	6,	6,	6,	4,	0,	0,	0,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	0,	0,	6,	6,	14,	14,	14,	6,	6,	6,	6,	6,	6,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	0,	0,	0,	14,	14,	0,	6,	14,	14,	14,	14,	14,	6,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	6,	14,	14,	14,	14,	14,	14,	6,	4,	4,	0,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	6,	6,	14,	14,	14,	14,	0,	4,	4,	0,	0,	0,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	14,	14,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	6,	6,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}}
 };

int leftIdleHead[26][29];

int leftIdleBody[7][11][29];

int frontAttackHead[26][29] = { {99, 99, 99, 99, 99, 99, 99, 99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99, 99},
								{99, 99, 99, 99, 99, 99, 99, 99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99, 99},
								{99, 99, 99, 99, 99, 99, 99, 99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99, 99},
								{99, 99, 99, 99, 99, 99, 0,	0,	0,	0,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,     99},
								{99, 99, 99, 99, 99, 0, 0, 0, 6, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 6,	0, 0, 0, 99, 99, 99, 99, 99,            99},
								{99, 99, 99, 99, 0, 0,  6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99,     99},
								{99, 99, 99, 0, 0, 6,  14, 14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99,     99},
								{99, 99, 0, 0, 6, 14, 14, 14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,     99},
								{99, 99, 0, 0, 14, 14, 14, 14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99,	99,     99},
								{99, 0, 0, 6, 14, 14, 14, 14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,     99},
								{99, 0, 0, 14, 14, 14, 14, 14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99,     99},
								{0, 0, 6, 14, 14, 14, 14, 14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,      99},
								{0, 0, 6, 14, 14, 14, 14, 14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,      99},
								{0, 0, 6, 6, 14, 14, 14, 14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	0,	0,      99},
								{0, 0, 4, 6, 0, 14, 14, 14,	14,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	14,	14,	14,	14,	0,	6,	4 ,	0,	0,      99},
								{0, 0, 4, 6, 0, 14, 14, 14,	14,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	14,	14,	14,	14,	0,	6,	4 ,	0,	0,      99},
								{99, 0, 0, 8, 0,  0,  0,	0,	0,	0,	14,	14,	0,	0,	0,	0,	14,	14,	0,	0,	0,	0,	0,	0,	8,	0,	0,	0,      99},
								{99, 0, 8, 8, 8,  0,  0,	0,	0,	6,	14,	0,	15,	15,	15,	15,	0,	14,	6,	0,	0,	0,	0,	8,	8,	8,	0,	99,     99},
								{99, 99, 0, 3, 6,  8,  8,	8,	6,	14,	14,	0,	0,	0,	0,	0,	0,	14,	14,	6,	8,	8,	8,	6,	3,	0,	99,	99,     99},
								{99, 99, 0, 0, 4,  8,  8,	8,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	8,	8,	8,	4 ,	0,	0,	99,	99,     99},
								{99, 99, 99, 0, 0,  3,  8,	8,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	8,	8,	3,	0,	0,	99,	99,	99,     99},
								{99, 99, 99, 99, 0,  0,  3,	8,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	8,	3,	0,	0,	99,	99,	99,	99,     99},
								{99, 99, 99, 99, 99, 0,  0,	0,	3,	6,	14,	14,	14,	14,	14,	14,	14,	14,	6,	3,	0,	0,	0,	99,	99,	99,	99,	99,     99},
								{99,99, 99, 99, 99, 99, 99, 0,	0,	0,	0,	4 ,	6,	6,	6,	6,	6,	6,	4 ,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
								{99,99, 99, 99, 99, 99, 99, 99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
								{99,99, 99, 99, 99, 99, 99, 99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}
};

int rightAttackHead[26][29] = { {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
								{99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
								{99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
								{99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
								{99,	99,	99,	99,	99,	0,	0,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	0,	99,	99,	99,	99,	99},
								{99,	99,	99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99},
								{99,	99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99},
								{99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99},
								{99,	99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99,	99},
								{99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99},
								{99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99},
								{0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0},
								{0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0},
								{0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	14,	14,	14,	14,	0,	14,	14,	14,	6,	0,	0,	0,	0},
								{0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	8,	0,	0,	0,	0,	0,	0,	14,	14,	6,	0,	0,	0,	0,	0},
								{0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	8,	0,	0,	0,	0,	0,	0,	14,	14,	6,	0,	0,	0,	0,	0},
								{99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	8,	8,	8,	0,	0,	0,	0,	6,	14,	14,	0,	15,	15,	15,	0,	0},
								{99,	0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	3,	14,	8,	8,	8,	8,	14,	14,	14,	0,	0,	0,	0,	0,	0},
								{99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	8,	8,	8,	8,	14,	14,	14,	6,	6,	6,	0,	0,	99},
								{99,	99,	0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	8,	8,	8,	8,	14,	14,	14,	14,	6,	4,	0,	0,	99},
								{99,	99,	99,	0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	8,	8,	8,	8,	14,	14,	14,	6,	4,	0,	0,	99,	99},
								{99,	99,	99,	99,	0,	0,	4,	6,	6,	6,	14,	14,	14,	14,	14,	14,	8,	8,	8,	8,	14,	14,	6,	4,	0,	0,	99,	99,	99},
								{99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	6,	14,	14,	14,	14,	14,	8,	8,	8,	3,	6,	4,	0,	0,	0,	99,	99,	99,	99},
								{99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	4,	6,	6,	6,	6,	3,	3,	3,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99},
								{99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
								{99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}
};

int leftAttackHead[26][29];

clock_t curTime, oldTime, attTime, walkTime, idleTime, invincibilityTime, twinkleTime;
int isWalk;

bool isRed;

// 스탯
int att;
int attRate;
int curHp;
int speed;
int maxHp;
int money;

int walkIndex;

bool isAttack;		// 공격중인상태
bool invincibility;		// 무적상태

vector<Equipment*> inventory;
Equipment* equipment;		// 착용중인 장비

public:
	Player();
	~Player();

	// getter, setter
	void getDamage(int damage);
	int getMaxHp() { return maxHp; }
	void setMaxHp(int _maxHp) {maxHp = _maxHp;}
	void setcurHp(int _curHp) {curHp = _curHp;}
	void setMoney(int _money) {money = _money;}
	void setAtt(int _att) { att = _att; }
	void setAttRate(int _attRate) { attRate = _attRate; }
	int getAttRate() { return attRate; }
	int getAtt() { return att; }
	void setSpeed(int _speed) { speed = _speed; }
	int getSpeed() { return speed; }
	int getCurHp() { return curHp; }
	int getMoney() { return money; }
	Equipment* getEquipment() { return equipment; }
	vector<Equipment*> getInventory() { return inventory; }
	int getInventorySize() { return inventory.size(); }

	void plusMoney(int _money) { money += _money; }
	void Update();
	void move(int x, int y);
	const char* getClassName();
	int* getColorLine(int row);
	int* getRedPlayer(int* source);
	Projectile* attack();

	// 장비 관련
	void putInventory(Equipment* equipment);
	void takeOutEquipment(int index);
	void wearEquipment(int index);
};

 