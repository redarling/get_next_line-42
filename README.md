# get_next_line

## Project Description 📝

get_next_line is a function that reads a line from a file descriptor. It allows you to read line by line from a file or a stream such as the standard input. This function is particularly useful for reading from files of unknown or variable length.

## 🛠️ Installation Instructions

1. Clone the repository using the command:

        git clone https://github.com/redarling/get_next_line-42.git

2. Navigate to the project directory:

        cd get_next_line-42

## 💻 Usage

1. Include the header file in your project:

        #include "get_next_line.h"

2. Call the function get_next_line in your code to read a line from a file descriptor:

        int    fd;

        fd = open("example.txt", O_RDONLY);
        printf("The output line: %s\n", get_next_line(fd));

## 📝 Author
- [asyvash](https://github.com/redarling)
