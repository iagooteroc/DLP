type 'a pointer = Null | Pointer of 'a ref;;

let ( !^ ) = function
    | Null -> invalid_arg "Attempt to dereference the null pointer"
    | Pointer r -> !r;;

let ( ^:= ) p v =
    match p with
    | Null -> invalid_arg "Attempt to assign the null pointer"
    | Pointer r -> r := v;;

let new_pointer x = Pointer (ref x);;

type tKey = int;;
type tPos = tNode pointer
and tNode = Empty | Node of nodeStruct
and nodeStruct = {
    mutable key: tKey; 
    mutable left: tPos;
    mutable right: tPos};;
type tBST = tPos;;

(* warning: devuelve un árbol construído ?¿?¿*)
let emptyTree  = 
    let (p: tBST) = new_pointer Empty in
    p;;

let root (t: tBST) = match (!^t) with
    Node {key = k; left = l; right = r} -> k;;

let leftChild (t: tBST) = match (!^t) with
    Node {key = k; left = l; right = r} -> l;;

let rightChild (t: tBST) = match (!^t) with
    Node {key = k; left = l; right = r} -> r;;

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
    if ((!^t) == Empty) then
        t ^:= !^newNode
    else
        let father = new_pointer (new_pointer Empty) in
        let child = new_pointer t in
        while (((!^(!^child)) != Empty) && (root (!^child) != x)) do
            father ^:= !^child;
            if (x < root (!^child)) then
                child ^:= leftChild (!^child)
            else
                child ^:= rightChild (!^child)
        done;
        if (!^(!^child) == Empty) then
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
    if ((!^t) == Empty) then
        new_pointer Empty
    else if ((root t) == x) then
        t
    else if (x < (root t)) then
        search_r (leftChild t) x
    else
        search_r (rightChild t) x;;

let search_i (t: tBST) x =
    let node = new_pointer t in
    while (((!^(!^node)) != Empty) && (root (!^node) != x)) do
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
        if (!^(l) == Empty)
            then t ^:= !^r
        else if (!^(r) == Empty)
            then t ^:= !^l
        else
    let rec sup2 (t2: tBST) = 
        if ((!^(rightChild t2)) != Empty) then
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
    while (((!^(!^sup)) != Empty) && (root (!^sup) != x)) do
        fSup ^:= !^sup;
        if (x < root (!^sup)) then
                sup ^:= leftChild (!^sup)
            else
                sup ^:= rightChild (!^sup)
    done;
    (* if it isn't in t, do nothing *)
    if (!^(!^sup) != Empty) then (
        (* count the number of childs *)
        if (!^(leftChild (!^sup)) != Empty) then
            childNum ^:= (!^childNum + 1)
        else ();
        if (!^(rightChild (!^sup)) != Empty) then
            childNum ^:= (!^childNum + 1)
        else ();
        match (!^childNum) with
            0 -> (* remove the leaf node *)
                if (!^(!^fSup) == Empty) then
                    t ^:= Empty (* the root was the only node of the tree *)
                else if (leftChild (!^fSup) == !^sup) then
                    leftChild (!^fSup) ^:= Empty
                else 
                    rightChild (!^fSup) ^:= Empty
        |   1 -> (* remove node with only 1 child *)
                let childNotEmpty = new_pointer Empty in
                if ((!^(leftChild (!^sup))) == Empty) then 
                    childNotEmpty ^:= !^(rightChild (!^sup))
                else
                    childNotEmpty ^:= !^(leftChild (!^sup));
                if (!^(!^fSup) == Empty) then
                    (* we remove the root *)
                    t ^:= !^childNotEmpty
                else if (leftChild (!^fSup) == (!^sup)) then
                    leftChild (!^fSup) ^:= !^childNotEmpty
                else 
                    rightChild (!^fSup) ^:= !^childNotEmpty

        |   _ -> (* remove node with 2 childs *)
                fSup ^:= !^sup;
                let supLeftMax = new_pointer (leftChild (!^sup)) in
                while ((!^(rightChild (!^supLeftMax))) != Empty) do
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

(* cambiar si eso para que se parezca más a pascal *)
let rec preorder (t: tBST) = match (!^t) with
    Empty ->
        Printf.printf " () "
|   Node {key = k; left = l; right = r} ->
        if ((!^l) == Empty) && ((!^r) == Empty) then
                (Printf.printf " ( ";
                Printf.printf "%d" k;
                Printf.printf " ) ")
        else
            (Printf.printf " ( ";
            Printf.printf "%d " k;
            preorder l;
            preorder r;
            Printf.printf " ) ");;

(*

let t = emptyTree;;

let t = new_pointer Empty;;
insertKey t 4;;
insertKey t 4;;
insertKey t 2;;
insertKey t 6;;
insertKey t 1;;
insertKey t 3;;
insertKey t 5;;
insertKey t 7;;

preorder t;;

removeKey t 5;;
preorder t;;
removeKey t 6;;
preorder t;;
removeKey t 4;;
preorder t;;
removeKey t 2;;
preorder t;;

*)