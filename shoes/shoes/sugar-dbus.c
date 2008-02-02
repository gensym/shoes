//
// shoes/sugar-dbus.c
// Shoes setup code specific to the Sugar graphical interface,
// which is used in the OLPC XO-1.
//
// This file contains code necessary to establish a DBus service
// for Sugar interprocess communication.
//
#include <glib.h>
#include <dbus/dbus.h>
#include <dbus/dbus-glib.h>

#include "shoes/sugar-ruby.h"
#include "shoes/sugar-dbus.h"

static DBusHandlerResult
shoes_sugar_dbus_filter(DBusConnection *connection, DBusMessage *message, void *user_data);

shoes_code
shoes_sugar_setup_dbus(shoes_app *app)
{
  DBusError error;
  DBusConnection *bus;

  dbus_error_init(&error);
  bus = dbus_bus_get(DBUS_BUS_SESSION, &error);

  if (!bus) {
    dbus_error_free(&error);
    return SHOES_FAIL;
  }

  dbus_bus_add_match(bus, "type='signal',interface='org.laptop.Activity'", NULL);
  dbus_connection_add_filter(bus, shoes_sugar_dbus_filter, NULL, NULL);

  return SHOES_OK;
}

static DBusHandlerResult
shoes_sugar_dbus_filter(DBusConnection *connection, DBusMessage *message, void *user_data)
{
  printf("connection=%p, message=%p\n", connection, message);
  return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
}
