php-valgrind
============

A PHP valgrind tool, it can be used to toggle collect in PHP scripts

```php
<?php
callgrind_toggle();
for ($i=0;$i<10000;$i++) {
}
callgrind_toggle();
callgrind_dump();
```
