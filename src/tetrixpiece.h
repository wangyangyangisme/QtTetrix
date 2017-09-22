//
// Created by newcoderlife on 17-9-17.
//

#ifndef QTTETRIX_TETRIXPIECE_H
#define QTTETRIX_TETRIXPIECE_H

enum TetrixShape {
    NoShape, ZShape, SShape, LineShape, TShape, SquareShape, LShape, MirroredLShape
};

class TetrixPiece {
public:
    TetrixPiece() { setShape(NoShape); }

    void setRandomShape();

    void setShape(TetrixShape shape);

    TetrixShape shape() const { return pieceShape; }

    int getX(int index) const { return coords[index][0]; }

    int getY(int index) const { return coords[index][1]; }

    int minX() const;

    int maxX() const;

    int minY() const;

    int maxY() const;

    TetrixPiece rotatedLeft() const;

    TetrixPiece rotatedRight() const;

private:
    void setX(int index, int x) { coords[index][0] = x; }

    void setY(int index, int y) { coords[index][1] = y; }

    TetrixShape pieceShape;
    int coords[4][2];
};

#endif //QTTETRIX_TETRIXPIECE_H
