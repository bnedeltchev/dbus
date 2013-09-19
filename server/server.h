
typedef struct _TobiObj TobiObj;
typedef struct _TobiObjClass TobiObjClass;
 
struct _TobiObj
{
  GObject parent_instance;
 
};
 
struct _TobiObjClass
{
  GObjectClass parent_class;
 
};

#define MY_TYPE_OBJECT                   (my_object_get_type ())
#define MY_OBJECT(obj)                   (G_TYPE_CHECK_INSTANCE_CAST ((obj), MY_TYPE_OBJECT, TobiObj))
#define MY_IS_OBJECT(obj)                (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MY_TYPE_OBJECT))
#define MY_OBJECT_CLASS(_class)          (G_TYPE_CHECK_CLASS_CAST ((_class), MY_TYPE_OBJECT, TobiObjClass))
#define MY_IS_OBJECT_CLASS(_class)       (G_TYPE_CHECK_CLASS_TYPE ((_class), MY_TYPE_OBJECT))
#define MY_OBJECT_GET_CLASS(obj)         (G_TYPE_INSTANCE_GET_CLASS ((obj), MY_TYPE_OBJECT, TobiObjClass))


gboolean tibo_many_args(GObject * instance, unsigned x, char* str, double trouble, double* d_ret, char** str_ret, GError ** tiberror);

