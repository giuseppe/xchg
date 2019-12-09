xchg
===========

Expose `renameat2(int olddirfd, const char *oldpath, int
newdirfd, const char *newpath, RENAME_EXCHANGE)` to atomically
exchange two files.

## Build

Assuming you have the autotools and gcc installed:

```console
$ ./autogen.sh && ./configure && make
```

## Usage

```console
$ xchg /path/to/file1 /path/to/file2
```
