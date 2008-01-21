//
// shoes/sugar.c
// Shoes setup code specific to the Sugar graphical interface,
// which is used in the OLPC XO-1.
//

#include "sugar.h"
#include "sugar-window.h"

shoes_code
shoes_sugar_setup(shoes_app *app)
{
  shoes_app_gtk *gk = &app->os;

  g_signal_connect(G_OBJECT(gk->window), "realize",
                   G_CALLBACK(shoes_sweeten_window), app);

  return SHOES_OK;
}

