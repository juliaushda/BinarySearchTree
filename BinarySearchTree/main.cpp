#include <iostream>
using namespace std;

namespace local {
	struct Node {
		int iData;
		Node* pLeft = nullptr; //less
		Node* pRight = nullptr; //more
	};

	class Set {
	private:
		Node* pRoot = nullptr; // address of root Node
		void Insert(Node*& obj, Node*& root);
		void PrintNode(Node*& root);
		void DeleteNode(Node*& root);
		bool FindNode(Node*& root, const int& value);
		struct Node* FindMin(Node*& root);
		void DeleteElement(Node*& root, int value);

	public:
		void Push(int value);
		void Pop(int value);
		void Clear();
		void Show();
		bool Find(int value);
		~Set();
	};
}


void::local::Set::Push(int value) {

	Node* pNew = new Node;
	pNew->iData = value;

	if (pRoot == nullptr) {
		pRoot = pNew;
	}
	else {
		Insert(pNew, this->pRoot);
	}
}


void::local::Set::Pop(int value) {
		if (pRoot == nullptr)
			return;
		else
			DeleteElement(this->pRoot, value);
}   


local::Node* local::Set::FindMin(Node*& root){
	if (root->pLeft == nullptr) {
		return root;
	}
	
	FindMin(root->pLeft);
}


void ::local::Set::DeleteElement(Node*& root, int value){

	if (root->iData > value) {
			DeleteElement(root->pLeft, value);
			return;
	}
	if ((root->iData < value)) {
			DeleteElement(root->pRight, value);
			return;
	}
	else {
		if (root->pLeft == nullptr && root->pRight == nullptr) {
				delete root;
				root = nullptr;
		}
		else if (root->pLeft == nullptr) {
				Node* temp = root;
				root = root->pRight;
				delete temp;
		}
		else if (root->pRight == nullptr) {
				Node* temp = root;
				root = root->pLeft;
				delete temp;
		}
		else { // 2 children
				Node* temp = FindMin(root->pRight);
				root->iData = temp->iData;
				DeleteElement(root->pRight, temp->iData);

		}
	}
}



void::local::Set::Insert(Node*& obj, Node*& root) {
	if (root->iData > obj->iData) { // left
		if (root->pLeft == nullptr)
			root->pLeft = obj;
		else
			Insert(obj, root->pLeft);
	}
	else if (root->iData < obj->iData) { // right
		if (root->pRight == nullptr)
			root->pRight = obj;
		else
			Insert(obj, root->pRight);
	}
	else { // equal
		delete obj;
	}
}


void::local::Set::Show() {
	if (pRoot == nullptr)
		return;

	PrintNode(pRoot);
}


void::local::Set::PrintNode(Node*& root) {
	if (root->pLeft != nullptr)
		PrintNode(root->pLeft);

	cout << "Data: " << root->iData <<" Left: "<< root->pLeft<< " Right: " << root->pRight << endl;

	if (root->pRight != nullptr)
		PrintNode(root->pRight);
}


void::local::Set::Clear() {
	if (pRoot == nullptr)
		return;

	DeleteNode(pRoot);
}


void::local::Set::DeleteNode(Node*& root) {
	if (root->pLeft != nullptr)
		DeleteNode(root->pLeft);

	if (root->pRight != nullptr)
		DeleteNode(root->pRight);

	delete root;
	//cout << "Delete\n";
}


local::Set::~Set() {
	Clear();
	pRoot = nullptr;
}


bool::local::Set::FindNode(Node*& root, const int& value) {
	if (root->iData == value)
		return true;

	if (root->iData > value) {
		if (root->pLeft != nullptr)
			return FindNode(root->pLeft, value);
		else
			return false;
	}
	else {
		if (root->pRight != nullptr)
			return FindNode(root->pRight, value);
		else
			return false;
	}
}


bool::local::Set::Find(int value) {
	if (pRoot == nullptr)
		return false;

	return FindNode(pRoot, value);
}



int main() {
	local::Set ourSet;

	/* BST
			  50
		   /     \
		  30      70
		 /  \    /  \
	   20   40  60   80 */

	ourSet.Push(50);
	ourSet.Push(30);
	ourSet.Push(20);
	ourSet.Push(40);
	ourSet.Push(70);
	ourSet.Push(60);
	ourSet.Push(80);

	ourSet.Show();
	cout << "---------------------------------" << endl;
	ourSet.Pop(50);
	ourSet.Show();

	cout << "---------------------------------" << endl;
	ourSet.Pop(80);
	ourSet.Show();

	cout << "---------------------------------" << endl;
	ourSet.Pop(20);
	ourSet.Show();
	//cout << "\nFind: " << ourSet.Find(30) << endl;
	
	system("pause");
	/*ourSet.Clear();
	system("pause");*/

	return 0;
}


