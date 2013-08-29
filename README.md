php-valgrind
============

A PHP valgrind tool, it can be used to toggle collect in PHP scripts

```php
<?php
$a =array();
callgrind_toggle();
for ($i=0;$i<100;$i++) {
   $a[$i] = 2;
}
callgrind_toggle();
callgrind_dump();  //This is optional in this case
```


then you must run valgrind with auto-toggle and auto-instr both off

```
$valgrind --tool=callgrind --collect-atstart=no --instr-atstart=no php /tmp/1.php

//Output:
...
==3533== Events    : Ir
==3533== Collected : 2361260
==3533==
==3533== I   refs:      2,361,260

```

then you will get a callgrind.out.*, let's open it with qcachegrind(or kcachegrind, callgrind_annotate)

![callgrind.out](https://github.com/laruence/laruence.github.com/raw/master/callgrind.png)

