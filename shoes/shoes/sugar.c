//
// shoes/sugar.c
// Shoes setup code specific to the Sugar graphical interface,
// which is used in the OLPC XO-1.
//

#include "sugar.h"
#include "sugar-window.h"
#include "sugar-dbus.h"

shoes_code
shoes_sugar_setup(shoes_app *app)
{
  shoes_app_gtk *gk = &app->os;
  shoes_code code = SHOES_OK;

  g_signal_connect(G_OBJECT(gk->window), "realize",
                   G_CALLBACK(shoes_sweeten_window), app);

  if (shoes_sugar_setup_dbus(app) != SHOES_OK)
    code = SHOES_FAIL;

  return code;
}

