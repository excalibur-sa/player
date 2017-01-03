/*   -*- buffer-read-only: t -*- vi: set ro:
 *
 *  DO NOT EDIT THIS FILE   (systemkey-args.c)
 *
 *  It has been AutoGen-ed
 *  From the definitions    systemkey-args.def
 *  and the template file   options
 *
 * Generated from AutoOpts 41:1:16 templates.
 *
 *  AutoOpts is a copyrighted work.  This source file is not encumbered
 *  by AutoOpts licensing, but is provided under the licensing terms chosen
 *  by the systemkey-tool author or copyright holder.  AutoOpts is
 *  licensed under the terms of the LGPL.  The redistributable library
 *  (``libopts'') is licensed under the terms of either the LGPL or, at the
 *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources
 *  for details.
 *
 * The systemkey-tool program is copyrighted and licensed
 * under the following terms:
 *
 *  Copyright (C) 2000-2016 Free Software Foundation, and others, all rights reserved.
 *  This is free software. It is licensed for use, modification and
 *  redistribution under the terms of the GNU General Public License,
 *  version 3 or later <http://gnu.org/licenses/gpl.html>
 *
 *  systemkey-tool is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  systemkey-tool is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __doxygen__
#define OPTION_CODE_COMPILE 1
#include "systemkey-args.h"
#include <sys/types.h>

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifdef  __cplusplus
extern "C" {
#endif
extern FILE * option_usage_fp;
#define zCopyright      (systemkey_tool_opt_strs+0)
#define zLicenseDescrip (systemkey_tool_opt_strs+289)


#ifndef NULL
#  define NULL 0
#endif

/**
 *  static const strings for systemkey-tool options
 */
static char const systemkey_tool_opt_strs[1628] =
/*     0 */ "systemkey-tool 3.5.7\n"
            "Copyright (C) 2000-2016 Free Software Foundation, and others, all rights reserved.\n"
            "This is free software. It is licensed for use, modification and\n"
            "redistribution under the terms of the GNU General Public License,\n"
            "version 3 or later <http://gnu.org/licenses/gpl.html>\n\0"
/*   289 */ "systemkey-tool is free software: you can redistribute it and/or modify it\n"
            "under the terms of the GNU General Public License as published by the Free\n"
            "Software Foundation, either version 3 of the License, or (at your option)\n"
            "any later version.\n\n"
            "systemkey-tool is distributed in the hope that it will be useful, but\n"
            "WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY\n"
            "or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License\n"
            "for more details.\n\n"
            "You should have received a copy of the GNU General Public License along\n"
            "with this program.  If not, see <http://www.gnu.org/licenses/>.\n\0"
/*   906 */ "Enable debugging\0"
/*   923 */ "DEBUG\0"
/*   929 */ "debug\0"
/*   935 */ "Input file\0"
/*   946 */ "INFILE\0"
/*   953 */ "infile\0"
/*   960 */ "Output file\0"
/*   972 */ "OUTFILE\0"
/*   980 */ "outfile\0"
/*   988 */ "Lists all stored keys.\0"
/*  1011 */ "LIST\0"
/*  1016 */ "list\0"
/*  1021 */ "Delete the key identified by the given URL.\0"
/*  1065 */ "DELETE\0"
/*  1072 */ "delete\0"
/*  1079 */ "Use the DER format for keys.\0"
/*  1108 */ "INDER\0"
/*  1114 */ "no-inder\0"
/*  1123 */ "no\0"
/*  1126 */ "Use DER format for output keys\0"
/*  1157 */ "OUTDER\0"
/*  1164 */ "no-outder\0"
/*  1174 */ "display extended usage information and exit\0"
/*  1218 */ "help\0"
/*  1223 */ "extended usage information passed thru pager\0"
/*  1268 */ "more-help\0"
/*  1278 */ "output version information and exit\0"
/*  1314 */ "version\0"
/*  1322 */ "SYSTEMKEY_TOOL\0"
/*  1337 */ "systemkey-tool - GnuTLS system key tool\n"
            "Usage:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]...\n\0"
/*  1435 */ "bugs@gnutls.org\0"
/*  1451 */ "\n\0"
/*  1453 */ "Program that allows handling user keys as stored in the system in a uniform\n"
            "way.\n\0"
/*  1535 */ "systemkey-tool 3.5.7\0"
/*  1556 */ "systemkey-tool [options]\n"
            "systemkey-tool --help for usage instructions.\n";

/**
 *  debug option description:
 */
/** Descriptive text for the debug option */
#define DEBUG_DESC      (systemkey_tool_opt_strs+906)
/** Upper-cased name for the debug option */
#define DEBUG_NAME      (systemkey_tool_opt_strs+923)
/** Name string for the debug option */
#define DEBUG_name      (systemkey_tool_opt_strs+929)
/** Compiled in flag settings for the debug option */
#define DEBUG_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))

/**
 *  infile option description:
 */
/** Descriptive text for the infile option */
#define INFILE_DESC      (systemkey_tool_opt_strs+935)
/** Upper-cased name for the infile option */
#define INFILE_NAME      (systemkey_tool_opt_strs+946)
/** Name string for the infile option */
#define INFILE_name      (systemkey_tool_opt_strs+953)
/** Compiled in flag settings for the infile option */
#define INFILE_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_FILE))

/**
 *  outfile option description:
 */
/** Descriptive text for the outfile option */
#define OUTFILE_DESC      (systemkey_tool_opt_strs+960)
/** Upper-cased name for the outfile option */
#define OUTFILE_NAME      (systemkey_tool_opt_strs+972)
/** Name string for the outfile option */
#define OUTFILE_name      (systemkey_tool_opt_strs+980)
/** Compiled in flag settings for the outfile option */
#define OUTFILE_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  list option description:
 */
/** Descriptive text for the list option */
#define LIST_DESC      (systemkey_tool_opt_strs+988)
/** Upper-cased name for the list option */
#define LIST_NAME      (systemkey_tool_opt_strs+1011)
/** Name string for the list option */
#define LIST_name      (systemkey_tool_opt_strs+1016)
/** Compiled in flag settings for the list option */
#define LIST_FLAGS     (OPTST_DISABLED)

/**
 *  delete option description:
 */
/** Descriptive text for the delete option */
#define DELETE_DESC      (systemkey_tool_opt_strs+1021)
/** Upper-cased name for the delete option */
#define DELETE_NAME      (systemkey_tool_opt_strs+1065)
/** Name string for the delete option */
#define DELETE_name      (systemkey_tool_opt_strs+1072)
/** Compiled in flag settings for the delete option */
#define DELETE_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  inder option description:
 */
/** Descriptive text for the inder option */
#define INDER_DESC      (systemkey_tool_opt_strs+1079)
/** Upper-cased name for the inder option */
#define INDER_NAME      (systemkey_tool_opt_strs+1108)
/** disablement name for the inder option */
#define NOT_INDER_name  (systemkey_tool_opt_strs+1114)
/** disablement prefix for the inder option */
#define NOT_INDER_PFX   (systemkey_tool_opt_strs+1123)
/** Name string for the inder option */
#define INDER_name      (NOT_INDER_name + 3)
/** Compiled in flag settings for the inder option */
#define INDER_FLAGS     (OPTST_DISABLED)

/**
 *  outder option description:
 */
/** Descriptive text for the outder option */
#define OUTDER_DESC      (systemkey_tool_opt_strs+1126)
/** Upper-cased name for the outder option */
#define OUTDER_NAME      (systemkey_tool_opt_strs+1157)
/** disablement name for the outder option */
#define NOT_OUTDER_name  (systemkey_tool_opt_strs+1164)
/** disablement prefix for the outder option */
#define NOT_OUTDER_PFX   (systemkey_tool_opt_strs+1123)
/** Name string for the outder option */
#define OUTDER_name      (NOT_OUTDER_name + 3)
/** Compiled in flag settings for the outder option */
#define OUTDER_FLAGS     (OPTST_DISABLED)

/*
 *  Help/More_Help/Version option descriptions:
 */
#define HELP_DESC       (systemkey_tool_opt_strs+1174)
#define HELP_name       (systemkey_tool_opt_strs+1218)
#ifdef HAVE_WORKING_FORK
#define MORE_HELP_DESC  (systemkey_tool_opt_strs+1223)
#define MORE_HELP_name  (systemkey_tool_opt_strs+1268)
#define MORE_HELP_FLAGS (OPTST_IMM | OPTST_NO_INIT)
#else
#define MORE_HELP_DESC  HELP_DESC
#define MORE_HELP_name  HELP_name
#define MORE_HELP_FLAGS (OPTST_OMITTED | OPTST_NO_INIT)
#endif
#ifdef NO_OPTIONAL_OPT_ARGS
#  define VER_FLAGS     (OPTST_IMM | OPTST_NO_INIT)
#else
#  define VER_FLAGS     (OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | \
                         OPTST_ARG_OPTIONAL | OPTST_IMM | OPTST_NO_INIT)
#endif
#define VER_DESC        (systemkey_tool_opt_strs+1278)
#define VER_name        (systemkey_tool_opt_strs+1314)
/**
 *  Declare option callback procedures
 */
extern tOptProc
    optionBooleanVal,   optionNestedVal,    optionNumericVal,
    optionPagedUsage,   optionPrintVersion, optionResetOpt,
    optionStackArg,     optionTimeDate,     optionTimeVal,
    optionUnstackArg,   optionVendorOption;
static tOptProc
    doOptDebug, doOptInfile, doUsageOpt;
#define VER_PROC        optionPrintVersion

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 *  Define the systemkey-tool Option Descriptions.
 * This is an array of OPTION_CT entries, one for each
 * option that the systemkey-tool program responds to.
 */
static tOptDesc optDesc[OPTION_CT] = {
  {  /* entry idx, value */ 0, VALUE_OPT_DEBUG,
     /* equiv idx, value */ 0, VALUE_OPT_DEBUG,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ DEBUG_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --debug */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptDebug,
     /* desc, NAME, name */ DEBUG_DESC, DEBUG_NAME, DEBUG_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 1, VALUE_OPT_INFILE,
     /* equiv idx, value */ 1, VALUE_OPT_INFILE,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ INFILE_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --infile */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptInfile,
     /* desc, NAME, name */ INFILE_DESC, INFILE_NAME, INFILE_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 2, VALUE_OPT_OUTFILE,
     /* equiv idx, value */ 2, VALUE_OPT_OUTFILE,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ OUTFILE_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --outfile */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ OUTFILE_DESC, OUTFILE_NAME, OUTFILE_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 3, VALUE_OPT_LIST,
     /* equiv idx, value */ 3, VALUE_OPT_LIST,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ LIST_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --list */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ LIST_DESC, LIST_NAME, LIST_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 4, VALUE_OPT_DELETE,
     /* equiv idx, value */ 4, VALUE_OPT_DELETE,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ DELETE_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --delete */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ DELETE_DESC, DELETE_NAME, DELETE_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 5, VALUE_OPT_INDER,
     /* equiv idx, value */ 5, VALUE_OPT_INDER,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ INDER_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --inder */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ INDER_DESC, INDER_NAME, INDER_name,
     /* disablement strs */ NOT_INDER_name, NOT_INDER_PFX },

  {  /* entry idx, value */ 6, VALUE_OPT_OUTDER,
     /* equiv idx, value */ 6, VALUE_OPT_OUTDER,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ OUTDER_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --outder */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ OUTDER_DESC, OUTDER_NAME, OUTDER_name,
     /* disablement strs */ NOT_OUTDER_name, NOT_OUTDER_PFX },

  {  /* entry idx, value */ INDEX_OPT_VERSION, VALUE_OPT_VERSION,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_VERSION,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ VER_FLAGS, AOUSE_VERSION,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ VER_PROC,
     /* desc, NAME, name */ VER_DESC, NULL, VER_name,
     /* disablement strs */ NULL, NULL },



  {  /* entry idx, value */ INDEX_OPT_HELP, VALUE_OPT_HELP,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_HELP,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ OPTST_IMM | OPTST_NO_INIT, AOUSE_HELP,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doUsageOpt,
     /* desc, NAME, name */ HELP_DESC, NULL, HELP_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_MORE_HELP, VALUE_OPT_MORE_HELP,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_MORE_HELP,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ MORE_HELP_FLAGS, AOUSE_MORE_HELP,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL,  NULL,
     /* option proc      */ optionPagedUsage,
     /* desc, NAME, name */ MORE_HELP_DESC, NULL, MORE_HELP_name,
     /* disablement strs */ NULL, NULL }
};


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/** Reference to the upper cased version of systemkey-tool. */
#define zPROGNAME       (systemkey_tool_opt_strs+1322)
/** Reference to the title line for systemkey-tool usage. */
#define zUsageTitle     (systemkey_tool_opt_strs+1337)
/** There is no systemkey-tool configuration file. */
#define zRcName         NULL
/** There are no directories to search for systemkey-tool config files. */
#define apzHomeList     NULL
/** The systemkey-tool program bug email address. */
#define zBugsAddr       (systemkey_tool_opt_strs+1435)
/** Clarification/explanation of what systemkey-tool does. */
#define zExplain        (systemkey_tool_opt_strs+1451)
/** Extra detail explaining what systemkey-tool does. */
#define zDetail         (systemkey_tool_opt_strs+1453)
/** The full version string for systemkey-tool. */
#define zFullVersion    (systemkey_tool_opt_strs+1535)
/* extracted from optcode.tlib near line 364 */

#if defined(ENABLE_NLS)
# define OPTPROC_BASE OPTPROC_TRANSLATE | OPTPROC_NXLAT_OPT
  static tOptionXlateProc translate_option_strings;
#else
# define OPTPROC_BASE OPTPROC_NONE
# define translate_option_strings NULL
#endif /* ENABLE_NLS */

#define systemkey_tool_full_usage (NULL)
#define systemkey_tool_short_usage (systemkey_tool_opt_strs+1556)

#endif /* not defined __doxygen__ */

/*
 *  Create the static procedure(s) declared above.
 */
/**
 * The callout function that invokes the optionUsage function.
 *
 * @param[in] opts the AutoOpts option description structure
 * @param[in] od   the descriptor for the "help" (usage) option.
 * @noreturn
 */
static void
doUsageOpt(tOptions * opts, tOptDesc * od)
{
    int ex_code;
    ex_code = SYSTEMKEY_TOOL_EXIT_SUCCESS;
    optionUsage(&systemkey_toolOptions, ex_code);
    /* NOTREACHED */
    exit(SYSTEMKEY_TOOL_EXIT_FAILURE);
    (void)opts;
    (void)od;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the debug option.
 * Specifies the debug level.
 * @param[in] pOptions the systemkey-tool options data structure
 * @param[in,out] pOptDesc the option descriptor for this option.
 */
static void
doOptDebug(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static struct {long rmin, rmax;} const rng[1] = {
        { 0 ,  9999 } };
    int  ix;

    if (pOptions <= OPTPROC_EMIT_LIMIT)
        goto emit_ranges;
    optionNumericVal(pOptions, pOptDesc);

    for (ix = 0; ix < 1; ix++) {
        if (pOptDesc->optArg.argInt < rng[ix].rmin)
            continue;  /* ranges need not be ordered. */
        if (pOptDesc->optArg.argInt == rng[ix].rmin)
            return;
        if (rng[ix].rmax == LONG_MIN)
            continue;
        if (pOptDesc->optArg.argInt <= rng[ix].rmax)
            return;
    }

    option_usage_fp = stderr;

 emit_ranges:
optionShowRange(pOptions, pOptDesc, VOIDP(rng), 1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the infile option.
 *
 * @param[in] pOptions the systemkey-tool options data structure
 * @param[in,out] pOptDesc the option descriptor for this option.
 */
static void
doOptInfile(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static teOptFileType const  type =
        FTYPE_MODE_MUST_EXIST + FTYPE_MODE_NO_OPEN;
    static tuFileMode           mode;
#ifndef O_CLOEXEC
#  define O_CLOEXEC 0
#endif
    mode.file_flags = O_CLOEXEC;

    /*
     * This function handles special invalid values for "pOptions"
     */
    optionFileCheck(pOptions, pOptDesc, type, mode);
}
/* extracted from optmain.tlib near line 1250 */

/**
 * The directory containing the data associated with systemkey-tool.
 */
#ifndef  PKGDATADIR
# define PKGDATADIR ""
#endif

/**
 * Information about the person or institution that packaged systemkey-tool
 * for the current distribution.
 */
#ifndef  WITH_PACKAGER
# define systemkey_tool_packager_info NULL
#else
/** Packager information for systemkey-tool. */
static char const systemkey_tool_packager_info[] =
    "Packaged by " WITH_PACKAGER

# ifdef WITH_PACKAGER_VERSION
        " ("WITH_PACKAGER_VERSION")"
# endif

# ifdef WITH_PACKAGER_BUG_REPORTS
    "\nReport systemkey_tool bugs to " WITH_PACKAGER_BUG_REPORTS
# endif
    "\n";
#endif
#ifndef __doxygen__

#endif /* __doxygen__ */
/**
 * The option definitions for systemkey-tool.  The one structure that
 * binds them all.
 */
tOptions systemkey_toolOptions = {
    OPTIONS_STRUCT_VERSION,
    0, NULL,                    /* original argc + argv    */
    ( OPTPROC_BASE
    + OPTPROC_ERRSTOP
    + OPTPROC_SHORTOPT
    + OPTPROC_LONGOPT
    + OPTPROC_NO_REQ_OPT
    + OPTPROC_NEGATIONS
    + OPTPROC_NO_ARGS
    + OPTPROC_GNUUSAGE
    + OPTPROC_MISUSE ),
    0, NULL,                    /* current option index, current option */
    NULL,         NULL,         zPROGNAME,
    zRcName,      zCopyright,   zLicenseDescrip,
    zFullVersion, apzHomeList,  zUsageTitle,
    zExplain,     zDetail,      optDesc,
    zBugsAddr,                  /* address to send bugs to */
    NULL, NULL,                 /* extensions/saved state  */
    optionUsage, /* usage procedure */
    translate_option_strings,   /* translation procedure */
    /*
     *  Indexes to special options
     */
    { INDEX_OPT_MORE_HELP, /* more-help option index */
      NO_EQUIVALENT, /* save option index */
      NO_EQUIVALENT, /* '-#' option index */
      NO_EQUIVALENT /* index of default opt */
    },
    10 /* full option count */, 7 /* user option count */,
    systemkey_tool_full_usage, systemkey_tool_short_usage,
    NULL, NULL,
    PKGDATADIR, systemkey_tool_packager_info
};

#if ENABLE_NLS
/**
 * This code is designed to translate translatable option text for the
 * systemkey-tool program.  These translations happen upon entry
 * to optionProcess().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifdef HAVE_DCGETTEXT
# include <gettext.h>
#endif
#include <autoopts/usage-txt.h>

static char * AO_gettext(char const * pz);
static void   coerce_it(void ** s);

/**
 * AutoGen specific wrapper function for gettext.  It relies on the macro _()
 * to convert from English to the target language, then strdup-duplicates the
 * result string.  It tries the "libopts" domain first, then whatever has been
 * set via the \a textdomain(3) call.
 *
 * @param[in] pz the input text used as a lookup key.
 * @returns the translated text (if there is one),
 *   or the original text (if not).
 */
static char *
AO_gettext(char const * pz)
{
    char * res;
    if (pz == NULL)
        return NULL;
#ifdef HAVE_DCGETTEXT
    /*
     * While processing the option_xlateable_txt data, try to use the
     * "libopts" domain.  Once we switch to the option descriptor data,
     * do *not* use that domain.
     */
    if (option_xlateable_txt.field_ct != 0) {
        res = dgettext("libopts", pz);
        if (res == pz)
            res = (char *)VOIDP(_(pz));
    } else
        res = (char *)VOIDP(_(pz));
#else
    res = (char *)VOIDP(_(pz));
#endif
    if (res == pz)
        return res;
    res = strdup(res);
    if (res == NULL) {
        fputs(_("No memory for duping translated strings\n"), stderr);
        exit(SYSTEMKEY_TOOL_EXIT_FAILURE);
    }
    return res;
}

/**
 * All the pointers we use are marked "* const", but they are stored in
 * writable memory.  Coerce the mutability and set the pointer.
 */
static void coerce_it(void ** s) { *s = AO_gettext(*s);
}

/**
 * Translate all the translatable strings in the systemkey_toolOptions
 * structure defined above.  This is done only once.
 */
static void
translate_option_strings(void)
{
    tOptions * const opts = &systemkey_toolOptions;

    /*
     *  Guard against re-translation.  It won't work.  The strings will have
     *  been changed by the first pass through this code.  One shot only.
     */
    if (option_xlateable_txt.field_ct != 0) {
        /*
         *  Do the translations.  The first pointer follows the field count
         *  field.  The field count field is the size of a pointer.
         */
        char ** ppz = (char**)VOIDP(&(option_xlateable_txt));
        int     ix  = option_xlateable_txt.field_ct;

        do {
            ppz++; /* skip over field_ct */
            *ppz = AO_gettext(*ppz);
        } while (--ix > 0);
        /* prevent re-translation and disable "libopts" domain lookup */
        option_xlateable_txt.field_ct = 0;

        coerce_it(VOIDP(&(opts->pzCopyright)));
        coerce_it(VOIDP(&(opts->pzCopyNotice)));
        coerce_it(VOIDP(&(opts->pzFullVersion)));
        coerce_it(VOIDP(&(opts->pzUsageTitle)));
        coerce_it(VOIDP(&(opts->pzExplain)));
        coerce_it(VOIDP(&(opts->pzDetail)));
        {
            tOptDesc * od = opts->pOptDesc;
            for (ix = opts->optCt; ix > 0; ix--, od++)
                coerce_it(VOIDP(&(od->pzText)));
        }
    }
}
#endif /* ENABLE_NLS */

#ifdef DO_NOT_COMPILE_THIS_CODE_IT_IS_FOR_GETTEXT
/** I18N function strictly for xgettext.  Do not compile. */
static void bogus_function(void) {
  /* TRANSLATORS:

     The following dummy function was crated solely so that xgettext can
     extract the correct strings.  These strings are actually referenced
     by a field name in the systemkey_toolOptions structure noted in the
     comments below.  The literal text is defined in systemkey_tool_opt_strs.
   
     NOTE: the strings below are segmented with respect to the source string
     systemkey_tool_opt_strs.  The strings above are handed off for translation
     at run time a paragraph at a time.  Consequently, they are presented here
     for translation a paragraph at a time.
   
     ALSO: often the description for an option will reference another option
     by name.  These are set off with apostrophe quotes (I hope).  Do not
     translate option names.
   */
  /* referenced via systemkey_toolOptions.pzCopyright */
  puts(_("systemkey-tool 3.5.7\n\
Copyright (C) 2000-2016 Free Software Foundation, and others, all rights reserved.\n\
This is free software. It is licensed for use, modification and\n\
redistribution under the terms of the GNU General Public License,\n\
version 3 or later <http://gnu.org/licenses/gpl.html>\n"));

  /* referenced via systemkey_toolOptions.pzCopyNotice */
  puts(_("systemkey-tool is free software: you can redistribute it and/or modify it\n\
under the terms of the GNU General Public License as published by the Free\n\
Software Foundation, either version 3 of the License, or (at your option)\n\
any later version.\n\n"));
  puts(_("systemkey-tool is distributed in the hope that it will be useful, but\n\
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY\n\
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License\n\
for more details.\n\n"));
  puts(_("You should have received a copy of the GNU General Public License along\n\
with this program.  If not, see <http://www.gnu.org/licenses/>.\n"));

  /* referenced via systemkey_toolOptions.pOptDesc->pzText */
  puts(_("Enable debugging"));

  /* referenced via systemkey_toolOptions.pOptDesc->pzText */
  puts(_("Input file"));

  /* referenced via systemkey_toolOptions.pOptDesc->pzText */
  puts(_("Output file"));

  /* referenced via systemkey_toolOptions.pOptDesc->pzText */
  puts(_("Lists all stored keys."));

  /* referenced via systemkey_toolOptions.pOptDesc->pzText */
  puts(_("Delete the key identified by the given URL."));

  /* referenced via systemkey_toolOptions.pOptDesc->pzText */
  puts(_("Use the DER format for keys."));

  /* referenced via systemkey_toolOptions.pOptDesc->pzText */
  puts(_("Use DER format for output keys"));

  /* referenced via systemkey_toolOptions.pOptDesc->pzText */
  puts(_("display extended usage information and exit"));

  /* referenced via systemkey_toolOptions.pOptDesc->pzText */
  puts(_("extended usage information passed thru pager"));

  /* referenced via systemkey_toolOptions.pOptDesc->pzText */
  puts(_("output version information and exit"));

  /* referenced via systemkey_toolOptions.pzUsageTitle */
  puts(_("systemkey-tool - GnuTLS system key tool\n\
Usage:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]...\n"));

  /* referenced via systemkey_toolOptions.pzExplain */
  puts(_("\n"));

  /* referenced via systemkey_toolOptions.pzDetail */
  puts(_("Program that allows handling user keys as stored in the system in a uniform\n\
way.\n"));

  /* referenced via systemkey_toolOptions.pzFullVersion */
  puts(_("systemkey-tool 3.5.7"));

  /* referenced via systemkey_toolOptions.pzFullUsage */
  puts(_("<<<NOT-FOUND>>>"));

  /* referenced via systemkey_toolOptions.pzShortUsage */
  puts(_("systemkey-tool [options]\n\
systemkey-tool --help for usage instructions.\n"));
  /* LIBOPTS-MESSAGES: */
#line 67 "../autoopts.c"
  puts(_("allocation of %d bytes failed\n"));
#line 93 "../autoopts.c"
  puts(_("allocation of %d bytes failed\n"));
#line 53 "../init.c"
  puts(_("AutoOpts function called without option descriptor\n"));
#line 86 "../init.c"
  puts(_("\tThis exceeds the compiled library version:  "));
#line 84 "../init.c"
  puts(_("Automated Options Processing Error!\n"
       "\t%s called AutoOpts function with structure version %d:%d:%d.\n"));
#line 80 "../autoopts.c"
  puts(_("realloc of %d bytes at 0x%p failed\n"));
#line 88 "../init.c"
  puts(_("\tThis is less than the minimum library version:  "));
#line 121 "../version.c"
  puts(_("Automated Options version %s\n"
       "\tCopyright (C) 1999-2014 by Bruce Korb - all rights reserved\n"));
#line 87 "../makeshell.c"
  puts(_("(AutoOpts bug):  %s.\n"));
#line 90 "../reset.c"
  puts(_("optionResetOpt() called, but reset-option not configured"));
#line 292 "../usage.c"
  puts(_("could not locate the 'help' option"));
#line 336 "../autoopts.c"
  puts(_("optionProcess() was called with invalid data"));
#line 748 "../usage.c"
  puts(_("invalid argument type specified"));
#line 598 "../find.c"
  puts(_("defaulted to option with optional arg"));
#line 76 "../alias.c"
  puts(_("aliasing option is out of range."));
#line 235 "../enum.c"
  puts(_("%s error:  the keyword '%s' is ambiguous for %s\n"));
#line 108 "../find.c"
  puts(_("  The following options match:\n"));
#line 293 "../find.c"
  puts(_("%s: ambiguous option name: %s (matches %d options)\n"));
#line 161 "../check.c"
  puts(_("%s: Command line arguments required\n"));
#line 43 "../alias.c"
  puts(_("%d %s%s options allowed\n"));
#line 94 "../makeshell.c"
  puts(_("%s error %d (%s) calling %s for '%s'\n"));
#line 306 "../makeshell.c"
  puts(_("interprocess pipe"));
#line 168 "../version.c"
  puts(_("error: version option argument '%c' invalid.  Use:\n"
       "\t'v' - version only\n"
       "\t'c' - version and copyright\n"
       "\t'n' - version and full copyright notice\n"));
#line 58 "../check.c"
  puts(_("%s error:  the '%s' and '%s' options conflict\n"));
#line 217 "../find.c"
  puts(_("%s: The '%s' option has been disabled."));
#line 430 "../find.c"
  puts(_("%s: The '%s' option has been disabled."));
#line 38 "../alias.c"
  puts(_("-equivalence"));
#line 469 "../find.c"
  puts(_("%s: illegal option -- %c\n"));
#line 110 "../reset.c"
  puts(_("%s: illegal option -- %c\n"));
#line 271 "../find.c"
  puts(_("%s: illegal option -- %s\n"));
#line 755 "../find.c"
  puts(_("%s: illegal option -- %s\n"));
#line 118 "../reset.c"
  puts(_("%s: illegal option -- %s\n"));
#line 335 "../find.c"
  puts(_("%s: unknown vendor extension option -- %s\n"));
#line 160 "../enum.c"
  puts(_("  or an integer from %d through %d\n"));
#line 170 "../enum.c"
  puts(_("  or an integer from %d through %d\n"));
#line 747 "../usage.c"
  puts(_("%s error:  invalid option descriptor for %s\n"));
#line 1081 "../usage.c"
  puts(_("%s error:  invalid option descriptor for %s\n"));
#line 385 "../find.c"
  puts(_("%s: invalid option name: %s\n"));
#line 527 "../find.c"
  puts(_("%s: The '%s' option requires an argument.\n"));
#line 156 "../autoopts.c"
  puts(_("(AutoOpts bug):  Equivalenced option '%s' was equivalenced to both\n"
       "\t'%s' and '%s'."));
#line 94 "../check.c"
  puts(_("%s error:  The %s option is required\n"));
#line 632 "../find.c"
  puts(_("%s: The '%s' option cannot have an argument.\n"));
#line 151 "../check.c"
  puts(_("%s: Command line arguments are not allowed.\n"));
#line 535 "../save.c"
  puts(_("error %d (%s) creating %s\n"));
#line 235 "../enum.c"
  puts(_("%s error:  '%s' does not match any %s keywords.\n"));
#line 93 "../reset.c"
  puts(_("%s error: The '%s' option requires an argument.\n"));
#line 186 "../save.c"
  puts(_("error %d (%s) stat-ing %s\n"));
#line 238 "../save.c"
  puts(_("error %d (%s) stat-ing %s\n"));
#line 143 "../restore.c"
  puts(_("%s error: no saved option state\n"));
#line 231 "../autoopts.c"
  puts(_("'%s' is not a command line option.\n"));
#line 113 "../time.c"
  puts(_("%s error:  '%s' is not a recognizable date/time.\n"));
#line 131 "../save.c"
  puts(_("'%s' not defined\n"));
#line 50 "../time.c"
  puts(_("%s error:  '%s' is not a recognizable time duration.\n"));
#line 92 "../check.c"
  puts(_("%s error:  The %s option must appear %d times.\n"));
#line 165 "../numeric.c"
  puts(_("%s error:  '%s' is not a recognizable number.\n"));
#line 201 "../enum.c"
  puts(_("%s error:  %s exceeds %s keyword count\n"));
#line 330 "../usage.c"
  puts(_("Try '%s %s' for more information.\n"));
#line 45 "../alias.c"
  puts(_("one %s%s option allowed\n"));
#line 208 "../makeshell.c"
  puts(_("standard output"));
#line 943 "../makeshell.c"
  puts(_("standard output"));
#line 274 "../usage.c"
  puts(_("standard output"));
#line 415 "../usage.c"
  puts(_("standard output"));
#line 625 "../usage.c"
  puts(_("standard output"));
#line 175 "../version.c"
  puts(_("standard output"));
#line 274 "../usage.c"
  puts(_("standard error"));
#line 415 "../usage.c"
  puts(_("standard error"));
#line 625 "../usage.c"
  puts(_("standard error"));
#line 175 "../version.c"
  puts(_("standard error"));
#line 208 "../makeshell.c"
  puts(_("write"));
#line 943 "../makeshell.c"
  puts(_("write"));
#line 273 "../usage.c"
  puts(_("write"));
#line 414 "../usage.c"
  puts(_("write"));
#line 624 "../usage.c"
  puts(_("write"));
#line 174 "../version.c"
  puts(_("write"));
#line 60 "../numeric.c"
  puts(_("%s error:  %s option value %ld is out of range.\n"));
#line 44 "../check.c"
  puts(_("%s error:  %s option requires the %s option\n"));
#line 130 "../save.c"
  puts(_("%s warning:  cannot save options - %s not regular file\n"));
#line 185 "../save.c"
  puts(_("%s warning:  cannot save options - %s not regular file\n"));
#line 237 "../save.c"
  puts(_("%s warning:  cannot save options - %s not regular file\n"));
#line 256 "../save.c"
  puts(_("%s warning:  cannot save options - %s not regular file\n"));
#line 534 "../save.c"
  puts(_("%s warning:  cannot save options - %s not regular file\n"));
  /* END-LIBOPTS-MESSAGES */

  /* USAGE-TEXT: */
#line 873 "../usage.c"
  puts(_("\t\t\t\t- an alternate for '%s'\n"));
#line 1148 "../usage.c"
  puts(_("Version, usage and configuration options:"));
#line 924 "../usage.c"
  puts(_("\t\t\t\t- default option for unnamed options\n"));
#line 837 "../usage.c"
  puts(_("\t\t\t\t- disabled as '--%s'\n"));
#line 1117 "../usage.c"
  puts(_(" --- %-14s %s\n"));
#line 1115 "../usage.c"
  puts(_("This option has been disabled"));
#line 864 "../usage.c"
  puts(_("\t\t\t\t- enabled by default\n"));
#line 40 "../alias.c"
  puts(_("%s error:  only "));
#line 1194 "../usage.c"
  puts(_(" - examining environment variables named %s_*\n"));
#line 168 "../file.c"
  puts(_("\t\t\t\t- file must not pre-exist\n"));
#line 172 "../file.c"
  puts(_("\t\t\t\t- file must pre-exist\n"));
#line 380 "../usage.c"
  puts(_("Options are specified by doubled hyphens and their name or by a single\n"
       "hyphen and the flag character.\n"));
#line 921 "../makeshell.c"
  puts(_("\n"
       "= = = = = = = =\n\n"
       "This incarnation of genshell will produce\n"
       "a shell script to parse the options for %s:\n\n"));
#line 167 "../enum.c"
  puts(_("  or an integer mask with any of the lower %d bits set\n"));
#line 897 "../usage.c"
  puts(_("\t\t\t\t- is a set membership option\n"));
#line 918 "../usage.c"
  puts(_("\t\t\t\t- must appear between %d and %d times\n"));
#line 382 "../usage.c"
  puts(_("Options are specified by single or double hyphens and their name.\n"));
#line 904 "../usage.c"
  puts(_("\t\t\t\t- may appear multiple times\n"));
#line 891 "../usage.c"
  puts(_("\t\t\t\t- may not be preset\n"));
#line 1309 "../usage.c"
  puts(_("   Arg Option-Name    Description\n"));
#line 1245 "../usage.c"
  puts(_("  Flg Arg Option-Name    Description\n"));
#line 1303 "../usage.c"
  puts(_("  Flg Arg Option-Name    Description\n"));
#line 1304 "../usage.c"
  puts(_(" %3s %s"));
#line 1310 "../usage.c"
  puts(_(" %3s %s"));
#line 387 "../usage.c"
  puts(_("The '-#<number>' option may omit the hash char\n"));
#line 383 "../usage.c"
  puts(_("All arguments are named options.\n"));
#line 971 "../usage.c"
  puts(_(" - reading file %s"));
#line 409 "../usage.c"
  puts(_("\n"
       "Please send bug reports to:  <%s>\n"));
#line 100 "../version.c"
  puts(_("\n"
       "Please send bug reports to:  <%s>\n"));
#line 129 "../version.c"
  puts(_("\n"
       "Please send bug reports to:  <%s>\n"));
#line 903 "../usage.c"
  puts(_("\t\t\t\t- may NOT appear - preset only\n"));
#line 944 "../usage.c"
  puts(_("\n"
       "The following option preset mechanisms are supported:\n"));
#line 1192 "../usage.c"
  puts(_("\n"
       "The following option preset mechanisms are supported:\n"));
#line 682 "../usage.c"
  puts(_("prohibits these options:\n"));
#line 677 "../usage.c"
  puts(_("prohibits the option '%s'\n"));
#line 81 "../numeric.c"
  puts(_("%s%ld to %ld"));
#line 79 "../numeric.c"
  puts(_("%sgreater than or equal to %ld"));
#line 75 "../numeric.c"
  puts(_("%s%ld exactly"));
#line 68 "../numeric.c"
  puts(_("%sit must lie in one of the ranges:\n"));
#line 68 "../numeric.c"
  puts(_("%sit must be in the range:\n"));
#line 88 "../numeric.c"
  puts(_(", or\n"));
#line 66 "../numeric.c"
  puts(_("%sis scalable with a suffix: k/K/m/M/g/G/t/T\n"));
#line 77 "../numeric.c"
  puts(_("%sless than or equal to %ld"));
#line 390 "../usage.c"
  puts(_("Operands and options may be intermixed.  They will be reordered.\n"));
#line 652 "../usage.c"
  puts(_("requires the option '%s'\n"));
#line 655 "../usage.c"
  puts(_("requires these options:\n"));
#line 1321 "../usage.c"
  puts(_("   Arg Option-Name   Req?  Description\n"));
#line 1315 "../usage.c"
  puts(_("  Flg Arg Option-Name   Req?  Description\n"));
#line 168 "../enum.c"
  puts(_("or you may use a numeric representation.  Preceding these with a '!'\n"
       "will clear the bits, specifying 'none' will clear all bits, and 'all'\n"
       "will set them all.  Multiple entries may be passed as an option\n"
       "argument list.\n"));
#line 910 "../usage.c"
  puts(_("\t\t\t\t- may appear up to %d times\n"));
#line 77 "../enum.c"
  puts(_("The valid \"%s\" option keywords are:\n"));
#line 1152 "../usage.c"
  puts(_("The next option supports vendor supported extra options:"));
#line 773 "../usage.c"
  puts(_("These additional options are:"));
  /* END-USAGE-TEXT */
}
#endif /* uncompilable code */
#ifdef  __cplusplus
}
#endif
/* systemkey-args.c ends here */
