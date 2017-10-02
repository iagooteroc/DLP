from abb import *

def preorder(bst):
	preorder_node(bst.root)
	print("")

def preorder_node(bst):
	print(" ( ", end="")
	if not isEmpty(bst.get()):
		if not isEmpty(bst.get().leftChild.get()) or not isEmpty(bst.get().rightChild.get()):
			print(bst.get().key, end="")
			preorder_node(bst.get().leftChild)
			preorder_node(bst.get().rightChild)
		else:
			print(bst.get().key, end="")
	print(" ) ", end="")

T = BinarySearchTree()
insertKey(T, 4)
insertKey(T, 4)
insertKey(T, 2)
insertKey(T, 6)
insertKey(T, 1)
insertKey(T, 3)
insertKey(T, 5)
insertKey(T, 7)

preorder(T)

print("Search 1...", str(root(searchKey(T, 1))))
print("Search 2...", str(root(searchKey(T, 2))))
print("Search 3...", str(root(searchKey(T, 3))))
print("Search 4...", str(root(searchKey(T, 4))))
print("Search 5...", str(root(searchKey(T, 5))))
print("Search 6...", str(root(searchKey(T, 6))))
print("Search 7...", str(root(searchKey(T, 7))))

print("Remove 5...", end="")
removeKey(T, 5)
preorder(T)
print("Remove 6...", end="")
removeKey(T, 6)
preorder(T)
print("Remove 4...", end="")
removeKey(T, 4)
preorder(T)
print("Remove 2...", end="")
removeKey(T, 2)
preorder(T)