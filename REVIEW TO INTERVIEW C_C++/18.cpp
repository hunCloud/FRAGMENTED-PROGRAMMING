/*18. How do you free up the allocated memory for an array?

To free up the emissive set for the array we use: delete []*/
template <typename T>
T* a = new T[11];
delete[] a;