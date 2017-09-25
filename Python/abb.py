class BinarySearchTree:
	def __init__(self, key=None, leftChild=None, rightChild=None):
		self.key = key
		self.leftChild = leftChild
		self.rightChild = rightChild

	def insertKey(self, key):
		if self.key == None:
			self.key = key
		elif key < self.key:
			if not (isEmpty(self.leftChild)):
				self.leftChild.insertKey(key)
			else:
				self.leftChild = BinarySearchTree(key)
		elif key > self.key:
			if not (isEmpty(self.rightChild)):
				self.rightChild.insertKey(key)
			else:
				self.rightChild = BinarySearchTree(key)

	def insertKey_i(self, key):
		if self.key == None:
			self.key = key
		else:
			father = None
			child = self
			while (child != None) and (child.key != key):
				father = child
				if key < child.key:
					child = child.leftChild
				else:
					child = child.rightChild
			if (child == None):
				if (key < father.key):
					father.leftChild = BinarySearchTree(key)
				else:
					father.rightChild = BinarySearchTree(key)

""" No funca porque está hecho para punteros.
	def removeKey(self, key):
		aux = None
		def sup2(bst):
			if (bst.rightChild != None):
				sup2(bst.rightChild)
			else:
				aux.key = bst.key
				aux = bst
				bst = bst.leftChild
		if (self.key != None):
			if (key < self.key):
				self.leftChild.removeKey(key)
			elif (key > self.key):
				self.leftChild.removeKey(key)
			else:
				aux = self
				if self.leftChild == None:
					self = self.rightChild
				elif self.rightChild == None:
					self = self.leftChild
				else:
					sup2(self.leftChild)
"""

def isEmpty(bst):
	return bst == None

def preorder(bst):
	print(" ( ", end="")
	if not isEmpty(bst):
		if not isEmpty(bst.leftChild) or not isEmpty(bst.rightChild):
			print(bst.key, end="")
			preorder(bst.leftChild)
			preorder(bst.rightChild)
		else:
			print(bst.key, end="")
	print(" ) ", end="")

def search(bst, key):
	if (bst == None):
		return None
	elif bst.key == key:
		return bst
	elif key < bst.key:
		return search(bst.leftChild, key)
	else:
		return search(bst.rightChild, key)

def search_i(bst,key):
	node = bst
	while (node != None) and (node.key != key):
		if key < node.key:
			node = node.leftChild
		else:
			node = node.rightChild
	return node

T = BinarySearchTree()
T.insertKey(4)
T.insertKey(4)
T.insertKey(2)
T.insertKey(6)
T.insertKey(1)
T.insertKey(3)
T.insertKey(5)
T.insertKey(7)

preorder(T)
print("")

