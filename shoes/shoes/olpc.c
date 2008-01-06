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
shoes_get_sugar_parameters(char *bundle_id_buf, char *activity_id_buf);

shoes_code
shoes_sugar_setup(shoes_app *app)
{
  shoes_code code = SHOES_OK;
  char* bundle_id;
  char* activity_id;
  
  if (shoes_get_sugar_parameters(bundle_id, activity_id) != SHOES_OK)
    code = SHOES_FAIL;

quit:
  return code;
}

shoes_code
shoes_get_sugar_parameters(char *bundle_id_buf, char *activity_id_buf)
{
  VALUE bundle_id = rb_eval_string("Shoes.sugar_bundle_id");
  VALUE activity_id = rb_eval_string("Shoes.sugar_activity_id");
  shoes_code code = SHOES_FAIL;

  if (bundle_id != Qnil && activity_id != Qnil)
  {
    bundle_id_buf = rb_string_value_cstr(&bundle_id);
    activity_id_buf = rb_string_value_cstr(&activity_id);
    code = SHOES_OK;
  }

  return code;
}
