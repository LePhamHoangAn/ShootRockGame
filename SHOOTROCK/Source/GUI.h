
#pragma once
#include "raylib.h"
#include <string>

class GUI
{
	int score;
public:
	int m_combo;
	bool showcombo;

	GUI();
	void ComboCounter(int scr);
	void Score();
	void ScoreForEndScreen();
};