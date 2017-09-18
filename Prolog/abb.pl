% >swipl -s file.pl

% emptyTree -> nil
% bst(K, L, R) -> K = key, L = left node, R = right node.

% insertKey(T, X, T2) = insert key X in tree T, resulting in tree T2.

insertKey(bst(K, L, R), X, bst(K, L2, R)) :- X < K, insertKey(L, X, L2).
insertKey(bst(K, L, R), X, bst(K, L, R2)) :- X > K, insertKey(R, X, R2).
insertKey(bst(K, L, R), X, bst(K, L, R)) :- X = K.
insertKey(nil, X, bst(X, nil, nil)).


% search(K, T, T2) -> obtains the subtree T2 with the key K in the tree T.

search(X, nil, nil).
search(X, bst(X, L, R), bst(X, L, R)).
search(X, bst(K, L, _), T) :- X < K, search(X, L, T).
search(X, bst(K, _, R), T) :- X > K, search(X, R, T).


% preorder(T) -> prints the tree T in preorder

preorder(nil) :- write(" () ").
preorder(bst(K, nil, nil)) :- write(" ( "), write(K), write(" ) ").
preorder(bst(K, L, R)) :- write(" ( "), write(K), preorder(L), preorder(R),  write(" ) ").


% removeKey(T, X, T2) -> removes the key X from the tree T, resulting in T2.

removeKey(nil, _, _).
removeKey(bst(K, L, R), X, bst(K, L2, R)) :- X < K, removeKey(L, X, L2).
removeKey(bst(K, L, R), X, bst(K, L, R2)) :- X > K, removeKey(R, X, R2).
removeKey(bst(K, nil, nil), X, nil) :- X = K.
removeKey(bst(K, nil, bst(R, L2, R2)), X, bst(R, L2, R2)) :- X = K.
removeKey(bst(K, bst(L, L2, R2), nil), X, bst(L, L2, R2)) :- X = K.
removeKey(bst(K, L, R), X, bst(K2, L2, R)) :- X = K, sup(L, K2, L2).


% sup(T, K2, L2) -> searches the biggest key (K2) in T and returns the resulting subtree L2 without it.

sup(bst(K, L, nil), K, L). 
sup(bst(K, L, R), K2, bst(K, L, R2)) :- sup(R, K2, R2).



% example of tree:
% bst(5, bst(3, nil, nil), bst(7, nil, nil)) ).
% insertKey(nil, 5, T), insertKey(T, 3, T2), insertKey(T2, 7, T3), insertKey(T3, 4, T4), insertKey(T4, 1, T5), insertKey(T5, 6, T6), insertKey(T6, 8, T7).

% insertKey(nil, 4, T), insertKey(T, 2, T2), insertKey(T2, 6, T3), insertKey(T3, 1, T4), insertKey(T4, 3, T5), insertKey(T5, 5, T6), insertKey(T6, 7, T7).

% insertKey(nil, 4, T), insertKey(T, 4, T2), insertKey(T2, 2, T3), insertKey(T3, 6, T4), insertKey(T4, 1, T5), insertKey(T5, 3, T6), insertKey(T6, 5, T7), insertKey(T7, 7, T8).

% bst(4, bst(2, bst(1, nil, nil), bst(3, nil, nil)), bst(6, bst(5, nil, nil), bst(7, nil, nil)))

% bst(5, bst(3, nil, nil), nil ).