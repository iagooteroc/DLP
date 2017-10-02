# python considers this file a module automatically
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
	def __init__(self, root = Pos(None)):
		self.root = root

	def insertKey(self, key):
		if (self.root.get() is None):
			self.root.set(Node(key))
		else:
			self.insert_r(self.root, key)

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
		# ignore duplicates

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
		# ignore duplicates

	def removeKey(self, key):
		self.remove_i(self.root, key)

	def remove_r(self, currentNode, key):
		aux = Pos(None)
		# procedure to be called when the node to be removed
		# has two childs, to replace it with the greatest key
		# from its left subtree.
		def sup2(bst):
			if (bst.get().rightChild.get() is not None):
				sup2(bst.get().rightChild)
			else:
				aux.get().key = bst.get().key
				bst.set(bst.get().leftChild.get())

		# if its not in the tree, nothing is done
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

	def remove_i(self, currentNode, key):
		sup = currentNode	# node to be removed
		fSup = Pos(None)	# father of the node to be removed
		# search for the node to be removed
		while (not isEmpty(sup.get())) and (sup.get().key != key):
			fSup = sup
			if (key < sup.get().key):
				sup = sup.get().leftChild
			else:
				sup = sup.get().rightChild
		# if its not in the tree, nothing is done
		if (not isEmpty(sup.get())):
			# count the number of childs
			childNum = 0
			if (not isEmpty(sup.get().leftChild.get())):
				childNum += 1
			if (not isEmpty(sup.get().rightChild.get())):
				childNum += 1
			# remove leaf node
			if (childNum == 0):
				if (isEmpty(fSup.get())):
					# the root was the only node of the tree
					currentNode.set(None)
				elif (fSup.get().leftChild.get() == sup.get()):
					fSup.get().leftChild.set(None)
				else:
					fSup.get().rightChild.set(None)
			# remove node with only one child
			elif (childNum == 1):
				if (isEmpty(sup.get().leftChild.get())):
					childNotEmpty = sup.get().rightChild
				else:
					childNotEmpty = sup.get().leftChild
				if (isEmpty(fSup.get())):
					# the root is removed
					currentNode.set(childNotEmpty.get())
				elif (fSup.get().leftChild.get() == sup.get()):
					fSup.get().leftChild.set(childNotEmpty.get())
				else:
					fSup.get().rightChild.set(childNotEmpty.get())
			# remove node with two childs
			else:
				fSup = sup
				# supLeftMax: node with the greatest value from the
				# left subtree
				supLeftMax = sup.get().leftChild
				while (not isEmpty(supLeftMax.get().rightChild.get())):
					fSup = supLeftMax
					supLeftMax = supLeftMax.get().rightChild
				sup.get().key = supLeftMax.get().key
				if (fSup.get() == sup.get()):
					fSup.get().leftChild.set(supLeftMax.get().leftChild.get())
				else:
					fSup.get().rightChild.set(supLeftMax.get().leftChild.get())



def isEmpty(bst):
	return bst is None

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

def searchKey(bst, key):
	return search_i(bst.root, key)

def search_r(currentNode, key):
	if (isEmpty(currentNode.get())):
		return BinarySearchTree(Pos(None))
	elif currentNode.get().key == key:
		return BinarySearchTree(currentNode)
	elif key < currentNode.get().key:
		return search_r(currentNode.get().leftChild, key)
	else:
		return search_r(currentNode.get().rightChild, key)

def search_i(currentNode, key):
	node = currentNode
	while (not isEmpty(node.get()) and (node.get().key != key)):
		if key < node.get().key:
			node = node.get().leftChild
		else:
			node = node.get().rightChild
	return BinarySearchTree(node)


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