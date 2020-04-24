# avail
simple shell with count, occurence and format function
### CEN-232-Project1-Group7-Task3
```
18001534
18001505
18001496
```
### Compile
compiler: gcc
```
make
```
### Run
```
./avail
```
### Usage
```
count <path> [OPTION]
occur <path> <str>
format <path> <opath> [OPTION]
```

**Tools**

``count`` - count amount of characters/words/lines

``occur `` - count all occurrences of characters/words

``format`` - format camelcase/snakecase/lowercase/uppercase

**Options**

**count**
```
-c         //count number characters in a file

-w         //count number of words in a file

-l         //count number of lines in a file
```

**occur** 
```
<str>      //count occurrences of specified string (character or word) in a file
```

**format**
```
-u        //convert text to uppercase in a file

-l        //convert text to uppercase in a file

-sc       //convert text to snakecase in a file
```