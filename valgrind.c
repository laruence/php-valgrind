/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2010 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Xinchen Hui <laruence@php.net>                               |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_valgrind.h"

#include <valgrind/callgrind.h>

ZEND_DECLARE_MODULE_GLOBALS(valgrind)

/* {{{ valgrind_functions[]
 */
zend_function_entry valgrind_functions[] = {
	PHP_FE(callgrind_toggle,	NULL)
	PHP_FE(callgrind_dump,	NULL)
	{NULL, NULL, NULL}
};
/* }}} */

/* {{{ PHP_GINIT_FUNCTION
*/
PHP_GINIT_FUNCTION(valgrind)
{
	valgrind_globals->flag = 0;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(valgrind)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "valgrind support", "enabled");
	php_info_print_table_header(2, "version", VALGRIND_VERSION);
	php_info_print_table_end();
}
/* }}} */

/* {{{ proto bool callgrind_toggle()
 */
PHP_FUNCTION(callgrind_toggle)
{
	VALGRIND_G(flag) = !VALGRIND_G(flag);
	if (VALGRIND_G(flag)) {
		CALLGRIND_START_INSTRUMENTATION;
	} else {
		CALLGRIND_STOP_INSTRUMENTATION;
	}
	CALLGRIND_TOGGLE_COLLECT;

	RETURN_BOOL(VALGRIND_G(flag));
}
/* }}} */

/* {{{ proto bool callgrind_dump()
 */
PHP_FUNCTION(callgrind_dump)
{
	CALLGRIND_DUMP_STATS;

	RETURN_TRUE;
}
/* }}} */

/* {{{ valgrind_module_entry
 */
zend_module_entry valgrind_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"valgrind",
	valgrind_functions,
	NULL,
	NULL,
	NULL,
	NULL,
	PHP_MINFO(valgrind),
	VALGRIND_VERSION,
	PHP_MODULE_GLOBALS(valgrind),
	PHP_GINIT(valgrind),
	NULL,
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};
/* }}} */

#ifdef COMPILE_DL_VALGRIND
ZEND_GET_MODULE(valgrind)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
