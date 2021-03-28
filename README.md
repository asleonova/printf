# printf

It's a recoding of the printf function in C. Printf can write combinations of strings, numbers of different bases, even pointers, to the stdout, with various options.

### Usage

* first run `make` to create the ``libftprintf.a`` binary.
* then `#include ft_printf.h` in your .c files where you use these libft functions.
* compile your files with the library with following flags:
```
gcc -L. -lftprintf your_file(s).c
```

### Available options

The function is called with the standard printf usage options.

You can print strings with ``%s``, or characters with ``%c``. For decimal numbers, use ``%d`` or ``%i``, or ``%u`` for unsigned. If you want another base, use ``%o`` for octal, ``%x`` for hexadecimal and ``%X`` for CAPS hexadecimal. Finally, ``%p`` displays a pointer address.

It can manage any combination of the following flags:  ``-`` and ``0`` (``%-5s`` or ``%05s``), as well as the width and precision like: (``%5s``), (``%.5s``)

### Example :

```c

ft_print("The number of %s is %d.", "people", 5);
// The number of people is 5.

ft_printf("%d is %x in hex and %o in octal.", 30, 30, 30);
// 30 is 1e in hex and 36 in octal.
```
