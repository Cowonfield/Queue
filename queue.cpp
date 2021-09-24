#include <iostream>
using namespace std;
class Print;
class Queue;
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
	int get_count(List& ls)
	{
		return ls._Count;
	}

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

	class Queue {
	private:
		List _ls;
		int _size;
	public:
		Queue(int size) :_size(size),_ls(List()){}
	
		bool IsEmpty() {
			return _ls._Count == 0;
		}
		bool IsFull() {
			if (_ls._Count == _size)
				return 1;
		}

		void Add(int value)

		{
			if(IsFull()!=1)
			_ls.add(value);
			
		}
		void Extract(int index) {

			if (!IsEmpty())
			_ls.remove(index);
		}
		void Insert(int value, int index)
		{
			_ls.insert(value, index);
		}
		void Clear() {
			_ls._Count = 0;
		}
		/*int GetCount(Queue & ls)
		{
			 return _ls.get_count(ls._ls);
		}*/
		void Show() {
			Print::print_list(_ls);
		}
		
		friend class Print;
};
void main()
	{
int size, n, index;
		cout << "Enter size: "; cin >> size;
		Queue b(size);
		int k;
		bool job = 1;

		while (job) {
			cout << "Enter 1-for add value,2- extract value,3- clear all,4-get count,5-insert value,6-show list, 0-Exit \n";
			cin >> k;
			switch (k)
			{
			case 1:
				cout << "Enter value "; cin >> n;
				b.Add(n);
				break;
			case 2:
				cout << "Enter index "; cin >> index;
				index--;
				b.Extract(index);
				break;
			case 3:

				b.Clear();
				break;
			case 4:

				cout<<b.GetCount(b)<<"\n";
				break;
			case 5:
				cout << "Enter value "; cin >> n;
				cout << "Enter index "; cin >> index;
				index--;
				b.Insert(n, index);
			case 6:
				b.Show();
				break;
			case 0:job = 0;
				break;
			default:
				cout << "Wrong index!\n";
				break;
			}
		}
	}