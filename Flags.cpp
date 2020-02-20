#include <stdio.h>
#include <stdlib.h>
#include "SwinGame.h"
#include <stdbool.h>


int btn_w = 100;
int btn_h =  25;
int index = 0;

void draw_button(color clr, float x, float y, int btnWidth, int btnHeight)
	{
		fill_rectangle(clr, x, y, btnWidth, btnHeight);
	}



bool btn_clicked(int x_value, int y_value,int btn_width, int  btn_height)
{
	float right_value;
	float bottom_value;

	right_value = x_value + btn_width;

	bottom_value = y_value + btn_height;

	if (mouse_clicked(LEFT_BUTTON))
	{
		if ((mouse_x() >= x_value) && (mouse_x() <= right_value) && (mouse_y() >= y_value) && (mouse_y() <= bottom_value))
			return true;
	}
	else 
		return false;
}
void showDrawings ()
	{
		switch(index)
		{
			case 0:
			fill_rectangle(ColorGreen, 350, 150, 200,50);
			fill_rectangle(ColorWhite, 350, 200, 200,50);
			fill_rectangle(ColorBlack, 350, 250, 200,50);
			fill_rectangle(ColorRed, 300, 150, 50,150);
			break;
			case 1:
			fill_rectangle(ColorBlack, 350, 150, 200,50);
			fill_rectangle(ColorRed, 350, 200, 200,50);
			fill_rectangle(ColorGold, 350, 250, 200,50);
			break;
			default:
			break;
	}
}

	int main()
	{
		open_graphics_window("Show Drawings",800,600);
		clear_screen (ColorWhite);

		do{
			clear_screen(ColorWhite);
			draw_button(ColorBlack, 0, 300, btn_w, btn_h);
			draw_text("Previous",ColorWhite,"arial.ttf",20,0,300);
			draw_button(ColorBlack,800-btn_w,300, btn_w, btn_h);
			draw_text("Next",ColorWhite,"arial.ttf",20,800-btn_w,300);
			if (btn_clicked(0,300, btn_w, btn_h) == true && index>0)
			
			{
				index--;
			}else if (btn_clicked (800 - btn_w, 300, btn_w, btn_h)== true && index<1)
			{
				index++;
			}

			showDrawings();
			process_events();
			refresh_screen(60);
		} while (!(window_close_requested()));
	}