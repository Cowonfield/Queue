#include <iostream>
using namespace std;
class Print;

struct Node {
	Node* next;
	int value;
	Node(int value) :value(value){}
};
class List {
private:
	Node* _p_head;
	Node* _p_tail;
	int _Count;
	
public:
	List():_p_head(nullptr),_p_tail(nullptr),_Count(0){}
	~List() {
		while (_p_head != nullptr) {
			Node* tmp = _p_head;
			_p_head = _p_head->next;
			delete tmp;
		}
	}
	void add(int value)
	{
		Node* tmp = new Node(value);
		if (_p_head == nullptr) {
			_p_head = _p_tail = tmp;

		}
		else {
			_p_tail->next = tmp;
			_p_tail = tmp;
         }
		_Count++;
	}
	void insert(int value, int index)
	{
		Node* new_node = new Node(value);
		if (index == 0)
		{
			new_node->next = _p_head;
			_p_head = new_node;
		}
		else
		{
			Node* tmp = _p_head;
			for (auto i = 0; i < index - 1; i++)
				tmp = tmp->next;
			new_node->next= tmp->next;
			tmp->next = new_node;
		}
		_Count++;
	}
	void remove(int index)
	{
		if (index == 0)
		{
			Node* tmp = _p_head;
			_p_head = _p_head->next;
			delete tmp;
        }
		else
		{
			Node* tmp = _p_head;
			for (auto i = 0; i < index - 1; i++)
				tmp = tmp->next;
			Node* tmp_remove = tmp->next;
			tmp->next = tmp_remove->next;
			delete tmp_remove;

		}
		_Count--;
	}
	int find(int value)
	{
		Node* tmp = _p_head;
		for(int index = 0; tmp != nullptr;index++)
		{
			if (tmp->value == value)
				return index;
			else
				tmp = tmp->next;
		}
		return -1;
	}
	/*int get_count(List& ls)
	{
		return ls._Count;
	}*/

	friend class Print;
	friend  class Queue;
		
};
	class Print {
	public:
		static void print_list(const List& ls)
		{
			Node* tmp = ls._p_head;
			if (ls._Count == 0)
				cout << "List is empty! Add value.\n";
			else
			{
				
				for(int i=0;i<ls._Count;i++)
				{
					cout << tmp->value << '\t';

					tmp = tmp->next;
				}
				
				
			} 
		

			cout << endl;
		}
	};

	
	void main()
	{
		List first;
		int k;
		bool job = 1;

		while (job) {
			cout << "Enter 1-for add value,2- insert value,3- remove,4-find value,5-show list, 0-Exit \n";
			cin >> k;
			switch (k)
			{
			case 1:
				int n;
				cout << "Enter value "; cin >> n;
				first.add(n);
				break;
			case 2:
				int index;
				cout << "Enter value "; cin >> n;
				cout << endl;
				cout << "Enter index "; cin >> index;
				first.insert(n, index);
				break;
			case 3:
			   cout << "Enter index "; cin >> index;
			   first.remove(index);
				break;
			case 4:
				cout << "Enter value "; cin >> n;
				cout<<first.find(n)<<endl;
				break;
			case 5:
				Print::print_list(first);
				break;
			case 0:job = 0;
				break;
			default:
				cout << "Wrong index!\n";
				break;
			}

		}