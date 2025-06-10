import copy
import time

def PowerSetsBinary(items):
    N = len(items)
    for i in range(2 ** N):
        combo = []
        for j in range(N):
            if (i >> j) % 2 == 1:
                combo.append(items[j])
        yield combo

def loadDataSetFromFile(filename):
    dataSet = []
    with open(filename, 'r') as file:
        for line in file:
            transaction = list(map(int, line.strip().split()))
            dataSet.append(transaction)
    return dataSet

def createC1(dataSet):
    C1 = set()
    for transaction in dataSet:
        for item in transaction:
            C1.add(frozenset([item]))
    return C1

def scanDataSet(D, Ck, minSupport):
    subSetCount = {}
    numItems = float(len(D))
    for tid in D:
        for can in Ck:
            if can.issubset(tid):
                subSetCount[can] = subSetCount.get(can, 0) + 1
    returnList = []
    supportData = {}
    for key in subSetCount:
        support = subSetCount[key] / numItems
        if support >= minSupport:
            returnList.append(key)
        supportData[key] = support
    return returnList, supportData

def aprioriGen(Lk, k):
    returnList = []
    for i in range(len(Lk)):
        for j in range(i + 1, len(Lk)):
            L1 = sorted(list(Lk[i])[: k - 2])
            L2 = sorted(list(Lk[j])[: k - 2])
            if L1 == L2:
                returnList.append(Lk[i] | Lk[j])
    return returnList

def has_infrequent_subset(L, Ck, k):
    Ckc = copy.deepcopy(Ck)
    for i in Ck:
        p = [t for t in i]
        i_subset = PowerSetsBinary(p)
        subsets = [i for i in i_subset]
        for each in subsets:
            if each != [] and each != p and len(each) < k:
                if frozenset(each) not in [t for z in L for t in z]:
                    Ckc.remove(i)
                    break
    return Ckc

def apriori(dataSet, minSupport):
    start_time = time.time()
    C1 = createC1(dataSet)
    D = [set(var) for var in dataSet]
    L1, suppData = scanDataSet(D, C1, minSupport)
    L = [L1]
    k = 2

    while len(L[k - 2]) > 0:
        Ck = aprioriGen(L[k - 2], k)
        Ck2 = has_infrequent_subset(L, Ck, k)
        Lk, supK = scanDataSet(D, Ck2, minSupport)
        suppData.update(supK)
        L.append(Lk)
        k += 1
    end_time = time.time()
    execution_time = end_time - start_time
    return L[:-1], suppData, execution_time

def count_itemsets(frequent_itemsets):
    for i, itemsets in enumerate(frequent_itemsets):
        print(f"{i + 1} {len(itemsets)}")

def save_frequent_itemsets(frequent_itemsets, output_file):
    with open(output_file, 'w') as file:
        for itemsets in frequent_itemsets:
            for itemset in itemsets:
                file.write("{" + ','.join(map(str, itemset)) + "}\n")

if __name__ == '__main__':
    filename = r"C:\Users\74140\Desktop\Term Course\数据挖掘\PythonApplication1\PythonApplication1\T1014D1K.dat"
    myDat = loadDataSetFromFile(filename)
    L, suppData, execution_time = apriori(myDat, 6 / len(myDat))
    frequent_itemsets = [sorted(list(itemset)) for itemset in L]
    output_file = f"{filename}_support_6.txt"
    save_frequent_itemsets(frequent_itemsets, output_file)
    count_itemsets(frequent_itemsets)
    print(f"Execution Time: {execution_time} seconds")
