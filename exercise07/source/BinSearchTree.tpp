template<typename T>
BinSearchTree<T>::Node::Node(const T& value, Node *left, Node *right)
	: value(value), left(left), right(right)
{
}


template<typename T>
inline BinSearchTree<T>::BinSearchTree()
	: root(nullptr), numberOfNodes(0)
{
}


template<typename T>
inline BinSearchTree<T>::BinSearchTree(const BinSearchTree<T>& other)
	: BinSearchTree()
{
	CopyHelper(other.root, root);
}


template<typename T>
inline BinSearchTree<T>& BinSearchTree<T>::operator=(BinSearchTree<T> other)
{
	numberOfNodes = other.numberOfNodes;
	std::swap(root, other.root);
}


template<typename T>
inline void BinSearchTree<T>::Insert(const T& value)
{
	InsertHelper(root, value);
}


template<typename T>
inline void BinSearchTree<T>::Delete(const T&value)
{
	DeleteHelper(root, value);
}


template<typename T>
inline bool BinSearchTree<T>::Contains(const T &element) const
{
	Node* crr = root;
	while (crr != nullptr && crr->value != element)
	{
		if (element > crr->value)
		{
			crr = crr->right;
		}
		else
		{
			crr = crr->left;
		}
	}

	return crr != nullptr;
}


template<typename T>
inline std::vector<T> BinSearchTree<T>::GetElements() const
{
	std::vector<T> res;
	PerformInOrderTraversal(root, res);

	return res;
}

template<typename T>
inline int BinSearchTree<T>::GetNumberOfElements() const
{
	return numberOfNodes;
}


template<typename T>
inline BinSearchTree<T>::~BinSearchTree()
{
	DeleteHelper(root);
}


template<typename T>
inline void BinSearchTree<T>::PerformInOrderTraversal(Node *node, std::vector<T> &res) const
{
	if (node == nullptr)
	{
		return;
	}

	PerformInOrderTraversal(node->left, res);
	res.push_back(node->value);
	PerformInOrderTraversal(node->right, res);
}


template<typename T>
inline void BinSearchTree<T>::DeleteHelper(Node *node)
{
	if (node == nullptr)
	{
		return;
	}

	DeleteHelper(node->left);
	DeleteHelper(node->right);

	delete node;
}


template<typename T>
inline void BinSearchTree<T>::CopyHelper(Node *otherNode, Node* &thisNode)
{
	if (otherNode == nullptr)
	{
		return;
	}

	thisNode = new Node(otherNode->value);
	++numberOfNodes;
	CopyHelper(otherNode->left, thisNode->left);
	CopyHelper(otherNode->right, thisNode->right);
}


template<typename T>
inline void BinSearchTree<T>::InsertHelper(Node* &node, const T& value)
{
	if (node == nullptr)
	{
		node = new Node(value);
		++numberOfNodes;
		return;
	}

	if (value > node->value)
	{
		InsertHelper(node->right, value);
		return;
	}

	InsertHelper(node->left, value);
}


template<typename T>
inline void BinSearchTree<T>::DeleteHelper(Node *&crr, const T&value)
{
	//No such element in the tree
	if (crr == nullptr)
	{
		return;
	}

	if (crr->value == value && crr->left == nullptr)
	{
		Node* toDelete = crr;
		crr = crr->right;
		
		delete toDelete;
		toDelete = nullptr;
		--numberOfNodes;

		return;
	}
	
	if (crr->value == value && crr->right == nullptr)
	{
		Node* toDelete = crr;
		crr = crr->left;

		delete toDelete;
		toDelete = nullptr;
		--numberOfNodes;

		return;
	}
	
	if (crr->value == value)
	{
		Node* maxOnRight = GetMaxNode(crr->right);
		crr->value = maxOnRight->value;
		DeleteHelper(crr->right, maxOnRight->value);

		return;
	}

	if (value > crr->value)
	{
		DeleteHelper(crr->right, value);
	}
	else
	{
		DeleteHelper(crr->left, value);
	}
}


// It is supposed to be called with non empty trees
template<typename T>
inline typename BinSearchTree<T>::Node* BinSearchTree<T>::GetMaxNode(Node *crr) const
{
	if (crr == nullptr)
	{
		return nullptr;
	}

	// The leftmost node is the one with the smallest value
	while (crr->left != nullptr)
	{
		crr = crr->left;
	}

	return crr;
}
