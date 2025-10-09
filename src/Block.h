#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <map>
#include "Position.h"
#include "Colors.h"

class Block
{
public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int columns);
    std::vector<Position> GetCellPositions();
    void Rotate();
    void UndoRotation();
    int id;
    std::map<int, std::vector<Position>> cells;
    std::vector<Color> colors;
    void SetNewColors(std::vector<Color> newColors);


private:
    int cellSize;
    int rotationState;
    int rowOffset;
    int columnOffset;
};

#endif