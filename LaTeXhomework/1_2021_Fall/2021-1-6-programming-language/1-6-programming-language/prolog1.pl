parent(a1, b1).
parent(a1, b2).
parent(b1, c1).

parent(a2, b3).
parent(a3, b3).
parent(b3, c4).
parent(b3, c5).

/* 判断 X 是否是 Y 的祖先。 */
isAncestor(X, Y) :-
    true.

/* 判断 X 是否是 Y 的旁系血亲，即 X 和 Y 有一个共同祖先，但他们互相不是对方的祖先 */
isCollaterialRelative(X, Y) :-
    true.

test(Description, Assertion) :-
    Assertion, write(Description), write(' passed.'), nl;
    \+ Assertion, write(Description), write(' failed!'), nl.

main :-
    test("Ancestor Test 1", isAncestor(a1, c1)),
    test("Ancestor Test 2", \+ isAncestor(b1, a1)),
    test("Ancestor Test 3", \+ isAncestor(b1, b2)),
    test("Ancestor Test 4", isAncestor(a2, c4)),
    test("Ancestor Test 5", \+ isAncestor(a2, a2)),
    test("Ancestor Test 6", \+ isAncestor(a1, b3)),
    
    test("Collaterial Relative Test 1", isCollaterialRelative(c1, b2)),
    test("Collaterial Relative Test 2", isCollaterialRelative(c4, c5)),
    test("Collaterial Relative Test 3", \+ isCollaterialRelative(b3, c4)),
    test("Collaterial Relative Test 4", \+ isCollaterialRelative(c4, b3)),
    test("Collaterial Relative Test 5", \+ isCollaterialRelative(c1, c4)).