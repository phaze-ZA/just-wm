#include "winman.h"
#include <X11/Xlib.h>
#include <stdio.h>

Display *create_window_manager() {
  Display *display = XOpenDisplay(0x0);

  if (display == 0x0) {
    printf("CANNOT OPEN X DISPLAY");
  }

  return display;
}

void set_layout(enum LAYOUTS layout_id) {
  // set layout
}

void moveWindow(Display *display) {
  // move window
}

void register_keys(Display *display, int modifier_key) {
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("F1")),
           modifier_key, DefaultRootWindow(display), True, GrabModeAsync,
           GrabModeAsync);

  // MouseButton: 1
  XGrabButton(display, 1, modifier_key, DefaultRootWindow(display), True,
              ButtonPressMask | ButtonReleaseMask | PointerMotionMask,
              GrabModeAsync, GrabModeAsync, None, None);

  // MouseButton: 3
  XGrabButton(display, 3, modifier_key, DefaultRootWindow(display), True,
              ButtonPressMask | ButtonReleaseMask | PointerMotionMask,
              GrabModeAsync, GrabModeAsync, None, None);
}

void on_create_notify(const XCreateWindowEvent e, Display *display) {}

// For Keyboard
void on_key_press(const XKeyEvent e, Display *display) {
  if (e.subwindow != None)
    XRaiseWindow(display, e.subwindow);
}

// For Mouse
void on_button_press(const XButtonEvent e, Display *display) {
  XButtonEvent start;
  XWindowAttributes attributes;
  if (e.subwindow != None) {
    XGetWindowAttributes(display, e.subwindow, &attributes);
    start = e;
  }
}
