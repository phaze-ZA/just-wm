#ifndef WINMAN_H
#define WINMAN_H

#include "config.h"
#include <X11/Xlib.h>

Display *create_window_manager();

void move_window(Display *display);
void set_layout(enum LAYOUTS layout_id);
void register_keys(Display *display, int modifier_key);
void on_create_notify(const XCreateWindowEvent e, Display *display);
void on_key_press(const XKeyEvent e, Display *display);
void on_button_press(const XButtonEvent e, Display *display);

#endif // !WINMAN_H
