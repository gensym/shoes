//
// shoes/sugar-ruby.h
// Shoes setup code specific to the Sugar graphical interface,
// which is used in the OLPC XO-1.
//
// This file contains code to read and write Sugar-specific data
// from/to the Ruby environment.
//

#ifndef SHOES_SUGAR_RUBY_H
#define SHOES_SUGAR_RUBY_H

#include "shoes/ruby.h"
#include "shoes/code.h"
#include "shoes/world.h"

void shoes_intern_sugar_symbols();
char const *shoes_get_sugar_activity_id();
char const *shoes_get_sugar_bundle_id();

#endif
