#pragma once
#include "Enemy.h"
#include <time.h>

class Fatty : public Enemy
{
private:
	int frontHead[21][32] = { {99, 99, 99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99, 99, 99},
							  {99, 99, 99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99, 99, 99},
							  {99, 99, 99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99, 99, 99},
							  {99, 99, 99,	99,	99,	0,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99, 99, 99},
							  {99, 99, 99,	99,	99,	0,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	0,	99,	99,	99, 99, 99},
							  {99, 99, 99,	99,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99,	99, 99, 99},
							  {99, 99, 99,	99,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99,	99, 99, 99},
							  {99, 99, 99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99, 99, 99},
							  {99, 99, 99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	99, 99, 99},
							  {99, 99, 0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	4,	14,	14,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0, 99, 99},
							  {99, 99, 0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	4,	14,	14,	14,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0, 99, 99},
							  {99, 99, 0,	0,	6,	0,	6,	6,	0,	0,	0,	0,	4,	14,	14,	14,	14,	14,	6,	0,	0,	6,	6,	0,	0,	0,	0,	6,	0,	0, 99, 99},
							  {99, 99, 0,	0,	6,	0,	15,	15,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	15,	15,	0,	0,	0,	6,	6,	0,	0, 99, 99},
							  {99, 99, 0,	0,	6,	0,	0,	0,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	0,	0,	6,	6,	0,	0, 99, 99},
							  {99, 99, 0,	0,	6,	4,	0,	0,	0,	0,	0,	4,	14,	14,	14,	14,	14,	14,	14,	14,	4,	0,	0,	0,	0,	0,	6,	6,	0,	0, 99, 99},
							  {99, 99, 99,	0,	4,	12,	12,	12,	12,	12,	12,	14,	0,	6,	14,	14,	14,	14,	6,	14,	14,	12,	12,	12,	12,	12,	6,	4,	0,	99, 99, 99},
							  {99, 99, 99,	0,	0,	6,	12,	12,	12,	12,	14,	4,	14,	14,	4,	4,	4,	14,	14,	6,	14,	14,	12,	12,	12,	12,	4,	0,	0,	99, 99, 99},
							  {99, 99, 99,	99,	0,	4,	6,	6,	6,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	6,	6,	6,	0,	0,	99,	99, 99, 99},
							  {99, 99, 99,	99,	99,	0,	4,	6,	6,	6,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	6,	6,	6,	4,	0,	99,	99,	99, 99, 99},
							  {99, 99, 99,	99,	99,	0,	0,	0,	0,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	0,	0,	0,	99,	99,	99,	99, 99, 99},
							  {99, 99, 99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99, 99, 99}
	};

	int frontBody[7][19][32] = { {{99,	99,	99,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	99,	99,	99},
								  {99,	99,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	99,	99},
								  {99,	99,	0,	6,	14,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	14,	6,	0,	99,	99},
								  {99,	0,	14,	14,	14,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	14,	14,	14,	0,	99},
								  {0,	0,	6,	6,	0,	6,	6,	6,	6,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	6,	6,	6,	6,	0,	6,	6,	0,	0},
								  {0,	0,	0,	0,	0,	14,	14,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	14,	14,	0,	0,	0,	0,	0},
								  {99,	0,	0,	0,	4,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	4,	0,	0,	0,	99},
								  {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99},
								  {99,	99,	0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	4,	0,	0,	99,	99},
								  {99,	99,	0,	0,	4,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	4,	0,	0,	99,	99},
								  {99,	99,	0,	0,	4,	4,	6,	6,	6,	14,	14,	14,	14,	14,	14,	0,	0,	14,	14,	14,	14,	14,	14,	6,	6,	6,	4,	4,	0,	0,	99,	99},
								  {99,	99,	0,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	0,	0,	99,	99},
								  {99,	99,	99,	0,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	0,	0,	99,	99,	99},
								  {99,	99,	99,	0,	0,	4,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99},
								  {99,	99,	99,	99,	0,	0,	4,	4,	4,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99},
								  {99,	99,	99,	99,	99,	0,	4,	4,	0,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	0,	4,	4,	0,	99,	99,	99,	99,	99},
								  {99,	99,	99,	99,	99,	99,	0,	4,	4,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	4,	4,	0,	99,	99,	99,	99,	99,	99},
								  {99,	99,	99,	99,	99,	99,	0,	0,	4,	4,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	4,	4,	0,	0,	99,	99,	99,	99,	99,	99},
								  {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99}},

								  {{99,	99,	0,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	0,	99,	99},
								   {99,	0,	6,	6,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	99,	99},
								   {0,	0,	14,	14,	14,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	14,	6,	0,	99},
								   {0,	0,	6,	14,	14,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	14,	14,	14,	0,	0},
								   {99,	0,	0,	0,	0,	6,	6,	6,	6,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	6,	6,	6,	4,	6,	6,	0,	0,	99},
								   {99,	99,	0,	0,	0,	14,	14,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	14,	14,	0,	0,	0,	99,	99},
								   {99,	99,	0,	0,	4,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	4,	0,	99,	99,	99},
								   {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99},
								   {99,	99,	0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	4,	0,	0,	99,	99},
								   {99,	99,	0,	0,	4,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	4,	0,	0,	99,	99},
								   {99,	99,	0,	0,	4,	4,	4,	0,	0,	0,	14,	14,	14,	14,	6,	0,	0,	6,	14,	14,	14,	14,	14,	6,	6,	6,	4,	4,	0,	0,	99,	99},
								   {99,	99,	0,	0,	4,	4,	0,	14,	6,	14,	0,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	0,	0,	99,	99},
								   {99,	99,	99,	0,	0,	0,	14,	6,	6,	6,	0,	0,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	0,	0,	99,	99,	99},
								   {99,	99,	99,	0,	0,	0,	6,	6,	6,	6,	6,	0,	0,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	4,	0,	0,	0,	99,	99,	99},
								   {99,	99,	99,	99,	0,	0,	6,	4,	4,	4,	6,	0,	0,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99},
								   {99,	99,	99,	99,	99,	99,	0,	4,	4,	4,	4,	0,	0,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
								   {99,	99,	99,	99,	99,	99,	0,	0,	4,	4,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	4,	4,	0,	0,	99,	99,	99,	99,	99,	99},
								   {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99},
								   {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99}},

								   {{99,	0,	0,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	0,	99,	99},
									{0,	0,	6,	6,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	14,	6,	0,	99},
									{0,	0,	14,	14,	14,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	14,	14,	14,	0,	0},
									{0,	0,	6,	14,	14,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	14,	14,	14,	0,	0},
									{99,	99,	0,	0,	0,	6,	6,	6,	6,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	6,	6,	6,	4,	6,	0,	0,	99,	99},
									{99,	99,	0,	0,	0,	14,	14,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	14,	14,	0,	0,	0,	99,	99},
									{99,	99,	0,	0,	4,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	4,	0,	0,	99,	99},
									{99,	99,	0,	0,	4,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99},
									{99,	99,	0,	0,	4,	4,	14,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	4,	0,	0,	99,	99},
									{99,	99,	0,	0,	4,	4,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	4,	0,	0,	99,	99},
									{99,	99,	0,	0,	4,	4,	0,	14,	14,	14,	0,	14,	14,	14,	6,	0,	0,	6,	14,	14,	14,	14,	14,	6,	6,	6,	4,	4,	0,	0,	99,	99},
									{99,	99,	99,	0,	0,	0,	14,	6,	6,	6,	0,	0,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	0,	0,	99,	99},
									{99,	99,	99,	0,	0,	0,	6,	6,	6,	6,	6,	0,	0,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	0,	0,	99,	99,	99},
									{99,	99,	99,	99,	0,	0,	6,	6,	6,	6,	6,	0,	0,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	4,	0,	0,	0,	99,	99,	99},
									{99,	99,	99,	99,	99,	0,	0,	4,	4,	4,	6,	0,	0,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99},
									{99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
									{99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	4,	4,	0,	0,	99,	99,	99,	99,	99,	99},
									{99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
									{99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99}},

								{{0,	0,	0,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	0,	0,	99,	99},
								 {0,	0,	14,	14,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	14,	14,	6,	0,	99},
								 {0,	0,	6,	14,	14,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	14,	14,	14,	14,	0,	0},
								 {99,	99,	0,	0,	6,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	6,	14,	14,	6,	0,	99},
								 {99,	99,	0,	0,	0,	14,	6,	6,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	6,	6,	14,	0,	0,	0,	0,	99,	99},
								 {99,	99,	99,	0,	0,	14,	14,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	14,	4,	0,	0,	0,	99,	99},
								 {99,	99,	0,	0,	6,	14,	6,	0,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99},
								 {99,	99,	0,	0,	6,	6,	0,	0,	14,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99},
								 {99,	99,	0,	0,	4,	0,	0,	14,	6,	14,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	4,	0,	0,	99,	99,	99},
								 {99,	99,	0,	0,	4,	0,	0,	4,	4,	4,	6,	0,	6,	14,	6,	0,	6,	14,	14,	14,	14,	14,	14,	6,	6,	6,	4,	0,	0,	99,	99,	99},
								 {99,	99,	0,	0,	4,	0,	0,	4,	4,	4,	4,	0,	6,	6,	6,	14,	6,	6,	6,	14,	6,	6,	6,	6,	4,	6,	4,	0,	0,	99,	99,	99},
								 {99,	99,	99,	0,	0,	4,	0,	0,	4,	4,	4,	0,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	0,	0,	0,	99,	99,	99},
								 {99,	99,	99,	99,	0,	4,	4,	4,	0,	0,	0,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	0,	0,	4,	4,	0,	4,	4,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	4,	4,	4,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}},

								{{99,	99,	0,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	0,	99,	99},
								 {99,	99,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	6,	6,	0,	99},
								 {99,	0,	6,	14,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	14,	14,	14,	0,	0},
								 {0,	0,	14,	14,	14,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	14,	14,	6,	0,	0},
								 {99,	0,	0,	6,	6,	4,	6,	6,	6,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	6,	6,	6,	6,	0,	0,	0,	0,	99},
								 {99,	99,	0,	0,	0,	14,	14,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	14,	14,	0,	0,	0,	99,	99},
								 {99,	99,	99,	0,	4,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	4,	0,	0,	99,	99},
								 {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99},
								 {99,	99,	0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	4,	0,	0,	99,	99},
								 {99,	99,	0,	0,	4,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	4,	0,	0,	99,	99},
								 {99,	99,	0,	0,	4,	4,	6,	6,	6,	14,	14,	14,	14,	14,	6,	0,	0,	6,	14,	14,	14,	14,	0,	0,	0,	6,	4,	4,	0,	0,	99,	99},
								 {99,	99,	0,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	0,	14,	6,	14,	0,	4,	4,	0,	0,	99,	99},
								 {99,	99,	99,	0,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	6,	6,	6,	14,	0,	0,	0,	99,	99,	99},
								 {99,	99,	99,	0,	0,	0,	4,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	6,	6,	6,	6,	6,	0,	0,	0,	99,	99,	99},
								 {99,	99,	99,	99,	99,	0,	0,	4,	4,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	0,	0,	6,	4,	4,	4,	6,	0,	0,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	0,	0,	4,	4,	4,	4,	0,	99,	99,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	99,	0,	0,	4,	4,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	4,	4,	0,	0,	99,	99,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	99,	0,	0,	0,	4,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99}},

								{{99,	99,	0,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	0,	0,	99},
								 {99,	0,	6,	14,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	6,	6,	0,	0},
								 {0,	0,	14,	14,	14,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	14,	14,	14,	0,	0},
								 {0,	0,	14,	14,	14,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	14,	14,	6,	0,	0},
								 {99,	99,	0,	0,	6,	4,	6,	6,	6,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	6,	6,	6,	6,	0,	0,	0,	99,	99},
								 {99,	99,	0,	0,	0,	14,	14,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	14,	14,	0,	0,	0,	99,	99},
								 {99,	99,	0,	0,	4,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	4,	0,	0,	99,	99},
								 {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99},
								 {99,	99,	0,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	14,	6,	4,	0,	0,	99,	99},
								 {99,	99,	0,	0,	4,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	6,	4,	0,	0,	99,	99},
								 {99,	99,	0,	0,	4,	4,	6,	6,	6,	14,	14,	14,	14,	14,	6,	0,	0,	6,	14,	14,	14,	0,	14,	14,	14,	0,	4,	4,	0,	0,	99,	99},
								 {99,	99,	0,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	6,	6,	6,	14,	0,	0,	0,	99,	99,	99},
								 {99,	99,	99,	0,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	6,	6,	6,	6,	6,	0,	0,	0,	99,	99,	99},
								 {99,	99,	99,	0,	0,	0,	4,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	6,	6,	6,	6,	6,	0,	0,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	0,	0,	4,	4,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	0,	0,	6,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	99,	0,	0,	4,	4,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	4,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
								 {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}},
								 
								  { {99,	99,	0,	0,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	0,	0,	0},
									{99,	0,	6,	14,	14,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	6,	14,	14,	0,	0},
									{0,	0,	14,	14,	14,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	14,	14,	6,	0,	0},
									{99,	0,	6,	14,	14,	4,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	0,	0,	99,	99},
									{99,	99,	0,	0,	0,	6,	14,	6,	6,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	6,	6,	6,	0,	0,	0,	99,	99},
									{99,	99,	0,	0,	0,	14,	14,	14,	14,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	14,	14,	0,	0,	99,	99,	99},
									{99,	99,	99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	0,	6,	14,	6,	0,	0,	99,	99},
									{99,	99,	99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	6,	0,	0,	14,	6,	0,	0,	99,	99},
									{99,	99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	6,	6,	6,	0,	6,	4,	0,	0,	99,	99},
									{99,	99,	99,	0,	0,	4,	6,	6,	6,	14,	14,	14,	14,	14,	14,	6,	0,	6,	14,	0,	0,	6,	4,	4,	4,	0,	4,	4,	0,	0,	99,	99},
									{99,	99,	99,	0,	0,	4,	6,	4,	6,	6,	6,	6,	14,	6,	6,	6,	14,	6,	6,	0,	0,	4,	4,	4,	4,	0,	4,	4,	0,	0,	99,	99},
									{99,	99,	99,	0,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	4,	4,	4,	0,	0,	4,	0,	0,	99,	99,	99},
									{99,	99,	99,	99,	0,	0,	4,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	0,	0,	0,	4,	4,	0,	0,	99,	99,	99,	99},
									{99,	99,	99,	99,	99,	0,	0,	4,	4,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	0,	4,	4,	0,	0,	99,	99,	99,	99,	99},
									{99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99},
									{99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
									{99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	4,	4,	0,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
									{99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
									{99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}}
};

int rightBody[7][19][32] = { {{99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	99,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	0,	0,	6,	4,	4,	4,	4,	4,	4,	4,	6,	6,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	4,	0,	0,	99,	99,	99},
							  {99,	99,	99,	0,	0,	14,	14,	14,	14,	6,	6,	6,	0,	14,	14,	14,	0,	0,	6,	6,	6,	6,	6,	14,	14,	14,	14,	0,	0,	99,	99,	99},
							  {99,	99,	0,	0,	4,	14,	14,	14,	14,	14,	14,	14,	0,	14,	14,	14,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	4,	0,	99,	99,	99},
							  {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	0,	14,	14,	14,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	99,	99,	99},
							  {99,	99,	0,	0,	4,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	4,	0,	99,	99,	99},
							  {99,	99,	0,	0,	4,	6,	6,	14,	14,	14,	14,	14,	14,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	4,	0,	99,	99,	99},
							  {99,	99,	0,	0,	4,	6,	6,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	6,	4,	4,	0,	99,	99,	99},
							  {99,	99,	99,	0,	0,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	0,	0,	99,	99,	99},
							  {99,	99,	99,	0,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	0,	0,	99,	99,	99},
							  {99,	99,	99,	99,	0,	4,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	0,	0,	4,	4,	4,	4,	4,	6,	6,	6,	14,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	6,	6,	14,	14,	14,	4,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	6,	6,	6,	6,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	4,	4,	4,	4,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}},

							 {{99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	0,	4,	4,	4,	4,	4,	4,	4,	6,	6,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	99,	0,	4,	4,	4,	4,	4,	4,	4,	14,	14,	14,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	0,	6,	14,	6,	6,	6,	4,	4,	0,	14,	14,	14,	14,	4,	4,	4,	4,	4,	4,	6,	6,	6,	14,	6,	0,	0,	99,	99,	99},
							  {99,	99,	99,	0,	14,	14,	14,	14,	6,	6,	6,	0,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	14,	14,	0,	0,	99,	99,	99},
							  {99,	99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	0,	6,	6,	6,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	4,	0,	99,	99,	99},
							  {99,	99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	99,	99,	99},
							  {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	4,	0,	99,	99,	99},
							  {99,	99,	0,	0,	6,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	4,	0,	99,	99,	99},
							  {99,	99,	0,	0,	4,	6,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	6,	4,	4,	0,	99,	99,	99},
							  {99,	99,	99,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	0,	0,	99,	99,	99},
							  {99,	99,	99,	0,	4,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	0,	0,	99,	99,	99},
							  {99,	99,	99,	99,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	99,	0,	0,	0,	4,	4,	4,	4,	4,	6,	6,	6,	6,	6,	6,	14,	14,	6,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	4,	4,	4,	4,	6,	6,	14,	14,	14,	14,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	4,	6,	6,	6,	6,	6,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	0,	0,	0,	0,	0,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	99,	99,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}},

							 {{99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	0,	4,	4,	4,	4,	4,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	0,	4,	4,	4,	4,	4,	0,	14,	14,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	99,	99,	99,	99,	99},
							  {99,	99,	99,	0,	0,	6,	4,	4,	4,	0,	14,	14,	14,	14,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	0,	0,	14,	6,	6,	6,	4,	6,	14,	14,	6,	4,	4,	4,	4,	4,	4,	4,	4,	6,	6,	6,	14,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	0,	0,	14,	14,	14,	6,	6,	4,	6,	6,	4,	4,	6,	6,	6,	6,	6,	6,	6,	14,	14,	14,	14,	0,	0,	99,	99,	99,	99},
							  {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99},
							  {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99},
							  {99,	99,	0,	0,	4,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	4,	0,	0,	99,	99,	99},
							  {99,	99,	0,	0,	4,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	4,	0,	0,	99,	99,	99},
							  {99,	99,	0,	0,	4,	6,	4,	6,	6,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	6,	6,	4,	6,	4,	0,	0,	99,	99,	99},
							  {99,	99,	99,	0,	0,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	0,	0,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	0,	0,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	0,	0,	4,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	6,	6,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	4,	4,	4,	6,	6,	6,	6,	6,	0,	4,	4,	6,	6,	6,	6,	6,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	4,	4,	0,	0,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	4,	0,	0,	99,	0,	0,	0,	0,	0,	99,	0,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	0,	0,	4,	4,	2,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}},

							 {{99,	99,	99,	99,	99,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	0,	0,	4,	4,	4,	0,	0,	0,	4,	3,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	0,	0,	4,	4,	4,	0,	14,	14,	14,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	0,	4,	6,	4,	4,	0,	14,	14,	14,	6,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	0,	0,	99,	99,	99,	99,	99},
							  {99,	99,	99,	0,	6,	14,	6,	6,	4,	14,	14,	14,	4,	0,	4,	4,	4,	4,	4,	4,	4,	6,	6,	6,	14,	0,	0,	99,	99,	99,	99,	99},
							  {99,	99,	99,	0,	14,	14,	14,	14,	6,	6,	6,	6,	4,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	14,	14,	0,	0,	99,	99,	99,	99,	99},
							  {99,	99,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99},
							  {99,	99,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99},
							  {99,	99,	0,	4,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	4,	0,	0,	99,	99,	99,	99},
							  {99,	99,	0,	4,	4,	6,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99},
							  {99,	99,	0,	4,	4,	6,	4,	6,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	14,	0,	99,	99,	99},
							  {99,	99,	99,	0,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	6,	6,	14,	14,	6,	4,	0,	99,	99,	99},
							  {99,	99,	99,	99,	0,	0,	0,	4,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	6,	6,	6,	6,	4,	4,	0,	99,	99,	99},
							  {99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	0,	4,	4,	0,	0,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	0,	0,	4,	4,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	0,	0,	0,	0,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	0,	0,	4,	4,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	0,	0,	4,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							  {99,	99,	99,	99,	99,	99,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}},

							{{99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	0,	4,	4,	4,	4,	4,	4,	4,	6,	6,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99},
							 {99,	99,	99,	99,	0,	4,	4,	4,	4,	4,	4,	4,	14,	14,	14,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99},
							 {99,	99,	99,	0,	4,	6,	4,	4,	4,	4,	4,	0,	14,	14,	14,	14,	0,	4,	4,	4,	4,	4,	4,	4,	4,	6,	4,	0,	0,	99,	99,	99},
							 {99,	99,	99,	0,	14,	14,	14,	14,	6,	6,	6,	0,	6,	6,	6,	6,	0,	6,	6,	6,	6,	6,	6,	14,	14,	14,	14,	0,	0,	99,	99,	99},
							 {99,	99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	0,	6,	6,	6,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	4,	0,	99,	99,	99},
							 {99,	99,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	0,	0,	0,	0,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	99,	99,	99},
							 {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	4,	0,	99,	99,	99},
							 {99,	99,	0,	0,	6,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	4,	0,	99,	99,	99},
							 {99,	99,	0,	0,	4,	6,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	6,	4,	4,	0,	99,	99,	99},
							 {99,	99,	99,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	0,	0,	99,	99,	99},
							 {99,	99,	99,	0,	4,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	0,	0,	99,	99,	99},
							 {99,	99,	99,	99,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99},
							 {99,	99,	99,	99,	0,	0,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	6,	6,	14,	14,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	6,	14,	14,	0,	0,	0,	0,	0,	0,	0,	4,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	6,	14,	0,	0,	0,	0,	0,	0,	0,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	99,	99,	99,	99,	99,	0,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99}},

							{{99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	0,	4,	4,	4,	4,	4,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	0,	4,	4,	4,	4,	4,	0,	14,	14,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	99,	99,	99,	99,	99},
							 {99,	99,	99,	0,	0,	6,	4,	4,	4,	0,	14,	14,	14,	14,	6,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	0,	0,	99,	99,	99,	99},
							 {99,	99,	99,	0,	0,	14,	6,	6,	6,	4,	6,	14,	14,	6,	4,	4,	4,	4,	4,	4,	4,	4,	6,	6,	6,	14,	0,	0,	99,	99,	99,	99},
							 {99,	99,	99,	0,	0,	14,	14,	14,	6,	6,	4,	6,	6,	4,	4,	6,	6,	6,	6,	6,	6,	6,	14,	14,	14,	14,	0,	0,	99,	99,	99,	99},
							 {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99},
							 {99,	99,	0,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99},
							 {99,	99,	0,	0,	4,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	4,	0,	0,	99,	99,	99},
							 {99,	99,	0,	0,	4,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	4,	0,	0,	99,	99,	99},
							 {99,	99,	0,	0,	4,	6,	4,	6,	6,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	6,	6,	4,	6,	4,	0,	0,	99,	99,	99},
							 {99,	99,	99,	0,	0,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	0,	0,	99,	99,	99,	99},
							 {99,	99,	99,	0,	0,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	0,	0,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	0,	0,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	0,	0,	4,	0,	0,	99,	99,	99},
							 {99,	99,	99,	99,	99,	0,	0,	0,	0,	6,	6,	6,	6,	4,	6,	6,	6,	6,	4,	4,	4,	4,	0,	0,	0,	0,	4,	0,	0,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	0,	6,	6,	14,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	4,	4,	0,	0,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	0,	6,	6,	14,	0,	0,	99,	0,	0,	0,	0,	0,	99,	99,	99,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	0,	6,	6,	14,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							 {99,	99,	99,	99,	99,	99,	99,	0,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}},

							 { {99,	99,	99,	99,	99,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	0,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	0,	0,	4,	4,	4,	4,	14,	14,	14,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	0,	0,	4,	4,	4,	0,	14,	14,	14,	0,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	0,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	0,	4,	6,	4,	4,	0,	14,	14,	14,	6,	0,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	6,	0,	0,	99,	99,	99,	99,	99},
							   {99,	99,	99,	0,	14,	14,	14,	14,	6,	6,	6,	6,	4,	6,	6,	6,	6,	6,	6,	6,	6,	14,	14,	14,	14,	0,	0,	99,	99,	99,	99,	99},
							   {99,	99,	0,	4,	14,	14,	14,	14,	14,	4,	4,	4,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	4,	0,	0,	99,	99,	99,	99},
							   {99,	99,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99},
							   {99,	99,	0,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	0,	0,	99,	99,	99,	99},
							   {99,	99,	0,	4,	6,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	4,	0,	0,	99,	99,	99,	99},
							   {99,	99,	0,	4,	4,	6,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99},
							   {99,	99,	0,	4,	4,	6,	4,	6,	6,	6,	14,	14,	14,	14,	14,	14,	14,	14,	14,	6,	6,	6,	6,	6,	6,	4,	0,	0,	99,	99,	99,	99},
							   {99,	99,	99,	0,	4,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	0,	0,	99,	99,	99,	99},
							   {99,	99,	99,	0,	0,	4,	4,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	6,	4,	4,	4,	4,	0,	0,	4,	0,	99,	99,	99},
							   {99,	99,	99,	99,	99,	0,	0,	4,	6,	6,	4,	4,	6,	6,	6,	6,	6,	6,	4,	4,	4,	0,	0,	0,	0,	4,	4,	0,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	0,	0,	6,	6,	6,	0,	0,	4,	4,	4,	4,	4,	4,	4,	0,	0,	0,	0,	0,	4,	4,	0,	0,	99,	99,	99,	99},
							   {99,	99,	99,	99,	0,	0,	4,	6,	6,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	99,	0,	0,	0,	0,	0,	99,	99,	99,	99},
							   {99,	99,	99,	99,	0,	0,	4,	4,	4,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	0,	0,	4,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	0,	0,	0,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}}
};

	int leftBody[7][19][32];

	clock_t curTime, walkTime;
	bool isWalk;
	int walkIndex;
	int increase;
	bool check;
	bool side;
public:
	Fatty(int x, int y);
	~Fatty();

	void Update();
	const char* getClassName();
	int* getColorLine(int row);

	int* getRedLine(int* source);
};

