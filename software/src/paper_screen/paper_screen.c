#include "paper_screen_internal.h"
#include "fontsepd.h"
#include <stdio.h>

#define MAX_X_SIZE_BYTE 9 
#define BITS_ON_BYTE 8
#define NUM_BIT_ON_PIX 2
#define NUM_PIX_ON_CELL 4 

static sFONT * pFont = &Font12;


uint8_t screen_paper_memory[3096] = {0};
void clear_paper_screen (void) {
	for (uint16_t num_cell = 0; num_cell < 3096; num_cell++){
		screen_paper_memory[num_cell] = 0xFF;
	}
}
void write_pixel (uint16_t x_value, uint16_t y_value, uint8_t color) {
	if (x_value >= 172 || y_value >= 72)
		return;

	uint16_t 
		num_byte = x_value * MAX_X_SIZE_BYTE * NUM_BIT_ON_PIX + y_value / NUM_PIX_ON_CELL,
		num_pos = y_value % NUM_PIX_ON_CELL;
	
	if (color == COLOR_BLACK)
		screen_paper_memory[num_byte] &= ~(0x3 << (6 - num_pos * NUM_BIT_ON_PIX));
	else
		screen_paper_memory[num_byte] |= (0x3 << (6 - num_pos * NUM_BIT_ON_PIX));
}

void draw_v_line (uint16_t x_value, uint16_t y_value, uint16_t length) {
	for (uint16_t shift = 0; shift < length; shift++) 
		write_pixel (x_value, y_value + shift, COLOR_BLACK);
}

void draw_h_line (uint16_t x_value, uint16_t y_value, uint16_t length) {
	for (uint16_t shift = 0; shift < length; shift++) 
		write_pixel (x_value + shift, y_value, COLOR_BLACK);
}

void draw_rectangle (uint16_t x_value, uint16_t y_value, uint16_t width, uint16_t height) {
	draw_h_line (x_value, y_value, width);
	draw_h_line (x_value, (y_value + height), (width + 1));

	draw_v_line (x_value, y_value, height);
	draw_v_line ((x_value + width), y_value, height);
}

#define PIX_COLOR(cell, num_pix) ((cell >> (6 - num_pix * 2)) & 0x3)
void draw_char (uint16_t x_value, uint16_t y_value, uint8_t ascii) {
  uint16_t
  	index = 0,  
  	width  = pFont->Width,
  	height = pFont->Height,
	data_length = height * width;

	ascii -= 32;
	uint8_t * ch = &pFont->table[ascii * data_length];

	for (uint16_t num_h_index = 0; num_h_index < width; num_h_index++)
		for (uint16_t num_v_index = 0; num_v_index < height; num_v_index++){
			for (uint16_t num_pix = 0; num_pix < NUM_PIX_ON_CELL; num_pix++){
				write_pixel(
					x_value + num_h_index,
					y_value + num_v_index * NUM_PIX_ON_CELL  + num_pix,
					PIX_COLOR(ch[index], num_pix)
				);
			}
			index++;
		}
} 

#define SCREEN_X_SIZE 172
#define CHAR_NOT_WITHOUT_FOR_SCREEN (((SCREEN_X_SIZE - (num_ch * pFont->Width)) & 0xFFFF) >= pFont->Width)
void draw_string  (uint16_t x_value, uint16_t y_value, uint8_t * text) {
	uint16_t 
		size = 0,
		num_ch = 0;
	uint8_t * ptr = text;
	while (*ptr++) size++;

	while ((*text != 0) &  CHAR_NOT_WITHOUT_FOR_SCREEN){
		draw_char(x_value, y_value, *text);
		x_value += pFont->Width;
		text++;
		num_ch++;
	}
}

void set_font (uint8_t font) {
	switch (font) {
		case 8: pFont = &Font8; break;
		case 12: pFont = &Font12; break;
		case 16: pFont = &Font16; break;
		case 20: pFont = &Font20; break;
		default: pFont = &Font12; break;
	}
}

void fill_rectangle (uint16_t x_value, uint16_t y_value, uint16_t width, uint16_t height, uint8_t color) {
	for (uint16_t num_v_line = 0; num_v_line < width; num_v_line++)
		for (uint16_t num_h_line = 0; num_h_line < height; num_h_line++){
			write_pixel(x_value + num_v_line, y_value + num_h_line, color);
		}
	
}