//
// shoes/sugar-dbus.h
// Shoes setup code specific to the Sugar graphical interface,
// which is used in the OLPC XO-1.
//
// This file contains code necessary to establish a DBus service
// for Sugar interprocess communication.
//
#ifndef SHOES_SUGAR_DBUS_H
#define SHOES_SUGAR_DBUS_H

#include "shoes/app.h"
#include "shoes/code.h"

shoes_code shoes_sugar_setup_dbus(shoes_app *app);

#endif
