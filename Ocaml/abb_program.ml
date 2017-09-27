open Abb

let rec preorder (t: tBST) = match (!^t) with
    Empty ->
        Printf.printf " () "
|   Node {key = k; left = l; right = r} ->
        if (isEmptyTree l) && (isEmptyTree r) then
                (Printf.printf " ( ";
                Printf.printf "%d" k;
                Printf.printf " ) ")
        else
            (Printf.printf " ( ";
            Printf.printf "%d " k;
            preorder l;
            preorder r;
            Printf.printf " ) ");;

let t = new_pointer Empty;;
insertKey t 4;;
insertKey t 4;;
insertKey t 2;;
insertKey t 6;;
insertKey t 1;;
insertKey t 3;;
insertKey t 5;;
insertKey t 7;;

preorder t;; Printf.printf "\n";;

Printf.printf "Searching for 1... %d \n" (root (searchKey t 1));;
Printf.printf "Searching for 2... %d \n" (root (searchKey t 2));;
Printf.printf "Searching for 3... %d \n" (root (searchKey t 3));;
Printf.printf "Searching for 4... %d \n" (root (searchKey t 4));;
Printf.printf "Searching for 5... %d \n" (root (searchKey t 5));;
Printf.printf "Searching for 6... %d \n" (root (searchKey t 6));;
Printf.printf "Searching for 7... %d \n" (root (searchKey t 7));;

Printf.printf "Deleting 5...\n";;
removeKey t 5;;
preorder t;; Printf.printf "\n";;

Printf.printf "Deleting 6...\n";;
removeKey t 6;;
preorder t;; Printf.printf "\n";;

Printf.printf "Deleting 4...\n";;
removeKey t 4;;
preorder t;; Printf.printf "\n";;

Printf.printf "Deleting 2...\n";;
removeKey t 2;;
preorder t;; Printf.printf "\n";;