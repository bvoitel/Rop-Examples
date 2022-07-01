# ROP-Examples
 
Here are two ROP-Examples which I use in the CPENT course and leave it to you to practice with. I included a compiled version (with symbols) and the sourcecode.  

**NOTE: Disable the ALSR with the following command before trying these:**  
```  
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space  
```  

**NOTE2: Make rop1b a SUID binary with root as the owner**  
```  
chown root:root rop1b  
chmod u+s rop1b
```  

Approach is usually as follows:  

1) Fuzzing (finding out, whether a buffer overflow exists)  
2) Calculate offset when EIP gets overwritten (e.g. using pattern_create and pattern_offset from gdb PEDA)  
3) Overwrite the stack with addresses to the gadgets (REMEMBER to use little endian format (write the hex codes in reverse!))  

## rop1a  

Here we simply try to run the functions rop1(), rop2(), rop3() and then use exit() to leave gracefully.

## rop1b  

A small variation of the above. Try to run the `shellnotcalled` function to get a rootshell.  

## Some useful gdb commands

```
b main - breakpoint at beginning of function
delete # - delete breakpoint
clear - delete all breakpoints
p main - value / address of function or $register or &variable
r "params" - run
c - continues until next breakpoint or error
s - step / next instruction
f - runs until current function is finished
disassemble main - disassemble named function or current location
info functions
info registers
x/10x $esp - display 10 elements of the stack
ropgadgets
´´´

