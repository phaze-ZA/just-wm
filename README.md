# just-wm
A window manager that is Just a Window Manager. Supports configuring layouts and default window state (i.e. docked/floating). If you want a status bar/theme/autostart apps/keybindings use the provided means to do so (xinitrc, polybar, xbindkeys, etc). The idea behind this window manager is to keep it lightweight and simple.

You like windows to start docked? You can have this
You like windows to start floating and drag them to specific area? You can have this
Want to expand a window size the way those Windows weebs do? Cool this is possible as well
Maybe you prefer holding GUI and then dragging the window edge? This is possible

I will try to keep the config short and sweet. I'll probably use ini format for config.

Feel free to fork this repo at any point.
Once zig gets its first official release I would like to convert this to a zig project. Not doing so now because I'd prefer to wait for the language to become more stable.

Default Layouts:
* Monocle
* Split Monocle
* Fibonnaci
* Main and Vertical Stack
* Main and Horizontal Stack
* Stack

Tags/workspaces by default will start with one. If you want more than one, config that or setup keybinding to add a new one. Can configure this to be saved on restart so that you don't have to keep adding new ones.
