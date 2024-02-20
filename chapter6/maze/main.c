#include <stdio.h>
#include <stdbool.h>
#include "mazelib.h"

pointT AdjacentPoint(pointT pt, directionT dir) {
    pointT newpt;

    newpt = pt;
    switch (dir) {
        case North:
            newpt.y++;
            break;
        case East:
            newpt.x++;
            break;
        case South:
            newpt.y--;
            break;
        case West:
            newpt.x--;
            break;
    }
    return newpt;
}

static bool SolveMaze(pointT pt);

/*
 * Function: SolveMaze
 * Usage: if (SolveMaze(pt)) ...
 * -----------------------------
 * This function attempts to generate a solution to the current
 * maze from point pt. SolveMaze returns TRUE if the maze has
 * a solution and FALSE otherwise. The implementation uses
 * recursion to solve the submazes that result from marking the
 * current square and moving one step along each open passage.
 */
static bool SolveMaze(pointT pt) {
    directionT dir;

    if (OutsideMaze(pt)) {
        return true;
    }
    if (IsMarked(pt)) {
        return false;
    }
    MarkSquare(pt);
    for (dir = North; dir <= West; dir++) {
        if (!WallExists(pt, dir)) {
            if (SolveMaze(AdjacentPoint(pt, dir))) {
                return true;
            }
        }
    }
    UnmarkSquare(pt);
    return false;

}

int main() {
    ReadMazeMap(MazeFile);
    if (SolveMaze(GetStartPosition())) {
        printf("The marked squares show a solution path.\n");
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}
