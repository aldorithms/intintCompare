#pragma once
class intintCompare
{
public:
	static bool lt(int x, int y) { return x < y; }
	static bool eq(int x, int y) { return x == y; }
	static bool gt(int x, int y) { return x > y; }
};

