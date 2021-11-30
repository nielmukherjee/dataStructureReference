# hash-table
Hash table implemented in C++ (named WordSet)

Basics:
- used to implement map and set data structures
- each value is mapped to a distinct key using a hashing function
- efficient lookup, insert, and delete operations

Implementation Details:
Our hash table (specific to strings) is built using an underlying array. Since we want the size of the array to be a prime (better for the hashing function), we have a constant int array of possible sizes. Once our array exceeds the LOAD_LIMIT (0.25), we create a new array of larger size and add the elements into that. 

To insert elements, we use a hashing function to compute the corresponding key given the current size of the array, base (37), and the new string to be added. We then use quadratic probing to find the desired position. 

