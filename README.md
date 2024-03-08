# Simple Shell Project

## Description

This project, created by Mahmoud Mostafa Ahmed, is part of the ALX Software Engineering curriculum, specifically the "0x16. C - Simple Shell" module. I am undertaking this project individually.

The goal is to create a simple UNIX command interpreter, which mimics the basic functionalities of a shell. This project serves as a practical application of what I've learned about C programming, system calls, process management, and more.

## Objective

By the end of this project, I aim to demonstrate a comprehensive understanding of how a shell works, including process creation and synchronization, environment manipulation, and the execution of programs within a shell context.

## Key Learning Concepts

- Basics of programming in C
- Understanding UNIX system calls
- Process creation and management
- Environment manipulation
- Development of problem-solving and engineering skills

## This Project was built using only some of these functions

`access`, `chdir`, `close`, `closedir`, `execve`, `exit`, `_exit`, `fflush`, `fork`, `free`, `getcwd`, `getline`, `getpid`, `isatty`, `kill`, `malloc`, `open`, `opendir`, `perror`, `read`, `readdir`, `signal`, `stat (__xstat)`, `lstat (__lxstat)`, `fstat (__fxstat)`, `wait`, `waitpid`, `wait3`, `wait4`, `write`

## Installation

To install and run this shell on your local machine, follow these steps:

``` bash
$ git clone https://github.com/m7moud-mostafa/simple_shell.git
$ cd simple_shell
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

Run the shell in interactive mode:

``` bash
$ ./hsh
```

Or in non-interactive mode:

``` bash
$ echo "/bin/ls" | ./hsh
```

## Features

- Basic command line interpretation
- Execution of commands in the PATH
- Handling of command lines with arguments
- Implementation of built-in commands like `exit`, `env`, `cd`

## Author

- Mahmoud Mostafa Ahmed
