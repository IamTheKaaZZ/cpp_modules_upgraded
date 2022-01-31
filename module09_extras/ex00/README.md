# The exercise

To formalize what was suggested as exercise would be to:
 - Define a class to represent a Matrix
 - Define operators for arithmetic operations, some with overloads (ex: matrix x number, matrix x matrix)
 - Define a print for the matrix (you could also define the << operator for that)
 - Experiment with your class and the operators you defined (printing stuff along the way)

# The Decision between Member and Non-member

> The binary operators = (assignment), [] (array subscription), -> (member access), as well as the n-ary () (function call) operator,
must always be implemented as member functions, because the syntax of the language requires them to.

## Other operators can be implemented either as members or as non-members.
Some of them, however, usually have to be implemented as non-member functions, because their left operand cannot be modified by you.
The most prominent of these are the input and output operators << and >>,
whose left operands are stream classes from the standard library which you cannot change.
</br>
For all operators where you have to choose to either implement them as a member function or a non-member function,
use the following rules of thumb to decide:
</br>
<ul>
    <li>If it is a unary operator, implement it as a member function.</li>
    <li>If a binary operator treats both operands equally (it leaves them unchanged), implement this operator as a non-member function.</li>
    <li>If a binary operator does not treat both of its operands equally (usually it will change its left operand), it might be useful to make it a member function of its left operand’s type, if it has to access the operand's private parts.</li>
</ul>

## Of course, as with all rules of thumb, there are exceptions.

If you have a type
```
enum Month {Jan, Feb, ..., Nov, Dec}
```
and you want to overload the increment and decrement operators for it,
you cannot do this as a member functions, since in C++, enum types cannot have member functions.</br>
So you have to overload it as a free function.</br>
And operator<() for a class template nested within a class template is much easier to write and read when done as a member function inline in the class definition.</br>
But these are indeed rare exceptions.</br>

### Exceptions

However, if you make an exception, do not forget the issue of const-ness for the operand that,
for member functions, becomes the implicit this argument.</br>
If the operator as a non-member function would take its left-most argument as a const reference,
the same operator as a member function needs to have a const at the end to make *this a const reference.
