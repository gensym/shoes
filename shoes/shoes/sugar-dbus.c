//
// shoes/sugar-dbus.c
// Shoes setup code specific to the Sugar graphical interface,
// which is used in the OLPC XO-1.
//
// This file contains code necessary to establish a DBus service
// for Sugar interprocess communication.
//
#include "shoes/sugar-dbus.h"

#include <glib.h>
#include <dbus/dbus-glib.h>

shoes_code
shoes_sugar_setup_dbus(shoes_app *app)
{
  return SHOES_OK;
}
