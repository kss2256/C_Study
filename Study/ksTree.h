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

			//처음 추가 하는 노드. 
			if (!m_Root)
			{
				m_Root = node;
			}

			//parentData와 같은 데이터를 가지고 있는 노드를 찾아서 
			//해당노드의 자식 노드로 추가한다.
			else
			{
				//처음 추가 하는 노드는 아니지만 Root의 인자가 true라면 새로 들어온
				//노드를 Root노드로 변경 한다.
				if (Root)
				{
					node->m_ChildList.push_back(m_Root);

					m_Root->m_Parent = node;

					m_Root = node;
				}

				//처음 추가 하는 노드도 아니고 Root의 인자가 false라면 
				//parentData 를 이용해서 이 데이터를 사용하는 노드를 찾는다.
				else
				{
					//find함수를 이용해서 노드를 찾는다.
					PNODE ParentNode = findNode(_parentData, m_Root);

					//만약 찾는 데이터가 없으면 리턴.
					if (!ParentNode)
						return;

					//찾아온 부모노드의 자식노드로 새로 생성한 노드를 지정한다.
					ParentNode->m_ChildList.push_back(node);
					//새로 생성한 노드의 부모 노드로 찾아온 부모노드를 지정한다.
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