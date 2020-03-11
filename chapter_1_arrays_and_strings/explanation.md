# Is unique: Implement an algorithm to determine if a string has all unique characters. 
## What if you cannot use additional data structures?

### My first thoughts are to use a map in order to count how many times each character appears in the string. I iterate through all the characters from the string and add one to it's value on the map (which starts with 0). After that I verify if the value is greater than 1, if it is, the string doesn't have unique characters.

### Changes I thought about after:

#### To use a vector instead of a map, with each char being associated to its ASCII respective code. This would probably make more space be used but if the characters are limited can be faster than a map.

#### Instead of using int values in the map, using boolean values, since they occupy less space and are faster to be compared. All values begin with true, once it is visited it is reversed (value = !value) and if this value is true, the word has non unique characters.
