#include "config.h"
#include <X11/X.h>
#include <X11/Xlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void set_layout(enum LAYOUTS layout_id) {
  // set layout
}

void moveWindow(Display *display) {
  // move window
}

void register_keys(Display *display, int modifier_key) {
  XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("F1")), modifier_key,
           DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync);

  XGrabButton(display, 1, modifier_key, DefaultRootWindow(display), True,
              ButtonPressMask | ButtonReleaseMask | PointerMotionMask,
              GrabModeAsync, GrabModeAsync, None, None);

  XGrabButton(display, 3, modifier_key, DefaultRootWindow(display), True,
              ButtonPressMask | ButtonReleaseMask | PointerMotionMask,
              GrabModeAsync, GrabModeAsync, None, None);
}

int main(void) {
  Display *display;
  XWindowAttributes attributes;
  XButtonEvent start;
  XEvent ev;

  // Try open X
  if (!(display = XOpenDisplay(0x0)))
    return 1;

  start.subwindow = None;

  for (;;) {
    XNextEvent(display, &ev);
    if (ev.type == KeyPress && ev.xkey.subwindow != None)
      XRaiseWindow(display, ev.xkey.subwindow);
    else if (ev.type == ButtonPress && ev.xbutton.subwindow != None) {
      XGetWindowAttributes(display, ev.xbutton.subwindow, &attributes);
      start = ev.xbutton;
    } else if (ev.type == MotionNotify && start.subwindow != None) {
      int xdiff = ev.xbutton.x_root - start.x_root;
      int ydiff = ev.xbutton.y_root - start.y_root;
      XMoveResizeWindow(
          display, start.subwindow,
          attributes.x + (start.button == 1 ? xdiff : 0),
          attributes.y + (start.button == 1 ? ydiff : 0),
          MAX(1, attributes.width + (start.button == 3 ? xdiff : 0)),
          MAX(1, attributes.height + (start.button == 3 ? ydiff : 0)));
    } else if (ev.type == ButtonRelease)
      start.subwindow = None;
  }

  return 0;
}
