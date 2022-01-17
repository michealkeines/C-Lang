
'+' is string concatenation
'-' is string subtration, it removes the first instance
for ex: 'abcd' - 'bc' wil give 'ad'

indexing using []

'><' is substring match, it looks for substrings inside a string
'ab' >< 'aabcdz' is true; 'ab' >< 'test' is false

'>!<' is string dont match, it looks for substrings inside a string and returns the opposite as the '><'

'ab' >!< 'aabcdz' is false; 'ab' >!< 'test' is true

'=~' is regex match, it is similar to internal function ereg

s =~ "[ab]\*x+1" is equivalent to ereg(string:s, pattern:"[ab]\*x+1", icase:1)

!~ is regex dont match, opposite of regex match

in special cases

if one of its argument is undefined, + retunrs the other one

if one of its argument is a pure string, the other argument is converted to a string, impure string are converted to pure string withour escape sequence interpretation

"ab\nde" -> "ab\\nde" i.e ab a backslash, then nde






