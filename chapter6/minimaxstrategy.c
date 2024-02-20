moveT FindBestMove(stateT state, int depth, int *pRating);
int EvaluatePosition(stateT state, int depth);

moveT FindBestMove(stateT state, int depth, int *pRating) {
    moveT moveArray[MaxMoves], move, bestMove;
    int i, nMovves, rating, minRating;

    nMoves = GenerateMoveList(state, moveArray);  // GenerateMoveList 每个 game 有自己的实现
    if (nMoves == 0) {
        Error("No move available.");
    }
    minRating = WinningPosition + 1;
    for (i = 0; i < nMovves && minRating != LosingPosition; i++) {
        move = moveArray[i];
        MakeMove(state, move);
        rating = EvaluatePosition(state, depth + 1);
        if (rating < minRating) {
            bestMove = move;
            minRating = rating;
        }
        RetractMove(state, move);
    }
    *pRating = -minRating;
    return bestMove;
}

int EvaluatePosition(stateT state, int depth) {
    int rating;

    if (GameIsOver(state) || depth >= MaxDepth) {
        return EvaluatePosition(state);
    }
    FindBestMove(state, depth, &rating);
    return rating;
}