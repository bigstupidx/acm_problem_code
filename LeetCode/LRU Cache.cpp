
class LRUCache {
public:
	struct Node {
		int value, key;
		Node* pre, *next;
	};

	map<int, Node*> mp;
	map<int, Node*>::iterator p;

	Node *head, *tail;

	int capacity;

	LRUCache(int cap) {
		capacity = cap;
		head = tail = NULL;
		mp.clear();
	}

	void moveNodeToEnd(Node*p) {
		if (p == tail)
			return;

		if (p == head) {
			head = p->next;
			p->next->pre = NULL;
		}
		if (p->pre != NULL) {
			p->pre->next = p->next;
		}
		if (p->next != NULL) {
			p->next->pre = p->pre;
		}
		p->pre = tail;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}

	int get(int key) {
		p = mp.find(key);
		if (p == mp.end()) {
			return -1;
		}
		moveNodeToEnd(p->second);
		return p->second->value;
	}

	void set(int key, int value) {
		p = mp.find(key);
		if (p == mp.end()) {
			if (mp.size() == capacity) {
				if (head != NULL) {
					mp.erase(head->key);
					Node *q = head;
					head = head->next;
					if (head != NULL) {
						head->pre = NULL;
					} else {
						tail = NULL;
					}
					delete q;
				}
			}
			Node *q = new Node();
			q->value = value;
			q->key = key;
			if (tail != NULL) {
				tail->next = q;
				q->pre = tail;
			}
			tail = q;
			if (head == NULL) {
				head = q;
			}

			mp.insert(make_pair(key, q));

		} else {
			p->second->value = value;
			moveNodeToEnd(p->second);
		}
	}
};
