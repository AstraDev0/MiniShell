# 42sh

Welcome to the 42sh project! This README provides a comprehensive overview of the project requirements, structure, and key features, integrating the functionalities of the previous Minishell1 and Minishell2 projects. The 42sh project is designed to create a fully-fledged Unix shell based on TCSH.

## Preliminaries

- **Binary Name**: `42sh`
- **Language**: C
- **Group Size**: 4 - 5
- **Compilation**: Via `Makefile`, including `re`, `clean`, and `fclean` rules.

### Authorized Functions

All functions included in the `libC` or the `ncurses` library.

## Project Requirements

1. **Source Files**: Include all source files, excluding unnecessary files like binaries, temporary files, and object files.
2. **Error Handling**: All error messages should be written to the error output, and the program should exit with the same error code as TCSH should.

## Features

### Basic Shell Functionalities

#### Command Execution

- **Prompt**: The shell should display a prompt (e.g., `$>`) and wait for command input.
- **Basic Command Lines**: Execute basic command lines found in the `PATH` variable. If the executable cannot be found, display an error message and prompt again.
- **Built-in Commands**: Implement the following built-ins:
  - `cd`: Change the current directory.
  - `setenv`: Set or modify an environment variable.
  - `unsetenv`: Remove an environment variable.
  - `env`: Display the environment.
  - `exit`: Exit the shell.

#### Environment Handling

- **PATH and Environment**: Handle the `PATH` and environment by copying and restoring the initial environment. Ensure the shell correctly processes and utilizes environment variables.

### Advanced Command Handling

#### Command Separators and Pipelines

- **Semicolons (`;`)**: Allow command separation to execute multiple commands sequentially.
- **Pipes (`|`)**: Enable the output of one command to be used as the input for the next command.

#### Redirections

- **Redirection Operators**:
  - `>`: Redirect output to a file, overwriting the file.
  - `<`: Redirect input from a file.
  - `>>`: Append output to a file.
  - `<<`: Here-document; read input until a line containing only the delimiter is seen.

### TCSH Compatibility and Additional Features

#### TCSH Compatibility

- **Error Codes**: Ensure that error handling is consistent with TCSH, including returning the same error codes.
- **Reference Shell**: TCSH is the reference shell for command syntax and compatibility.

#### Enhanced Features

- **Inhibitors**: Handle characters like quotes (`'` and `"`).
- **Globbings**: Support wildcards (`*`, `?`, `[`, `]`) for file name expansion.
- **Job Control**: Implement job control commands (`&`, `fg`, `bg`).
- **Backticks**: Execute commands within backticks (`\``) and replace them with their output.
- **Parentheses**: Handle command grouping with parentheses (`(` and `)`).
- **Special Variables**: Manage special variables like `term`, `precmd`, `cwdcmd`, `cwd`, `ignoreof`.

## Compilation

To compile the project, use the provided `Makefile` with the following rules:
- `re`: Recompile the project.
- `clean`: Remove temporary files.
- `fclean`: Remove all generated files, including binaries.