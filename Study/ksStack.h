#pragma once

#include <assert.h>
namespace ks
{
	template <typename T>
	class StakcNode
	{

	private:

		T					m_Data;
		StakcNode<T>*		m_Next;


	private:
		StakcNode()
			: m_Data(0)
			, m_Next(nullptr)
		{}
		~StakcNode()
		{}

		template <typename T>
		friend class CStack;

	};



	template <typename T>
	class Stack
	{
	private:
		typedef StakcNode<T>		NODE;
		typedef StakcNode<T>*		PNODE;

	private:

		PNODE		m_Last;
		int			m_Size;

	public:

		//��� �߰�.
		void Push(const T& _data)
		{
			PNODE node = new NODE;

			node->m_Data = _data;

			node->m_Next = m_Last;  //�߰��� ����� Next �κ��� Last ���� ���� �صд�.

			m_Last = node;			//�߰� �� ���� Last��尡 �ȴ�

			++m_Size;
		}

		//Last��� Next��带 Last�� �����ϰ� ���� Last��带 ���� �Ѵ�.
		void pop()
		{
			if (m_Size == 0)
			{
				assert(false);
			}
			PNODE node = m_Last->m_Next;

			delete m_Last;

			m_Last = node;

			--m_Size;
		}

		// Last����� �����͸� �����´�.
		T& top()
		{
			if (m_Size == 0)
			{
				assert(false);
			}
			return m_Last->m_Data;
		}
		// Last����� �����͸� �����´�. const ����.
		const T& top() const
		{
			if (m_Size == 0)
			{
				assert(false);
			}
			return m_Last->m_Data;
		}
		// ��� ��带 ����� Last ��带 nullptr�� ����
		void clear()
		{
			PNODE Node = m_Last;

			while (Node != nullptr)
			{
				PNODE next = Node->m_Next;
				delete Node;
				Node = next;
			}
			m_Last = nullptr;
			m_Size = 0;
		}


		int size() const
		{
			return m_Size;
		}

		bool empty() const
		{
			return m_Size == 0;
		}




	public:
		Stack()
			: m_Last(nullptr)
			, m_Size(0)
		{

		}
		~Stack()
		{
			PNODE Node = m_Last;

			while (Node != nullptr)
			{
				PNODE next = Node->m_Next;
				delete Node;
				Node = next;
			}
		}

	};

}