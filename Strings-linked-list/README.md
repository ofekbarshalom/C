# C Strings Linked List

Suggested folder name for `Ex3`: **`C-string-list`**

This exercise implements a singly linked list of strings in C using:

- `strList.h` — public API declarations
- `strList.c` — implementation

## What it includes

The library supports:

- allocation/free (`StrList_alloc`, `StrList_free`)
- insert operations (`StrList_insertLast`, `StrList_insertAt`)
- removal operations (`StrList_remove`, `StrList_removeAt`)
- queries (`StrList_size`, `StrList_firstData`, `StrList_count`, `StrList_printLen`)
- utility operations (`StrList_clone`, `StrList_reverse`, `StrList_sort`, `StrList_isSorted`, `StrList_isEqual`)
- printing (`StrList_print`, `StrList_printAt`)

## Build

Compile as an object file:

```bash
gcc -Wall -Werror -c strList.c -o strList.o
```

Or compile with your own `main.c` test file:

```bash
gcc -Wall -Werror main.c strList.c -o program
./program
```

## Notes

- Strings are copied into internal node storage when inserted.
- Always release memory with `StrList_free` when done.
