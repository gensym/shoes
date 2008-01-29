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
#include "shoes/sugar-window.h"

#ifndef SHOES_GTK
#error Must be building GTK+ Shoes to enable Sugar-specific functionality.
#endif

static shoes_code
shoes_get_sugar_parameters(char **bundle_id_buf, char **activity_id_buf);

gboolean
shoes_sweeten_window(GtkWidget *widget, gpointer user_data)
{
  GdkWindow *window = gtk_widget_get_root_window(widget);

  Display *xdisplay = GDK_WINDOW_XDISPLAY(window);
  Window xwindow = GDK_WINDOW_XID(window);

  char *bundle_id, *activity_id;
  gboolean retval = TRUE;

  if (shoes_get_sugar_parameters(&bundle_id, &activity_id) == SHOES_OK)
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

static shoes_code
shoes_get_sugar_parameters(char **bundle_id_buf, char **activity_id_buf)
{
  VALUE bundle_id = rb_eval_string("Shoes.sugar_bundle_id");
  VALUE activity_id = rb_eval_string("Shoes.sugar_activity_id");

  shoes_code code = SHOES_FAIL;

  if (bundle_id != Qnil && activity_id != Qnil)
  {
    *bundle_id_buf = rb_string_value_cstr(&bundle_id);
    *activity_id_buf = rb_string_value_cstr(&activity_id);
    code = SHOES_OK;
  }

  return code;
}

