#pragma once

enum Scorer { NONE, PLAYER, CPU };

class Scoring
{
private:
	bool justScored = false;
	int scores[2] = {0, 0};

public:
	bool getJustScored();
	void setJustScored(bool value);
	void incrementScore(Scorer scorer);
	int getScore(Scorer scorer);
};

