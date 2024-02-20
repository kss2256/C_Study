#pragma once


namespace ks
{
	template <typename T, bool SORT = false, int SIZE = 4>
	class Vector
	{


	private:
		
		T*			mData;
		int			mSize;
		int			mCapacity;

	private:

		void sort(int _data)
		{
			if (_data == 1)
				return;

			for (size_t i = 0; i < mSize - 1; i++)
			{				
				if (mData[i] > mData[i + 1])
				{
					mData[mSize] = mData[i];
					mData[i] = mData[i + 1];
					mData[i + 1] = mData[mSize];
				}
			}

			return sort(_data - 1);
		}


	public:

		T& operator[] (int _data)
		{
			return mData[_data];
		}


	public:

		
		void push_Back(T _data)
		{

			if (mSize + 1 >= mCapacity)
			{
				Relocation();
			}		
			mData[mSize++] = _data;

			if(SORT)
			sort(mSize);
		}

	public:

		int size() { return mSize; }
		bool empty() { return mSize == 0; }


		void Relocation()
		{
			T* type = new T[mCapacity * 2];
			for (size_t i = 0; i < mSize; i++)
			{
				type[i] = mData[i];
			}
			delete[] mData;
			mData = type;
			mCapacity *= 2;			
		}

	public:

		Vector()
		{
			mSize = 0;
			mCapacity = SIZE;

			mData = new T[mCapacity];

		}
		~Vector()
		{
			delete[] mData;
		}

	};

}