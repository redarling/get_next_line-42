# 📄 get_next_line

## Project Description

get_next_line is a function that reads a line from a file descriptor. It allows you to read line by line from a file, which could be pretty useful.

## 🛠️ Installation Instructions

1. Clone the repository using the command:

        git clone https://github.com/redarling/get_next_line-42.git

2. Navigate to the project directory:

        cd get_next_line-42

## 💻 Usage

1. Include the header file in your project:

        #include "get_next_line.h"

2. Call the function get_next_line in your code to read a line from a file descriptor:

           int        fd;

           fd = open("example.txt", O_RDONLY);
           if (fd < 0)
                   return (1);
           printf("The output line: %s\n", get_next_line(fd));

## 📝 Author
- [asyvash](https://github.com/redarling)
