AC_PREREQ([2.69])
AC_INIT([ctexgen], [1.0], [hasnain.mohsan@gmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([subdir-objects])

AC_CONFIG_SRCDIR([cli/src/main.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([makefile])

AC_PROG_CC
AC_PROG_RANLIB

AC_DEFINE([DEFAULT_INPUT_MODEL_NAME], ["model.mkv"], [The default input model name])
AC_DEFINE([DEFAULT_OUTPUT_MODEL_NAME], ["model.mkv"], [The default output model name])
AC_DEFINE([DEFAULT_INPUT_TEXT_FILE], ["input.txt"], [The default input text file])
AC_DEFINE([DEFAULT_TEXT_LENGTH_MIN], ["64"], [The default minimum length of text to generate])
AC_DEFINE([DEFAULT_TEXT_LENGTH_MAX], ["128"], [The default maximum length of text to generate])

AC_OUTPUT