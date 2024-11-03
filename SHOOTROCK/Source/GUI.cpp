#include "GUI.h"


GUI::GUI()
{
	score = 0;
	m_combo = 0;
	showcombo = 0;
}

void GUI::ComboCounter(int scr)
{
	if (scr == 0)
	{
		m_combo = 40;
		showcombo = false;
	}
	m_combo = m_combo + scr*10;
	if (scr == 1)
	{
		score = score + m_combo;
		showcombo = true;
	}
	  
}




void GUI::Score()
{	
	DrawText(TextFormat("Score: %08i", score), 10, 10, 30, GRAY);
}


void GUI::ScoreForEndScreen()
{
	DrawText(TextFormat("Score: %08i", score), 200, 500, 50, RAYWHITE);
}
