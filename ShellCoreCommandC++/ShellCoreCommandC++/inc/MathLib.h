#pragma once

//CMath is... slow... (and also other math things i wanted to add)
class MathLib {
public: 
	static int floor(int x)
	{
		return (int)x - (x < (int)x);
	}
	static int grid(int x, int grid)
	{
		return floor(x / grid) * grid;
	}
};