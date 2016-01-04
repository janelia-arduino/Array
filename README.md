#Array

Authors:

    Peter Polidoro <polidorop@janelia.hhmi.org>

License:

    BSD

An array container similar to the C++
[std::array](http://www.cplusplus.com/reference/array/array/), with
some [std::vector](http://www.cplusplus.com/reference/vector/vector/)
methods added. The maximum size is fixed as a template parameter, but
the size is variable, like a vector. Values can be pushed and popped
and the size adjusts accordingly. The data are stored internally as a
statically allocated c style array. Care must be taken not to
dereference an empty array or access elements beyond bounds.

[Usage Examples](./examples)

