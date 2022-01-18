comments are # to end of the line

tokens are parsed similar to C ansi

Strings, which can exist in two flavours "pure" and "impure"

"Impure" strings are entered between double quotes and are not converted: blacklslashes remain blackslashes.

impure stirngs are transformed into pure string by the internal string function

"Pure" strings are returned by string or entered between simple quores, in this case, a few escape sequences are transformed.

arrays, can be indexed with integers or strings

NULL value, is what we get if we read an when some error

![[Pasted image 20220117012130.png]]

all built in or user defined functions can hanlde or return all those types (even arrays)

NULL and array operator:

reading an array element form NULL value wil immediately convert it into a array(empty array), thus no undefined variable.

![[Pasted image 20220117012629.png]]

if you want to check is a variable is undefined, you have to use isnull(variable), testing the equality with the NULL is not good idea (variable == NULL)

nasl does not support floatin point operations

division or modulo by zero will return 0 instead of crashing

in all shift operators, the cound is on the right, ie x>>2 that is x/4 and x<<2 is x\*4
if the partter could not be compiled, you will get an NULL

to declare local and global variables explicitly

local_var var;
global_var var;

function declarations

user-defined function parameters must be named, unnamed argments may be used without declaring

named arguments are just accesed as any local variable

unnamed argements are implemented through the special array 'FCT_ANON_ARGS'

writing to that array is undefined

trying to read named arguments using that array returns NULL



# user defined functions

User defined functions cannot call itself, like recurssion



x is an other, that is short hand to repart any statement a given numver of time, like call a function 10 times

eg: send_packet(temp_packet) x 10;

this will call send_packet 10 times



In NASL there is no way you can open connection to some specific host, this way, a NASL script cannot be trojaned

