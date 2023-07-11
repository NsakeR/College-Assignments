#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	char c;
	int frequency;
	Node *left, *right;
};

Node* makeNode(char c, int frequency, Node* left, Node* right)
{
	Node* node = new Node();

	node->c = c;
	node->frequency = frequency;
	node->left = left;
	node->right = right;

	return node;
}


struct comp
{
	bool operator()(Node* left, Node* right)
	{
		return left->frequency > right->frequency;
	}
};


bool sortbysec(const pair<char, int>& a, const pair<char, int>& b)
{
	return (a.second > b.second);
}

void encode(Node* root, string str,	unordered_map<char, string>& huffmanCode)
{
	if (root == nullptr)
		return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->c] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}


void huffmann(string x) {
	unordered_map<char, int> map;
	for (char c : x) {
		map[c]++;
	}

	priority_queue<Node*, vector<Node*>, comp> prio_q;

	for (auto node : map) {
		prio_q.push(makeNode(node.first, node.second, nullptr, nullptr));
	}

	while (prio_q.size() != 1) {
		
		Node* left = prio_q.top(); prio_q.pop();
		Node* right = prio_q.top();	prio_q.pop();

		int sum = left->frequency + right->frequency;
		prio_q.push(makeNode('\0', sum, left, right));
	}

	Node* root = prio_q.top();

	unordered_map<char, string> huffman;
	encode(root, "", huffman);

	for (auto node : huffman) {
		cout << node.first << " " << node.second << '\n';
	}
}

int main()
{
	string mess;

	cout << "Kodowanie Huffmana" << endl;
	cout << "Podaj tekst" << endl;
	cin >> mess;

	huffmann(mess);

    return 0;
}





