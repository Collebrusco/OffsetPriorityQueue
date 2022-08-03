# Data Structures
Repo for storing custom data structures I've made.
Some have been for specific applications, some for practice.

# OffsetPriQueue.h
Queue structure that keeps list of composite data types. Queue is kept in order based off of a given data member of the compound data type that the Queue is storing. This is useful for things like Prim's algorithm. Takes two template arguments, first is compound type Queue will store, second is type of member variable that will be used to keep order. Constructor takes offset of this data member in struct.
