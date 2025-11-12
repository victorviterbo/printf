# ft_printf

A recode of the standard C `printf` function. This project teaches variadic functions and the management of complex, formatted output.

## 🖨️ Supported Conversions
- `%c` - Characters
- `%s` - Strings
- `%p` - Pointers
- `%d`, `%i` - Signed integers
- `%u` - Unsigned integers
- `%x`, `%X` - Hexadecimal numbers
- `%%` - Percent sign

## 🎯 Features
- Manages flags, width, and precision for most specifiers
- Handles minimum field width
- Precision specification
- Variadic argument handling

## 🚀 Usage
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you have %d messages!\n", "User", 5);
    return (0);
}
