class Node:
	def __init__(self, key):
		self.key = key
		self.leftChild = None
		self.rightChild = None

class BinarySearchTree:
	def __init__(self):
		self.root = None

	def insertKey(self, key):
		if (self.root is None):
			self.root = Node(key)
		else:
			self.insert_i(self.root, key)

	def insert_r(self, currentNode, key):
		if key < currentNode.key:
			if not (isEmpty(currentNode.leftChild)):
				self.insert_r(currentNode.leftChild, key)
			else:
				currentNode.leftChild = Node(key)
		elif key > currentNode.key:
			if not (isEmpty(currentNode.rightChild)):
				self.insert_r(currentNode.rightChild, key)
			else:
				currentNode.rightChild = Node(key)

	def insert_i(self, currentNode, key):
		father = None
		child = currentNode
		while (child != None) and (child.key != key):
			father = child
			if key < child.key:
				child = child.leftChild
			else:
				child = child.rightChild
		if (child == None):
			if (key < father.key):
				father.leftChild = Node(key)
			else:
				father.rightChild = Node(key)

	def removeKey(self, key):
		self.remove_r(self.root, key)

	def remove_r(self, currentNode, key):
		aux = None
		def sup2(bst):
			if (bst.rightChild is not None):
				sup2(bst.rightChild)
			else:
				aux.key = bst.key
				aux = bst
				bst = bst.leftChild

		if (currentNode is not None):
			if (key < currentNode.key):
				self.remove_r(currentNode.leftChild, key)
			elif (key > currentNode.key):
				self.remove_r(currentNode.rightChild, key)
			else:
				aux = currentNode
				if currentNode.leftChild is None:
					currentNode = currentNode.rightChild
				elif currentNode.rightChild is None:
					currentNode = currentNode.leftChild
				else:
					sup2(currentNode.leftChild)

def isEmpty(bst):
	return bst == None

def preorder(bst):
	preorder_aux(bst.root)
	print("")

def preorder_aux(bst):
	print(" ( ", end="")
	if not isEmpty(bst):
		if not isEmpty(bst.leftChild) or not isEmpty(bst.rightChild):
			print(bst.key, end="")
			preorder_aux(bst.leftChild)
			preorder_aux(bst.rightChild)
		else:
			print(bst.key, end="")
	print(" ) ", end="")

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

