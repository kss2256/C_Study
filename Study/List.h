#pragma once
#include <assert.h>


template <typename T>
class ListNode
{

private:

	ListNode<T>* m_PrevNode;
	ListNode<T>* m_NextNode;
	T				m_Data;

private:




private:
	ListNode()
		: m_PrevNode(nullptr)
		, m_NextNode(nullptr)
		, m_Data()
	{

	}

	~ListNode()
	{

	}

	template <typename T>
	friend class LinkedList;
	template <typename T>
	friend class Citerator;

};

template <typename T>
class Citerator
{
	template <typename T>
	friend class LinkedList;

private:

	ListNode<T>* m_Node;



public:
	//bool Ÿ������ ������ �����ε� ���ͷ����� ���� ��尡 ������ Ȯ��.
	bool operator == (const Citerator<T>& iter) const
	{
		return m_Node == iter.m_Node;
	}
	//bool Ÿ������ ������ �����ε� ���ͷ����� ���� ��尡 �ٸ��� Ȯ��.
	bool operator != (const Citerator<T>& iter) const
	{
		return m_Node != iter.m_Node;
	}
	// ++ ���� ����
	void operator ++ ()
	{
		m_Node = m_Node->m_NextNode;
	}
	// -- ���� ����
	void operator -- ()
	{
		m_Node = m_Node->m_PrevNode;
	}
	// ++ ���� ����
	void operator ++ (int)
	{
		m_Node = m_Node->m_NextNode;
	}
	// -- ���� ����
	void operator -- (int)
	{
		m_Node = m_Node->m_PrevNode;
	}
	// ������ �����ε� *
	T& operator * ()
	{
		return m_Node->m_Data;
	}


public:
	Citerator()
		: m_Node(nullptr)
	{}
	~Citerator()
	{}
};





template <typename T>
class LinkedList
{

public:

	ListNode<T>*	m_Begin;
	ListNode<T>*	m_End;
	int				m_Size;

public:

	//����� �� �ڿ� �����͸� �߰� �Ѵ�.
	void Push_Back(const T& _data)
	{
		ListNode<T>* Node = new ListNode<T>;

		Node->m_Data = _data;

		ListNode<T>* PrevNode = m_End->m_PrevNode;

		m_End->m_PrevNode = Node;

		Node->m_NextNode = m_End;

		PrevNode->m_NextNode = Node;

		Node->m_PrevNode = PrevNode;

		m_Size++;

	}
	//����� �� �տ� �����͸� �߰� �Ѵ�.
	void Push_Front(const T& _data)
	{
		ListNode<T>* Node = new ListNode<T>;

		Node->m_Data = _data;

		ListNode<T>* PrevNode = m_Begin->m_NextNode;

		Node->m_PrevNode = m_Begin;

		m_Begin->m_NextNode = Node;

		PrevNode->m_PrevNode = Node;

		Node->m_NextNode = PrevNode;

		m_Size++;

	}

	//iterator�� ������ �ִ� ���� �״��� ��� ���̿� ���ο� ��带 �߰� �Ѵ�.
	void Insert(const Citerator<T>& iter, const T& _data)
	{
		ListNode<T>* node = new ListNode<T>;
		node->m_Data = _data;

		ListNode<T>* next = iter.m_Node->m_NextNode;

		node->m_NextNode = next;
		next->m_PrevNode = node;

		node->m_PrevNode = iter.m_Node;
		iter.m_Node->m_NextNode = node;

		m_Size++;

	}



	//������ ��带 ���� �Ѵ�.
	void Pop_Back()
	{
		if (m_Size == 0)
			assert(false);


		ListNode<T>* DeleteNode = m_End->m_PrevNode;
		ListNode<T>* temporaryNode = DeleteNode->m_PrevNode;

		temporaryNode->m_NextNode = m_End;
		m_End->m_PrevNode = temporaryNode;

		delete DeleteNode;

		m_Size--;

	}

	//ù��° ��带 �����Ѵ�.
	void Pop_Front()
	{
		if (m_Size == 0)
			assert(false);


		ListNode<T>* DeleteNode = m_Begin->m_NextNode;
		ListNode<T>* temporaryNode = DeleteNode->m_NextNode;

		temporaryNode->m_PrevNode = m_Begin;
		m_Begin->m_NextNode = temporaryNode;

		delete DeleteNode;

		m_Size--;

	}

	//��� ��� �����ϰ� ó�� ���·� ����
	void Clear()
	{

		ListNode<T>* DeleteNode = m_Begin->m_NextNode;
		ListNode<T>* Node = DeleteNode->m_NextNode;

		for (int i = 0; i < m_Size; ++i)
		{
			delete DeleteNode;
			DeleteNode = Node;
			Node = Node->m_NextNode;

		}
		m_Size = 0;
		m_Begin->m_NextNode = m_End;
		m_End->m_PrevNode = m_Begin;

		//������ �ؿ��� ó���� ��򸮼��� ����.. �߿� �ؿ��� �ȵǴ� �ڵ�� m_Begin�� �ؽ�Ʈ�� ���� ����
		//m_End = m_Begin->m_NextNode;
		//m_Begin = m_End->m_PrevNode;

	}


	// ���� ����Ʈ�� ����ִٸ� ������ �߻� �Ѵ�.
	//�� �Լ��� ù��° �����͸� ��ȯ�Ѵ�.
	const T& Front()	const
	{
		if (m_Size == 0)
		{
			assert(false);
		}
		return m_Begin->m_NextNode->m_Data;
	}
	//������ �����͸� ��ȯ�Ѵ�.
	const T& Back()	const
	{
		if (m_Size == 0)
		{
			assert(false);
		}
		return m_End->m_PrevNode->m_Data;
	}




	int Size() const
	{
		return m_Size;
	}

	//�� �Լ��� ����Ʈ�� ������� Ȯ�� �Ҽ� �ִ� �Լ��̴�.
	bool Empty() const
	{
		return m_Size == 0;
	}

public:

	//�� �Լ��� ù��° �����͸� ��ȯ�Ѵ�. 
	Citerator<T> Begin() const
	{
		Citerator<T> iter;
		iter.m_Node = m_Begin->m_NextNode;
		return iter;
	}
	//������ �����͸� ��ȯ�Ѵ�.
	Citerator<T> End() const
	{
		Citerator<T> iter;
		iter.m_Node = m_End->m_PrevNode;

		return iter;
	}

	//���� Ÿ���� iterator�� �ϴ� ������ Ư�� iteraotr �� �޾Ƽ� �� iterator�� ������ �ִ� 
	//��带 ������ ���̴�. �̶� ������ ����� ���� ��带 iterator�� ��Ƽ� ��ȯ �� ���̴�.
	Citerator<T> Erase(const Citerator<T>& iter)
	{
		if (iter.m_Node == m_End || iter.m_Node == m_Begin)
		{
			assert(false);
			return End();
		}
		ListNode<T>* prev = iter.m_Node->m_PrevNode;
		ListNode<T>* next = iter.m_Node->m_NextNode;

		prev->m_NextNode = next;
		next->m_PrevNode = prev;

		delete iter.m_Node;
		--m_Size;

		Citerator<T> result;
		result.m_Node = next;
		return result;


	}

	//����� �����Ͱ����� ���� �˻��ؼ� �� ��带 �����. �̶� �����Ͱ��� �˻� ���� �ʴٸ� End�� ��ȯ.
	Citerator<T> Erase(const T& _data)
	{
		iterator iter, iterEnd = End();

		for (iter = Begin(); iter < iterEnd; ++iter)
		{
			if (*iter == _data)
				return Erase(iter);
		}

		return End();

	}


	//������ ����� ���۰� ���� �����ְ� ���ۺ��� ������ ���� ���� ���ִ� �Լ�.
	Citerator<T> Erase(const Citerator<T>& start, const Citerator<T>& end)
	{

		if (start.m_Node == m_End || start.m_Node == m_Begin ||
			end.m_Node == m_End || end.m_Node == m_Begin)
		{
			assert(false);
			return End();
		}

		Citerator<T> iter = Begin();
		Citerator<T> iterEnd = End();

		bool Cheak = false;

		//iterator �� ó������ ������ ���鼭 start, end �� ���� �����°� � ������� Ȯ���Ѵ�.
		//end �� ���� ������start���� end ��带 �ٲ��ش�.
		for (; iter != iterEnd; ++iter)
		{
			if (iter == start)
				break;

			else if (iter == end)
			{
				Cheak = true;
				break;
			}
		}

		Citerator<T> iterStart = start;
		iterEnd = end;

		//End�� ���� �߰� �� ��� �̹Ƿ� start�� end�� �ٲ��ش�.
		if (Cheak)
		{
			iterStart = end;
			iterEnd = start;
		}

		//for�� ����
		ListNode<T>* Prev = iterStart.m_Node->m_PrevNode;
		ListNode<T>* Next = iterEnd.m_Node->m_NextNode;
		ListNode<T>* Node = iterStart.m_Node;
		for (; iterStart.m_Node < Next; ++iterStart.m_Node)
		{
			ListNode<T>* NextNode = Node->m_NextNode;

			delete Node;
			Node = NextNode;
			--m_Size;
		}

		////while �� ����
		//ListNode<T>* Prev = iterStart.m_Node->m_PrevNode;
		//ListNode<T>* Next = iterEnd.m_Node->m_NextNode;
		//ListNode<T>* Node = iterStart.m_Node;
		//while (Node != Next)
		//{
		//	ListNode<T>* NodeNext = Node->m_NextNode;

		//	delete Node;

		//	Node = NodeNext;
		//	--m_Size;
		//}

		Prev->m_NextNode = Next;
		Next->m_PrevNode = Prev;

		iter.m_Node = Next;




		return iter;
	}

	//�� ����� ������ ������ ���� ���ִ� �Լ� (���� ����)
	//���ڷ� �Լ� �����͸� �Ѱ� �޾Ƽ� ���� ��ü�ؾ� ������ �������ְ� �Ѵ�.
	//�Լ� �����ͷ� �ϴ� ������ ����Ʈ�� template �̱⶧���� TŸ���̶� � Ÿ������ �˼� ���� ������
	//���� ���� �� �Ҽ� ���� ��Ȳ�̶�� �ϴ��� ����ڰ� �Լ��� �����Ͽ� ���� �� �� �� �ְ� 
	//���� �ϴ� ����� ������ֱ� ���ؼ� �̴�.
	void Sort(bool(*Func)(const T&, const T&))
	{
		Citerator<T> IterOut, IterOutEnd;
		Citerator<T> IterIn, IterInEnd;

		IterInEnd = End();

		IterOutEnd = End();
		--IterOutEnd;


		for (IterOut = Begin(); IterOut != IterOutEnd; ++IterOut)
		{
			IterIn = IterOut;
			++IterIn;

			for (; IterIn != IterInEnd; ++IterIn)
			{
				if (Func(*IterOut, *IterIn))
				{
					T Temp = *IterOut;
					*IterOut = *IterIn;
					*IterIn = Temp;
				}
			}

		}



	}


public:

	LinkedList()
		: m_Begin(nullptr)
		, m_End(nullptr)
	{
		m_Begin = new ListNode<T>;
		m_End = new ListNode<T>;



		m_Begin->m_NextNode = m_End;
		m_End->m_PrevNode = m_Begin;
		m_Size = 0;
	}

	~LinkedList()
	{

		ListNode<T>* Node = m_Begin;
		ListNode<T>* DeleteNode = Node->m_NextNode;

		//for �� ���� �޸� ����
		//for (int i = 0; i < m_Size + 1; ++i)
		//{							
		//		delete Node;
		//		Node = DeleteNode;
		//		DeleteNode = DeleteNode->m_NextNode;		
		//}
		//
		//delete Node;

		//while �� ���� �޸� ����
		while (Node != nullptr)
		{
			ListNode<T>* DelNode = Node->m_NextNode;
			delete Node;
			Node = DelNode;
		}

	}

public:
	typedef Citerator<T> iterator;

};