<h1 align="center">
    <p>
        📓 Printf
    </p>
</h1>

<p align="center">
    <b><i>Repo for the Printf project at 42 Heilbronn</i></b>
</p>

<p align="center">
    This repository is coded in&nbsp&nbsp
    <a href="https://skillicons.dev">
        <img src="https://skillicons.dev/icons?i=c" />
    </a>
     &nbsp&nbspwith&nbsp&nbsp
    <a href="https://skillicons.dev">
        <img src="https://skillicons.dev/icons?i=neovim" />
    </a>
</p>

<h3 align="center">
    Status
</h3>

<p align="center">
    Finished: 06/04/2023<br>
    Grade: 100%
</p>

---

## 💾 About
> The task of the Printf project is to code a function that can handle input of different formats and prints it to the terminal.

## Table of Contents
- [Available specifiers](#available-specifiers)
- [Installation](#installation)
- [Tests](#tests)
- [License](#license)

## Available specifiers 
* %c: character
* %s: string
* %i: integer
* %d: decimal
* %u: unsigned integer
* %x: hexadecimal lowercase character
* %X: hexadecimal uppercase character
* %p: pointer

## Installation
To install the library, follow these steps:
1. Clone the repository: 
```shell
% git clone https://github.com/kurz-m/Printf.git
```
2. Run the Makefile: 
```shell
% cd Printf && make
```
3. Add the header file to your source code and add the library to the compiler: 
```c
#include "libftprintf.h"
```
```shell
% cc [your function] -L[path/to/lib] -lftprintf
```

## Tests
The tests I wrote are written with [Criterion](https://criterion.readthedocs.io/en/master/index.html).
It is a unit testing framework for testing C and C++ code. The difficult part with testing
my `ft_printf()` function is that I had to capture _STDOUT_ in some way and compare it to 
the real `printf()`. To be able to compare the 2 functions, I used the `cr_redirect_stdout()` 
and redirected the output of my function to a variable. Furthermore, I created a buffer 
and redirected the _STDERR_ to that buffer. With `fprintf()` I then printed to _STDERR_ and I then 
was able to compare that buffer with `cr_expect_stdout_eq_str(buf)` to my function.

## License
[MIT](https://choosealicense.com/licenses/mit/)
