#include "paper_screen_internal.h"
#include "paper_screen.h"
#include <stdio.h>
#include <stdint.h>

uint8_t screen_paper_bytes[1548] = {0};

// #define PIXEL_COLOR_WHITE (num_pixel, num_cell) (((COLOR_WHITE << (6 - (num_pixel % 4) * 2)) & screen_paper_memory[num_cell * 2 + 0]))
// #define PIXEL_STATE(num_pixel, num_cell) ((PIXEL_COLOR_WHITE(num_pixel, num_cell) ? 0 : 1) << num_pixel)


#define PIXEL_STATE(num_pixel, num_byte_cell, num_memory_cell) \
	((((COLOR_WHITE << (6 - (num_pixel % 4) * 2)) & screen_paper_memory[num_byte_cell * 2 + num_memory_cell]) ? 0 : 1) << num_pixel)


void save_and_open_image (void) {
	char name_file [] = "paper_screen_file.xbm";
	FILE * paper_screen = fopen (name_file, "w");
	if (paper_screen == NULL){
		printf("File not open\n");
		return;
	}
	printf("%d\n", *screen_paper_memory);
	for (uint16_t num_cell = 0; num_cell < 1548; num_cell++){
		screen_paper_bytes[num_cell] |= 
			PIXEL_STATE(0, num_cell, 0) | PIXEL_STATE(1, num_cell, 0) | 
			PIXEL_STATE(2, num_cell, 0) | PIXEL_STATE(3, num_cell, 0) | 
			PIXEL_STATE(4, num_cell, 1) | PIXEL_STATE(5, num_cell, 1) | 
			PIXEL_STATE(6, num_cell, 1) | PIXEL_STATE(7, num_cell, 1)
		;
		
	}

	fprintf(paper_screen, "#define screen_paper_width 72\n" );
	fprintf(paper_screen, "#define screen_paper_height 172\n" );
	fprintf(paper_screen, "static char screen_paper_bits[] = {\n" );

	for (uint16_t num_cell = 0; num_cell < 1548; num_cell++) {
		fprintf(paper_screen, "%#x ,", screen_paper_bytes[num_cell]);
	}
	fprintf(paper_screen, "\n};" );
	fclose(paper_screen);
	system("start paper_screen_file.xbm");
}
