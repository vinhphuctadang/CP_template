#include <bits/stdc++.h>
using namespace std;
const int WIDTH = 3, HEIGHT = 3;

struct State {
	int board[HEIGHT][WIDTH];
	int X, Y; // to trace which cell is leaved empty
};

struct Node {
	State state;
	Node* parent;
	int f, g, h;
};


State start, goal;

struct node_cmp{
	bool operator () (Node *a, Node* b) {
		return a->f < b->f;
	}
};

int heuristicDIFFERENCE (State& a, State& b) {
	int cnt = 0;
	for (int i = 0; i<HEIGHT; ++i)
		for (int j=0; j<WIDTH; ++j)
			cnt += (a.board[i][j] != b.board[i][j]);
	return cnt;
}

int heuristicMAHATAN (State& a, State& b) {
	
	unordered_map <int, pair<int, int>> umap;
	for (int i = 0; i<HEIGHT; ++i)
		for (int j = 0; j<WIDTH; ++j) {
			umap [b.board[i][j]] = {i, j};
		}
		
	int sum = 0;
	for (int i = 0; i<HEIGHT; ++i)
		for (int j = 0; j<WIDTH; ++j) {
			int X = umap[a.board[i][j]].first, 
				Y = umap[a.board[i][j]].second;
			sum += abs (X-i) + abs (Y-j);
		}
	return sum;
}

int difference (State a, State b) {
	return heuristicMAHATAN (a, b);	
}

bool same (State a, State b) {
	return difference (a, b) == 0;
}

void printState (State state) {
	for (int i = 0; i<HEIGHT; ++i) {
		for (int j = 0; j<WIDTH; ++j)
			cout << state.board[i][j] << " ";
		cout << endl;
	}
	cout << state.X << " " << state.Y << endl;
}
void printNode (Node* parent) {
	if (parent == NULL) {
		cout << "Null NODE!" <<endl;
		return;
	}
	printState (parent->state);
	
	cout << "(f, g, h)= (" << parent->f << ", " << parent->g << ", " << parent->h <<")" << endl;
}


Node* newNode (Node* parent) {
	
//	cout << parent << endl;
	Node* result = new Node;
	result->parent = NULL;
	if (parent == NULL) 
		return result;
	*result = *parent;
	result->parent = parent;
		
	return result;
}

Node* up (Node* node) {
	
	if (node->state.X == 0) 
		return NULL;
	
	Node* result = newNode (node);
	int X = node->state.X, Y = node->state.Y;
	swap (result->state.board[X-1][Y], result->state.board[X][Y]);
	--result->state.X;
	int
		g = node->g+1,
		h = difference (result->state, goal); 
	int f = g + h;
	result->f = f, result->g = g, result->h = h;
	return result;	
}

Node* down (Node* node) {
	if (node->state.X >= HEIGHT-1) 
		return NULL;
	Node* result = newNode (node);
	int X = node->state.X, Y = node->state.Y;
	swap (result->state.board[X+1][Y], result->state.board[X][Y]);
	++result->state.X;
	int
		g = node->g+1,
		h = difference (result->state, goal); 
	int f = g + h;
	result->f = f, result->g = g, result->h = h;
	return result;	
}

Node* left (Node* node) {
	if (node->state.Y == 0) 
		return NULL;
	Node* result = newNode (node);
	int X = node->state.X, Y = node->state.Y;
	swap (result->state.board[X][Y-1], result->state.board[X][Y]);
	--result->state.Y;
	int
		g = node->g+1,
		h = difference (result->state, goal); 
	int f = g + h;
	result->f = f, result->g = g, result->h = h;
	return result;	
}

Node* right (Node* node) {
	if (node->state.Y >= WIDTH-1) 
		return NULL;
	Node* result = newNode (node);
	int X = node->state.X, Y = node->state.Y;
	swap (result->state.board[X][Y+1], result->state.board[X][Y]);
	++result->state.Y;
	int
		g = node->g+1,
		h = difference (result->state, goal); 
	int f = g + h;
	result->f = f, result->g = g, result->h = h;
	return result;	
}

Node* action (Node* src, int x) {
	switch (x) {
		case 0:
			return up (src);
			break;
		case 1:
			return down (src);
			break;
		case 2:
			return left (src);
			break;
		case 3:
			return right (src);
			break;		
	}	
}

bool isExplored (vector<State>& explored, State st) {
	for (auto& state: explored) {
		if (difference (state, st) == 0)
			return true;
	}
	return false;
}

Node* existCheck (multiset<Node*, node_cmp>& p, State u) {
	for (Node* pnode: p) {
		auto node = pnode;
		if (same (node->state, u)) {
			return pnode;
		}
	}
	return NULL;
}

Node* search (Node* root) {
		
	vector<State> explored;
//	vector<pair<Node*, int>> q;
	multiset<Node*, node_cmp> q;
	q.insert(root);
	 
	while (q.size ()) {
		
		// priority queue should be implemented in order to sort f online
		// pick a node for tranversal
		auto it = q.begin();
		Node* u = *it;
		q.erase(it);
		
		if (same (u->state, goal)) {
			return u;
		}
		
		for (int i = 0; i<4; ++i) {
			Node* v = action (u, i);
			if (v == NULL)	
				continue;
			if (!isExplored (explored, v->state)) {
				explored.push_back(v->state);
			} 
			
			auto existed = existCheck (q, v->state);
			if (existed == NULL) {
				q.insert (v); 				
			} else { 
				if (existed->f > v->f) {
					q.erase(existed);
					q.insert(v); 
				}
			}
		}		
	}		
	return NULL;
}

void printResult (Node* target) {
	
	if (target == NULL) {
		cout << "Khong co cach nao ca";
		return;
	}
	stack<Node*> result;
	int cnt = 0;
	while (target != NULL) {
		++cnt;
		result.push (target);
		target = target->parent;
	}
	
	while (result.size()) printNode (result.top()), result.pop(), 0;
	cout << "Tong so buoc: " << cnt;
}


State readState () {
	State start;
	for (int i = 0; i<HEIGHT; ++i) {
		for (int j = 0; j<WIDTH; ++j) {
			cin >> start.board[i][j];
			if (start.board[i][j] == 0) {
				start.X = i;
				start.Y = j;
			}
		}
	}
	return start;	
}
Node* input () {
	freopen ("input.txt", "r", stdin);
	Node* result = newNode (NULL);
	start = readState ();
	goal  = readState ();
	result->g = 0, result->h = difference (start, goal);
	result->f = result->h + result->g;
	result->state = start;			
	return result;
}
int main () {
		
	Node* root = input ();
	Node* result = search (root);
	printResult (result);
	return 0;
}
