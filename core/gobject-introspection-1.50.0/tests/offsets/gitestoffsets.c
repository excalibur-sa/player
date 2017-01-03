 /* GENERATED FILE. DO NOT EDIT. See gen-gitestoffsets */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <glib.h>
#include <girepository.h>
#include "offsets.h"

static GIRepository *repository;
static const char *namespace = "Offsets";
static const char *version = "1.0";

static void
print_field_offset(FILE         *outfile,
                   GIStructInfo *struct_info,
                   const gchar  *name)
{
   gint i;
   gint n_fields = g_struct_info_get_n_fields (struct_info);
   for (i = 0; i < n_fields; i++)
     {
       GIFieldInfo *field_info = g_struct_info_get_field (struct_info, i);
       const char *field_name = g_base_info_get_name ((GIBaseInfo *)field_info);
       if (strcmp (field_name, name) == 0)
         {
           fprintf (outfile, "%s %d\n", name, g_field_info_get_offset (field_info));
           g_base_info_unref ((GIBaseInfo *)field_info);
           return;
         }

       g_base_info_unref ((GIBaseInfo *)field_info);
     }

   g_error("Can't find field '%s.%s' in introspection information",
           g_base_info_get_name ((GIBaseInfo *)struct_info), name);
}

typedef struct {
   char dummy;
   OffsetsArray struct_;
} AlignOffsetsArray;

static void
compiled_OffsetsArray (FILE *outfile)
{
  fprintf (outfile, "OffsetsArray: size=%" G_GSIZE_FORMAT ", alignment=%ld\n",
           sizeof(OffsetsArray),
           G_STRUCT_OFFSET(AlignOffsetsArray, struct_));

  fprintf (outfile, "%s %ld\n", "some_ints", G_STRUCT_OFFSET(OffsetsArray, some_ints));
  fprintf (outfile, "%s %ld\n", "some_int8s", G_STRUCT_OFFSET(OffsetsArray, some_int8s));
  fprintf (outfile, "%s %ld\n", "some_doubles", G_STRUCT_OFFSET(OffsetsArray, some_doubles));
  fprintf (outfile, "%s %ld\n", "some_enum", G_STRUCT_OFFSET(OffsetsArray, some_enum));
  fprintf (outfile, "%s %ld\n", "some_ptrs", G_STRUCT_OFFSET(OffsetsArray, some_ptrs));

  fprintf (outfile, "\n");
}

static void
introspected_OffsetsArray (FILE *outfile)
{
  GIStructInfo *struct_info = (GIStructInfo *)g_irepository_find_by_name(repository, namespace,
                                                                         "Array");
  if (!struct_info)
     g_error ("Can't find GIStructInfo for 'OffsetsArray'");

  fprintf (outfile, "OffsetsArray: size=%" G_GSIZE_FORMAT ", alignment=%" G_GSIZE_FORMAT "\n",
           g_struct_info_get_size (struct_info),
           g_struct_info_get_alignment (struct_info));

  print_field_offset(outfile, struct_info, "some_ints");
  print_field_offset(outfile, struct_info, "some_int8s");
  print_field_offset(outfile, struct_info, "some_doubles");
  print_field_offset(outfile, struct_info, "some_enum");
  print_field_offset(outfile, struct_info, "some_ptrs");

  fprintf (outfile, "\n");

  g_base_info_unref ((GIBaseInfo *)struct_info);
}
typedef struct {
   char dummy;
   OffsetsBasic struct_;
} AlignOffsetsBasic;

static void
compiled_OffsetsBasic (FILE *outfile)
{
  fprintf (outfile, "OffsetsBasic: size=%" G_GSIZE_FORMAT ", alignment=%ld\n",
           sizeof(OffsetsBasic),
           G_STRUCT_OFFSET(AlignOffsetsBasic, struct_));

  fprintf (outfile, "%s %ld\n", "dummy1", G_STRUCT_OFFSET(OffsetsBasic, dummy1));
  fprintf (outfile, "%s %ld\n", "field_int8", G_STRUCT_OFFSET(OffsetsBasic, field_int8));
  fprintf (outfile, "%s %ld\n", "dummy2", G_STRUCT_OFFSET(OffsetsBasic, dummy2));
  fprintf (outfile, "%s %ld\n", "field_int16", G_STRUCT_OFFSET(OffsetsBasic, field_int16));
  fprintf (outfile, "%s %ld\n", "dummy3", G_STRUCT_OFFSET(OffsetsBasic, dummy3));
  fprintf (outfile, "%s %ld\n", "field_int32", G_STRUCT_OFFSET(OffsetsBasic, field_int32));
  fprintf (outfile, "%s %ld\n", "dummy4", G_STRUCT_OFFSET(OffsetsBasic, dummy4));
  fprintf (outfile, "%s %ld\n", "field_int64", G_STRUCT_OFFSET(OffsetsBasic, field_int64));
  fprintf (outfile, "%s %ld\n", "dummy5", G_STRUCT_OFFSET(OffsetsBasic, dummy5));
  fprintf (outfile, "%s %ld\n", "field_pointer", G_STRUCT_OFFSET(OffsetsBasic, field_pointer));
  fprintf (outfile, "%s %ld\n", "dummy6", G_STRUCT_OFFSET(OffsetsBasic, dummy6));
  fprintf (outfile, "%s %ld\n", "field_float", G_STRUCT_OFFSET(OffsetsBasic, field_float));
  fprintf (outfile, "%s %ld\n", "dummy7", G_STRUCT_OFFSET(OffsetsBasic, dummy7));
  fprintf (outfile, "%s %ld\n", "field_double", G_STRUCT_OFFSET(OffsetsBasic, field_double));
  fprintf (outfile, "%s %ld\n", "dummy8", G_STRUCT_OFFSET(OffsetsBasic, dummy8));
  fprintf (outfile, "%s %ld\n", "field_size", G_STRUCT_OFFSET(OffsetsBasic, field_size));

  fprintf (outfile, "\n");
}

static void
introspected_OffsetsBasic (FILE *outfile)
{
  GIStructInfo *struct_info = (GIStructInfo *)g_irepository_find_by_name(repository, namespace,
                                                                         "Basic");
  if (!struct_info)
     g_error ("Can't find GIStructInfo for 'OffsetsBasic'");

  fprintf (outfile, "OffsetsBasic: size=%" G_GSIZE_FORMAT ", alignment=%" G_GSIZE_FORMAT "\n",
           g_struct_info_get_size (struct_info),
           g_struct_info_get_alignment (struct_info));

  print_field_offset(outfile, struct_info, "dummy1");
  print_field_offset(outfile, struct_info, "field_int8");
  print_field_offset(outfile, struct_info, "dummy2");
  print_field_offset(outfile, struct_info, "field_int16");
  print_field_offset(outfile, struct_info, "dummy3");
  print_field_offset(outfile, struct_info, "field_int32");
  print_field_offset(outfile, struct_info, "dummy4");
  print_field_offset(outfile, struct_info, "field_int64");
  print_field_offset(outfile, struct_info, "dummy5");
  print_field_offset(outfile, struct_info, "field_pointer");
  print_field_offset(outfile, struct_info, "dummy6");
  print_field_offset(outfile, struct_info, "field_float");
  print_field_offset(outfile, struct_info, "dummy7");
  print_field_offset(outfile, struct_info, "field_double");
  print_field_offset(outfile, struct_info, "dummy8");
  print_field_offset(outfile, struct_info, "field_size");

  fprintf (outfile, "\n");

  g_base_info_unref ((GIBaseInfo *)struct_info);
}
typedef struct {
   char dummy;
   OffsetsEnum struct_;
} AlignOffsetsEnum;

static void
compiled_OffsetsEnum (FILE *outfile)
{
  fprintf (outfile, "OffsetsEnum: size=%" G_GSIZE_FORMAT ", alignment=%ld\n",
           sizeof(OffsetsEnum),
           G_STRUCT_OFFSET(AlignOffsetsEnum, struct_));

  fprintf (outfile, "%s %ld\n", "enum1", G_STRUCT_OFFSET(OffsetsEnum, enum1));
  fprintf (outfile, "%s %ld\n", "dummy1", G_STRUCT_OFFSET(OffsetsEnum, dummy1));
  fprintf (outfile, "%s %ld\n", "enum2", G_STRUCT_OFFSET(OffsetsEnum, enum2));
  fprintf (outfile, "%s %ld\n", "dummy2", G_STRUCT_OFFSET(OffsetsEnum, dummy2));
  fprintf (outfile, "%s %ld\n", "enum3", G_STRUCT_OFFSET(OffsetsEnum, enum3));
  fprintf (outfile, "%s %ld\n", "dummy3", G_STRUCT_OFFSET(OffsetsEnum, dummy3));
  fprintf (outfile, "%s %ld\n", "enum4", G_STRUCT_OFFSET(OffsetsEnum, enum4));
  fprintf (outfile, "%s %ld\n", "dummy4", G_STRUCT_OFFSET(OffsetsEnum, dummy4));
  fprintf (outfile, "%s %ld\n", "enum5", G_STRUCT_OFFSET(OffsetsEnum, enum5));
  fprintf (outfile, "%s %ld\n", "dummy5", G_STRUCT_OFFSET(OffsetsEnum, dummy5));
  fprintf (outfile, "%s %ld\n", "enum6", G_STRUCT_OFFSET(OffsetsEnum, enum6));
  fprintf (outfile, "%s %ld\n", "dummy6", G_STRUCT_OFFSET(OffsetsEnum, dummy6));

  fprintf (outfile, "\n");
}

static void
introspected_OffsetsEnum (FILE *outfile)
{
  GIStructInfo *struct_info = (GIStructInfo *)g_irepository_find_by_name(repository, namespace,
                                                                         "Enum");
  if (!struct_info)
     g_error ("Can't find GIStructInfo for 'OffsetsEnum'");

  fprintf (outfile, "OffsetsEnum: size=%" G_GSIZE_FORMAT ", alignment=%" G_GSIZE_FORMAT "\n",
           g_struct_info_get_size (struct_info),
           g_struct_info_get_alignment (struct_info));

  print_field_offset(outfile, struct_info, "enum1");
  print_field_offset(outfile, struct_info, "dummy1");
  print_field_offset(outfile, struct_info, "enum2");
  print_field_offset(outfile, struct_info, "dummy2");
  print_field_offset(outfile, struct_info, "enum3");
  print_field_offset(outfile, struct_info, "dummy3");
  print_field_offset(outfile, struct_info, "enum4");
  print_field_offset(outfile, struct_info, "dummy4");
  print_field_offset(outfile, struct_info, "enum5");
  print_field_offset(outfile, struct_info, "dummy5");
  print_field_offset(outfile, struct_info, "enum6");
  print_field_offset(outfile, struct_info, "dummy6");

  fprintf (outfile, "\n");

  g_base_info_unref ((GIBaseInfo *)struct_info);
}
typedef struct {
   char dummy;
   OffsetsNested struct_;
} AlignOffsetsNested;

static void
compiled_OffsetsNested (FILE *outfile)
{
  fprintf (outfile, "OffsetsNested: size=%" G_GSIZE_FORMAT ", alignment=%ld\n",
           sizeof(OffsetsNested),
           G_STRUCT_OFFSET(AlignOffsetsNested, struct_));

  fprintf (outfile, "%s %ld\n", "dummy1", G_STRUCT_OFFSET(OffsetsNested, dummy1));
  fprintf (outfile, "%s %ld\n", "nestee", G_STRUCT_OFFSET(OffsetsNested, nestee));
  fprintf (outfile, "%s %ld\n", "dummy2", G_STRUCT_OFFSET(OffsetsNested, dummy2));
  fprintf (outfile, "%s %ld\n", "nestee_union", G_STRUCT_OFFSET(OffsetsNested, nestee_union));
  fprintf (outfile, "%s %ld\n", "dummy3", G_STRUCT_OFFSET(OffsetsNested, dummy3));

  fprintf (outfile, "\n");
}

static void
introspected_OffsetsNested (FILE *outfile)
{
  GIStructInfo *struct_info = (GIStructInfo *)g_irepository_find_by_name(repository, namespace,
                                                                         "Nested");
  if (!struct_info)
     g_error ("Can't find GIStructInfo for 'OffsetsNested'");

  fprintf (outfile, "OffsetsNested: size=%" G_GSIZE_FORMAT ", alignment=%" G_GSIZE_FORMAT "\n",
           g_struct_info_get_size (struct_info),
           g_struct_info_get_alignment (struct_info));

  print_field_offset(outfile, struct_info, "dummy1");
  print_field_offset(outfile, struct_info, "nestee");
  print_field_offset(outfile, struct_info, "dummy2");
  print_field_offset(outfile, struct_info, "nestee_union");
  print_field_offset(outfile, struct_info, "dummy3");

  fprintf (outfile, "\n");

  g_base_info_unref ((GIBaseInfo *)struct_info);
}
typedef struct {
   char dummy;
   OffsetsNestee struct_;
} AlignOffsetsNestee;

static void
compiled_OffsetsNestee (FILE *outfile)
{
  fprintf (outfile, "OffsetsNestee: size=%" G_GSIZE_FORMAT ", alignment=%ld\n",
           sizeof(OffsetsNestee),
           G_STRUCT_OFFSET(AlignOffsetsNestee, struct_));

  fprintf (outfile, "%s %ld\n", "field1", G_STRUCT_OFFSET(OffsetsNestee, field1));
  fprintf (outfile, "%s %ld\n", "field2", G_STRUCT_OFFSET(OffsetsNestee, field2));
  fprintf (outfile, "%s %ld\n", "field3", G_STRUCT_OFFSET(OffsetsNestee, field3));

  fprintf (outfile, "\n");
}

static void
introspected_OffsetsNestee (FILE *outfile)
{
  GIStructInfo *struct_info = (GIStructInfo *)g_irepository_find_by_name(repository, namespace,
                                                                         "Nestee");
  if (!struct_info)
     g_error ("Can't find GIStructInfo for 'OffsetsNestee'");

  fprintf (outfile, "OffsetsNestee: size=%" G_GSIZE_FORMAT ", alignment=%" G_GSIZE_FORMAT "\n",
           g_struct_info_get_size (struct_info),
           g_struct_info_get_alignment (struct_info));

  print_field_offset(outfile, struct_info, "field1");
  print_field_offset(outfile, struct_info, "field2");
  print_field_offset(outfile, struct_info, "field3");

  fprintf (outfile, "\n");

  g_base_info_unref ((GIBaseInfo *)struct_info);
}
typedef struct {
   char dummy;
   OffsetsObj struct_;
} AlignOffsetsObj;

static void
compiled_OffsetsObj (FILE *outfile)
{
  fprintf (outfile, "OffsetsObj: size=%" G_GSIZE_FORMAT ", alignment=%ld\n",
           sizeof(OffsetsObj),
           G_STRUCT_OFFSET(AlignOffsetsObj, struct_));

  fprintf (outfile, "%s %ld\n", "parent_instance", G_STRUCT_OFFSET(OffsetsObj, parent_instance));
  fprintf (outfile, "%s %ld\n", "other", G_STRUCT_OFFSET(OffsetsObj, other));

  fprintf (outfile, "\n");
}

static void
introspected_OffsetsObj (FILE *outfile)
{
  GIStructInfo *struct_info = (GIStructInfo *)g_irepository_find_by_name(repository, namespace,
                                                                         "Obj");
  if (!struct_info)
     g_error ("Can't find GIStructInfo for 'OffsetsObj'");

  fprintf (outfile, "OffsetsObj: size=%" G_GSIZE_FORMAT ", alignment=%" G_GSIZE_FORMAT "\n",
           g_struct_info_get_size (struct_info),
           g_struct_info_get_alignment (struct_info));

  print_field_offset(outfile, struct_info, "parent_instance");
  print_field_offset(outfile, struct_info, "other");

  fprintf (outfile, "\n");

  g_base_info_unref ((GIBaseInfo *)struct_info);
}
typedef struct {
   char dummy;
   OffsetsObjClass struct_;
} AlignOffsetsObjClass;

static void
compiled_OffsetsObjClass (FILE *outfile)
{
  fprintf (outfile, "OffsetsObjClass: size=%" G_GSIZE_FORMAT ", alignment=%ld\n",
           sizeof(OffsetsObjClass),
           G_STRUCT_OFFSET(AlignOffsetsObjClass, struct_));

  fprintf (outfile, "%s %ld\n", "parent_class", G_STRUCT_OFFSET(OffsetsObjClass, parent_class));

  fprintf (outfile, "\n");
}

static void
introspected_OffsetsObjClass (FILE *outfile)
{
  GIStructInfo *struct_info = (GIStructInfo *)g_irepository_find_by_name(repository, namespace,
                                                                         "ObjClass");
  if (!struct_info)
     g_error ("Can't find GIStructInfo for 'OffsetsObjClass'");

  fprintf (outfile, "OffsetsObjClass: size=%" G_GSIZE_FORMAT ", alignment=%" G_GSIZE_FORMAT "\n",
           g_struct_info_get_size (struct_info),
           g_struct_info_get_alignment (struct_info));

  print_field_offset(outfile, struct_info, "parent_class");

  fprintf (outfile, "\n");

  g_base_info_unref ((GIBaseInfo *)struct_info);
}

int main(int argc, char **argv)
{
  GError *error = NULL;
  FILE *outfile;

  if (argc != 3)
    g_error ("Usage: gitestoffsets COMPILED_OFFSETS_FILE INTROSPECTED_OFFSETS_FILE");

  repository = g_irepository_get_default ();
  if (!g_irepository_require (repository, namespace, version, 0, &error))
     g_error ("Failed to load %s-%s.typelib: %s", namespace, version, error->message);

  outfile = fopen (argv[1], "w");
  if (!outfile)
    g_error ("Cannot open '%s': %s'", argv[1], g_strerror(errno));

  compiled_OffsetsArray (outfile);
  compiled_OffsetsBasic (outfile);
  compiled_OffsetsEnum (outfile);
  compiled_OffsetsNested (outfile);
  compiled_OffsetsNestee (outfile);
  compiled_OffsetsObj (outfile);
  compiled_OffsetsObjClass (outfile);

  fclose (outfile);

  outfile = fopen (argv[2], "w");
  if (!outfile)
    g_error ("Cannot open '%s': %s'", argv[1], g_strerror(errno));

  introspected_OffsetsArray (outfile);
  introspected_OffsetsBasic (outfile);
  introspected_OffsetsEnum (outfile);
  introspected_OffsetsNested (outfile);
  introspected_OffsetsNestee (outfile);
  introspected_OffsetsObj (outfile);
  introspected_OffsetsObjClass (outfile);

  fclose (outfile);

  return 0;
}
