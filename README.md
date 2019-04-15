#C program for clang static analyzer test

- The C program have some vulnerabilities which are incompliant examples of [CMU SEI CERT rules](https://wiki.sei.cmu.edu/confluence/display/c/SEI+CERT+C+Coding+Standard) for C code
  - The name of C source code file indicates the file including violation of which CERT rules
  - executable file will be in directory build after compiling
- Makefile is aligned with usage of clang static analyzer
  - Line 25 in Makefile "CC = g++" is there because clang static analyzer works by substituting CC
  - If run without clang static analyzer, line 25 need to be removed
- How to run with clang static analyzer
 - compile source code with clang static analyzer: scan-build make
 - view report if bugs detected: scan-view [report name]
```


