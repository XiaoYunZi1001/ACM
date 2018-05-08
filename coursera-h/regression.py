from numpy import *

#   打开一个以tab分隔的文本文件，默认文件每行最后一个值是目标值。
def loadDataSet(filename):
    numFeat = len(open(filename).readline().split('\t'))-1
    dataMat = []; labelMat = []
    fr = open(filename)
    for line in fr.readlines():
        lineArr = []
        curLine = line.strip().split('\t')
        for i in range(numFeat):
            lineArr.append(float(curLine[i]))
        dataMat.append(lineArr)
        labelMat.append(float(curLine[-1]))
    return dataMat,labelMat

# 计算最佳拟合曲线
# 读入x,y 并将其存入矩阵中； 计算XTX 并判断其行列式是否为零
def standRegres(xArr,yArr):
    xMat = mat(xArr);yMat = mat(yArr).T
    xTx = xMat.T * xMat
    if linalg.det(xTx) == 0.0:
        print("This matrix is singular,cannot do inverse")
        return
    ws = xTx.I * (xMat.T * yMat)

   # ws = linalg.solve(xTx,xMat.T * yMat)

    return ws

# LWLR
# 给定x空间中任意一点，计算出对应的预测值yHat。


def lwlr(testPoint,xArr,yArr,k=1.0):
    # 读入数据并创建所需矩阵，之后创建对角权重矩阵weights.
    # 权重矩阵是一个方阵eye()，阶数等于样本点个数。也就是说每个矩阵为每个样本点初始化了一个权重。
    xMat = mat(xArr); yMat = mat(yArr).T
    m = shape(xMat)[0]
    weights = mat(eye(m))
    # 遍历数据集，计算每个样本点对应的权重值：随着样本点与待预测点距离递增，权重将以指数级衰减
    #输入参数k 控制衰减速度。
    # 在权重矩阵计算完毕后，就可以得到对回归系数ws的一个估计
    for j in range(m):
        diffMat = testPoint - xMat[j,:]
        weights[j,j] = exp(diffMat * diffMat.T / (-2.0 * k **2))
    xTx = xMat.T * (weights * xMat)
    if linalg.det(xTx) == 0.0:
        print("Thins matrix is singular , cannot do inverse")
        return
    ws = xTx.I * (xMat.T * (weights * yMat))
    return testPoint * ws

# 用于为数据集中每个点调用lwlr()，有助于求解k的大小
def lwlrTest(testArr,xArr,yArr,k=1.0):
    m = shape(testArr)[0]
    yHat = zeros(m)
    for i in range(m):
        yHat[i] = lwlr(testArr[i],xArr,yArr,k)
    return yHat