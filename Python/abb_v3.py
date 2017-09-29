class Pos:
	def __init__(self, obj):
		self.obj = obj
	def get(self):
		return self.obj
	def set(self, obj):
		self.obj = obj

class Node:
	def __init__(self, key):
		self.key = key
		self.leftChild = Pos(None)
		self.rightChild = Pos(None)


class BinarySearchTree:
	def __init__(self):
		self.root = Pos(None)

	def insertKey(self, key):
		if (self.root.get() is None):
			self.root.set(Node(key))
		else:
			self.insert_i(self.root, key)

	def insert_r(self, currentNode, key):
		if key < currentNode.get().key:
			if not (isEmpty(currentNode.get().leftChild.get())):
				self.insert_r(currentNode.get().leftChild, key)
			else:
				currentNode.get().leftChild.set(Node(key))
		elif key > currentNode.get().key:
			if not (isEmpty(currentNode.get().rightChild.get())):
				self.insert_r(currentNode.get().rightChild, key)
			else:
				currentNode.get().rightChild.set(Node(key))

	def insert_i(self, currentNode, key):
		father = Pos(None)
		child = currentNode
		while (child.get() is not None) and (child.get().key != key):
			father = child
			if key < child.get().key:
				child = child.get().leftChild
			else:
				child = child.get().rightChild
		if (child.get() is None):
			if (key < father.get().key):
				father.get().leftChild.set(Node(key))
			else:
				father.get().rightChild.set(Node(key))

	def removeKey(self, key):
		self.remove_r(self.root, key)

	def remove_r(self, currentNode, key):
		aux = Pos(None)
		def sup2(bst):
			if (bst.get().rightChild.get() is not None):
				sup2(bst.get().rightChild)
			else:
				aux.get().key = bst.get().key
				bst.set(bst.get().leftChild.get())

		if (currentNode.get() is not None):
			if (key < currentNode.get().key):
				self.remove_r(currentNode.get().leftChild, key)
			elif (key > currentNode.get().key):
				self.remove_r(currentNode.get().rightChild, key)
			else:
				aux.set(currentNode.get())
				if currentNode.get().leftChild.get() is None:
					currentNode.set(currentNode.get().rightChild.get())
				elif currentNode.get().rightChild.get() is None:
					currentNode.set(currentNode.get().leftChild.get())
				else:
					sup2(currentNode.get().leftChild)

def isEmpty(bst):
	return bst is None

def preorder(bst):
	preorder_aux(bst.root)
	print("")

def preorder_aux(bst):
	print(" ( ", end="")
	if not isEmpty(bst.get()):
		if not isEmpty(bst.get().leftChild.get()) or not isEmpty(bst.get().rightChild.get()):
			print(bst.get().key, end="")
			preorder_aux(bst.get().leftChild)
			preorder_aux(bst.get().rightChild)
		else:
			print(bst.get().key, end="")
	print(" ) ", end="")

"""

def search(bst, key):
	return search_r(bst.root, key)

def search_r(bst, key):
	if (bst is None):
		return None
	elif bst.key == key:
		return bst
	elif key < bst.key:
		return search_r(bst.leftChild, key)
	else:
		return search_r(bst.rightChild, key)

def search_i(bst,key):
	node = bst
	while (node != None) and (node.key != key):
		if key < node.key:
			node = node.leftChild
		else:
			node = node.rightChild
	return node
"""

"""
T = BinarySearchTree()
T.insertKey(4)
T.insertKey(4)
T.insertKey(2)
T.insertKey(6)
T.insertKey(1)
T.insertKey(3)
T.insertKey(5)
T.insertKey(7)

T.removeKey(5)
preorder(T)
T.removeKey(6)
preorder(T)
T.removeKey(4)
preorder(T)
T.removeKey(2)
preorder(T)

"""