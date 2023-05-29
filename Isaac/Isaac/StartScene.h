#pragma once
class StartScene
{
private:
	int startScene[79][96] = { {99,	99,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 ,	99, 1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	99,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	99,	99,	99,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	99,	99,	99,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	1 ,	99,	99},
							   {99,	99,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	1,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	1,	99,	1,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	1,	99,	1,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	1,	1 },
							   {99,	99,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	1,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1 },
							   {99,	99,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1 },
							   {99,	99,	1,	1,	1,	1,	1,	15,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	1,	15,	15,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	15,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	15,	15,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	15,	15,	15,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	15,	15,	15,	15,	15,	15,	15,	1 },
							   {99,	99,	99,	99,	1,	1,	1,	15,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	1,	15,	15,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	15,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	15,	15,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	1,	15,	15,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	15,	15,	15,	15,	15,	15,	1 },
							   {99,	99,	99,	99,	99,	99,	1,	15,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	3,	15,	15,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	15,	15,	1,	15,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	15,	15,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	15,	15,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	15,	15,	15,	15,	15,	15,	1 },
							   {99,	99,	99,	99,	99,	99,	1,	15,	15,	15,	15,	15,	15,	1,	1,	1,	15,	15,	3,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	1,	15,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	15,	1,	15,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
							   {99,	99,	99,	99,	99,	99,	1,	15,	15,	15,	15,	11,	15,	1,	1,	1,	15,	15,	3,	1,	1,	15,	11,	15,	15,	15,	15,	15,	11,	15,	11,	15,	15,	11,	15,	15,	1,	1,	1,	15,	15,	15,	11,	11,	15,	11,	15,	15,	15,	15,	11,	11,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	11,	15,	15,	15,	15,	15,	15,	15,	11,	15,	15,	15,	15,	1,	1,	15,	15,	15,	15,	15,	15,	1,	15,	1,	1,	1,	1,	1,	1,	1,	1,	99,	99},
							   {99,	99,	99,	99,	99,	99,	1,	11,	11,	15,	11,	11,	11,	1,	1,	1,	15,	99,	15,	1,	1,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	11,	11,	11,	15,	1,	1,	1,	11,	15,	11,	15,	15,	15,	11,	11,	15,	15,	15,	15,	11,	11,	11,	11,	15,	1,	1,	15,	15,	11,	11,	15,	15,	11,	11,	15,	11,	11,	11,	11,	15,	15,	15,	11,	15,	1,	1,	11,	15,	15,	11,	15,	15,	1,	15,	15,	15,	15,	1,	1,	1,	1,	1,	1,	1 },
							   {99,	99,	99,	99,	99,	99,	1,	11,	11,	11,	11,	11,	11,	1,	1,	1,	15,	99,	99,	15,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	15,	11,	11,	11,	11,	15,	1,	1,	1,	11,	15,	11,	15,	15,	11,	1,	1,	1,	1,	1,	11,	1,	11,	11,	1,	11,	1,	1,	15,	15,	15,	11,	11,	11,	11,	1,	1,	1,	1,	1,	11,	11,	11,	11,	11,	15,	1,	1,	11,	15,	11,	11,	15,	11,	1,	15,	99,	15,	1,	15,	11,	15,	15,	15,	15,	1 },
							   {99,	99,	99,	99,	99,	99,	1,	15,	11,	11,	11,	11,	11,	1,	1,	1,	15,	15,	15,	15,	15,	1,	1,	1,	1,	1,	1,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	1,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	1,	11,	11,	11,	11,	11,	11,	11,	1,	1,	1,	1,	1,	15,	11,	11,	11,	11,	11,	1,	1,	11,	11,	11,	15,	11,	11,	1,	15,	15,	1,	1,	11,	15,	11,	11,	11,	11,	1 },
							   {1 ,	1,	1,	1,	1,	3,	1,	11,	11,	11,	11,	11,	11,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	1,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	1,	11,	11,	11,	11,	11,	11,	11,	1,	1,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	1,	11,	11,	11,	11,	11,	11,	1,	1,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1 },
							   {1 ,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	1,	1,	1,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	15,	15,	15,	1,	11,	11,	11,	11,	11,	11,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	15,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	1,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	0,	1 },
							   {1 ,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	1,	1,	1,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	15,	8,	15,	1,	11,	11,	11,	11,	11,	11,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	15,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	1,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	0,	1 },
							   {1 ,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	1,	1,	1,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	1,	1,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	15,	8,	15,	1,	11,	11,	11,	11,	11,	11,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	15,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	1,	1,	1,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	1,	1 },
							   {1 ,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	1,	1,	1,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	1,	1,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	15,	8,	15,	1,	11,	11,	11,	11,	11,	11,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	15,	1,	1,	1,	11,	11,	11,	11,	11,	11,	1,	1,	1,	1,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	11,	1,	1,	15},
							   {1 ,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	15,	1,	1,	1,	1,	1,	1,	1,	1,	15,	8,	15,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	15,	15,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	15,	15},
							   {15,	15,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	15,	1,	1,	1,	1,	1,	1,	1,	1,	15,	8,	15,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	15,	15,	15,	1,	1,	1,	1,	1,	1,	1,	1,	15,	15,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	15,	15,	99},
							   {99,	99,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	0,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	0,	15,	0,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	0,	0,	0,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	0,	0,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	0,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	0,	15,	0,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	0,	15,	0,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	0,	0,	0,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	0,	15,	15,	15,	15,	15,	0,	0,	0,	0,	0,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	0,	0,	0,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	0,	0,	0,	0,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	0,	15,	0,	0,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	0,	15,	0,	15,	15,	15,	15,	15,	15,	0,	0,	0,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	0,	14,	0,	15,	15,	0,	0,	0,	15,	0,	0,	0,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	14,	15,	15,	15,	15,	15,	15,	15,	15,	0,	14,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	0,	0,	0,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	15,	15,	15,	0,	0,	0,	0,	15,	0,	0,	0,	0,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	0,	0,	0,	15,	15,	0,	0,	0,	0,	0,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	0,	0,	0,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	14,	14,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	0,	15,	15,	15,	0,	15,	0,	15,	15,	15,	15,	15,	15,	0,	0,	0,	15,	15,	15,	15,	0,	0,	0,	0,	0,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	0,	0,	0,	0,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	0,	15,	0,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	0,	0,	0,	0,	0,	0,	15,	0,	15,	15,	0,	0,	0,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	0,	0,	0,	0,	0,	15,	15,	15,	15,	15,	15,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	0,	0,	0,	15,	15,	15,	15,	0,	0,	0,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	15,	15,	0,	0,	0,	15,	15,	15,	15,	0,	0,	0,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	0,	0,	0,	0,	0,	0,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	15,	15,	15,	15,	0,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	0,	15,	15,	0,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	8,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	15,	8,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	15,	15,	15,	8,	8,	99,	8,	8,	8,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	8,	8,	8,	8,	99,	99,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	8,	8,	99,	99,	99,	99,	99,	99,	99,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	15,	15,	15,	15,	15,	8,	8,	8,	8,	8,	8,	8,	15,	15,	15,	15,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99},
							   {99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	8,	8,	8,	8,	8,	99,	99,	99,	99,	99,	99,	99,	8,	8,	8,	8,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99,	99}
	};

	int pressS[10][73] = {{15, 15, 15, 99, 99, 15, 15, 15, 99, 99, 99, 15, 15, 15, 99, 99, 15, 15, 15, 99, 99, 99, 15, 15, 15, 99, 99, 15, 99, 99, 15, 15, 15, 99, 99, 15, 99, 15, 15, 15, 99, 99, 15, 15, 99, 99, 99, 15, 15, 15, 99, 99, 15, 15, 15, 99, 99, 99, 99, 15, 99, 99, 99, 99, 15, 15, 15, 99, 99, 99, 15, 15, 15},
						  {15, 99, 99, 15, 99, 15, 99, 99, 15, 99, 99, 15, 99, 99, 99, 15, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 99, 15, 99, 15, 99, 99, 99, 99, 99, 15, 99, 99, 15, 99, 99, 15, 99, 99, 15, 99, 15, 99, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 15, 99, 15, 99, 99, 99, 15, 99, 99, 15, 99, 99, 99, 15, 99},
						  {15, 99, 99, 15, 99, 15, 99, 99, 15, 99, 99, 15, 99, 99, 99, 15, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 99, 15, 99, 15, 99, 99, 99, 99, 99, 15, 99, 99, 15, 99, 99, 15, 99, 99, 15, 99, 15, 99, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 15, 99, 15, 99, 99, 99, 15, 99, 99, 15, 99, 99, 99, 15, 99},
						  {15, 99, 15, 99, 99, 15, 99, 15, 99, 99, 99, 15, 99, 99, 99, 15, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 99, 99, 99, 99, 15, 99, 99, 15, 99, 99, 15, 99, 15, 99, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 15, 99, 15, 99, 99, 99, 15, 99, 15, 99, 99, 99, 99, 15, 99},
						  {15, 15, 99, 99, 99, 15, 15, 99, 99, 99, 99, 15, 99, 99, 99, 15, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 99, 99, 99, 99, 15, 99, 99, 15, 99, 99, 15, 99, 15, 99, 99, 99, 99, 99, 99, 15, 99, 99, 99, 15, 99, 99, 99, 15, 99, 99, 15, 15, 99, 99, 99, 99, 99, 15, 99},
						  {15, 99, 99, 99, 99, 15, 99, 99, 99, 99, 99, 15, 15, 15, 99, 99, 15, 15, 15, 99, 99, 99, 15, 15, 15, 99, 99, 99, 99, 99, 15, 15, 15, 99, 99, 99, 99, 99, 15, 99, 99, 15, 99, 99, 15, 99, 99, 15, 15, 15, 99, 99, 99, 15, 99, 99, 99, 15, 15, 15, 15, 15, 99, 99, 15, 99, 99, 99, 99, 99, 99, 15, 99},
						  {15, 99, 99, 99, 99, 15, 15, 99, 99, 99, 99, 15, 99, 99, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 15, 99, 99, 15, 99, 99, 15, 99, 99, 99, 99, 99, 15, 99, 99, 15, 99, 99, 99, 15, 99, 99, 99, 15, 99, 99, 15, 15, 99, 99, 99, 99, 99, 15, 99},
						  {15, 99, 99, 99, 99, 15, 99, 15, 99, 99, 99, 15, 99, 99, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 15, 99, 99, 15, 99, 99, 15, 99, 99, 99, 99, 99, 15, 99, 99, 15, 99, 99, 15, 99, 99, 99, 99, 99, 15, 99, 15, 99, 15, 99, 99, 99, 99, 15, 99},
						  {15, 99, 99, 99, 99, 15, 99, 99, 15, 99, 99, 15, 99, 99, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 99, 99, 99, 15, 99, 99, 99, 99, 15, 99, 99, 15, 99, 99, 15, 99, 99, 99, 99, 99, 15, 99, 99, 15, 99, 99, 15, 99, 99, 99, 99, 99, 15, 99, 15, 99, 99, 15, 99, 99, 99, 15, 99},
						  {15, 99, 99, 99, 99, 15, 99, 99, 99, 15, 99, 15, 15, 15, 99, 99, 15, 15, 15, 99, 99, 99, 15, 15, 15, 99, 99, 99, 99, 99, 15, 15, 15, 99, 99, 99, 99, 99, 15, 99, 99, 99, 15, 15, 99, 99, 99, 15, 15, 15, 99, 99, 99, 15, 99, 99, 15, 99, 99, 99, 99, 99, 15, 99, 15, 99, 99, 99, 15, 99, 99, 15, 99}
						  };
public:
	StartScene();
	~StartScene();

	int* getColorLine(int row);
	int* getPressS(int row);
};
