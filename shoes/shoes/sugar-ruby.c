//
// shoes/sugar-ruby.c
// Shoes setup code specific to the Sugar graphical interface,
// which is used in the OLPC XO-1.
//
// This file contains code to read and write Sugar-specific data
// from/to the Ruby environment.
//

#include "shoes/app.h"
#include "shoes/config.h"
#include "shoes/sugar-ruby.h"

ID s_sugar_activity_id = Qnil;
ID s_sugar_bundle_id = Qnil;

static char const*
shoes_get_sugar_attribute(ID id);

void
shoes_intern_sugar_symbols()
{
  s_sugar_activity_id = rb_intern("sugar_activity_id");
  s_sugar_bundle_id = rb_intern("sugar_bundle_id");
}

char const*
shoes_get_sugar_activity_id()
{
  return shoes_get_sugar_attribute(s_sugar_activity_id);
}

char const*
shoes_get_sugar_bundle_id()
{
  return shoes_get_sugar_attribute(s_sugar_bundle_id);
}

static char const*
shoes_get_sugar_attribute(ID id)
{
  if (id != Qnil)
  {
    VALUE result = rb_funcall(cShoes, id, 0);
    if (TYPE(result) == T_STRING) 
      return StringValuePtr(result);
  } 
  return NULL;
}
