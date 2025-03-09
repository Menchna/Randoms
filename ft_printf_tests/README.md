# ft\_printf

## 📌 Description

**`ft_printf`** is an implementation of the standard `printf` function from the C standard library. This function allows formatting and outputting strings with various format specifiers.

## Features

- Supports the following format specifiers:
  - **`%c`** — character
  - **`%s`** — string
  - **`%p`** — pointer
  - **`%d`**** / ****`%i`** — decimal number (int)
  - **`%u`** — unsigned decimal number (unsigned int)
  - **`%x`**** / ****`%X`** — hexadecimal number (lowercase/uppercase)
  - **`%%`** — prints the `%` character
- Uses only allowed functions (`write`, `malloc`, `free`, `va_start`, `va_arg`, `va_copy`, `va_end`)
- No memory leaks
