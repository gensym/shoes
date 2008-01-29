//
// shoes/sugar-window.c
// Shoes setup code specific to the Sugar graphical interface,
// which is used in the OLPC XO-1.
//
// This file contains code necessary to set up an X11 window
// for Sugar.
//

#include <ruby.h>
#include <X11/Xlib.h>
#include <X11/X.h>

#include "shoes/app.h"
#include "shoes/internal.h"
#include "shoes/sugar-ruby.h"
#include "shoes/sugar-window.h"

#ifndef SHOES_GTK
#error Must be building GTK+ Shoes to enable Sugar-specific functionality.
#endif

gboolean
shoes_sweeten_window(GtkWidget *widget, gpointer user_data)
{
  GdkWindow *window = gtk_widget_get_root_window(widget);

  Display *xdisplay = GDK_WINDOW_XDISPLAY(window);
  Window xwindow = GDK_WINDOW_XID(window);

  char *bundle_id, *activity_id;
  gboolean retval = TRUE;

  bundle_id = shoes_get_sugar_bundle_id();
  activity_id = shoes_get_sugar_activity_id();

  if (bundle_id != NULL && activity_id != NULL)
  {
    XChangeProperty(
      xdisplay,
      xwindow, 
      XInternAtom(xdisplay, "_SUGAR_BUNDLE_ID", 0),
      XInternAtom(xdisplay, "STRING", 0),
      8,
      PropModeReplace,
      (unsigned char *)bundle_id,
      strlen(bundle_id));
  
    XChangeProperty(
      xdisplay,
      xwindow,
      XInternAtom(xdisplay, "_SUGAR_ACTIVITY_ID", 0),
      XInternAtom(xdisplay, "STRING", 0),
      8,
      PropModeReplace,
      (unsigned char *)activity_id,
      strlen(activity_id));
  }
  else
  {
    retval = FALSE;
  }

  return retval;
}
