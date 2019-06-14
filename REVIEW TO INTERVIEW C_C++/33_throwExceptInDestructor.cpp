/*33. Why don't you ever throw an exception in a cancel function?

Throwing an exception in the cancel function is undefined behavior, it can crash the program. Because often in the destruct function we just clean up, destroy objects so if an error occurs we can ignore them.*/
