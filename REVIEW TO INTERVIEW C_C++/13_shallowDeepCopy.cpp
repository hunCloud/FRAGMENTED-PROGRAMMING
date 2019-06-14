/*13. What is the difference between a "shallow" and a "deep" copy?

Shallow copy:

Copy the value of one object to another.
With the cursor, only copy the value (2 objects still point to the same address of the cursor)
=> this object changes the value of the cursor, the other object also changes.
Deep copy:

Copy the value of one object to another.
With the cursor created the new address is assigned to the copied object.
=> this object replaces the value of the cursor, the object does NOT change.
=> in deep copy must prepend the assignment operator and redefine the copy constructor function*/