#include "unity_fixture.h"

#include "paper_screen_internal.h"

TEST_GROUP (paper_screen);

TEST_SETUP (paper_screen) {

}

TEST_TEAR_DOWN (paper_screen) {

}

TEST (paper_screen, start_here) {
	clear_paper_screen();
	// write_pixel(0, 72, 0x0);
	// write_pixel(0, 1, 0x3);
	// draw_v_line(100, 0 , 100);
	// draw_rectangle(0, 0, 71, 71);
	// draw_char(50, 50, 'X');
	uint8_t string[] = "V.1 memory display";
	draw_string(20, 50, string);
	// draw_h_line(0, 45 , 172);
	draw_rectangle(15, 45, 140, 20);
	save_and_open_image();
}


