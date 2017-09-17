type 'a bst =
    Empty
|   Node of 'a * 'a bst * 'a bst;;

exception Leaf;;

let empty = Empty;;

let comp r (i,d) = Node (r,i,d);;

let rec insertKey x = function
	Empty -> Node (x, Empty, Empty)
| 	Node (k, l, r) ->
		if (x < k) then
			Node (k, (insertKey x l), r)
		else if (x > k) then
			Node (k, l, (insertKey x r))
		else
			Node (k, l, r);;

let isEmpty = function
    Empty -> true
|   Node(_,_,_) -> false;;

let leftSon = function
    Empty -> raise Leaf
|   Node(_,l,_)-> l;;

let rightSon = function
    Empty -> raise Leaf
|   Node(_,_,r)-> r;;

let root = function
    Empty -> raise Leaf
|   Node(r,_,_) -> r;;

let rec removeKey x = function
	Empty -> Empty
| 	Node(k, l, r) -> 
		if (x < k) then
			Node (k, (removeKey x l), r)
		else if (x > k) then
			Node (k, l, (removeKey x r)) 
		else if (isEmpty l) then
			try Node (root r, leftSon r, rightSon r)
			match Leaf -> Empty
		else if (isEmpty r) then
			Node (root l, leftSon l, rightSon l)
			(* no hace falta otro try porque ya sabemos que no
				son los dos hijos Empty*)
		else
			let auxRoot, aux
			Node(sup l, ;;

let rec sup Node(k, l, r) =
	if (isEmpty r) then
		Node(k, ) 
	else
		Node(k, l, sup r);;