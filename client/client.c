#include <stdlib.h>
#include <unistd.h>
#include <glib.h>
#include <glib-object.h>

#include <dbus/dbus.h>
#include <dbus/dbus-glib.h>


#include "binding_client.h"





int
main (int argc, char **argv)
{
  DBusGConnection *connection;
  GError *error;
  DBusGProxy *proxy;
  gdouble tibor; // It could have been tibère
  char *babouche;
  
  g_type_init ();

  error = NULL;
  connection = dbus_g_bus_get (DBUS_BUS_SESSION,
                               &error);
  if (connection == NULL)
    {
      g_printerr ("Failed opening connection to this bus: %s\n",
                  error->message);
      g_error_free (error);
      exit (1);
    }

  /* Create a proxy object for the "bus driver" (name "org.freedesktop.DBus") */
  
  proxy = dbus_g_proxy_new_for_name (connection,
                                     DBUS_SERVICE_DBUS,
                                     "/com/example/MyObject",
                                     DBUS_INTERFACE_DBUS);
/*

  proxy = dbus_g_proxy_new_for_name (connection,
                                     DBUS_SERVICE_DBUS,
                                     DBUS_PATH_DBUS,
                                     DBUS_INTERFACE_DBUS);
*/


	int i=0;
	gboolean result;
/*	
	gboolean
com_example_MyObject_many_args (DBusGProxy *proxy, const guint IN_x, const char * IN_str, const gdouble IN_trouble, gdouble* OUT_d_ret, char ** OUT_str_ret, GError **error)
*/
	while (1)
	{
		g_print ("  %s: calling tibo\n", __FUNCTION__);
		result = com_example_MyObject_many_args(proxy, i, "tito", 2.0f, &tibor, &babouche, &error);
		if (result == FALSE)
		{
      			g_printerr ("DUDE: %s\n",
                  		error->message);
		}
		
		i++;
		sleep(1);
	}
	return 0;
}	



