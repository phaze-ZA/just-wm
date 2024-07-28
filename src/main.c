#include "config.h"
#include "winman.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
const int MODIFIER = Mod4Mask;

int main(void) {
  Display *display;
  XWindowAttributes attributes;
  XButtonEvent start;

  // Try open X
  if (!(display = create_window_manager()))
    return 1;

  register_keys(display, MODIFIER);

  start.subwindow = None;

  for (;;) {
    XEvent ev;
    XNextEvent(display, &ev);

    switch (ev.type) {
    case CreateNotify:
      on_create_notify(ev.xcreatewindow, display);
      break;

    case KeyPress:
      on_key_press(ev.xkey, display);
      break;

    case ButtonPress:
      on_button_press(ev.xbutton, display);
      break;

    case MotionNotify:
      // on_motion_notify(ev, start.subwindow, display, attributes)
      break;
    default:
      printf("Unhandled event %d", ev.type);
    }

    if (ev.type == ButtonPress && ev.xbutton.subwindow != None) {
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
