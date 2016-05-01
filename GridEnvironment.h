#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <utility>
#include <cstdint>

enum GridAction { up, down, left, right, up_left, up_right, down_left, down_right };

class GridState
{
public:
	GridState(uint32_t x, uint32_t y) : x(x), y(y) {}
	uint32_t x = 0, y = 0;
};

inline bool operator==(const GridState& lhs, const GridState& rhs)
{
	return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}

class GridEnvironment
{
public:
	GridEnvironment(std::string filename);
	~GridEnvironment();
	void GetActions(GridState &s, std::vector<GridAction> &actions);
	void ApplyAction(GridState &s, GridAction a);
	void UndoAction(GridState &s, GridAction a);
private:
	uint32_t width, height;
	std::vector<bool> grid;
};
