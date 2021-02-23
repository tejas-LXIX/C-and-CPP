/*it is a simple templated class which wraps a native array. It does not use malloc/realloc. Instead, it uses the passed allocator (which by default is std::allocator).

Resizing is done by allocating a new array and copy constructing each element in the new array from the old one (this way it is safe for non-POD objects). To avoid frequent allocations, often they follow a non-linear growth pattern.

UPDATE: in C++11, the elements will be moved instead of copy constructed if it is possible for the stored type.

In addition to this, it will need to store the current "size" and "capacity". Size is how many elements are actually in the vector. Capacity is how many could be in the vector.*/