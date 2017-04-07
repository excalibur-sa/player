#ifndef __MAMAN_BAR_H__
#define __MAMAN_BAR_H__

#include <glib-object.h>

#define MAMAN_TYPE_BAR                  (maman_bar_get_type ())
#define MAMAN_BAR(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), MAMAN_TYPE_BAR, MamanBar))
#define MAMAN_IS_BAR(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MAMAN_TYPE_BAR))
#define MAMAN_BAR_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), MAMAN_TYPE_BAR, MamanBarClass))
#define MAMAN_IS_BAR_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), MAMAN_TYPE_BAR))
#define MAMAN_BAR_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), MAMAN_TYPE_BAR, MamanBarClass))

typedef struct _MamanBar        MamanBar;
typedef struct _MamanBarClass   MamanBarClass;

struct _MamanBar
{
  GObject parent_instance;
};

struct _MamanBarClass
{
  GObjectClass parent_class;
};

GType maman_bar_get_type (void);

#endif /* __MAMAN_BAR_H__ */
