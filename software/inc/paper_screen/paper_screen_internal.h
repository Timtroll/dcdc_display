#ifndef _PAPER_SCREEN_INTERNAL_H_
#define _PAPER_SCREEN_INTERNAL_H_

#include "paper_screen.h"
#include <stdint.h>

// #define EPD_TESTS

#define COLOR_BLACK 0x00
// #define COLOR_DARKGRAY 0x1
// #define COLOR_LIGHTGRAY 0x2
#define COLOR_WHITE 0x3


extern uint8_t screen_paper_memory[3096];

void write_pixel (uint16_t x_value, uint16_t y_value, uint8_t color);
void draw_v_line (uint16_t x_value, uint16_t y_value, uint16_t length);
void draw_h_line (uint16_t x_value, uint16_t y_value, uint16_t length);
void draw_rectangle (uint16_t x_value, uint16_t y_value, uint16_t width, uint16_t height);
void fill_rectangle (uint16_t x_value, uint16_t y_value, uint16_t width, uint16_t height, uint8_t color);
void clear_paper_screen (void);
void draw_char (uint16_t x_value, uint16_t y_value, uint8_t ascii);
void draw_string  (uint16_t x_value, uint16_t y_value, uint8_t * text);
void set_font (uint8_t font);
void display_screen (void);

#endif//_PAPER_SCREEN_INTERNAL_H_

