<h1 align="center">
	🔗 pipex
</h1>

---

## 💡 About the project

> _The purpose of this project is the discovery in detail UNIX mechanism - pipe._

	The program `pipex` should repeat the behaviour of the next shell command
```bash
$> < file1 cmd1 | cmd2 > file2
```
and looks like this:
```bash
$> ./pipex file1 cmd1 cmd2 file2
```


## 🛠️ Usage

### Instructions

**1. Compiling the project**

To compile, go to the root path and run:

```shell
$ make
```

**2. Using the project**

To use the function specify input files, cmd 1, cmd 2 and file.
Example:

```C
./pipex Makefile cat "head -n 5" "wc -l" out
```

