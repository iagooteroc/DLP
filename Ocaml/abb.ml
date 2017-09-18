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
			with Leaf -> Empty
		else if (isEmpty r) then
			Node (root l, leftSon l, rightSon l)
			(* no hace falta otro try porque ya sabemos que no
				son los dos hijos Empty*)
		else
			let (auxRoot, auxLeft) = sup l in
			Node(auxRoot, auxLeft, r);;

let rec sup (Node(k, l, r)) =
	if (isEmpty r) then
		if (isEmpty l) then
			(k, Empty)
		else 
			(k, Node(root l, leftSon l, rightSon l)) 
	else
		let (auxRoot, auxLeft) = sup r in
		(auxRoot, Node(k, l, auxLeft));;


let rec preorder t =
    try (root t::preorder (leftSon t)) @ preorder (rightSon t)
    with Leaf -> [];;


let rec search x = function
	Empty -> Empty
| 	Node (k, l, r) ->
		if (x < k) then
			search x l
		else if (x > k) then
			search x r
		else 
			Node (k, l, r);;


let rec preorder = function
    Empty        -> Printf.printf " () "
|   Node (k, Empty, Empty) -> 
        Printf.printf " ( ";
        Printf.printf "%d" k;
        Printf.printf " ) "
|   Node (k,l,r) -> 
        Printf.printf " ( ";
        Printf.printf "%d " k;
        preorder l;
        preorder r;
        Printf.printf " ) ";;


(*
let t = insertKey 4 Empty;;
let t = insertKey 4 t;;
let t = insertKey 2 t;;
let t = insertKey 6 t;;
let t = insertKey 1 t;;
let t = insertKey 3 t;;
let t = insertKey 5 t;;
let t = insertKey 7 t;;

preorder t;;

search 1 t;;
search 2 t;;
search 3 t;;
search 4 t;;
search 5 t;;
search 6 t;;
search 7 t;;

let newt = removeKey 5 t;;
preorder newt;;
let newt = removeKey 6 newt;;
preorder newt;;
let newt = removeKey 4 newt;;
preorder newt;;
let newt = removeKey 2 newt;;
preorder newt;;


*)
