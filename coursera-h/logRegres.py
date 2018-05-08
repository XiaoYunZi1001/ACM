from numpy import *
# 打开文本文件testSet.txt并逐行读取
# 每行前两个值分别是 X1 X2 第三个值是数据对应的类别标签
def loadDataSet():
    dataMat = []; labelMat = []
    fr = open('data/horseColicTest.txt')
    for line in fr.readlines():
        lineArr = line.strip().split()
        dataMat.append([1.0,float(lineArr[0]),float(lineArr[1])])
        labelMat.append(int(lineArr[21]))
    return dataMat,labelMat

def sigmod(inX):
    return 1.0/(1+exp(-inX))

def gradAscent(dataMatIn,classLabels):
    dataMatrix = mat(dataMatIn)
    labelMat = mat(classLabels).transpose()
    m,n = shape(dataMatrix)
    alpha = 0.001
    maxCycles = 500
    weights = ones((n,1))
    for k in range(maxCycles):
        h = sigmod(dataMatrix * weights)
        error = (labelMat - h)
        weights = weights + alpha * dataMatrix.transpose() * error
    return weights

# 画出数据集和Logitic回归最佳拟合直线函数
def plotBestFit(weights):
    import matplotlib.pyplot as plt
    dataMat,labelMat = loadDataSet()
    dataArr = array(dataMat)

    n = shape(dataArr)[0]
    xcord1 = []; ycord1 = []
    xcord2 = []; ycord2 = []
    for i in range(n):
        if int(labelMat[i]) == 1:
            xcord1.append(dataArr[i,1]);ycord1.append(dataArr[i,2])
        else:
            xcord2.append(dataArr[i,1]);ycord2.append(dataArr[i,2])
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.scatter(xcord1,ycord1,s=30,c='red',marker='s')
    ax.scatter(xcord2,ycord2,s=30,c='green')
    # x = arange(-3.0,3.0,0.1)
    # y = (-weights[0]-weights[1]*x)/weights[2]
    x = weights.copy()
    x.sort(0)
    y = weights * x
    # plt.ylim(-5, 20)
    # plt.xlim(-2.5, 3)
    ax.plot(x,y)
    plt.xlabel('X1'); plt.ylabel('X2')
    plt.show()

# 期望算法避免迭代计算参数时的波动
def stoGradAscent0(dataMatrix,classLabels):
    m,n = shape(dataMatrix)
    alpha = 0.01
    weights = ones(n)
    for i in range(m):
        h = sigmod(sum(dataMatrix[i]*weights))
        error = classLabels[i] - h
        weights = weights + alpha * error *dataMatrix[i]
    return weights

def stocGradAscent1(dataMatrix,classLabels,numIter = 150):
    m,n = shape(dataMatrix)
    weights = ones(n)
    for j in range(numIter):
        dataIndex = list(range(m))
        for i in range(m):
            alpha = 4/(1.0+j+i)+0.01 # alpha每次迭代都调整 0.01常数项是为了保证多次迭代之后新数据仍然具有一定影响
            # 避免参数严格下降也常见模拟退火算法等其他优化算法
            randIndex = int(random.uniform(0,len(dataIndex)))# 通过随机选取样本更新回归系数
            h = sigmod(sum(dataMatrix[randIndex]*weights))
            error = classLabels[randIndex]-h
            weights = weights + alpha*error*dataMatrix[randIndex]
            del(dataIndex[randIndex])
    return weights
# 以回归系数和特征向量作为特征向量作为输入来计算对应的sigmoid值。大于0.5返回1，否则返回0
def classifyVector(inX,weights):
     prob = sigmod(sum(inX*weights))
     if prob > 0.5:
         return 1.0
     else:
         return 0.0
# 打开训练集和测试集，并对数据进行格式化处理的函数
def colicTest():
    # 导入训练集，数据最后一列仍是类别标签。
    frTrain = open('data/horseColicTraining.txt')
    frTest = open('data/horseColicTest.txt')
    trainingSet = [];trainingLabels = []
    for line in frTrain.readlines():
        currLine = line.strip().split('\t')
        lineArr = []
        for i in range(21):
            lineArr.append(float(currLine[i]))
        trainingSet.append(lineArr)
        trainingLabels.append(float(currLine[21]))
    trainWeights = stocGradAscent1(array(trainingSet),trainingLabels,500)

    errorCount = 0;numTestVec = 0.0
    for line in frTest.readlines():
        numTestVec += 1.0
        currLine = line.strip().split('\t')
        lineArr = []
        for i in range(21):
            lineArr = []
            for i in range(21):
                lineArr.append(float(currLine[i]))
        if int(classifyVector(array(lineArr),trainWeights))!=int(currLine[21]):
                errorCount +=1
        # print(errorCount)
        # print(numTestVec)
        errorRate = (float(errorCount)/numTestVec)
        print("the error rate of this test is :%f"%errorRate)
    print(trainWeights)
    plotBestFit(trainWeights)
    return errorRate
# 调用colicTest()10次并求结果的平均值
def multiTest():
    numTests = 10; errorSum = 0.0
    for k in range(numTests):
        errorSum += colicTest()
    print("after %d iterations the average error rate is:%f"%(numTests,errorSum/float(numTests)))

