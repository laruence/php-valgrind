dnl $Id$
PHP_ARG_WITH(valgrind, for valgrind support,
[  --with-valgrind     Include valgrind support])

if test "$PHP_VALGRIND" != "no"; then
  SEARCH_PATH="/usr/local /usr"
  SEARCH_FOR="/include/valgrind/valgrind.h"
  if test -r $PHP_VALGRIND/$SEARCH_FOR; then
    VALGRIND_DIR=$PHP_VALGRIND
  else
    AC_MSG_CHECKING([for valgrind files in default path])
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        VALGRIND_DIR=$i
        AC_MSG_RESULT(found in $i)
      fi
    done
  fi
  
  if test -z "$VALGRIND_DIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall the valgrind distribution])
  fi

  PHP_ADD_INCLUDE($VALGRIND_DIR/include)

  dnl LIBNAME=valgrind
  dnl LIBSYMBOL=valgrind

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $VALGRIND_DIR/lib, VALGRIND_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_VALGRINDLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong valgrind lib version or lib not found])
  dnl ],[
  dnl   -L$VALGRIND_DIR/lib -lm -ldl
  dnl ])
  dnl 
  dnl PHP_SUBST(VALGRIND_SHARED_LIBADD)

  PHP_NEW_EXTENSION(valgrind, valgrind.c, $ext_shared)
fi
