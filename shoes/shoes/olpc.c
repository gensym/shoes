//
// shoes/olpc.c
// Shoes setup code specific to the Sugar graphical interface,
// which is used in the OLPC XO-1.
//

#include <ruby.h>

#include "shoes/app.h"
#include "shoes/internal.h"
#include "shoes/olpc.h"

static shoes_code
shoes_has_sugar_parameters(shoes_app *app);

shoes_code
shoes_sugar_setup(shoes_app *app)
{
  shoes_code code = SHOES_OK;

  if (!shoes_has_sugar_parameters(app))
    QUIT("Missing required Sugar parameters.", 0);
  
quit:
  return code;
}

shoes_code
shoes_has_sugar_parameters(shoes_app *app)
{
  return SHOES_FAIL;
}
