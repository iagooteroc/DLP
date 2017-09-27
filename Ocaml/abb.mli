type 'a pointer = Null | Pointer of 'a ref
type tKey = int
type tPos = tNode pointer
and tNode = Empty | Node of nodeStruct
and nodeStruct = {
    mutable key: tKey; 
    mutable left: tPos;
    mutable right: tPos}
type tBST = tPos

val emptyTree : tBST -> unit
val insertKey : tBST -> tKey -> unit
val leftChild : tBST -> tPos
val rightChild : tBST -> tPos
val root : tBST -> tKey
val isEmptyTree : tBST -> bool
val searchKey : tBST -> tKey -> tBST
val removeKey : tBST -> tKey -> unit

val new_pointer : 'a -> 'a pointer
val ( !^ ) : 'a pointer -> 'a
