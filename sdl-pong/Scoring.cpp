#include "Scoring.h"

bool Scoring::getJustScored()
{
    return justScored;
}

void Scoring::setJustScored(bool value)
{
    justScored = value;
}

void Scoring::incrementScore(Scorer scorer)
{
    scores[scorer - 1]++;
}

int Scoring::getScore(Scorer scorer)
{
    return scores[scorer - 1];
}
