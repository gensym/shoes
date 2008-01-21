//
// shoes/sugar-window.h
// Shoes setup code specific to the Sugar graphical interface,
// which is used in the OLPC XO-1.
//
// This file contains code necessary to set up an X11 window
// for Sugar.
//

#ifndef SHOES_SUGAR_WINDOW_H
#define SHOES_SUGAR_WINDOW_H

#include <glib.h>
#include "shoes/code.h"

gboolean shoes_sweeten_window(GtkWidget *widget, gpointer user_data);

#endif
