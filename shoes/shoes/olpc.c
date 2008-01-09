//
// shoes/olpc.c
// Shoes setup code specific to the Sugar graphical interface,
// which is used in the OLPC XO-1.
//

#include <ruby.h>

#include "shoes/app.h"
#include "shoes/internal.h"
#include "shoes/olpc.h"

#ifndef SHOES_GTK
#error Must be building GTK+ Shoes to enable Sugar-specific functionality.
#endif

static shoes_code
shoes_get_sugar_parameters(char *bundle_id_buf, char *activity_id_buf);
static shoes_code
shoes_attach_sugar_signals(shoes_app *app, char const *bundle_id, char const *activity_id);
static gboolean
shoes_sweeten_window(GtkWidget *widget, gpointer user_data);

shoes_code
shoes_sugar_setup(shoes_app *app)
{
  shoes_code code = SHOES_OK;
  char* bundle_id;
  char* activity_id;
  
  if (shoes_get_sugar_parameters(bundle_id, activity_id) != SHOES_OK)
    code = SHOES_FAIL;
  else
    shoes_attach_sugar_signals(app, bundle_id, activity_id);

  return code;
}

static shoes_code
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

static shoes_code
shoes_attach_sugar_signals(shoes_app *app, char const *bundle_id, char const *activity_id)
{
  shoes_app_gtk *gk = &app->os;

  g_signal_connect(G_OBJECT(gk->window), "realize",
                   G_CALLBACK(shoes_sweeten_window), app);

  return SHOES_OK;
}

static gboolean
shoes_sweeten_window(GtkWidget *widget, gpointer user_data)
{
  g_log(NULL, G_LOG_LEVEL_DEBUG, "sweetening!");
  return TRUE;
}
