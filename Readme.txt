Get Next Line.

C function. Read a line from a specified file descriptor (stdin, stdout or stderr).

Paramaters:
The function takes a const int fd(the file descriptor returned by the open function) and a char **line(a pointer to a char pointer used to point towards the a string of a line read from the file).

Return values:
The function returns an int(-1: When an error occurs, 0: When the end of file has been reached, 1: When the function successfully reads a line from the file).
