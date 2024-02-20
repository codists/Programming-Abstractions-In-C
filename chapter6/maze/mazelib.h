//
// Created by codists on 2023/12/18.
//
#include "strlib.h"
/*
 * File: mazelib.h
 * ---------------
 * This interface provides a library of primitive operations
 * to simplify the solution to the maze problem.
 */

#ifndef _mazelib_h
#define _mazelib_h

/*
 * Type: pointT
 * ------------
 * The type pointT is used to encapsulate a pair of integer
 * coordinate into a single value with x and y components.
 */

typedef struct {
    int x, y;
} pointT;

/*
 * Type: directionT
 * ----------------
 * This type is used to represent the four compass directions.
 */
typedef enum {
    North, East, South, West
} directionT;
//typedef enum {
//    Jan, Feb, Mar, Apr, May, Jun, Jul,
//    Aug, Sep, Oct, Nov, Dec
//} year;

/*
 * Function: ReadMazeMap
 * Usage: ReadMazeMapZ(filename)
 * -----------------------------
 * This function reads in a map of the maze from the specified
 * file and stores it in private data structures maintained by
 * this module. In the data file, the characters '+', '-', and
 * '|'represent corners, horizontal walls, and vertical walls,
 * respectively; spaces represent open passageway squares. The
 * starting position is indicated by the character 'S'. For
 * example, the following dta file defines a simple maze:
 * +-+-+-+-+-+
 * |     |
 * + +-+ + +-+
 * |S  |     |
 * +-+-+-+-+-+
 * Coordinates are numbered starting at (0,0) in the lower left.
 */
void ReadMazeMap(string filename);


/*
 * Function: GetStartPosition
 * Usage: pt = GetStartPosition();
 * -------------------------------
 * This function returns a pointT indicating the coordinates of
 * the start square;
 */
pointT GetStartPosition(void);

/*
 * Function: OutsideMaze
 * Usage: if (OutsideMaze(pt)) ...
 * -------------------------------
 * This function returns TRUE if the specified point is outside
 * the boundary of the maze.
 */
bool OutsideMaze(pointT pt);

/*
 * Function: WallExists
 * Usage: if (WallExists(pt, dir)) ...
 * -------------------------------
 * This function returns TRUE if there is a wall in the indicated
 * direction from the square at position pt.
 *
 */
bool WallExists(pointT pt, directionT dir);


/*
 * Function: MarkSquare, UnmarkSquare, IsMarked
 * Usage: MarkSquare(pt);
 *        UnmarkSquare(pt);
 *        if (IsMarked(pt)); ...
 * -------------------------------
 * These functions mark, unmark, and test the status of the
 * square specified by the coordinates pt.
 *
 */
void MarkSquare(pointT pt);

void UnmarkSquare(pointT pt);

bool IsMarked(pointT pt);

#endif


















