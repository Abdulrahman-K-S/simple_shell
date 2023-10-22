# <p align='center'> simple_shell

<br>

## AUTHORS
This file lists all individuals who have contributed content to this repository.
## man_1_simple_shell
This file is a manual page for our simple Unix command line interpreter.
## C - Simple Shell Project
### Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- All files will be compiled on Ubuntu 14.04 LTS
- The C programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- The code uses the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl).
- There will be no more than 5 functions per file, and each file should end in a newline.
- All header files should be include guarded
- Only use system calls when necessary
### Output
- Unless specified, our program should have the exact same output as `sh` (`/bin/sh`) as well as the exact same error output. The only difference is when we print an error, the name of the program will be equivalent to our `argv[0]` (see below)

Example of error with `sh`:
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
```
Same error with our program `hsh`:
```
$ echo "qwerty" | /bin/hsh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
```
### List of allowed functions and system calls
- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `stat` (man 2 stat)
- `lstat` (man 2 lstat)
- `fstat` (man 2 fstat)
- `getcwd` (man 3 getcwd)
- `getline` (man 3 getline)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `opendir` (man 3 opendir)
- `perror` (man 3 perror)
- `read` (man 2 read)
- `readdir` (man 3 readdir)
- `signal` (man 2 signal)
- `strtok` (man 3 strtok)
- `wait` (man 2 wait)
- `waitpid` (man 2 waitpid)
- `wait3` (man 2 wait3)
- `wait4` (man 2 wait4)
- `write` (man 2 write)
- `_exit` (man 2 `_exit`)
- `isatty` (man 3 isatty)
- `fflush` (man 3 fflush)
### Compilation
The shell should be compiled in this way:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
### How it should work
Our shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
### The simple shell
What our UNIX command line interpreter does:
- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The command is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- Handle the "end of file" condition (`Control+D`)
- Handle the `PATH`
- Take the command `exit` that exits the shell.
- Print current environment with `env`
- Change the current working directory `cd`
- Handle special characters: `"`, `'`, `\`, `*`, `&`, `#`, `` ` ``

What our shell does not have to do:
- Be able to move the cursor.


<br>


## Contributors

Abdulrahman Khaled [Github](https://github.com/Bebo-K-S).

Fadi Haddad [Github](https://github.com/fadirafik).

<a href = "https://github.com/Bebo-K-S/simple_shell/graphs/contributors">
   <img src = "https://contrib.rocks/image?repo=bebo-k-s/simple_shell"/>
 </a>