# SNHU_Work
Banking.h, Banking.cpp, and main.cpp are part of Project Two created for SNHU's CS-210 class.

*Summarize the project and what problem it was solving.*
This program accepts user input for an initial investment, monthly investment yearly interest rate (compounded monthly), and number of years, then return the user's account balance and interest earned for each consecutive year up to the max number of years the user entered. The project used three files - Banking.cpp, Banking.h, and main.cpp. The idea behind the program is to show the user how their investment would grow over time depending on interest rates and the amount of deposits they make, regularly or with just one initial deposit.
 
*What did you do particularly well?*
I think I did quite well when formatting output, given that the length of the output adjust depending on the size of the balance in the user's account. I also think I did quite well with error catching, using try / catch and then clearing the entire line so that there were no repeats of error messages.

*Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?*
I think I could improve my code by finding a way to reduce redundancy in the Banking.cpp code when outputting amounts without and subsequently with interest. Doing so would make the code shorter and easier to read. I also believe if I were to implement some sort of UI this would make the program more visibly pleasing to use.

*Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?*
The most challenging piece of code to write was the input validation using try / catch. The issue I was having was that when the user would enter a long stream of incorrect input followed by a space, the error message would be displayed more than once. I ended up solving this by including a getline statement at the end of the try / catch so that user input would be cleared after the first error message was thrown. When I've run into issues such as this and other problems, I've found sites such as Stack Exchange, cplusplus.com, and w3schools to be quite useful, alongside any resources provided by SNHU such as textbooks.

*What skills from this project will be particularly transferable to other projects or course work?*
Input validation will be quite useful in other projects I'm sure, as well as implementing my own classes in C++.

*How did you make this program maintainable, readable, and adaptable?*
Throughout each project file I've included numerous comments about what variables are used for and how functions work. I've also made the project in such a way that the Banking class can be modified without ruining the main class, rather than writing functions in main.cpp. Doing so means that I could use the Banking class in other files, or modify the main.cpp file as I need without ruining the Banking class.
