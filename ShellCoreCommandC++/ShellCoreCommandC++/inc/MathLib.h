#pragma once

//CMath is... slow... (and also other math things i wanted to add)
class MathLib {
public: 
	//tau constatnt or 2 pi
	static long double TAU() {
		return 6.283185307179586476925;
	}
	//pi constant
	static long double PI() {
		return 3.141592653589793238463;
	}
	static int floor(int x)
	{
		return (int)x - (x < (int)x);
	}
	static int grid(int x, int grid)
	{
		return floor(x / grid) * grid;
	}
};