template <class Type>
class MinHeap                           //��С���ࣻ
{
public:
    MinHeap(Type a[], int n);           //���������Ĺ��캯�����ڴ˳�����û��Ӧ�ã�
    MinHeap(int ms);                    //���캯�����أ�ֻ��ʼ���ѵĴ�С���Զ��н�㲻��ʼ�������⣬��Ԫ�صĴ洢��������
    ~MinHeap();                         //��ʽ�����޸�����ָ�룬���ʸ��׽�㣬���������Ž��У�
    bool Insert(const Type& x);         //�������һ��Ԫ�أ�
    bool RemoveMin(Type& x);            //ɾ���Ѷ���С��㣻
    void MakeEmpty();                   //ʹ��Ϊ��
    bool IsEmpty();
    bool IsFull();
    int Size();
protected:
    void FilterDown(const int start, const int endOfHeap);            //�Զ����¹����
    void FilterUp(const int start);                                   //�Ե����Ϲ����
private:
    Type* heap;
    int maxSize;
    const int defaultSize;
    int currentSize;                                                  //�ѵ�ǰ��������С
};

template <class Type>
MinHeap<Type>::MinHeap(int ms) :defaultSize(100)
{
    maxSize = (ms > defaultSize) ? ms : defaultSize;
    heap = new Type[maxSize];
    currentSize = 0;
}

template <class Type>
MinHeap<Type>::MinHeap(Type a[], int n) :defaultSize(100)
{
    maxSize = (n > defaultSize) ? n : defaultSize;
    heap = new Type[maxSize];
    currentSize = n;
    for (int i = 0; i < n; i++) heap[i] = a[i];
    int curPos = (currentSize - 2) / 2;
    while (curPos >= 0)
    {
        FilterDown(curPos, currentSize - 1);
        curPos--;
    }
}

template <class Type>
MinHeap<Type>::~MinHeap()
{
    delete[]heap;
}

template <class Type>
void MinHeap<Type>::FilterDown(const int start, const int endOfHeap)
{
    int i = start, j = i * 2 + 1;
    Type temp = heap[i];
    while (j <= endOfHeap)
    {
        if (j<endOfHeap && heap[j]>heap[j + 1]) j++;
        if (temp < heap[j]) break;
        else
        {
            heap[i] = heap[j];
            i = j;
            j = 2 * i + 1;
        }
    }
    heap[i] = temp;
}

template <class Type>
void MinHeap<Type>::FilterUp(const int start)
{
    int i = start, j = (i - 1) / 2;
    Type temp = heap[i];
    while (i > 0)
    {
        if (temp >= heap[j]) break;
        else
        {
            heap[i] = heap[j];
            i = j;
            j = (i - 1) / 2;
        }
    }
    heap[i] = temp;
}

template <class Type>
bool MinHeap<Type>::RemoveMin(Type& x)
{
    if (IsEmpty())
    {
        cerr << "Heap empty!" << endl;
        return false;
    }
    x = heap[0];
    heap[0] = heap[currentSize - 1];
    currentSize--;
    FilterDown(0, currentSize - 1);
    return true;
}

template <class Type>
bool MinHeap<Type>::Insert(const Type& x)
{
    if (IsFull())
    {
        cerr << "Heap Full!" << endl;
        return false;
    }
    heap[currentSize] = x;
    FilterUp(currentSize);
    currentSize++;
    return true;
}

template <class Type>
bool MinHeap<Type>::IsEmpty()
{
    return currentSize == 0;
}

template <class Type>
bool MinHeap<Type>::IsFull()
{
    return currentSize == maxSize;
}

template <class Type>
void MinHeap<Type>::MakeEmpty()
{
    currentSize = 0;
}

template <class Type>
int MinHeap<Type>::Size()
{
    return currentSize;
}