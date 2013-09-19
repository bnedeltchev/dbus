#include <stdlib.h>
#include <unistd.h>
#include <glib.h>
#include <glib-object.h>

#include <dbus/dbus.h>
#include <dbus/dbus-glib.h>

#include "server.h"

#include "binding_server.h"

G_DEFINE_TYPE(TobiObj, tobi_object, G_TYPE_OBJECT);

static void tobi_object_class_init(TobiObjClass *_class) 
{
     /* code */
}
 
static void tobi_object_init(TobiObj* obj)
{
     /* code */
}


GObject* tobi_object_new(void)
{
     return g_object_new(MY_TYPE_OBJECT , 0);
}

gboolean tibo_many_args(GObject * instance, unsigned x, char* str, double trouble, double* d_ret, char** str_ret, GError ** tiberror)
{

	g_print ("  %s: I was called with the following parameter(s):%d\n", __FUNCTION__, x);
	return (TRUE);
}


int
main (int argc, char **argv)
{
  DBusGConnection *connection;
  GError *error;
  GObject* totor= tobi_object_new();

  g_type_init ();


  error = NULL;
  connection = dbus_g_bus_get (DBUS_BUS_SESSION,
                               &error);
  if (connection == NULL)
    {
      g_printerr ("Failed to open connection to bus: %s\n",
                  error->message);
      g_error_free (error);
      exit (1);
    }


	//dbus_g_object_type_install_info (G_TYPE_UINT, &dbus_glib_tibo_object_info);  
	dbus_g_connection_register_g_object (connection,
                                               "/com/foo/MyObject",
                                               totor); 
	while (1)
	{
		g_print ("  %s: sleeping\n", __FUNCTION__);
		sleep(1);
	}
	return 0;
}	


/*

     The function must return a value of type gboolean; TRUE on success, and FALSE otherwise.

    The first parameter is a pointer to an instance of the object.

    Following the object instance pointer are the method input values.

    Following the input values are pointers to return values.

    The final parameter must be a GError **. If the function returns FALSE for an error, the error parameter must be initalized with g_set_error. 

Finally, you can export an object using dbus_g_connection_register_g_object. For example:

	  dbus_g_connection_register_g_object (connection,
                                               "/com/foo/MyObject",
                                               obj);
      */
