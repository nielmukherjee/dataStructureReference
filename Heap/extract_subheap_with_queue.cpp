#include <iostream>
#include <vector>
#include <queue>

size_t leftChild(size_t index)
{
    return (index + 1) * 2 - 1;
}

size_t rightChild(size_t index)
{
    return (index + 1) * 2;
}

template<typename Range, typename OutputIterator>
OutputIterator extractSubHeap(Range const& heap, size_t subRootIndex, OutputIterator out)
{
    std::vector<size_t> subHeapIndices;

    std::queue<size_t> currentIndices;

    currentIndices.push(subRootIndex);
    subHeapIndices.push_back(subRootIndex);

    while (!currentIndices.empty())
    {
        size_t index = currentIndices.front();
        if (leftChild(index) < heap.size())
        {
            currentIndices.push(leftChild(index));
            subHeapIndices.push_back(leftChild(index));
        }
        if (rightChild(index) < heap.size())
        {
            currentIndices.push(rightChild(index));
            subHeapIndices.push_back(rightChild(index));
        }
        currentIndices.pop();
    }

    std::vector<int> subHeap;
    std::transform(begin(subHeapIndices), end(subHeapIndices), out,
        [&heap](size_t index) { return heap[index]; });
    return out;
}


int main()
{
    std::vector<int> heap = { 9, 8, 6, 7, 4, 5, 2, 0, 3, 1 };

    std::vector<int> subHeap;
    extractSubHeap(heap, 1, std::back_inserter(subHeap));

    for (int node : subHeap)
    {
        std::cout << node << ' ';
    }
    std::cout << '\n';
}