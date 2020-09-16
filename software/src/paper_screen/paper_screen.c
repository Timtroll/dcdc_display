#include "../../inc/paper_screen/paper_screen_internal.h"

void draw_main_screen (void) {
	clear_paper_screen();

	set_font(12);
	draw_string(48, 58, &"System info");

	draw_string(30, 1, &"type");
	draw_string(110, 1, &"Li-io");

	draw_string(10, 12, &"STR 1 type");
	draw_string(30, 23, &"STR 2");
	draw_string(30, 34, &"STR 3");
	draw_string(30, 45, &"STR 4");
	draw_string(110, 45, &"Li-io");

	//menu line
	draw_v_line(86, 0 , 57);
	draw_h_line(0, 13 , 172);
	draw_h_line(0, 24 , 172);
	draw_h_line(0, 35 , 172);
	draw_h_line(0, 46 , 172);
	draw_h_line(0, 57 , 172);

	//circuit
	draw_h_line(0, 0 , 172);
	draw_h_line(0, 71 , 172);
	draw_v_line(0, 0 , 72);
	draw_v_line(171, 0 , 72);
} 

void draw_menu_parametr_screen (void) {
	clear_paper_screen();

	set_font(16);
	draw_string(15, 50, &"<- CURRENT ->");
	draw_string(15, 25, &"1.000.000 A");


	set_font(12);
	draw_string(15, 11, &"Ni-cd: 5-10 A");
	draw_string(15, 1, &"Li-io: 8-12 A");

	//menu line
	draw_h_line(0, 24 , 172);
	draw_h_line(0, 48 , 172);

	//circuit
	draw_h_line(0, 0 , 172);
	draw_h_line(0, 71 , 172);
	draw_v_line(0, 0 , 72);
	draw_v_line(171, 0 , 72);
}