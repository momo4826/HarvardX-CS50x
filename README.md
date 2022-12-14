<p align="center">
    <img src="./img/uni_img.png" alt="logo" height="150"/>
</p>
<p align="center">
    <a href="https://cs50.harvard.edu/x/2022/">official website</a> |
    <a href="https://www.edx.org/course/introduction-computer-science-harvardx-cs50x">edx course</a> |
</p>

## Intro
Here you can find notes, problem sets and solutions of Harvard CS50x 2022 from week 1 - week 8.

## Set up Environments
If you're new to Computer Science, to start this course, first please follow [this manual](https://cs50.harvard.edu/x/2022/new/#did-you-start-cs50x-in-2021-or-earlier) to set up your CS50 IDE and CS50 Codespace.

Or if you want to set up an environment locally, follow this [instruction](https://momo4826.github.io/2022/12/02/developing-c-programs-on-mac-os-and-windows).
## Walk through
I will walk you through the whole process by create and submit a "hello.c", which is the first problem in Problem Set 1.

In order to use the pipeline of CS50X, first please follow [this manual](https://cs50.harvard.edu/x/2022/new/#did-you-start-cs50x-in-2021-or-earlier) to set up your CS50 IDE and CS50 Codespace.

Now create a new file by execute `code hello.c` in terminal of online VS Code. Edit your program like:
```c
    #include<stdio.h>
    #include<cs50.h>
    int main(void)
    {
        // Enter a username
        string name = get_string("What's your name? ");
        // say hello to this user
        printf("hello, %s\n", name);
    }
```
Execute `check50 cs50/problems/2022/x/hello` to check your program.

<p align="center">
    <img src="./img/cs50_editor_command_1.png" alt="check" height="250"/>
</p>

Use `style50 hello.c` to evaluate the style of your code. It's very useful especially if you're new to Computer Science.

<p align="center">
    <img src="./img/cs50_editor_command_2.png" alt="style" height="250"/>
</p>


To submit your work, execute `submit50 cs50/problems/2022/x/hello` in terminal.

<p align="center">
    <img src="./img/cs50_editor_command_3.png" alt="submit" height="250"/>
</p>


Then you can see your work in `submit.cs50.io`.
