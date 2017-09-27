(* Note: this file results automatically in a module implementation
        named Abb *)

(*------Auxiliar functions to work with pointers in Ocaml-------*)

type 'a pointer = Null | Pointer of 'a ref;;

let ( !^ ) = function
    | Null -> invalid_arg "Attempt to dereference the null pointer"
    | Pointer r -> !r;;

let ( ^:= ) p v =
    match p with
    | Null -> invalid_arg "Attempt to assign the null pointer"
    | Pointer r -> r := v;;

let new_pointer x = Pointer (ref x);;

(****************************************************************)

type tKey = int;;
type tPos = tNode pointer
and tNode = Empty | Node of nodeStruct
and nodeStruct = {
    mutable key: tKey; 
    mutable left: tPos;
    mutable right: tPos};;
type tBST = tPos;;

(****************************************************************)

(* emptyTree does not have the same usage as the pascal version
    because t has to be declared before calling the function,
    so its only use is changing the value of t to Empty *)
let emptyTree (t: tBST) = 
    t ^:= Empty;;

(* createNode would be useless since you need to initialize
    t before calling the function, and you can't do something
    like "let createNode = new_pointer Empty" because this will
    create only one pointer called "createNode" the moment you 
    define the function. *)

let root (t: tBST) = match (!^t) with
    Node {key = k; left = l; right = r} -> k;;

let leftChild (t: tBST) = match (!^t) with
    Node {key = k; left = l; right = r} -> l;;

let rightChild (t: tBST) = match (!^t) with
    Node {key = k; left = l; right = r} -> r;;

let isEmptyTree (t: tBST) =
    (!^t == Empty);;

(****************************************************************)

let rec insert_r (t: tBST) x = match (!^t) with
    Empty -> 
        t ^:= Node {
            key = x;
            left = new_pointer Empty;
            right = new_pointer Empty}
|   Node {key = k; left = l; right = r} ->
        if (x < k) then
            insert_r l x
        else if (x > k) then
            insert_r r x;;

let insert_i (t: tBST) x =
    let newNode = new_pointer (Node {
        key = x;
        left = new_pointer Empty;
        right = new_pointer Empty
    }) in
    if (isEmptyTree t) then
        t ^:= !^newNode
    else
        let father = new_pointer (new_pointer Empty) in
        let child = new_pointer t in
        while ((not (isEmptyTree (!^child))) && (root (!^child) != x)) do
            father ^:= !^child;
            if (x < root (!^child)) then
                child ^:= leftChild (!^child)
            else
                child ^:= rightChild (!^child)
        done;
        if (isEmptyTree (!^child)) then
            if (x < (root (!^father))) then
                !^father ^:= Node {
                    key = root (!^father);
                    left = newNode;
                    right = rightChild (!^father)
                }
            else
                !^father ^:= Node {
                    key = root !^(father);
                    left = leftChild (!^father);
                    right = newNode
                }
        else ();;

let insertKey (t: tBST) x =
    insert_r t x;;

(****************************************************************)

let rec search_r (t: tBST) x =
    if (isEmptyTree t) then
        new_pointer Empty
    else if ((root t) == x) then
        t
    else if (x < (root t)) then
        search_r (leftChild t) x
    else
        search_r (rightChild t) x;;

let search_i (t: tBST) x =
    let node = new_pointer t in
    while ((not (isEmptyTree (!^node))) && (root (!^node) != x)) do
        if (x < root (!^node)) then
            node ^:= leftChild (!^node)
        else
            node ^:= rightChild (!^node)
    done;
    !^node;;

let searchKey (t: tBST) x =
    search_r t x;;

(****************************************************************)

let rec remove_r (t: tBST) x = match (!^t) with
    Empty -> ()
|   Node {key = k; left = l; right = r} ->
        if (x < k) then
            remove_r l x
        else if (x > k) then
            remove_r r x
        else 
            let (aux: tBST) = t in
        if (isEmptyTree l)
            then t ^:= !^r
        else if (isEmptyTree r)
            then t ^:= !^l
        else
    let rec sup2 (t2: tBST) = 
        if (not (isEmptyTree (rightChild t2))) then
            sup2 (rightChild t2)
        else
            (aux ^:= Node {
                key = root t2;
                left = leftChild aux;
                right = rightChild aux
            };
            t2 ^:= !^(leftChild t2))
    in
        sup2 l;;

let remove_i (t: tBST) x =
    let childNum = new_pointer 0 in
    let sup = new_pointer t in
    let fSup = new_pointer (new_pointer Empty) in
    (* search for the node to remove *)
    while ((not (isEmptyTree (!^sup))) && (root (!^sup) != x)) do
        fSup ^:= !^sup;
        if (x < root (!^sup)) then
                sup ^:= leftChild (!^sup)
            else
                sup ^:= rightChild (!^sup)
    done;
    (* if it isn't in t, do nothing *)
    if (not (isEmptyTree (!^sup))) then (
        (* count the number of childs *)
        if (not (isEmptyTree (leftChild (!^sup)))) then
            childNum ^:= (!^childNum + 1)
        else ();
        if (not (isEmptyTree (rightChild (!^sup)))) then
            childNum ^:= (!^childNum + 1)
        else ();
        match (!^childNum) with
            0 -> (* remove the leaf node *)

                if (isEmptyTree(!^fSup)) then
                    t ^:= Empty (* the root was the only node of the tree *)
                else if (leftChild (!^fSup) == !^sup) then
                    leftChild (!^fSup) ^:= Empty
                else 
                    rightChild (!^fSup) ^:= Empty
        |   1 -> (* remove node with only 1 child *)
                let childNotEmpty = new_pointer Empty in
                if (isEmptyTree (leftChild (!^sup))) then 
                    childNotEmpty ^:= !^(rightChild (!^sup))
                else
                    childNotEmpty ^:= !^(leftChild (!^sup));
                if (isEmptyTree(!^fSup)) then
                    (* we remove the root *)
                    t ^:= !^childNotEmpty
                else if (leftChild (!^fSup) == (!^sup)) then
                    leftChild (!^fSup) ^:= !^childNotEmpty
                else 
                    rightChild (!^fSup) ^:= !^childNotEmpty

        |   _ -> (* remove node with 2 childs *)
                fSup ^:= !^sup;
                let supLeftMax = new_pointer (leftChild (!^sup)) in
                while (not (isEmptyTree(rightChild (!^supLeftMax)))) do
                    fSup ^:= !^supLeftMax;
                    supLeftMax ^:= rightChild (!^supLeftMax)
                done;
                !^sup ^:= Node {
                    key = root !^(supLeftMax);
                    left = leftChild (!^sup);
                    right = rightChild (!^sup)
                };
                if ((!^fSup) == (!^sup)) then
                    leftChild (!^fSup) ^:= !^(leftChild (!^supLeftMax))
                else 
                    rightChild (!^fSup) ^:= !^(leftChild (!^supLeftMax))
    )
    else ();;

let removeKey (t: tBST) x =
    remove_r t x;;

