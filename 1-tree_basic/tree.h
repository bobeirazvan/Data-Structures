#include <queue>

template<typename var>
class TreeNode {
private:
	
	TreeNode *leftChild = nullptr;
	TreeNode *rightChild = nullptr;
	var data;

public:
		
	TreeNode* getLeftChild() {
		if (this -> leftChild == nullptr) { // std::cout << "null \n";
		 return nullptr;}
		return this -> leftChild;
	}
	
	TreeNode* getRightChild() {
		if (this -> rightChild == nullptr) { // std::cout << "null \n";
		 return nullptr;}
		return this -> rightChild;
	}

	void setLeftChild(TreeNode* child) {
		this -> leftChild = child;
	}

	void setRightChild(TreeNode* child) {
		this -> rightChild = child;
	}

	void setData(var data) {
		this -> data = data;
	}

	var getData() {
		return this -> data;
	}
};

template<typename var>
class Tree {
private:

	TreeNode<var> *root;
	int size = 0;

public:

	Tree() {

	}

	~Tree() {

	}

	var insert(var value) {

		TreeNode<var>* added = new TreeNode<var>;
		added -> setData(value);

		if (size == 0) {
			// std::cout << "Setam radacina" << std::endl;
			this -> root = added;
		}
		else
		{
			// std::cout << "Adaugam el nou" << std::endl;
			std::queue<TreeNode<var> *> myqueue;
			myqueue.push(root);
			bool found = false;
			while (!found && myqueue.size() != 0) {
				TreeNode<var> * current = myqueue.front();
				// std::cout << "Got front \n";
				if (current != nullptr && current -> getLeftChild() == nullptr) {
					current -> setLeftChild(added);
					found = true;
					// std::cout << "if1 \n";
				}
				else if (current  != nullptr && current -> getRightChild() == nullptr) {
					current -> setRightChild(added);
					found = true;
					// std::cout << "if2 \n";
				}
				else {
					myqueue.push(current -> getLeftChild());
					myqueue.push(current -> getRightChild());
					// std::cout << "else \n";
				}
				myqueue.pop();
			}

		}

		size++;

		return added -> getData();
	}

	TreeNode<var>* getRoot() {
		return root;
	}

	void print() {
		std::queue<TreeNode<var> *> myqueue;
		myqueue.push(root);

		if (size != 0) std::cout << root -> getData() << "\n";
		else {
			std::cout << "NUll \n";
			return;
		}; 
		bool stop = false;
		int line = 1;
		while (!stop) {
			for (int i = 1; i <= line; ++i)
			{
				//std::cout << "\n line is " << line << "\n";
				TreeNode<var> * current = myqueue.front();
				myqueue.push(current -> getLeftChild());
				if (current -> getLeftChild() != nullptr) std::cout << current -> getLeftChild() -> getData() << " ";
				else stop = true;
				myqueue.push(current -> getRightChild());
				if (current -> getRightChild() != nullptr) std::cout << current -> getRightChild() -> getData() << " ";
				else stop = true;
				myqueue.pop();
			}


			std::cout << "\n";
			line = line * 2;
		}
	}

};