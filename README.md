# Compiler Design: Top Down Parser
Provide Rules and Input to check if the input string is valid as per the rules
<br>The Rules should not have left recursion.
<br>More on Left Recursion and eliminating it: https://en.wikipedia.org/wiki/Left_recursion 
<hr>

**Example:**

```
E -> E+T | E-T | T
T -> T*F | T/F | F
F -> 0|1|2|3|4|5|6|7|8|9
contains Left Recursion

After eliminating Left Recursion:
E -> TA
A -> +TA | -TA | e
T -> FB
B -> *FB | /FB | e
F -> 0|1|2|3|4|5|6|7|8|9
```
