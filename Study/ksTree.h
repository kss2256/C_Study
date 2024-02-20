#pragma once

#include <assert.h>
#include <list>

using std::list;
using std::iterator;


namespace ks
{
	template <typename T>
	class TreeNode
	{
		template <typename T>
		friend class CTree;
	private:

		T									m_Data;
		TreeNode<T>*						m_Parent;
		list<TreeNode<T>*>					m_ChildList;

	private:
		TreeNode()
		{
			m_Parent = nullptr;
		}
		~TreeNode()
		{
			

		}

	};



	template <typename T>
	class Tree
	{
		typedef TreeNode<T>		NODE;
		typedef TreeNode<T>*	PNODE;

	private:

		PNODE		m_Root;
		int			m_Size;


	public:


	public:

		void insert(T _data, T _parentData = 0, bool Root = false)
		{

			PNODE node = new NODE;

			node->m_Data = _data;

			//ó�� �߰� �ϴ� ���. 
			if (!m_Root)
			{
				m_Root = node;
			}

			//parentData�� ���� �����͸� ������ �ִ� ��带 ã�Ƽ� 
			//�ش����� �ڽ� ���� �߰��Ѵ�.
			else
			{
				//ó�� �߰� �ϴ� ���� �ƴ����� Root�� ���ڰ� true��� ���� ����
				//��带 Root���� ���� �Ѵ�.
				if (Root)
				{
					node->m_ChildList.push_back(m_Root);

					m_Root->m_Parent = node;

					m_Root = node;
				}

				//ó�� �߰� �ϴ� ��嵵 �ƴϰ� Root�� ���ڰ� false��� 
				//parentData �� �̿��ؼ� �� �����͸� ����ϴ� ��带 ã�´�.
				else
				{
					//find�Լ��� �̿��ؼ� ��带 ã�´�.
					PNODE ParentNode = findNode(_parentData, m_Root);

					//���� ã�� �����Ͱ� ������ ����.
					if (!ParentNode)
						return;

					//ã�ƿ� �θ����� �ڽĳ��� ���� ������ ��带 �����Ѵ�.
					ParentNode->m_ChildList.push_back(node);
					//���� ������ ����� �θ� ���� ã�ƿ� �θ��带 �����Ѵ�.
					node->m_Parent = ParentNode;

				}

			}
			++m_Size;
		}


		void OutputTree(void(*Func)(const T&))
		{
			OutputTree(Func, m_Root);
		}



	private:

		void OutputTree(void(*Func)(const T&), PNODE _node)
		{
			Func(_node->m_Data);

			typename list<TreeNode<T>*>::iterator iter = _node->m_ChildList.begin();

			typename list<TreeNode<T>*>::iterator iterend = _node->m_ChildList.end();

			for (; iter != iterend; ++iter)
			{
				OutputTree(Func, *iter);

			}
		}



		PNODE findNode(const T& _data, PNODE _node)
		{
			if (_node->m_Data == _data)
				return _node;

			typename list<TreeNode<T>*>::iterator iter = _node->m_ChildList.begin();

			typename list<TreeNode<T>*>::iterator iterend = _node->m_ChildList.end();

			for (; iter != iterend; ++iter)
			{
				PNODE Result = findNode(_data, *iter);

				if (Result)
					return Result;

			}

			return nullptr;
		}


	public:
		Tree()
		{
			m_Root = nullptr;
			m_Size = 0;

		}
		~Tree()
		{
			



		}

	};


}