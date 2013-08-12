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

#ifndef PHP_VALGRIND_H
#define PHP_VALGRIND_H

extern zend_module_entry valgrind_module_entry;
#define phpext_valgrind_ptr &valgrind_module_entry

#ifdef PHP_WIN32
#define PHP_VALGRIND_API __declspec(dllexport)
#else
#define PHP_VALGRIND_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#define VALGRIND_VERSION "0.1.0"

PHP_MINFO_FUNCTION(valgrind);

PHP_FUNCTION(callgrind_toggle);	
PHP_FUNCTION(callgrind_dump);	

ZEND_BEGIN_MODULE_GLOBALS(valgrind)
	zend_bool flag;
ZEND_END_MODULE_GLOBALS(valgrind)

#ifdef ZTS
#define VALGRIND_G(v) TSRMG(valgrind_globals_id, zend_valgrind_globals *, v)
#else
#define VALGRIND_G(v) (valgrind_globals.v)
#endif

#endif	/* PHP_VALGRIND_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
